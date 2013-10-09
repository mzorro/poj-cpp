#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

char map[10][10];
bool vst[10][10];
int main() {
	//freopen("..\\test.txt", "r", stdin);
	int R, C, S;
	while (cin >> R >> C >> S && R && C && S) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> map[j][i];
			}
		}
		memset(vst, 0, sizeof(vst));
		int curx = S - 1, cury = 0;
		vector<int> path;
		bool flag = false;
		while (curx >= 0 && curx < C && cury >= 0 && cury < R) {
			if (vst[curx][cury]) {
				vector<int>::reverse_iterator rit = path.rbegin();
				while (*rit != curx * C + cury) rit ++;
				cout << path.rend() - rit - 1
					<< " step(s) before a loop of "
					<< rit - path.rbegin() + 1
					<< " step(s)" << endl;
				flag = true;
				break;
			} else {
				path.push_back(curx * C + cury);
				vst[curx][cury] = true;
			}
			switch (map[curx][cury]) {
			case 'N': cury --; break;
			case 'S': cury ++; break;
			case 'E': curx ++; break;
			case 'W': curx --; break;
			}
		}
		if (!flag) {
			cout << path.size() << " step(s) to exit" << endl;
		}
	}
}