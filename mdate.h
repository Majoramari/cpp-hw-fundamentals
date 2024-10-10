#ifndef MDATE_H
#define MDATE_H
#include <iostream>
#include <chrono>

#include "utils.h"

using namespace std;

namespace m_date {
	struct Date {
		short year, month, day;
	};

	inline Date get_system_date() {
		const auto now = chrono::system_clock::now();
		const std::time_t t = chrono::system_clock::to_time_t(now);
		// ReSharper disable once CppUseStructuredBinding
		const std::tm local_tm = *localtime(&t);

		return Date{
			static_cast<short>(local_tm.tm_year + 1900),
			static_cast<short>(local_tm.tm_mon + 1),
			static_cast<short>(local_tm.tm_mday)
		};
	}

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

	inline short calc_day_order(const Date &date) {
		const int a = (14 - date.month) / 12;
		const int y = date.year - a;
		const int m = date.month + 12 * a - 2;

		return static_cast<short>((date.day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7);
	}

	inline string get_week_short_name(const short day) {
		switch (day) {
			case 0:
				return "Sun";
			case 1:
				return "Mon";
			case 2:
				return "Tue";
			case 3:
				return "Wed";
			case 4:
				return "Thu";
			case 5:
				return "Fri";
			case 6:
				return "Sat";
			default:
				return "Invalid day";
		}
	}

	inline string get_month_short_name(const short month) {
		switch (month) {
			case 1:
				return "Jan";
			case 2:
				return "Feb";
			case 3:
				return "Mar";
			case 4:
				return "Apr";
			case 5:
				return "May";
			case 6:
				return "Jun";
			case 7:
				return "Jul";
			case 8:
				return "Aug";
			case 9:
				return "Sep";
			case 10:
				return "Oct";
			case 11:
				return "Nov";
			case 12:
				return "Dec";
			default:
				return "Invalid month";
		}
	}

	inline bool is_end_of_week(const Date &date) {
		return calc_day_order(date) == 6;
	}

	inline bool is_weekend(const Date &date) {
		return calc_day_order(date) == 5 || calc_day_order(date) == 6;
	}

	inline bool is_business_day(const Date &date) {
		return !is_weekend(date);
	}

	inline short get_days_until_weekend(const Date &date) {
		return static_cast<short>(6 - calc_day_order(date));
	}

	inline short get_days_until_end_of_month(const Date &date) {
		return static_cast<short>(get_month_days(date.month, date.year) - date.day);
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

	inline bool is_date_after(const Date &date1, const Date &date2) {
		return date1.year > date2.year ||
		       (date1.year == date2.year && date1.month > date2.month) ||
		       (date1.year == date2.year && date1.month == date2.month && date1.day > date2.day);
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

	inline Date calc_vacation_return_date(Date date, const short &days) {
		short days_remaining = days;

		while (is_weekend(date)) {
			date = increase_date_by_one_day(date);
		}

		while (days_remaining > 0) {
			if (!is_weekend(date)) {
				days_remaining--;
			}
			date = increase_date_by_one_day(date);
		}

		while (is_weekend(date)) {
			date = increase_date_by_one_day(date);
		}

		return date;
	}

	inline void swap_dates(Date &date1, Date &date2) {
		const Date temp = date1;
		date1 = date2;
		date2 = temp;
	}

	inline short count_business_days_in_range(Date start_date, const Date end_date) {
		short weekend_count = 0;

		while (is_date_before(start_date, end_date)) {
			if (!is_weekend(start_date))
				weekend_count++;
			start_date = increase_date_by_one_day(start_date);
		}

		return weekend_count;
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
