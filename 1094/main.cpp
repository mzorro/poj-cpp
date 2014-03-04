#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
#define MAX_BYTE 0x7f
#define MAX_INT 0x7fffffff

int main() {
	//freopen("..\\test.txt", "r", stdin);
	int N, M;
	while (cin >> N >> M && N && M) {
		vector<set<int> > G(N);
		vector<int> ind(N, 0);
		string tmp;
		bool circled = false;
		bool determined = false;
		int m;
		for (m = 0; m < M; m++) {
			cin >> tmp;
			int a = tmp[0] - 'A', b = tmp[2]-'A';
			
			if (G[a].find(b) != G[a].end()) continue; // Already Exists
			
			G[a].insert(b);
			ind[b]++;

			// Try to determine a sorted sequence
			vector<int> tmp_ind(ind);
			vector<int> seq;
			bool uncertain = false;
			queue<int> q;
			for (int i = 0; i < N; i++) {
				if (tmp_ind[i] == 0) q.push(i);
			}
			while (!q.empty()) {
				if (q.size() > 1) uncertain = true;
				int next = q.front(); q.pop();
				seq.push_back(next);
				set<int>::iterator it;
				for (it = G[next].begin(); it != G[next].end(); it++) {
					if (--tmp_ind[*it] == 0) q.push(*it);
				}
			}
			if ((int)seq.size() < N) { // Found Inconsistant
				cout << "Inconsistency found after " << m+1 << " relations." << endl;
				break;
			} else if (!uncertain) {
				cout << "Sorted sequence determined after " << m+1 << " relations: ";
				vector<int>::iterator it;
				for (it = seq.begin(); it != seq.end(); it++) cout << char('A'+*it);
				cout << '.' << endl;
				break;
			}
		}
		if (m == M) {
			cout << "Sorted sequence cannot be determined." << endl;
		} else {
			while (++m < M) cin >> tmp;
		}
	}
}