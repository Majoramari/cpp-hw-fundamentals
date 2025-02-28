#ifndef UTILS_HPP
#define UTILS_HPP

#include <array>
#include <concepts>
#include <string>
#include <vector>

namespace utils {

    enum class CharacterType { LOWER, UPPER, MIX, DIGIT, SPECIAL, ALL };

    // ? === Template Function Declarations ===

    template<typename T>
        requires std::integral<T> || std::floating_point<T>
    T gen_random_number(T min, T max);

    template<std::integral T = int>
    std::string gen_serial(T sections = 4);

    template<typename T>
    void swap(T &var1, T &var2);

    template<typename T, std::size_t N>
    void shuffle_array(std::array<T, N> &arr);

    template<typename T, std::size_t N>
        requires std::integral<T> || std::floating_point<T>
    void fill_array(std::array<T, N> &arr, T min = 0, T max = 100);

    template<typename T>
        requires std::integral<T>
    std::string gen_word(T length, CharacterType type = CharacterType::MIX);

    // ? === Non-Template Function Declarations ===

    bool is_palindrome(const std::string &str);
    bool is_prime(int num);
    std::vector<std::string> split(const std::string &str, char delimiter);
    char gen_random_char(CharacterType type = CharacterType::ALL);

} // namespace utils

// Include the template definitions.
#include "utils.tpp"

#endif // UTILS_HPP
