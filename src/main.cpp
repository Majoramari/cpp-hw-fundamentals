#include <iostream>

using std::cin;
using std::cout;
using std::endl;

static int read_positive_number() {
    int number = 0;
    do {
        cout << "Please enter a number: ";
        cin >> number;
    } while (number <= 0);
    return number;
}

static int reverse_number(int number) {
    int remainder = 0;
    int placeholder = 0;

    while (number > 0) {
        remainder = number % 10;
        number /= 10;
        placeholder = placeholder * 10 + remainder;
    }

    return placeholder;
}

static void print_digits(int number) {
    int remainder = 0;

    while (number > 0) {
        remainder = number % 10;
        number /= 10;
        cout << remainder << endl;
    }
}

int main() {
    int number = read_positive_number();
    int reversed_number = reverse_number(number);
    
    print_digits(reversed_number);

    return 0;
}
