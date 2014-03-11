#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)
#define MAX_BYTE 0x7f
#define MAX_INT 0x7fffffff

int main() {
	// freopen("..\\test.txt", "r", stdin);
	string s, l;
	while (cin >> s >> l) {
		unsigned i = 0, j = 0;
		while (i < s.length() && j < l.length()) {
			if (s[i] == l[j]) i++, j++;
			else j++;
		}
		if (i == s.length()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}