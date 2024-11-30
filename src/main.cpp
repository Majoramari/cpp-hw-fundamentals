#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace utils {
    static int read_number(string message = "Please enter a number: ") {
        int number = 0;
        cout << message;
        cin >> number;
        return number;
    }
} // namespace utils

namespace {
    double calc_circle_area(int length) { return pow(length, 2) / (4 * M_PI); }

    void print_result(double area) {
        cout << "The area of the circle is " << area << endl;
    }
} // namespace

int main() {
    int length = utils::read_number("Please enter the length of the circle: ");

    double circle_area = calc_circle_area(length);

    print_result(circle_area);

    return 0;
}
