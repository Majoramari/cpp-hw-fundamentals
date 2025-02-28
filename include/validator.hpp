#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include "concepts"

namespace validator {
    template<typename T>
        requires std::integral<T> || std::floating_point<T>
    static bool is_num_in_range(T num, T min, T max);
} // namespace validator

#include "validator.tpp"

#endif // VALIDATOR_HPP
