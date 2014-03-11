#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

struct Stone {
	int x, y;
	Stone *pnt;
} stones[200];

double dist(Stone *a, Stone *b) {
	return sqrt(double((a->x - b->x)*(a->x - b->x)) +
		double((a->y - b->y)*(a->y - b->y)));
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int N, T = 1;
	vector<Stone*> sa, sb;
	while (cin >> N && N) {
		sa.clear(); sb.clear();
		for (int i = 0; i < N; i++) {
			cin >> stones[i].x >> stones[i].y;
			stones[i].pnt = NULL;
			sb.push_back(stones + i);
		}
		sa.push_back(*sb.begin());
		sb.erase(sb.begin());
		while (!sb.empty()) {
			double mind = 1e6;
			vector<Stone*>::iterator ita, itb, mina, minb;
			for (ita = sa.begin(); ita != sa.end(); ita++) {
				for (itb = sb.begin(); itb != sb.end(); itb++) {
					if (mind > dist(*ita, *itb)) {
						mina = ita;
						minb = itb;
						mind = dist(*ita, *itb); 
					}
				}
			}
			(*minb)->pnt = *mina;
			if (*minb == stones + 1) break;
			sa.push_back(*minb);
			sb.erase(minb);
		}
		double maxd = 0;
		Stone *p = stones + 1;
		while (p->pnt) {
			if (maxd < dist(p, p->pnt)) {
				maxd = dist(p, p->pnt);
			}
			p = p->pnt;
		}
		cout << "Scenario #" << T++ << endl;
		cout.precision(3); cout << fixed;
		cout << "Frog Distance = " << maxd << endl << endl;
	}
}