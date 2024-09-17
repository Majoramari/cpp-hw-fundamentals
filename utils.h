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

	inline int gen_random_int(const int &min, const int &max) {
		random_device rd;
		mt19937 generator(rd());

		uniform_int_distribution distribution(min, max);

		return distribution(generator);
	}

	inline bool is_prime(const int input) {
		if (input < 2) return false;
		if (input == 2 || input == 3) return true;
		if (input % 2 == 0 || input % 3 == 0) return false;

		const int limit = static_cast<int>(sqrt(input));

		for (int i = 5; i <= limit; i += 6)
			if (input % i == 0 || input % (i + 2) == 0) return false;

		return true;
	}
}
