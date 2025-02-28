#include "concepts"

namespace validator {
    template<typename T>
        requires std::integral<T> || std::floating_point<T>
    static bool is_num_in_range(T num, T min, T max) {
        return num >= min && num <= max;
    };
} // namespace validator
