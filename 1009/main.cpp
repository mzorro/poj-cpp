#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int values[2000], begs[2000];
int cnt, sum, width;
int value_at(int pos) {
	int low = 0, high = cnt - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (begs[mid] < pos) {
			low = mid + 1;
		} else if (begs[mid] > pos) {
			high = mid - 1;
		} else {
			return values[mid];
		}
	}
	return values[high];
}

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
	return p1.first < p2.first;
}

vector<pair<int, int> > result;
int get_max_abs(int beg, int value) {
	int max_abs = 0, s, v;

	int row = beg / width;
	int beg1 = (row == 0) ? 0 : -width;
	int end1 = (row == sum/width - 1) ? 0 : width;

	int col = beg % width;
	int beg2 = (col == 0) ? 0 : -1;
	int end2 = (col == width - 1) ? 0 : 1;

	for (int d1 = beg1; d1 <= end1; d1 +=width) {
		for (int d2 = beg2; d2 <= end2; d2 += 1) {
			s = beg + d1 + d2;
			v = abs(value_at(s) - value);
			max_abs = max(max_abs, v);
		}
	}
	return max_abs;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	while (cin >> width && width > 0) {
		cnt = sum = 0;
		result.clear();
		int value, count = 1;
		while (count > 0) {
			cin >> value >> count;
			values[cnt] = value;
			begs[cnt++] = sum;
			sum += count;
		}

		//for (int i=0; i < sum; i++) {
		//	cout.width(2);
		//	cout << value_at(i) << ' ';
		//	if ((i+1) % width == 0) cout << endl;
		//}

		int s, v;
		for (int i = 0; i < cnt; i++) {
			for (int d1 = -width; d1 <= width; d1 +=width) {
				for (int d2 = -1; d2 <= 1; d2 += 1) {
					s = begs[i] + d1 + d2;
					if (s < 0 || s >= sum) continue;
					v = get_max_abs(s, value_at(s));
					result.push_back(pair<int, int>(s, v));
				}
			}
		}

		sort(result.begin(), result.end(), cmp);
		
		cout << width << '\n';
		vector<pair<int, int> >::iterator it = result.begin(), last = it++;
		while (it != result.end()) {
			if (it->second == last->second) {
				it = result.erase(it);
			} else {
				cout << last->second << ' ' << it->first - last->first << '\n';
				last = it++;
			}
		}
		cout << last->second << ' ' << sum - (--it)->first << '\n';
		cout << "0 0\n";
	}
	cout << '0' << endl;
}