#include <iostream>

#include "utils.h"

using namespace std;

bool is_leap_year(const unsigned short int &year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

unsigned short int read_month_number() {
	unsigned short int month;
	do {
		cout << "Please enter a month number: ";
		cin >> month;
	} while (month < 1 || month > 12);
	return month;
}

int get_month_days(const unsigned short int &year, const unsigned short int &month) {
	static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	return month == 2 && is_leap_year(year) ? 29 : days_in_month[month - 1];
}

int get_days_in_year(const unsigned short int &year) {
	return is_leap_year(year) ? 366 : 365;
}

int get_hours_in_year(const unsigned short int &year) {
	return get_days_in_year(year) * 24;
}

int get_minutes_in_year(const unsigned short int &year) {
	return get_hours_in_year(year) * 60;
}

int get_seconds_in_year(const unsigned short int &year) {
	return get_minutes_in_year(year) * 60;
}

// Unused in this problem
void print_year_duration(const unsigned short int &year) {
	cout << "Number of Days: " << get_days_in_year(year) << endl;
	cout << "Number of Hours: " << get_hours_in_year(year) << endl;
	cout << "Number of Minutes: " << get_minutes_in_year(year) << endl;
	cout << "Number of Seconds: " << get_seconds_in_year(year) << endl;
}

void print_month_duration(const unsigned short int &year, const unsigned short int &month) {
	cout << "Number of Days: " << get_month_days(year, month) << endl;
	cout << "Number of Hours: " << get_month_days(year, month) * 24 << endl;
	cout << "Number of Minutes: " << get_month_days(year, month) * 24 * 60 << endl;
	cout << "Number of Seconds: " << get_month_days(year, month) * 24 * 60 * 60 << endl;
}

int main() {
	const unsigned short int year = utils::get_number("Please enter a year to check: ");
	const unsigned short int month = read_month_number();

	print_month_duration(year, month);

	return 0;
}
