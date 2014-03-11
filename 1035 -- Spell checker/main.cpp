#include <iostream>
#include <vector>
#include <string>
using namespace std;
#pragma warning(disable:4996)
#define MAX_BYTE 0x7f
#define MAX_INT 0x7fffffff

int match(string &s1, string &s2) {
	string &s = s1.length() < s2.length() ? s1 : s2;
	string &l = s1.length() < s2.length() ? s2 : s1;
	// s.legnth() < l.length()
	unsigned i = 0, j = 0, count = 0;
	while (i < s.length() && j < l.length()) {
		if (s[i] == l[j]) i++, j++, count++;
		else j++;
	}
	return count;
}

int main() {
	// freopen("..\\test.txt", "r", stdin);
	vector<string> dict;
	string tmp;
	while (cin >> tmp && tmp[0] != '#') {
		dict.push_back(tmp);
	}
	while (cin >> tmp && tmp[0] != '#') {
		unsigned len = tmp.length();
		vector<string> possible;
		bool correct = false;
		vector<string>::iterator it;
		for (it = dict.begin(); it != dict.end(); it++) {
			if (it->length() == len) {
				unsigned count = 0;
				for (unsigned i = 0; i < len; i++) {
					if ((*it)[i] == tmp[i]) count++;
				}
				if (count == len) {
					correct = true;
					break;
				} else if (count == len-1) {
					possible.push_back(*it);
				}
			} else if (it->length() == len+1) {
				if (match(*it, tmp) == len) possible.push_back(*it);
			} else if (it->length() == len-1) {
				if (match(*it, tmp) == len-1) possible.push_back(*it);
			}
		}
		if (correct) cout << tmp << " is correct\n";
		else {
			cout << tmp << ':';
			for (it = possible.begin(); it != possible.end(); it++) {
				cout << ' ' << *it;
			}
			cout << '\n';
		}
	}
}