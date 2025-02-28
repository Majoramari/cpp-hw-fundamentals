#include <numeric>
#include <string>
#include "str.hpp"

template<typename Container>
std::string Str::join_strings(const Container &container, const std::string &delim) {
    if (container.empty()) {
        return "";
    }
    return std::accumulate(
            std::next(container.begin()),
            container.end(),
            std::string(*container.begin()), // Ensure it's a string to avoid type mismatches
            [&delim](const std::string &first, const typename Container::value_type &second) {
                return first + delim + second;
            });
}
