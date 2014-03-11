#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int lessthan(const string &s, string::const_iterator beg) {
	int cnt = 0;
	char value = *beg;
	while (++beg != s.end()) {
		if (*beg < value) cnt++;
	}
	return cnt;
}

int measure(const string &s) {
	int cnt = 0;
	string::const_iterator it;
	for (it=s.begin(); it != s.end(); it++) {
		cnt += lessthan(s, it);
	}
	return cnt;
}

bool cmp(const pair<string, int> &p1,
		 const pair<string, int> &p2) {
	return p1.second < p2.second;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int len, N;
	cin >> len >> N;
	vector<pair<string, int> > strs(N);
	for (int i = 0; i < N; i++) {
		cin >> strs[i].first;
		strs[i].second = measure(strs[i].first);
	}
	sort(strs.begin(), strs.end(), cmp);
	vector<pair<string, int> >::iterator it = strs.begin();
	while (it != strs.end()) {
		cout << (it++)->first << endl;
	}
}