#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff
#define MAX_BYTE 0x7f
#define MAXN 505
int matrix[MAXN][MAXN];
int dis[MAXN];
bool vst[MAXN];

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int M;
		scanf("%d", &M);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}
		memset(dis, MAX_BYTE, sizeof(dis));
		memset(vst, 0, sizeof(vst));
		int prim_max = 0;
		int s = 0;
		for (int k = 1; k < M; k++)
		{
			int mind = MAX_INT, mini;
			vst[s] = true;
			for (int i = 1; i < M; i++) {
				if (vst[i]) continue;
				if (dis[i] > matrix[i][s]) {
					dis[i] = matrix[i][s];
				}
				if (mind > dis[i]) {
					mind = dis[i];
					mini = i;
				}
			}
			s = mini;
			prim_max = max(prim_max, mind);
		}
		printf("%d\n", prim_max);
	}
}