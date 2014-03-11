#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int T, N, f, t;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> cnt(201, 0);;
		while (N--) {
			cin >> f >> t;
			f = (f + 1) / 2;
			t = (t + 1) / 2;
			if (f > t) swap(f, t);
			while (f <= t) {
				cnt[f++] += 1;
			}
		}
		int maxcnt = 0;
		for (int i = 1; i <= 200; i++) {
			maxcnt = max(maxcnt, cnt[i]);
		}
		cout << maxcnt * 10 << endl;
	}
}