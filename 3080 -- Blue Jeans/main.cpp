#include <iostream>
#include <vector>
#include <string>
using namespace std;
#pragma warning(disable:4996)
#define MAX_BYTE 0x7f
#define MAX_INT 0x7fffffff

int main() {
	// freopen("..\\test.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int M; cin >> M;
		vector<string> dna(M);
		while (M--) {
			cin >> dna[M];
		}
		string match;
		for (int len = 60; len > 2 && match.empty(); len--) {
			for (int i = 0; i < 61-len; i++) {
				string pat = dna[0].substr(i, len);
				vector<string>::iterator it = dna.begin();
				for (it++; it != dna.end(); it++) {
					if (it->find(pat) == string::npos) {
						break;
					}
				}
				if (it == dna.end()) {
					if (match.empty()) match = pat;
					else match = min(match, pat);
				}
			}
		}
		if (match.empty()) cout << "no significant commonalities" << endl;
		else cout << match << endl;
	}
}