#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace utils {
    static int read_number(string message = "Please enter a number: ") {
        int number;
        cout << message;
        cin >> number;
        return number;
    }
} // namespace utils

namespace {
    int calc_factorial(int number) {
        int sum = 1;
        for (int i = 1; i <= number; i++) {
            sum *= i;
        }
        return sum;
    }

    void print_factorial_result(int number, int result) {
        cout << "Factorial of " << number << " is " << result << endl;
    }
} // namespace

int main() {
    int number = utils::read_number();

    int factorial = calc_factorial(number);

    print_factorial_result(number, factorial);

    return 0;
}
