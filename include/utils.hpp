#ifndef UILS_HPP
#define UILS_HPP

#include <algorithm>
#include <array>
#include <concepts>
#include <random>
#include <string>

using std::array;
using std::floating_point;
using std::integral;
using std::mt19937;
using std::random_device;
using std::string;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

namespace utils {
    enum class CharacterType { LOWER, UPPER, MIX, DIGIT, SPECIAL, ALL };
    /*
        Using "concepts" from C++ 20
        Reference https://en.cppreference.com/w/cpp/concepts
    */
    template<typename T>
    // Reference https://en.cppreference.com/w/cpp/language/requires
        requires integral<T> || floating_point<T>
    static T gen_random_number(T min, T max) {
        static random_device rand_device;
        static mt19937 gen(rand_device());

        if constexpr (integral<T>) {
            return uniform_int_distribution<T>(min, max)(gen);
        } else {
            return uniform_real_distribution<T>(min, max)(gen);
        }
    }

    static char gen_random_char(CharacterType type = CharacterType::ALL) {
        if (type == CharacterType::ALL) {
            type = static_cast<CharacterType>(gen_random_number<int>(0, 3));
        }

        switch (type) {
            case CharacterType::LOWER:
                return gen_random_number<char>('a', 'z');
            case CharacterType::UPPER:
                return gen_random_number<char>('A', 'Z');
            case CharacterType::MIX: {
                bool is_upper = gen_random_number(0, 1) != 0;
                return gen_random_number<char>(is_upper ? 'A' : 'a', is_upper ? 'Z' : 'z');
            }
            case CharacterType::DIGIT:
                return gen_random_number<char>('0', '9');
            case CharacterType::SPECIAL: {
                constexpr std::string_view special_chars = "!@#$%^&*()_+-=[]{}|;:,.";
                return special_chars[gen_random_number<size_t>(0, special_chars.size() - 1)];
            }
            default:
                return '?';
        }
    }

    static string gen_word(integral auto length, CharacterType type = CharacterType::MIX) {
        string word;
        for (short i = 0; i < length; i++) {
            word += gen_random_char(type);
        }
        return word;
    }

    template<integral T = int>
    static string gen_serial(T sections = 4) {
        string serial;
        for (short i = 0; i <= sections; i++) {
            serial += gen_word(4, CharacterType::UPPER);
            if (i != sections) {
                serial += "-";
            }
        }
        return serial;
    }

    template<typename T>
    static void swap(T &var1, T &var2) {
        T temp = var1;
        var1 = var2;
        var2 = temp;
    }

    template<typename T, size_t N>
    void shuffle_array(array<T, N> &arr) {
        static std::random_device rand_device;
        static std::mt19937 gen(rand_device());

        std::shuffle(arr.begin(), arr.end(), gen);
    }

    template<typename T, size_t N>
        requires integral<T> || floating_point<T>
    void fill_array(array<T, N> &arr, T min = 0, T max = 100) {
        for (auto &elem: arr) {
            elem = gen_random_number<T>(min, max);
        }
    }
} // namespace utils

#endif // UILS_HPP
