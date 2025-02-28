#include "concepts"

using std::floating_point;
using std::integral;

namespace validator {
    template<typename T>
        requires integral<T> || floating_point<T>
    static bool is_num_in_range(T num, T min, T max) {
        return num >= min && num <= max;
    };
} // namespace validator
