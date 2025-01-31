#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;
using std::setw;
using std::string;

namespace types {
    using u8 = unsigned char;
}

void print_header() {
    cout << "\t\t\tMultiplication Table From 1 To 10" << endl;
    cout << "\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10" << endl;
    cout << "__________________________________________________________________"
            "________________";
    cout << endl;
}

string separator(types::u8 i) { return i < 10 ? "  |" : " |"; }

void print_multiplication_table() {
    for (types::u8 row = 1; row <= 10; ++row) {
        cout << " " << static_cast<int>(row) << separator(row) << "\t";

        for (types::u8 col = 1; col <= 10; ++col) {
            cout << row * col << setw(4) << "\t";
        }

        cout << endl;
    }
}

int main() {
    print_header();
    print_multiplication_table();
    return 0;
}
