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
    char get_grade_letter(const int grade) {
        if (grade >= 90 && grade <= 100) {
            return 'A';
        }
        if (grade >= 80 && grade <= 89) {
            return 'B';
        }
        if (grade >= 70 && grade <= 79) {
            return 'C';
        }
        if (grade >= 60 && grade <= 69) {
            return 'D';
        }
        if (grade >= 50 && grade <= 59) {
            return 'E';
        }
        return 'F';
    }

    void print_result(char grade) { cout << "You got: " << grade << endl; }
} // namespace

int main() {
    int number = utils::read_number();

    char grade = get_grade_letter(number);

    print_result(grade);

    return 0;
}
