#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include <random>
#include "concepts"

using std::floating_point;
using std::integral;
using std::mt19937;
using std::random_device;


namespace validator {
    template<typename T>
        requires integral<T> || floating_point<T>
    static bool is_num_in_range(T num, T min, T max);
} // namespace validator

#include "validator.tpp"

#endif // VALIDATOR_HPP
