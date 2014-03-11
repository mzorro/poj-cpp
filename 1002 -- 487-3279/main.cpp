#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

map<char, char> char2num;
void create_map() {
	char c = 'A' - 1, num = '2';
	int i = 0;
	while (++c < 'Z') {
		if (c == 'Q') continue;
		char2num[c] = num;
		if (++i % 3 == 0) num++;
	}
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	create_map();
	int N;
	cin >> N;
	vector<string> nums(N);
	string s;
	while (N--) {
		cin >> s;
		string::iterator it;
		for (it=s.begin(); it!=s.end(); it++) {
			if (*it == '-') continue;
			if (char2num.find(*it)!=char2num.end()) {
				nums[N] += char2num[*it];
			} else {
				nums[N] += *it;
			}
		}
		nums[N].insert(nums[N].begin()+3, '-');
	}
	sort(nums.begin(), nums.end());
	vector<string>::iterator it = nums.begin();
	string last = *nums.begin();
	int cnt = 1;
	bool have_result = false;
	while (++it != nums.end()) {
		if (*it != last) {
			if (cnt > 1) {
				cout << last << ' ' << cnt << endl;
				have_result = true;
			}
			last = *it;
			cnt = 1;
		} else {
			cnt++;
		}
	};
	if (cnt > 1) {
		cout << last << ' ' << cnt << endl;
		have_result = true;
	}
	if (!have_result) {
		cout << "No duplicates." << endl;
	}
}