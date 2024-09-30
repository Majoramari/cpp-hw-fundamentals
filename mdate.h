#ifndef MDATE_H
#define MDATE_H
#include <iostream>

#include "utils.h"

using namespace std;

namespace m_date {
	struct Date {
		unsigned short year, month, day;
	};

	inline unsigned short read_month_number() {
		unsigned short month = 1;
		do {
			if (month < 1 || month > 12)
				cout << endl << "Invalid month number, try again: " << endl;;

			cout << "Please enter a month number: ";
			cin >> month;
		} while (month < 1 || month > 12);
		return month;
	}

	inline unsigned short read_day_number() {
		unsigned short day = 1;
		do {
			if (day < 1 || day > 31)
				cout << endl << "Invalid day number, try again: ";

			cout << "Please enter a day number: ";
			cin >> day;
		} while (day < 1 || day > 31);
		return day;
	}

	inline bool is_leap_year(const unsigned short year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	inline unsigned short get_month_days(const unsigned short month, const unsigned short year) {
		const unsigned short days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		if (is_leap_year(year) && month == 2)
			return 29;

		return days_in_month[month - 1];
	}

	inline Date read_date() {
		const unsigned short day = read_day_number();
		const unsigned short month = read_month_number();
		const unsigned short year = utils::get_number("Please enter a year: ");
		cout << endl;
		return {year, month, day};
	}

	inline bool is_date_before(const Date &date1, const Date &date2) {
		return date1.year < date2.year ||
		       (date1.year == date2.year && date1.month < date2.month) ||
		       (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day);
	}

	inline bool is_last_day(const Date &date) {
		return date.day == get_month_days(date.month, date.year);
	}

	inline bool is_last_month(const Date &date) {
		return date.month == 12;
	}

	inline Date increase_date_by_one_day(Date date) {
		if (is_last_day(date)) {
			date.day = 1;

			if (is_last_month(date)) {
				date.month = 1;
				date.year++;
			} else {
				date.month++;
			}
		} else {
			date.day++;
		}

		return date;
	}

	inline unsigned short calc_diff_days(Date date1, const Date date2, const bool include_1st = false) {
		unsigned short days = 0;

		while (is_date_before(date1, date2)) {
			days++;
			date1 = increase_date_by_one_day(date1);
		}

		return include_1st ? days + 1 : days;
	}
}

#endif
