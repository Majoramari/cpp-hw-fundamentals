#include "Utils.hpp"
#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> Utils::split(const string &str, const string &delim) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type pos;

    while ((pos = str.find(delim, start)) != string::npos) {
        tokens.emplace_back(str.substr(start, pos - start));
        start = pos + delim.length();
    }

    tokens.emplace_back(str.substr(start));
    return tokens;
}

void Utils::print_separator(size_t width, bool new_line_before, bool new_line_after) {
    if (new_line_before) {
        cout << endl;
    }

    cout << string(width, '_');

    if (new_line_after) {
        cout << endl;
    }
}

void Utils::print_row(initializer_list<pair<string, int>> cols) {
    std::cout << "| ";
    for (const auto &[title, width]: cols) {
        std::cout << std::left << std::setw(width) << title << " | ";
    }
    std::cout << "\n";
}
