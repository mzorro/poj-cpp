#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7FFFFFFF

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int M, N;
	cin >> M >> N;
	vector<vector<pair<int, int> > > matrix(N+1);
	vector<int> loc(N+1);
	vector<int> dis(N+1);
	int x, t, v;
	for (int i = 1; i <= N; i++) {
		cin >> dis[i] >> loc[i] >> x;
		matrix[0].push_back(pair<int, int>(i, dis[i]));
		while (x--) {
			cin >> t >> v;
			matrix[t].push_back(pair<int, int>(i, v));
		}
	}
	dis[0] = 0;
	int mincost = MAX_INT;
	for (int k = 1; k <= N; k++) {
		vector<int> d(dis);
		vector<bool> vst(N+1, false);
		for (int i = 1; i <= N; i++) {
			if (loc[i] > loc[k] || loc[i] < loc[k] - M) vst[i] = true;
		}
		int cur = 0;
		for (int i = 0; i <= N; i++) {
			vst[cur] = true;
			vector<pair<int, int> >::iterator it;
			for (it = matrix[cur].begin(); it != matrix[cur].end(); it++) {
				if (vst[it->first]) continue;
				if (d[it->first] > d[cur] + it->second) {
					d[it->first] = d[cur] + it->second;
				}
			}
			int mind = MAX_INT;
			for (int j = 1; j <= N; j++) {
				if (vst[j]) continue;
				if (d[j] < mind) {
					mind = d[j];
					cur = j;
				}
			}
		}
		mincost = min(mincost, d[1]);
	}
	cout << mincost << endl;
}