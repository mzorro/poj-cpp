#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\test.txt", "r", stdin);
	string s;
	while (getline(cin, s) && s != "#") {
		int len = s.size(), sum = 0;
		for (int i = 0; i < len; i++) {
			char c = s[i];
			if (c == ' ') c = 'A' - 1;
			sum += (i + 1) * (c - 'A' + 1);
		}
		cout << sum << endl;
	}
}