#include <chrono>
#include <iostream>

#include "mdate.h"

using namespace std;
using namespace m_date;

Date get_system_date() {
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

int main() {
	const Date date1 = read_date();
	const Date date2 = read_date();

	cout << "Difference in days: " << calc_diff_days(date1, date2, true) << endl;

	return 0;
}
