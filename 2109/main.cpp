#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

int main() {
	freopen("..\\test.txt", "r", stdin);
	double n, p;
	while (cin >> n >> p) {
		cout.precision(0);
		cout << fixed << pow(p, 1/n) << endl;
	}
}