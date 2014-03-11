#include <iostream>
using namespace std;
#define PI 3.1415f
#pragma warning(disable:4996)

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cout << "Property " << i;
		cout << ": This property will begin eroding in year ";
		float x, y;
		cin >> x >> y;
		int year = int((x*x + y*y) * PI / 100) + 1;
		cout << year << '.' << endl;
	}
	cout << "END OF OUTPUT." << endl;
}