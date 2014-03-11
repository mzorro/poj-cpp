#include <iostream>
using namespace std;
#pragma warning(disable:4996)
#define MAXN 280
#define PRINT(X) cout << #X << ':' << X << endl

float length[MAXN];
int binSearch(float value) {
	int low = 0, high = MAXN - 1;
	int mid;
	while (low < high) {
		mid = (high + low) / 2;
		if (length[mid] < value) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return low;
}
int main() {
	//freopen("..\\test.txt", "r", stdin);
	length[0] = 0.0f;
	for (int i = 1; i < MAXN; i++) {
		length[i] = length[i-1] + 1.0f/(i+1);
	}
	float tmp;
	cin >> tmp;
	while (tmp > 1e-4f) {
		cout << binSearch(tmp) << " card(s)" << endl;
		cin >> tmp;
	}
}