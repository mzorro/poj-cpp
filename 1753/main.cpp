#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

bool rect[6][6];
int step;

bool check() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (rect[i][j] != rect[1][1]) {
				return false;
			}
		}
	}
	return true;
}

int r[] = {-1, 1, 0, 0, 0};
int c[] = {0, 0, -1, 1, 0};
void fliparound(int pos) {
	int row = pos / 4 + 1, col = pos % 4 + 1;
	for (int i = 0; i < 5; i++) {
		rect[row+r[i]][col+c[i]] = !rect[row+r[i]][col+c[i]];
	}
}

bool dfs(int pos, int deep) {
	if (deep == step) return check();
	if (pos == 16) return false;
	fliparound(pos);
	if (dfs(pos+1, deep+1)) return true;

	fliparound(pos);
	if (dfs(pos+1, deep)) return true;
	return false;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	char c;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			rect[i][j] = (cin >> c && c == 'b');
		}
	}

	for (step = 0; step <= 16; step++) {
		if (dfs(0, 0)) {
			cout << step << endl;
			return 0;
		}
	}
	cout << "Impossible" << endl;
}