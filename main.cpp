#include <iostream>

#include "utils.h"

using namespace std;

int main() {
	const int number = utils::get_number();

	const string result = number == 0 ? "Zero" : number > 0 ? "Positive" : "Negative";

	cout << "The number is " << number << " is " << result << endl;
}
