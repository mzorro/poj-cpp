#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

bool rect[4][4];

bool check() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (!rect[i][j]) return false;
		}
	}
	return true;
}

void change(int pos) {
	int row = pos / 4, col = pos % 4;
	rect[row][col] = !rect[row][col];
	for (int i = 0; i < 4; i++) {
		rect[row][i] = !rect[row][i];
		rect[i][col] = !rect[i][col];
	}
}

vector<int> steps;
int maxdeep = 0;
bool dfs(int pos, int deep) {
	if (deep == maxdeep) return check();
	if (pos == 16) return false;
	
	steps.push_back(pos);
	change(pos);
	if (dfs(pos+1, deep+1)) return true;

	steps.pop_back();
	change(pos);
	if (dfs(pos+1, deep)) return true;
	return false;
}

void print() {
	int len = steps.size();
	cout << len << endl;
	for (int i = 0; i < len; i++) {
		cout << steps[i] / 4 + 1 << ' '
			 << steps[i] % 4 + 1 << endl;
	}
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	char c;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (cin >> c && c == '-')
				rect[i][j] = true;
			else rect[i][j] = false;
		}
	}
	while (maxdeep <= 16) {
		steps.clear();
		if (dfs(0, 0)) { print(); break; }
		maxdeep++;
	}
}