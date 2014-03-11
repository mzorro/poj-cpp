#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)
#define MAXN 1000
int n, d;
struct Point {
	double x, y, xdist;

	bool input() {
		scanf("%lf%lf", &x, &y);
		if (y > d) return false;
		xdist = sqrt(d*d - y*y);
		return true;
	}

	bool operator<(const Point &p) const {
		return x < p.x;
	}
};

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int cnt = 0;
	while (scanf("%d%d", &n, &d)==2 && n && d) {
		printf("Case %d: ", ++cnt);
		Point islands[MAXN];
		bool possible = true;
		for (int i = 0; i < n; i++) {
			if(!islands[i].input()) possible = false;
		}
		if (!possible) { printf("-1\n"); continue; }
		sort(islands, islands + n);
		int radar = 0;
		double lastx;
		for (int i = 0; i < n; i++){
			Point &p = islands[i];
			if (radar == 0 || p.x - p.xdist > lastx) {
				lastx = p.x + p.xdist;
				radar++;
			} else if (p.x + p.xdist < lastx) {
				lastx = p.x + p.xdist;
			}
		}
		printf("%d\n", radar);
	}
}