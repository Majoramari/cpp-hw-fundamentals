#ifndef UTILS_HPP
#define UTILS_HPP

#include <initializer_list>
#include <string>
#include <vector>

using std::initializer_list;
using std::pair;
using std::string;
using std::vector;

class Utils {
public:
    static vector<string> split(const string &str, const string &delim);
    static void
    print_separator(size_t width, bool new_line_before = true, bool new_line_after = true);
    static void print_row( initializer_list<pair<string, int>> cols);
};

#endif // UTILS_HPP
