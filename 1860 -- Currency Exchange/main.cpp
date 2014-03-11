#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

struct Edge {
	int a, b;
	double r, c;
	Edge(int a, int b, double r, double c)
		: a(a), b(b), r(r), c(c) {}
};

int N, M, S;
double V;
vector<Edge> edges;

bool bellman_ford() {
	vector<double> d(N+1, 0.0);
	d[S] = V;
	vector<Edge>::iterator it;
	bool flag;
	for (int i = 1; i < N; i++) {
		flag = false;
		for (it = edges.begin(); it != edges.end(); it++) {
			if (d[it->b] < (d[it->a] - it->c) * it->r) {
				d[it->b] = (d[it->a] - it->c) * it->r;
				flag = true;
			}
		}
		if (!flag) break;
	}
	for (it = edges.begin(); it != edges.end(); it++) {
		if (d[it->b] < (d[it->a] - it->c) * it->r) return true;
	}
	return false;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	cin >> N >> M >> S >> V;
	int a, b;
	double r, c;
	while (M--) {
		cin >> a >> b >> r >> c;
		edges.push_back(Edge(a, b, r, c));
		cin >> r >> c;
		edges.push_back(Edge(b, a, r, c));
	}
	if (bellman_ford()) cout << "YES" << endl;
	else cout << "NO" << endl;
}