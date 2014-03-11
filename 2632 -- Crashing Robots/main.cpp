#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

struct Robot {
	int x, y, ort, id;
	static int A, B;
	static int map[101][101];

	Robot(int i) : id(i) {
		cin >> x >> y;
		map[x][y] = i;
		char c;
		cin >> c;
		switch(c) {
		case 'N': ort = 0; break;
		case 'E': ort = 1; break;
		case 'S': ort = 2; break;
		case 'W': ort = 3; break;
		}
	}

	int act(char action, int repeat) {
		switch (action) {
		case 'L':
			while (repeat--) ort --;
			while (ort < 0) ort += 4;
			return true;
		case 'R':
			while (repeat--) ort ++;
			ort %= 4;
			return true;
		case 'F':
			while (repeat--) {
				map[x][y] = 0;
				switch (ort) {
				case 0: y ++; break;
				case 1: x ++; break;
				case 2: y --; break;
				case 3: x --; break;
				}
				if (x == 0 || x == A + 1 ||
					y == 0 || y == B + 1) {
					cout << "Robot " << id << " crashes into the wall" << endl;
					return false;
				} else if (map[x][y]) {
					cout << "Robot " << id << " crashes into robot " << map[x][y] << endl;
					return false;
				} else {
					map[x][y] = id;
				}
			}
		}
		return true;
	}
};
int Robot::A, Robot::B;
int Robot::map[101][101];

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		cin >> Robot::A >> Robot::B;
		memset(Robot::map, 0, sizeof(Robot::map));
		int N, M;
		cin >> N >> M;
		vector<Robot> robots;
		for (int i = 1; i <= N; i++) {
			robots.push_back(Robot(i));
		}
		bool crashed = false;
		while (M--) {
			int robot, repeat;
			char action;
			cin >> robot >> action >> repeat;
			if (!crashed && !robots[robot-1].act(action, repeat)) {
				crashed = true;
			}
		}
		if (!crashed) cout << "OK" << endl;
	}
}