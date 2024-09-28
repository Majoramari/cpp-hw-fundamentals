#include <iostream>

#include "utils.h"

using namespace std;

unsigned short read_month_number() {
	unsigned short int month = 1;
	do {
		if (month < 1 || month > 12)
			cout << endl << "Invalid month number, try again: " << endl;;

		cout << "Please enter a month number: ";
		cin >> month;
	} while (month < 1 || month > 12);
	return month;
}

unsigned short read_day_number() {
	unsigned short int day = 1;
	do {
		if (day < 1 || day > 31)
			cout << endl << "Invalid day number, try again: " << endl;;

		cout << "Please enter a day number: ";
		cin >> day;
	} while (day < 1 || day > 31);
	return day;
}

unsigned short calc_day_order(const unsigned short &day, const unsigned short &month, const unsigned short &year) {
	const unsigned short a = (14 - month) / 12;
	const unsigned short y = year - a;
	const unsigned short m = month + 12 * a - 2;

	return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

string get_day_name(const unsigned short &day_index) {
	string days_of_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	return days_of_week[day_index];
}

int main() {
	const unsigned short year = utils::get_number("Please enter a year to check: ");
	const unsigned short month = read_month_number();
	const unsigned short day = read_day_number();


	cout << "Date: " << day << "/" << month << "/" << year << endl;
	cout << "Day order: " << calc_day_order(day, month, year) + 1 << endl;
	cout << "Day name: " << get_day_name(calc_day_order(day, month, year)) << endl;

	return 0;
}
