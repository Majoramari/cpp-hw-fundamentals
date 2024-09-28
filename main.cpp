#include <iostream>

#include "utils.h"

using namespace std;

bool is_leap_year(const int &year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
	const int year = utils::get_number("Please enter a year: ");

	cout << year << (is_leap_year(year) ? " is a Leap Year" : " is not a Leap Year");

	return 0;
}
