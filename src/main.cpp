#include <cmath>
#include <iostream>

namespace {
    int read_number() {
        int number;
        std::cout << "Please enter a number: ";
        std::cin >> number;
        return number;
    }

    double calc_area(int rect_a, int rect_d) {
        return rect_a * std::sqrt(pow(rect_d, 2) - pow(rect_a, 2));
    }

    void print_result(double area) {
        std::cout << "The area of the rectangle is " << area << std::endl;
    }
} // namespace

int main() {
    int rect_a = read_number();
    int rect_d = read_number();

    double area = calc_area(rect_a, rect_d);

    print_result(area);

    return 0;
}
