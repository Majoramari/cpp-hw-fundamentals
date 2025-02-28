#include "utils.hpp"
#include <algorithm>
#include <sstream>

namespace utils {

    bool is_palindrome(const std::string &str) {
        return std::equal(str.begin(), str.end(), str.rbegin());
    }

    bool is_prime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i < num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    std::vector<std::string> split(const std::string &str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream token_stream(str);
        while (std::getline(token_stream, token, delimiter)) {
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }
        return tokens;
    }

    char gen_random_char(CharacterType type) {
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
                return special_chars[gen_random_number<std::size_t>(0, special_chars.size() - 1)];
            }
            default:
                return '?';
        }
    }

} // namespace utils
