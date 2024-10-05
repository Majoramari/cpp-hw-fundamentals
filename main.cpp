#include <iostream>

using namespace std;

int read_number() {
	int number;
	cout << "Enter a number: ";
	cin >> number;
	return number;
}

bool is_even(const int &number) {
	return number % 2 == 0;
}

void print_number_type(const int &number) {
	cout << "The number is: " << (is_even(number) ? "Even" : "Odd") << endl;
}

int main() {
	print_number_type(read_number());
	return 0;
}
