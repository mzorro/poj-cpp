#include <iostream>
using namespace std;
#define MAXN 12
#pragma warning(disable:4996)

int main() {
	//freopen("..\\test.txt", "r", stdin);
	float sum = 0.0f, tmp;
	int i = MAXN;
	while (i--) {
		cin >> tmp;
		sum += tmp;
	}
	cout << '$';
	cout.precision(2);
	cout << fixed << sum / MAXN << endl;
}