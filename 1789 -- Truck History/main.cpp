#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff

#define MAXN 2005
int dis[MAXN][MAXN];
int mindis[MAXN];
bool vst[MAXN];
string str[MAXN];

int dist(int i, int j) {
	int res = 0, k = str[i].length();
	while (k--) {
		if (str[i][k] != str[j][k]) res++;
	}
	return res;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int N;
	while (cin >> N && N) {
		for (int i = 0; i < N; i++) {
			cin >> str[i];
		}
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				dis[i][j] = dis[j][i] = dist(i, j);
			}
		}
		memset(vst, 0, sizeof(vst));
		memset(mindis, 0x7f, sizeof(mindis));
		int sumd = 0;
		int cur = 0;
		for (int k = 1; k < N; k++) {
			vst[cur] = true;
			int mind = MAX_INT, mini;
			for (int i = 1; i < N; i++) {
				if (vst[i]) continue;
				if (mindis[i] > dis[cur][i]) {
					mindis[i] = dis[cur][i];
				}
				if (mind > mindis[i]) {
					mind = mindis[i];
					mini = i;
				}
			}
			cur = mini;
			sumd += mind;
		}
		cout << "The highest possible quality is 1/" << sumd << "." << endl;
	}
}