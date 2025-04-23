#include "Utils.hpp"

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
