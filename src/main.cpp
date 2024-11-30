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
    double calc_circle_area(double side_a, double side_b, double side_c) {
        double semi_perimeter = (side_a + side_b + side_c) / 2.0;

        // Calculate the numerator: a * b * c
        double numerator = side_a * side_b * side_c;

        // Calculate the denominator: 4 * sqrt(p * (p - a) * (p - b) * (p - c))
        double denominator =
                4.0
                * sqrt(semi_perimeter * (semi_perimeter - side_a)
                       * (semi_perimeter - side_b) * (semi_perimeter - side_c));

        return M_PI * pow(numerator / denominator, 2);
    }

    void print_result(double area) {
        cout << "The area of the circle is " << area << endl;
    }
} // namespace

int main() {
    int side_a = utils::read_number("Please enter the side a of the tringle: ");
    int side_b = utils::read_number("Please enter the side b of the tringle: ");
    int side_c = utils::read_number("Please enter the side c of the tringle: ");

    double circle_area = calc_circle_area(side_a, side_b, side_c);

    print_result(circle_area);

    return 0;
}
