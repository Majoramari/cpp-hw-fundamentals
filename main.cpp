#include <iomanip>
#include <iostream>

#include "utils.h"

using namespace std;

bool is_leap_year(const unsigned short &year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

unsigned short read_month_number() {
	unsigned short month = 1;
	do {
		if (month < 1 || month > 12)
			cout << endl << "Invalid month number, try again: " << endl;;

		cout << "Please enter a month number: ";
		cin >> month;
	} while (month < 1 || month > 12);
	return month;
}

unsigned short read_day_number() {
	unsigned short day = 1;
	do {
		if (day < 1 || day > 31)
			cout << endl << "Invalid day number, try again: ";

		cout << "Please enter a day number: ";
		cin >> day;
	} while (day < 1 || day > 31);
	return day;
}

unsigned short get_month_days(const unsigned short &month, const unsigned short &year) {
	static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	return month == 2 && is_leap_year(year) ? 29 : days_in_month[month - 1];
}

unsigned short get_days_passed(const unsigned short &day, const unsigned short &month, const unsigned short &year) {
	unsigned short days_passed = 0;
	for (int i = 1; i <= month; i++) {
		if (month != i)
			days_passed += get_month_days(i, year);
		else
			days_passed += day;
	}
	return days_passed;
}

int main() {
	const unsigned short year = utils::get_number("Please enter a year: ");
	const unsigned short month = read_month_number();
	const unsigned short day = read_day_number();

	cout << "Number of days passed since "
			<< month << "/" << day << "/" << year << ": "
			<< get_days_passed(day, month, year);

	return 0;
}
