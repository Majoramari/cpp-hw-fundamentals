#include "IO.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string IO::get_string(const string &message = "Please enter your input: ") {
    string input;
    cout << message << endl;
    cin >> input;
    return input;
}

float IO::get_float(const string &message = "Please enter your input: ") {
    float input;
    cout << message << endl;
    cin >> input;
    return input;
}

