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
    void print_numbers_up_to(int number) {
        for (int i = 1; i <= number; i++) {
            cout << i << endl;
        }
    }
} // namespace

int main() {
    int number = utils::read_number();

    print_numbers_up_to(number);

    return 0;
}
