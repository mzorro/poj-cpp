#include <iostream>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
#define MAX_BYTE 0x7f
#define MAX_INT 0x7fffffff

#define GMAX 55
char G[GMAX][GMAX];
int node[GMAX][GMAX];

#define NMAX 105
int dist[NMAX][NMAX];

int M, N, all;
int mode[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

void BFS(int sx, int sy) {
	bool vst[51][51];
	int d[51][51];
	d[sx][sy] = 0;
	memset(vst, 0, sizeof(vst));
	queue<int> qx, qy;
	qx.push(sx); qy.push(sy);
	while (!qx.empty()) {
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		if (G[x][y]=='A' || G[x][y]=='S') {
			dist[ node[sx][sy] ][ node[x][y] ] = d[x][y];
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + mode[i][0];
			int ny = y + mode[i][1];
			if (vst[nx][ny] || nx < 0 || nx >= N ||
				ny < 0 || ny >= M || G[nx][ny]=='#') continue;
			d[nx][ny] = d[x][y] + 1;
			vst[nx][ny] = true;
			qx.push(nx); qy.push(ny);
		}
	}
}

int Prim() {
	int prim_sum = 0;
	int d[NMAX];
	memset(d, MAX_BYTE, sizeof(d));
	bool vst[NMAX];
	memset(vst, 0, sizeof(vst));
	int s = 0;
	for (int k = 1; k < all; k++) {
		int mind = MAX_INT, mini;
		vst[s] = true;
		for (int i = 1; i < all; i++) {
			if (vst[i]) continue;
			if (d[i] > dist[s][i]) {
				d[i] = dist[s][i];
			}
			if (mind > d[i]) {
				mind = d[i];
				mini = i;
			}
		}
		s = mini;
		prim_sum += mind;
	}
	return prim_sum;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		cin >> M >> N;
		char tmp[GMAX];
		gets(tmp); // Use cin.get() and you'll get WA!! Don't ask me why!
		all = 0;
		memset(node, -1, sizeof(node));
		for (int i = 0; i < N; i++) {
			gets(G[i]);
			for (int j = 0; j < M; j++) {
				if (G[i][j] == 'A' || G[i][j] == 'S') {
					node[i][j] = all++;
				}
			}
		}

		// BFS
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (node[i][j]>=0) BFS(i, j);
			}
		}

		// Prim
		cout << Prim() << endl;
	}
}