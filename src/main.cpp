#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

static int read_number(const string &message = "Please enter a number: ") {
    int number = 0;
    cout << message;
    cin >> number;
    return number;
}

static bool is_prime(int number) {
    if (number <= 1) return false;


    for (int i = 2; i <= (number / 2); i++) {
        if (number % i == 0) return false;
    }

    return true;
}

static void print_primes_1_to_n(int number) {
    for (int i = 1; i <= number; i++) {
        if (is_prime(i)) {
            cout << i << endl;
        }
    }
}

int main() {
    int number = read_number();
    print_primes_1_to_n(number);
    return 0;
}
