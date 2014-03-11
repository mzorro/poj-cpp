#include <iostream>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)
#define CALC_T(D, H) (H-0.5555*(6.11*exp(5417.7530*(1/273.16-1/(D+273.16)))-10.0))
#define CALC_D(T, H) (1/(1/273.16-log((((H-T)/0.5555)+10.0)/6.11)/5417.7530)-273.16)
#define CALC_H(T, D) (T+0.5555*(6.11*exp(5417.7530*(1/273.16-1/(D+273.16)))-10.0))

int main() {
	//freopen("..\\test.txt", "r", stdin);
	char c;
	double t, d, h;
	while (cin >> c && c != 'E') {
		t = d = h = 200.0;
		switch(c) {
		case 'T': cin >> t; break;
		case 'D': cin >> d; break;
		case 'H': cin >> h; break;
		}
		cin >> c;
		switch(c) {
		case 'T': cin >> t; break;
		case 'D': cin >> d; break;
		case 'H': cin >> h; break;
		}
		if (t == 200.0) t = CALC_T(d, h);
		if (d == 200.0) d = CALC_D(t, h);
		if (h == 200.0) h = CALC_H(t, d);
		cout.precision(1);
		cout << "T " << fixed << t << ' ';
		cout << "D " << fixed << d << ' ';
		cout << "H " << fixed << h << endl;
	}
}