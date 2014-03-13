#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
#define MAX_BYTE 0x7f
#define MAX_INT 0x7fffffff

#define MAXN 1000001
int data[MAXN];

void put(int v) {
	while (v < MAXN) {
		data[v]++;
		v += v&-v;
	}
}

int sum(int v) {
	int res = 0;
	while (v > 0) {
		res += data[v];
		v -= v&-v;
	}
	return res;
}

int binFind(int v) {
	int low = 0, high = MAXN;
	while (low < high) {
		int mid = (low + high) / 2;
		int tmp = sum(mid);
		if (tmp == v) high = mid;
		else if (tmp < v) low = mid + 1;
		else high = mid - 1;
	}
	return low;
}

int main() {
	// freopen("..\\test.txt", "r", stdin);
	int N; cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		put(tmp);
	}
	cout << binFind((N+1)/2) << endl;
}