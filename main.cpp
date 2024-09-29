#include <iostream>

#include "utils.h"

using namespace std;

struct Date {
	unsigned short year, month, day;
};

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

Date read_date() {
	const unsigned short day = read_day_number();
	const unsigned short month = read_month_number();
	const unsigned short year = utils::get_number("Please enter a year: ");
	return {year, month, day};
}

unsigned short get_month_days(const unsigned short &month, const unsigned short &year) {
	static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	return month == 2 && is_leap_year(year) ? 29 : days_in_month[month - 1];
}

unsigned short get_days_passed(const Date date) {
	unsigned short days_passed = 0;
	for (int i = 1; i <= date.month; i++) {
		if (date.month != i)
			days_passed += get_month_days(i, date.year);
		else
			days_passed += date.day;
	}
	return days_passed;
}

Date add_days(const unsigned short days_to_add, Date date) {
	unsigned short remaining_days = days_to_add + get_days_passed(date);
	date.month = 1;

	while (remaining_days > 0) {
		// ReSharper disable once CppTooWideScopeInitStatement
		const unsigned short month_days = get_month_days(date.month, date.year);

		if (remaining_days > month_days) {
			remaining_days -= month_days;
			date.month++;

			if (date.month > 12) {
				date.month = 1;
				date.year++;
			}
		} else {
			date.day = remaining_days;
			break;
		}
	}

	return date;
}

int main() {
	Date date = read_date();
	const unsigned short days_to_add = utils::get_number("How many days you want to add: ");

	date = add_days(days_to_add, date);
	cout << "Days after adding [" << days_to_add << "] days: "
			<< date.day << "/"
			<< date.month << "/"
			<< date.year << endl;

	return 0;
}
