#include <iostream>

#include "mdate.h"

using namespace std;
using namespace m_date;
using namespace utils;

int main() {
	const Date date = read_date();

	if (is_valid_date(date))
		cout << "Yes, Date is valid!" << endl;
	else
		cout << "No, Date is not valid!" << endl;

	return 0;
}
