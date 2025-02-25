#ifndef STR_HPP
#define STR_HPP

#include <string>

using std::string;

class Str {
private:
    std::string _str;

public:
    Str();
    Str(std::string str);
    Str(const char *str);

    Str &operator=(const string &str);

    operator std::string() const;

    friend std::ostream &operator<<(std::ostream &osys, const Str &str);
};

#endif // STR_HPP
