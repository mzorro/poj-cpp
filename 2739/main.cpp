#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

bool isPrime(int num) {
	for (int i=2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

vector<int> primes;
void getPrimes() {
	for (int i = 2; i < 10000; i++) {
		if (isPrime(i)) primes.push_back(i);
	}
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	getPrimes();
	int N, len = primes.size();
	while (cin >> N && N) {
		int cnt = 0, sum = 0;
		vector<int> chain;
		for (int i = 0; i < len; i++) {
			if (primes[i] > N) break;
			chain.push_back(primes[i]);
			sum += primes[i];
			while (sum >= N) {
				if (sum == N) cnt++;
				sum -= chain.front();
				chain.erase(chain.begin());
			}
		}
		cout << cnt << endl;
	}
}