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
    double calc_circle_area(double side, double base) {
        return M_PI * (pow(base, 2) / 4)
               * ((2 * side - base) / (2 * side + base));
    }

    void print_result(double area) {
        cout << "The area of the circle is " << area << endl;
    }
} // namespace

int main() {
    int side = utils::read_number("Please enter the side of the tringle: ");
    int base = utils::read_number("Please enter the base of the tringle: ");

    double circle_area = calc_circle_area(side, base);

    print_result(circle_area);

    return 0;
}
