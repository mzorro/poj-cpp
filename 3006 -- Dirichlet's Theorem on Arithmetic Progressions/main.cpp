#include <iostream>
using namespace std;
#pragma warning(disable:4996)

bool isPrime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i*i <= n; i+=2) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int a, d, n;
	while (cin >> a >> d >> n && a && d && n) {
		if (isPrime(a)) n--;
		while (n) {
			a += d;
			if (isPrime(a)) n--;
		}
		cout << a << endl;
	}
}