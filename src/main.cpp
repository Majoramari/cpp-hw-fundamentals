#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

static int read_number(string message = "Please enter a number: ") {
    int number = 0;
    cout << message;
    cin >> number;
    return number;
}

static void print_letters(const int number) {
    for (int i = number; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << char(i + 64);
        }
        cout << endl;
    }
}

int main() {
    int line_count = read_number();

    cout << endl;
    print_letters(line_count);

    return 0;
}
