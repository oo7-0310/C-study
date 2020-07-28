#include <iostream>
#include <string.h>
using namespace std;


int main() {
	int a;
	int b;
	int month;
	int days = 0;
	int index;

	string day[7] = { "FRI","SAT","SUN","MON" ,"TUE","WED","THU" };

	cin >> a;
	cin >> b;
	for (int i = 0; i < a; i++) {
		if (i == 0) {
			days += 0;
		}
		if (i == 1) {
			days += 31;
		}
		if (i == 2) {
			days += 29;
		}
		if (i == 3) {
			days += 31;
		}
		if (i == 4) {
			days += 30;
		}
		if (i == 5) {
			days += 31;
		}
		if (i == 6) {
			days += 30;
		}
		if (i == 7) {
			days += 31;
		}if (i == 8) {
			days += 31;
		}if (i == 9) {
			days += 30;
		}if (i == 10) {
			days += 31;
		}if (i == 11) {
			days += 30;
		}
	}
	days += b;
	index = (days % 7)-1 ;
	cout << day[index] << endl;

}