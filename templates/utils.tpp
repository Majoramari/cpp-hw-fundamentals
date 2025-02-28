#include <algorithm>
#include <concepts>
#include <random>
#include "utils.hpp"

namespace utils {

    template<typename T>
        requires std::integral<T> || std::floating_point<T>
    T gen_random_number(T min, T max) {
        static std::random_device rand_device;
        static std::mt19937 gen(rand_device());
        if constexpr (std::integral<T>) {
            return std::uniform_int_distribution<T>(min, max)(gen);
        } else {
            return std::uniform_real_distribution<T>(min, max)(gen);
        }
    }

    template<std::integral T>
    std::string gen_serial(T sections) {
        std::string serial;
        for (T i = 0; i <= sections; i++) {
            serial += gen_word(4, CharacterType::UPPER);
            if (i != sections) {
                serial += "-";
            }
        }
        return serial;
    }

    template<typename T>
    void swap(T &var1, T &var2) {
        T temp = var1;
        var1 = var2;
        var2 = temp;
    }

    template<typename T, std::size_t N>
    void shuffle_array(std::array<T, N> &arr) {
        static std::random_device rand_device;
        static std::mt19937 gen(rand_device());
        std::shuffle(arr.begin(), arr.end(), gen);
    }

    template<typename T, std::size_t N>
        requires std::integral<T> || std::floating_point<T>
    void fill_array(std::array<T, N> &arr, T min, T max) {
        for (auto &elem: arr) {
            elem = gen_random_number<T>(min, max);
        }
    }

    template<typename T>
        requires std::integral<T>
    std::string gen_word(T length, CharacterType type) {
        std::string word;
        for (T i = 0; i < length; ++i) {
            word += gen_random_char(type);
        }
        return word;
    }

} // namespace utils
