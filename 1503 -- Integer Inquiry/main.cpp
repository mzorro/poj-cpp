#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

bool cmp(const string &s1, const string & s2) {
	return s1.size() > s2.size();
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	string s;
	vector<string> nums;
	while (cin >> s && s != "0") {
		nums.push_back(s);
	}
	sort(nums.begin(), nums.end(), cmp);
	int cnt = nums.size();
	vector<string::reverse_iterator> it(cnt);
	for (int i = 0; i < cnt; i++) {
		it[i] = nums[i].rbegin();
	}
	string res;
	int c = 0;
	while (it[0] != nums[0].rend()) {
		int n=0;
		for (int i = 0; i < cnt; i++) {
			if (it[i] != nums[i].rend()) {
				n += *(it[i]++) - '0';
			}
		}
		n += c;
		res += '0' + n % 10;
		c = n / 10;
	}
	while (c) {
		res += '0' + c % 10;
		c /= 10;
	}
	string::reverse_iterator i = res.rbegin();
	while (i != res.rend()) {
		cout << *(i++);
	}
	cout << endl;
}