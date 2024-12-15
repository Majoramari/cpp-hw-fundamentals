#include "iostream"

using std::cout;
using std::endl;

static void print_header() {
    cout << endl << "\t\t\tMultiaction Table From 1 to 10" << endl;
    cout << "\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10" << endl;
    cout << "__________________________________________________________________"
         << "_________________" << endl;
}

static std::string divider(int position) {
    return position < 10 ? "    |" : "   |";
}

static void print_multiplication_table() {
    for (int i = 1; i <= 10; i++) {

        cout << " " << i << divider(i) << "\t";

        for (int j = 1; j <= 10; j++) {
            cout << i * j << "\t";
        }

        cout << endl;
    }
}

int main() {
    print_header();
    print_multiplication_table();
    return 0;
}
