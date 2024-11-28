#include <iostream>

namespace {
    int read_number(std::string message = "Please enter a number: ") {
        int number;
        std::cout << message;
        std::cin >> number;
        return number;
    }

    double calc_triangle_area(int base, int height) {
        return (0.5 * base) * height;
    }

    void print_result(double area) {
        std::cout << "The area of the triangle is: " << area << std::endl;
    }
} // namespace

int main() {
    int base = read_number("Please enter the triangle base: ");
    int height = read_number("Please enter the triangle height: ");

    double area = calc_triangle_area(base, height);

    print_result(area);

    return 0;
}
