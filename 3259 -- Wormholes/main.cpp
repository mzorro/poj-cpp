#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
#define INFINITE 0x3FFFFFFF

struct Edge {
	int a, b, w;
	Edge(int a, int b, int w) : a(a), b(b), w(w) {}
};
int N, P, W;
vector<Edge> edges;

bool bellman_ford() {
	vector<int> d(N+1, INFINITE);
	d[1] = 0;
	vector<Edge>::iterator it;
	bool flag;
	for (int i = 1; i < N; i++) {
		flag = false;
		for (it = edges.begin(); it != edges.end(); it++) {
			if (d[it->b] > d[it->a] + it->w) {
				d[it->b] = d[it->a] + it->w;
				flag = true;
			}
		}
		if (!flag) break;
	}
	for (it = edges.begin(); it != edges.end(); it++) {
		if (d[it->b] > d[it->a] + it->w) return true;
	}
	return false;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int F, s, e, t;
	cin >> F;
	while (F--) {
		edges.clear();
		cin >> N >> P >> W;
		while (P--) {
			cin >> s >> e >> t;
			edges.push_back(Edge(s, e, t));
			edges.push_back(Edge(e, s, t));
		}
		while (W--) {
			cin >> s >> e >> t;
			edges.push_back(Edge(s, e, -t));
		}
		if (bellman_ford()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}