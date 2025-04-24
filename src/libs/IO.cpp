#include <iostream>
#include "IO.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

string IO::get_string(const string &message) {
    string input;
    cin >> input;
    return input;
}