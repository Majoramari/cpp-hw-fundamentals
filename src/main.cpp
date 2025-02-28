#include <iostream>
#include "validator.hpp"

using std::cout;
using std::endl;

int main() {
    cout << "6 is in range 5-10: " << (validator::is_num_in_range(6, 5, 10) ? "Yes" : "No") << endl;
    cout << "3 is in range 5-10: " << (validator::is_num_in_range(3, 5, 10) ? "Yes" : "No") << endl;
}
