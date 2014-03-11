#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)

struct Tree {
	char value;
	Tree *left, *right;
	Tree(string preord, string inord) {
		value = *preord.begin();
		int pos = inord.find(value);
		string left_inord = inord.substr(0, pos);
		if (left_inord.empty()) left = 0;
		else left = new Tree(preord.substr(1, left_inord.size()), left_inord);
		
		string right_inord = inord.substr(pos+1);
		if (right_inord.empty()) right = 0;
		else right = new Tree(preord.substr(pos+1, right_inord.size()), right_inord);
	}

	void postOrdTraversal() {
		if (left) left->postOrdTraversal();
		if (right) right->postOrdTraversal();
		cout << value;
	}
};

int main() {
	//freopen("..\\test.txt", "r", stdin);
	string preord, inord;
	while (cin >> preord >> inord) {
		Tree* tree = new Tree(preord, inord);
		tree->postOrdTraversal();
		cout << endl;
	}
}