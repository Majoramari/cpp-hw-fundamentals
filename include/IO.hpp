#ifndef IO_HPP
#define IO_HPP

#include <string>

using std::string;

class IO {
public:
    static string get_string(const string &message);
    static float get_float(const string &message);
    static short get_short_in_range(const string &message, const short &min, const short &max);
};

#endif // IO_HPP
