#include "str.hpp"
#include <algorithm>
#include <cctype>
#include <iterator>
#include <sstream>
#include <vector>

Str::Str(const char *str) : _data(str) {}

std::ostream &operator<<(std::ostream &osys, const Str &str) {
    osys << str._data;
    return osys;
}

std::string Str::get_value() { return _data; }
void Str::set_value(const char *str) { _data = str; }

short Str::words_count(const std::string &str) {
    std::istringstream iss(str);
    return static_cast<short>(distance(std::istream_iterator<std::string>(iss),
                                       std::istream_iterator<std::string>()));
}
short Str::words_count() { return words_count(_data); }

short Str::capitals_count(const std::string &str) {
    return static_cast<short>(count_if(str.begin(), str.end(), [](char chr) -> int {
        return isupper(static_cast<unsigned char>(chr));
    }));
}
short Str::capitals_count() { return capitals_count(_data); }

short Str::smalls_count(const std::string &str) {
    return static_cast<short>(count_if(str.begin(), str.end(), [](char chr) -> int {
        return islower(static_cast<unsigned char>(chr));
    }));
}
short Str::smalls_count() { return smalls_count(_data); }

short Str::letters_count(const std::string &str) {
    return static_cast<short>(count_if(str.begin(), str.end(), [](char chr) -> int {
        return isalpha(static_cast<unsigned char>(chr));
    }));
}
short Str::letters_count() { return letters_count(_data); }

short Str::count_specific_letter(const std::string &str, const char &target) {
    return static_cast<short>(count(str.begin(), str.end(), target));
}
short Str::count_specific_letter(const char &target) {
    return count_specific_letter(_data, target);
}

short Str::vowels_count(const std::string &str) {
    return static_cast<short>(count_if(str.begin(), str.end(), [](char chr) {
        char lower = static_cast<char>(std::tolower(chr));
        return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
    }));
}
short Str::vowels_count() { return vowels_count(_data); }

std::string Str::invert_caps(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char chr) {
        return isupper(chr) ? tolower(chr) : toupper(chr);
    });
    return str;
}
std::string Str::invert_caps() { return invert_caps(_data); }

char Str::invert_char(const char &chr) {
    return (std::isupper(chr) != 0) ? static_cast<char>(std::tolower(chr))
                                    : static_cast<char>(std::toupper(chr));
}

bool Str::is_vowel(const char &chr) {
    char lower = static_cast<char>(std::tolower(chr));
    return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
}

short Str::length(const std::string &str) {
    short count = 0;
    for (auto it = str.begin(); it != str.end(); ++it) {
        ++count;
    }
    return count;
}
short Str::length() { return length(_data); }

std::string Str::to_lower_string(std::string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char chr) { return tolower(chr); });
    return str;
}
std::string Str::to_lower_string() { return to_lower_string(_data); }

std::string Str::to_upper_string(std::string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char chr) { return toupper(chr); });
    return str;
}
std::string Str::to_upper_string() { return to_upper_string(_data); }

std::string Str::lower_word_intials(const std::string &str) {
    std::istringstream iss(str);
    std::vector<std::string> words;

    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter(words));

    for (auto &word: words) {
        word[0] = static_cast<char>(tolower(word[0]));
    }
    return join_strings(words, " ");
}
std::string Str::lower_word_intials() { return lower_word_intials(_data); }
