#include <iostream>
#include "utils.h"

using namespace std;

string verbalize_number(const int &number) {
	if (number == 0)
		return "Zero";

	const string under_twenty[] = {
		"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
		"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
	};

	const string tens[] = {
		"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
	};

	string result;

	// Handle numbers below 20
	// Example: 15 -> Fifteen
	if (number < 20) {
		result = under_twenty[number];
	}

	// Handle numbers below 100
	// Example: 75 -> Seventy Five
	else if (number < 100) {
		result = tens[number / 10];
		if (number % 10 != 0)
			result += " " + verbalize_number(number % 10);
	}

	// Handle numbers below hundreds
	// Example: 375 -> Three Hundred Seventy Five
	else if (number < 1000) {
		result = under_twenty[number / 100] + " Hundred";
		if (number % 100 != 0)
			result += " " + verbalize_number(number % 100);
	}

	// Handle numbers below thousands
	// Example: 3750 -> Three Thousand Seven Hundred Fifty
	else if (number < 1000000) {
		const string thousands = verbalize_number(number / 1000);
		result = thousands + (number / 1000 == 1 ? " Thousand" : " Thousands");
		if (number % 1000 != 0)
			result += " " + verbalize_number(number % 1000);
	}

	// Handle numbers below millions
	// Example: 3750000 -> Three Million Seven Hundred Fifty Thousand
	else if (number < 1000000000) {
		const string millions = verbalize_number(number / 1000000);
		result = millions + (number / 1000000 == 1 ? " Million" : " Millions");
		if (number % 1000000 != 0)
			result += " " + verbalize_number(number % 1000000);
	}

	// Handle billions
	// Example: 3750000000 -> Three Billion Seven Hundred Fifty Million
	else {
		const string billions = verbalize_number(number / 1000000000);
		result = billions + (number / 1000000000 == 1 ? " Billion" : " Billions");
		if (number % 1000000000 != 0)
			result += " " + verbalize_number(number % 1000000000);
	}

	return result;
}

int main() {
	const int number = utils::get_number();
	cout << verbalize_number(number);
	return 0;
}
