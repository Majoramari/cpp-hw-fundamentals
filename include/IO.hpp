#ifndef IO_HPP
#define IO_HPP

#include <string>

using std::string;

namespace IO {
    string get_string(const string &message);
    float get_float(const string &message);
} // namespace IO

#endif // IO_HPP
