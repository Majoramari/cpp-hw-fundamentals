#include <iostream>
#include <string>

#include "mdate.h"

using namespace std;
using namespace m_date;

int main() {
	const Date date = get_system_date();

	cout << endl << "Today is " << get_week_short_name(calc_day_order(date)) << ", "
			<< date.day << " " << get_month_short_name(date.month) << " " << date.year << endl;

	cout << endl << "Is it end of week?" << endl;
	if (is_last_day(date))
		cout << "Yes. It is Saturday, it is the end of week." << endl;
	else
		cout << "No. It is not the end of week." << endl;

	cout << endl << "Is it Weekend?" << endl;
	if (is_weekend(date))
		cout << "Yes. It is Saturday or Sunday." << endl;
	else
		cout << "No. Today is " << get_week_short_name(calc_day_order(date)) << "." << endl;

	cout << endl << "Is it business day?" << endl;
	if (is_business_day(date))
		cout << "Yes. Today is " << get_week_short_name(calc_day_order(date)) << "." << endl;
	else
		cout << "No. It is " << get_week_short_name(calc_day_order(date)) << "." << endl;

	cout << endl << "How many days until end of week?" << endl;
	cout << get_days_until_weekend(date) << " days until end of week." << endl;

	cout << endl << "How many days until end of month?" << endl;
	cout << get_days_until_end_of_month(date) << " days until end of month." << endl;

	return 0;
}
