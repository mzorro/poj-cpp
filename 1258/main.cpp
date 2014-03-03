#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
#define MAX_BYTE 0x7f
#define MAX_INT 0x7fffffff
#define MAXN 105
int matrix[MAXN][MAXN];
int dis[MAXN];
bool vst[MAXN];
int main() {
	//freopen("..\\test.txt", "r", stdin);
	int N;
	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> matrix[i][j];
			}
		}
		memset(dis, MAX_BYTE, sizeof(dis));
		memset(vst, 0 ,sizeof(vst));
		int prim_sum = 0;
		int s = 0;
		for (int i = 1; i < N; i++) {
			int mind = MAX_INT, minj;
			vst[s] = true;
			for (int j = 1; j < N; j++) {
				if (vst[j]) continue;
				if (dis[j] > matrix[s][j]) {
					dis[j] = matrix[s][j];
				}
				if (mind > dis[j]) {
					mind = dis[j];
					minj = j;
				}
			}
			s = minj;
			prim_sum += mind;
		}
		cout << prim_sum << endl;
	}
}