#include <iostream>

#include "mdate.h"

using namespace std;
using namespace m_date;
using namespace utils;

int main() {
	cout << "Enter Date1:" << endl;
	const Date date1 = read_date();

	cout << "Enter Date2:" << endl;
	const Date date2 = read_date();

	cout << "Compare result:" << static_cast<int>(compare_dates(date1, date2)) << endl;

	return 0;
}
