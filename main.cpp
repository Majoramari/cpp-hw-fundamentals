#include <iostream>
#include <string>

#include "mdate.h"

using namespace std;
using namespace m_date;
using namespace utils;

int main() {
	cout << "Vacation starts" << endl;
	const Date date = read_date();

	const int vacation_days = get_number("Please enter vacation days: ");

	const Date return_date = calc_vacation_return_date(date, vacation_days);

	cout << endl << "Return date: " << return_date.day << "/" << return_date.month << "/" << return_date.year << endl;

	return 0;
}
