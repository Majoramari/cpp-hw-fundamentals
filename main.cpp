#include <iostream>
#include <string>

#include "mdate.h"

using namespace std;
using namespace m_date;

int main() {
	cout << "Starting period" << endl;
	const Date start_date = read_date();

	cout << "Ending period" << endl;
	const Date end_date = read_date();

	cout << "Period from: " << get_week_short_name(start_date.day) << ", "
			<< start_date.day << "/"
			<< start_date.month << "/"
			<< start_date.year << endl;

	cout << "Period to: " << get_week_short_name(end_date.day) << ", "
			<< end_date.day << "/"
			<< end_date.month << "/"
			<< end_date.year << endl;

	cout << endl << "Period length is: " << calc_diff_days(start_date, end_date);
	cout << endl << "Period length is (including first day): " << calc_diff_days(start_date, end_date, true);

	return 0;
}
