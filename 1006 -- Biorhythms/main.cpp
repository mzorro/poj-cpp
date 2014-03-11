#include <iostream>
using namespace std;
#pragma warning(disable:4996)
#define P 23
#define E 28
#define I 33
#define LCM (P * E * I)

int min3(int i1, int i2, int i3) {
	if (i1 <= i2 && i1 <= i3) return 1;
	if (i2 <= i1 && i2 <= i3) return 2;
	if (i3 <= i1 && i3 <= i2) return 3;
	return 0;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int cnt = 1;
	int p, e, i, d, t;
	cin >> p >> e >> i >> d;
	while (p+e+i+d >= 0) {
		cout << "Case " << cnt++;
		do {
			switch (min3(p, e, i)) {
			case 1: p += P; break;
			case 2: e += E; break;
			case 3: i += I; break;
			}
		} while (!(p == e && p == i));
		t = p - d;
		if (t <= 0) t += LCM;
		if (t > LCM) t -= LCM;
		cout << ": the next triple peak occurs in ";
		cout << t << " days." << endl;
		cin >> p >> e >> i >> d;
	}
}