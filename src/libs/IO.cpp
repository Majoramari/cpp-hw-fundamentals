#include "IO.hpp"
#include <iostream>
#include <limits>

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

short IO::get_short_in_range(const string &message, const short &min, const short &max) {
    short input;
    cout << message;
    while (true) {
        cin >> input;
        if (input >= min && input <= max) {
            break;
        }
        cout << "Please enter a number between " << min << " and " << max << ":\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return input;
}
