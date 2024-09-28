#include <iomanip>
#include <iostream>

#include "utils.h"

using namespace std;

bool is_leap_year(const unsigned short int &year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

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

unsigned short get_month_days(const unsigned short int &month, const unsigned short int &year) {
	static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	return month == 2 && is_leap_year(year) ? 29 : days_in_month[month - 1];
}

unsigned short calc_day_order(const unsigned short &day, const unsigned short &month, const unsigned short &year) {
	const unsigned short a = (14 - month) / 12;
	const unsigned short y = year - a;
	const unsigned short m = month + 12 * a - 2;

	return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

string get_shortmonth_name(const unsigned short &month) {
	string months_of_year[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

	return months_of_year[month];
}

void print_month_calendar(const unsigned short &month, const unsigned short &year) {
	const unsigned short number_of_days = get_month_days(month, year);
	const unsigned short first_day_of_month = calc_day_order(1, month, year);

	cout << endl << " ===============[" << get_shortmonth_name(month) << "]=============== " << endl;
	cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

	unsigned short i;
	for (i = 0; i < first_day_of_month; i++)
		cout << "     ";

	for (int j = 1; j <= number_of_days; j++) {
		cout << setw(5) << j;

		if (++i == 7) {
			i = 0;
			cout << endl;
		}
	}

	cout << endl << " =================================== " << endl;
}

void print_year_calendar(const unsigned short &year) {
	cout << " =================================== " << endl;
	cout << "\t\t\tCalendar - " << year << endl;
	cout <<  " =================================== " << endl;

	for (int i = 1; i <= 12; i++)
		print_month_calendar(i, year);
}

int main() {
	const unsigned short year = utils::get_number("Please enter a year: ");

	print_year_calendar(year);
	return 0;
}
