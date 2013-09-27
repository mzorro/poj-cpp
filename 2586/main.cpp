#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int s, d;
void print(int scnt, int dcnt) {
	int sum = scnt * s - dcnt * d;
	if (sum < 0) cout << "Deficit" << endl;
	else cout << sum << endl;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	while (cin >> s >> d) {
		if (d > 4 * s) print(10, 2);
		else if (2 * d > 3 * s) print(8, 4);
		else if (3 * d > 2 * s) print(6, 6);
		else if (4 * d > s) print(3, 9);
		else print(0, 12);
	}
}