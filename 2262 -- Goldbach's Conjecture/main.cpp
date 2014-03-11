#include <iostream>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

bool isPrime(int n) {
	if (n % 2 == 0) return false;
	for (int i = 3; i*i <= n; i+=2) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int N;
	while (cin >> N && N) {
		for (int i = 3; i <= N / 2; i += 2) {
			if (isPrime(i) && isPrime(N - i)) {
				cout << N << " = " << i << " + " << N-i << endl;
				break;
			}
		}
	}
}