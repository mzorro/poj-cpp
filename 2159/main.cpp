#include <iostream>
#include <string>
#include <set>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\test.txt", "r", stdin);
	string s[2];
	cin >> s[0] >> s[1];
	multiset<int> cnt[2];
	for (int i = 0; i < 2; i++) {
		set<char> cnted;
		int len = s[i].size();
		for (int j = 0; j < len; j++) {
			if (cnted.find(s[i][j])==cnted.end()) {
				cnted.insert(s[i][j]);
				int c = 0, t = j;
				while ((t=s[i].find(s[i][t], t+1))!=string::npos) {
					c++;
				}
				cnt[i].insert(c);
			}
		}
	}
	multiset<int>::iterator it1, it2;
	it1 = cnt[0].begin(), it2 = cnt[1].begin();
	while (it1!=cnt[0].end() && it2!=cnt[1].end()) {
		if (*(it1++) != *(it2++)) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}