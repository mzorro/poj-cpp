#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\test.txt", "r", stdin);
	char chess[9][9];
	memset(chess, 0, sizeof(chess));
	string ws, bs;
	getline(cin, ws);
	getline(cin, bs);
	int beg = 7, end = ws.find(',', beg);
	do {
		if (end - beg == 3) {
			chess[ws[beg+1]-'a'+1][ws[beg+2]-'0'] = ws[beg];
		} else {
			chess[ws[beg]-'a'+1][ws[beg+1]-'0'] = 'P';
		}
		beg = end + 1;
		end = ws.find(',', beg);
	} while (beg != string::npos + 1);
	beg = 7, end = bs.find(',', beg);
	do {
		if (end - beg == 3) {
			chess[bs[beg+1]-'a'+1][bs[beg+2]-'0'] = tolower(bs[beg]);
		} else {
			chess[bs[beg]-'a'+1][bs[beg+1]-'0'] = 'p';
		}
		beg = end + 1;
		end = bs.find(',', beg);
	} while (beg != string::npos + 1);
	for (int row = 8; row >= 1; row--) {
		cout << "+---+---+---+---+---+---+---+---+" << endl;
		cout << '|';
		for (int col = 1; col <= 8; col++) {
			char tag = (row + col) % 2 == 1 ? '.' : ':';
			cout << tag;
			if (chess[col][row] == 0) cout << tag;
			else cout << chess[col][row];
			cout << tag << '|';
		} cout << endl;
	} cout << "+---+---+---+---+---+---+---+---+" << endl;
}