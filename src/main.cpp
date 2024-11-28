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
    double calc_circle_area(int radius) { return M_PI * pow(radius, 2); }

    void print_result(double area) {
        cout << "The area of the circle is " << area << endl;
    }
} // namespace

int main() {
    int radius = utils::read_number("Please enter the radius of the circle: ");

    double circle_area = calc_circle_area(radius);

    print_result(circle_area);

    return 0;
}
