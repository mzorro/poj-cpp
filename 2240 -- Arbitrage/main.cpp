#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
#pragma warning(disable:4996)


int N, M;
map<string, int> name2no;
struct Edge {
	int a, b;
	double r;
	Edge(string sa, string sb, double r)
		: a(name2no[sa])
		, b(name2no[sb])
		, r(r) {}
};
vector<Edge> edges;

void init() {
	name2no.clear();
	edges.clear();
}

bool bellman_ford(int s) {
	vector<double> dis(N, 0);
	dis[s] = 10.0;
	vector<Edge>::iterator it;
	for (int i = 1; i < N; i++) {
		bool flag = false;
		for (it = edges.begin(); it != edges.end(); it++) {
			if (dis[it->b] < dis[it->a] * it->r) {
				dis[it->b] = dis[it->a] * it->r;
				flag = true;
			}
		}
		if (!flag) break;
	}
	for (it = edges.begin(); it != edges.end(); it++) {
		if (dis[it->b] < dis[it->a] * it->r) return true;
	}
	return false;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int T = 1;
	while (cin >> N && N) {
		init();
		string s;
		for (int i = 0; i < N; i++) {
			cin >> s;
			name2no.insert(pair<string, int>(s, i));
		}
		cin >> M;
		string a, b;
		double r;
		while (M--) {
			cin >> a >> r >> b;
			edges.push_back(Edge(a, b, r));
		}
		cout << "Case " << T++ << ": ";
		bool flag = false;
		for (int i = 0; i < N; i++) {
			if (bellman_ford(i)) {
				flag = true;
				break;
			}
		}
		if (flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}