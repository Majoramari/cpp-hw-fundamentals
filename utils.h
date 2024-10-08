#pragma once
#include <iostream>
#include <limits>
#include <random>

using namespace std;

namespace utils {
	inline int get_number(const string &message = "Enter a number: ") {
		int number;
		cout << message;
		cin >> number;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid number, try again: ";

			cin >> number;
		}
		return number;
	}

	inline string get_string(const string &message = "Enter a string: ") {
		string input;
		cout << message;
		getline(cin, input);

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid string, try again: ";
			getline(cin, input);
		}

		return input;
	}

	inline int gen_random_int(const int &min, const int &max) {
		random_device rd;
		mt19937 generator(rd());

		uniform_int_distribution distribution(min, max);

		return distribution(generator);
	}
}
