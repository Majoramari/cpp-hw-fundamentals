#include "str.hpp"
#include <iostream>

using std::string;

Str::Str() { _str = ""; }
Str::Str(std::string str) { _str = str; }
Str::Str(const char *str) : _str(str) {}

Str &Str::operator=(const string &str) {
    _str = str;
    return *this;
}

// Getter using conversion operator
Str::operator string() const { return _str; }

// Overloaded stream insertion operator for Str
std::ostream &operator<<(std::ostream &osys, const Str &str) {
    osys << str._str;
    return osys;
}
