#pragma once
#include <iostream>

using namespace std;

namespace utils {
	inline int get_number() {
		int number;
		cout << "Enter a number: ";
		cin >> number;
		return number;
	}
}
