#include <iostream>
#include <string>
#include <map>
using namespace std;
#pragma warning(disable:4996)

map<string, int> haab_month_map;
void create_haab_month_map() {
	static const int haab_month_cnt = 19;
	string haab_months[] = {
		"pop", "no", "zip", "zotz", "tzec",
		"xul", "yoxkin", "mol", "chen",
		"yax", "zac", "ceh", "mac", "kankin",
		"muan", "pax", "koyab", "cumhu","uayet"
	};
	for (int i = 0; i < haab_month_cnt; i++) {
		haab_month_map[haab_months[i]] = i;
	}
}

string tzolkin_day_map[] = {
	"imix", "ik", "akbal", "kan",
	"chicchan", "cimi", "manik",
	"lamat", "muluk", "ok", "chuen",
	"eb", "ben", "ix", "mem", "cib",
	"caban", "eznab", "canac", "ahau",
};

int get_haab_date() {
	int day, month, year;
	string month_name;
	cin >> day;
	cin.get();
	cin >> month_name >> year;
	month = haab_month_map[month_name];
	return year * 365 + month * 20 + day;
}

int main() {
	//freopen("..\\test.txt", "r", stdin);
	create_haab_month_map();
	int N;
	cin >> N;
	cout << N << endl;
	while (N--) {
		int days = get_haab_date();
		int year, month, day;
		year = days / 260;
		month = days % 13 + 1;
		day = days % 20;
		cout << month << ' ';
		cout << tzolkin_day_map[day] << ' ';
		cout << year << endl;
	}
}