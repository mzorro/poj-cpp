#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int N;
	while (cin >> N && N) {
		vector<vector<pair<int, int> > > matrix(N+1);
		int n, a, t;
		for (int i = 1; i <= N; i++) {
			cin >> n;
			while (n--) {
				cin >> a >> t;
				matrix[i].push_back(pair<int, int>(a, t));
			}
		}
		int fastest, mincost = MAX_INT;
		for (int i = 1; i <= N; i++) {
			int cur = i;
			vector<bool> vst(N+1, false);
			vector<int> dis(N+1, MAX_INT);
			dis[cur] = 0;
			for (int k = 0; k < N; k++) {
				vst[cur] = true;
				vector<pair<int, int> >::iterator it;
				for (it = matrix[cur].begin(); it != matrix[cur].end(); it++) {
					if (vst[it->first]) continue;
					if (dis[it->first] > dis[cur] + it->second) {
						dis[it->first] = dis[cur] + it->second;
					}
				}
				int mind = MAX_INT;
				for (int j = 1; j <= N; j++) {
					if (vst[j]) continue;
					if (dis[j] < mind) {
						mind = dis[j];
						cur = j;
					}
				}
			}
			int maxd = 0, maxj;
			for (int j = 1; j <= N; j++) {
				if (maxd < dis[j]) {
					maxd = dis[j];
					maxj = j;
				}
			}
			if (mincost > maxd) {
				fastest = i;
				mincost = maxd;
			}
		}
		if (mincost == MAX_INT) cout << "disjoint" << endl;
		else cout << fastest << ' ' << mincost << endl;
	}
}