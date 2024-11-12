#pragma once
#include <string>

namespace utils {
    int get_number(const std::string &message = "Enter a number: ");
    std::string get_string(const std::string &message = "Enter a string: ");
    int gen_random_int(const int &min, const int &max);
}

