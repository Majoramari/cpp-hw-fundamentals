#include <iostream>

#include "utils.h"

using namespace std;

struct Date {
	unsigned short year, month, day;
};

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

bool is_leap_year(const unsigned short year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

unsigned short get_month_days(const unsigned short month, const unsigned short year) {
	const unsigned short days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (is_leap_year(year) && month == 2)
		return 29;

	return days_in_month[month - 1];
}

Date read_date() {
	const unsigned short day = read_day_number();
	const unsigned short month = read_month_number();
	const unsigned short year = utils::get_number("Please enter a year: ");
	return {year, month, day};
}

bool is_last_day(const Date &date) {
	return date.day == get_month_days(date.month, date.year);
}

bool is_last_month(const Date &date) {
	return date.month == 12;
}

Date increase_date_by_one_day(Date date) {
	if (is_last_day(date) && is_last_month(date))
		++date.year;

	if (is_last_day(date))
		date.day = 1;
	else
		++date.day;

	if (is_last_month(date))
		date.month = 1;
	else
		++date.month;

	return date;
}

int main() {
	const Date date = read_date();

	cout << endl;

	const auto [year, month, day] = increase_date_by_one_day(date);
	cout << "Date after one day: " << day << "/" << month << "/" << year << endl;

	return 0;
}
