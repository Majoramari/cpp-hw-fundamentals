#pragma once
#include <iostream>
#include <limits>

using namespace std;

namespace utils {
	inline int get_number() {
		int number;
		cout << "Enter a number: ";
		cin >> number;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid number, try again: ";

			cin >> number;
		}

		return number;
	}
}
