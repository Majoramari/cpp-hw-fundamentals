#include "Screen.hpp"
#include <iostream>
#include "Utils.hpp"

using std::cout;

void Screen::screen_header(const string &title, const string &sub_title) {
    Utils::print_separator(60, false);
    Utils::print_row({{"\t\t\t" + title, 37}});
    if (sub_title != "") {
        Utils::print_row({{"\t\t\t" + sub_title, 37}});
    }
    Utils::print_separator(60, false);
}

void Screen::clear_screen() { cout << "\033[2J\033[1;1H" << std::flush; }
