#ifndef UTILS_HPP
#define UTILS_HPP

#include <sstream>
#include <string>
#include <vector>

class Utils {
public:
    static std::vector<std::string> split(const std::string &str, const std::string &delim);
};

#endif //UTILS_HPP
