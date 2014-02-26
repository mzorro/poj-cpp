#include <iostream>
#include <string>
#include <set>
using namespace std;
#pragma warning(disable:4996)

struct chess {
	enum type {K, Q, R, B, N, P} t;
	int row; char col; bool iswhite;
	chess(char c, int row, char col, bool iswhite)
		: row(row)
		, col(col)
		, iswhite(iswhite) {
		c = tolower(c);
		switch(c) {
		case 'k': t = K; break;
		case 'q': t = Q; break;
		case 'r': t = R; break;
		case 'b': t = B; break;
		case 'n': t = N; break;
		case 'p': t = P; break;
		}
	}

	bool operator<(chess const &r) const {
		if (t != r.t) return t < r.t;
		else if (row != r.row) {
			if (iswhite) return row < r.row;
			else return row > r.row;
		} else return col < r.col;
	}

	void output() const {
		switch (t) {
		case K: cout << 'K'; break;
		case Q: cout << 'Q'; break;
		case R: cout << 'R'; break;
		case B: cout << 'B'; break;
		case N: cout << 'N'; break;
		}
		cout << col << row;
	}
};

int main() {
	//freopen("..\\test.txt", "r", stdin);
	string dump;
	set<chess> white, black;
	for (int row = 8; row >= 1; row--) {
		getline(cin, dump);
		char c;
		for (int col = 'a'; col <= 'h'; cin.get(c), col++) {
			cin.get(c); cin.get(c); cin.get(c);
			if (!isalpha(c)) continue;
			bool w = false;
			if (isupper(c)) w = true;
			if (w) white.insert(chess(c, row, col, w));
			else black.insert(chess(c, row, col ,w));
		}
		getline(cin, dump);
	}
	cout << "White: ";
	set<chess>::iterator it;
	it = white.begin();
	it->output();
	for (it++ ; it != white.end(); it++) {
		cout << ',';
		it->output();
	}
	cout << endl << "Black: ";
	it = black.begin();
	it->output();
	for (it++; it != black.end(); it++) {
		cout << ',';
		it->output();
	}
	cout << endl;
}