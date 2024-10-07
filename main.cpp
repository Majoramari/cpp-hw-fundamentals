#include <iostream>
#include <string>

#include "mdate.h"

using namespace std;
using namespace m_date;

int main() {
	cout << "Vacation starts" << endl;
	const Date start_date = read_date();

	cout << "Vacation ends" << endl;
	const Date end_date = read_date();

	cout << "Vacation from: " << get_week_short_name(start_date.day) << ", "
			<< start_date.day << "/"
			<< start_date.month << "/"
			<< start_date.year << endl;

	cout << "Vacation to: " << get_week_short_name(end_date.day) << ", "
			<< end_date.day << "/"
			<< end_date.month << "/"
			<< end_date.year << endl;

	const short days = count_business_days_in_range(start_date, end_date);
	cout << endl << "Actual vacation days is: " << days << endl;

	return 0;
}
