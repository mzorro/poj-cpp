#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#pragma warning(disable:4996)

int remove_point(string &s) {
	while (*s.begin()=='0') {
		s.erase(s.begin());
	}
	int p = s.rfind('.');
	if (p == string::npos) {
		p = 0;
	} else {
		while (*(s.end()-1)=='0') {
			s.erase(s.end() - 1);
		}
		s.erase(s.begin() + p);
		p = s.size() - p;
	}
	while (*s.begin()=='0') {
		s.erase(s.begin());
	}
	return p;
}

void add_point(string &s, int cnt) {
	if (cnt==0) return;
	while (int(s.size()) < cnt) {
		s.insert(s.begin(), '0');
	}
	s.insert(s.begin() + s.size() - cnt, '.');
}

string multiply(string s, int n) {
	string::reverse_iterator rit = s.rbegin();
	int tmp, c = 0;
	while (rit != s.rend()) {
		tmp = (*rit - '0') * n + c;
		c = tmp / 10;
		*rit = tmp % 10 + '0';
		rit++;
	}
	while (c) {
		s.insert(s.begin(), c % 10 + '0');
		c /= 10;
	}
	return s;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	string s;
	int n;
	while (cin >> s >> n) {
		int p = remove_point(s);
		if (s.empty()) {
			cout << '0' << endl;
			continue;
		}
		istringstream sin(s);
		int num; sin >> num;
		for (int i = 1; i < n; ++i) {
			s = multiply(s, num);
		}
		add_point(s, p*n);
		cout << s << endl;
	}
	return 0;
}