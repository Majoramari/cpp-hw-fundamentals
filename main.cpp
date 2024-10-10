#include <iostream>
#include <string>

#include "mdate.h"

using namespace std;
using namespace m_date;
using namespace utils;

int main() {
	cout << "Enter Date1:" << endl;
	const Date date1 = read_date();

	cout << "Enter Date2:" << endl;
	const Date date2 = read_date();

	if (is_date_after(date1, date2))
		cout << "Yes, Date1 is after Date2" << endl;
	else
		cout << "No, Date1 is not after Date2" << endl;

	return 0;
}
