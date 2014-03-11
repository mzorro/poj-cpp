#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

bool S[200];
int top;
void add(int cnt, bool value) {
	while (cnt--) S[++top] = value;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int N;
	cin >> N;
	while (N--) {
		top = -1;
		int n, c, last = 0;
		cin >> n;
		while (n--) {
			cin >> c;
			c -= last;
			add(c, false);
			add(1, true);
			last += c;
		}
		vector<int> vcnt;
		for (int i = 0; i <= top; i++) {
			if (!S[i]) continue;
			int c = 0, cnt = 1;
			for (int j = i-1; j >= 0; j--) {
				if (S[j]) c++, cnt++;
				else if (c!=0) c--;
				else break;
			}
			vcnt.push_back(cnt);
		}
		vector<int>::iterator it = vcnt.begin();
		cout << *it;
		while (++it != vcnt.end()) {
			cout << ' ' << *it;
		}
		cout << endl;
	}
}