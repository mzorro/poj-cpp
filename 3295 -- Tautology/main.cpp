#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)

bool stk[1000];
unsigned int flag;
#define VALUEOF(c) ((flag >> (c - 'p')) & 1)
bool calculate(string s) {
	int top = -1;
	string::reverse_iterator rit = s.rbegin();
	bool tmp;
	for (; rit!=s.rend(); rit++) {
		switch(*rit) {
		case 'N':
			stk[top] = !stk[top];
			break;
		case 'K':
			tmp = stk[top--];
			stk[top] &= tmp;
			break;
		case 'A':
			tmp = stk[top--];
			stk[top] |= tmp;
			break;
		case 'C':
			tmp = stk[top--];
			stk[top] = !stk[top] | tmp;
			break;
		case 'E':
			tmp = stk[top--];
			stk[top] = stk[top] == tmp;
			break;
		default:
			stk[++top] = VALUEOF(*rit);
			break;
		}
	}
	return stk[top];
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	string src;
	while (cin >> src && src != "0") {
		flag = 0;
		while (!(flag >> 5)) {
			if(!calculate(src)) break;
			flag++;
		}
		if (flag >> 5) cout << "tautology" << endl;
		else cout << "not" << endl;
	}
}