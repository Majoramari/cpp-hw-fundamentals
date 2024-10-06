#include <iostream>

using namespace std;

int get_number() {
	int number;
	cout << "Enter a number: ";
	cin >> number;
	return number;
}

float display_half(const int &number) {
	return static_cast<float>(number) / 2;
}

void print_number(const int &number) {
	cout << display_half(number) << endl;
}

int main() {
	print_number(get_number());
	return 0;
}
