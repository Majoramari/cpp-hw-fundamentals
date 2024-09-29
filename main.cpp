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

Date read_date() {
	const unsigned short day = read_day_number();
	const unsigned short month = read_month_number();
	const unsigned short year = utils::get_number("Please enter a year: ");
	return {year, month, day};
}

bool is_equal(const Date &date1, const Date &date2) {
	return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}

int main() {
	const Date date1 = read_date();

	cout << endl;

	const Date date2 = read_date();

	cout << endl << date1.year << "/" << date1.month << "/" << date1.day
			<< " is " << (is_equal(date1, date2) ? "equal" : "NOT equal") << " "
			<< date2.year << "/" << date2.month << "/" << date2.day << endl;

	return 0;
}
