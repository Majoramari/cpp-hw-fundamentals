#ifndef MDATE_H
#define MDATE_H
#include <iostream>

#include "utils.h"

using namespace std;

namespace m_date {
	struct Date {
		short year, month, day;
	};

	inline short read_month_number() {
		short month = 1;
		do {
			if (month < 1 || month > 12)
				cout << endl << "Invalid month number, try again: " << endl;;

			cout << "Please enter a month number: ";
			cin >> month;
		} while (month < 1 || month > 12);
		return month;
	}

	inline short read_day_number() {
		short day = 1;
		do {
			if (day < 1 || day > 31)
				cout << endl << "Invalid day number, try again: ";

			cout << "Please enter a day number: ";
			cin >> day;
		} while (day < 1 || day > 31);
		return day;
	}

	inline bool is_leap_year(const short year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	inline short get_month_days(const short month, const short year) {
		const short days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		if (is_leap_year(year) && month == 2)
			return 29;

		return days_in_month[month - 1];
	}

	inline Date read_date() {
		const short day = read_day_number();
		const short month = read_month_number();
		const short year = static_cast<short>(utils::get_number("Please enter a year: "));
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

	inline void swap_dates(Date &date1, Date &date2) {
		const Date temp = date1;
		date1 = date2;
		date2 = temp;
	}

	inline short calc_diff_days(Date date1, Date date2, const bool include_1st = false) {
		int days = 0;
		short swap_flag = 1;

		if (!is_date_before(date1, date2)) {
			swap_dates(date1, date2);
			swap_flag = -1;
		}

		while (is_date_before(date1, date2)) {
			days++;
			date1 = increase_date_by_one_day(date1);
		}

		days = include_1st ? days + 1 : days;

		return static_cast<short>(days * swap_flag);
	}
}

#endif
