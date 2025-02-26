#include "mj_str.hpp"
#include <algorithm>
#include <cctype>
#include <iterator>
#include <sstream>

using std::count;
using std::count_if;
using std::distance;
using std::isalpha;
using std::islower;
using std::istream_iterator;
using std::istringstream;
using std::isupper;
using std::string;
using std::transform;

MjStr::MjStr(const char *str) : _data(str) {}

std::ostream &operator<<(std::ostream &osys, const MjStr &str) {
    osys << str._data;
    return osys;
}

string MjStr::get_value() { return _data; }
void MjStr::set_value(const char *str) { _data = str; }

short MjStr::words_count(const std::string &str) {
    istringstream iss(str);
    return static_cast<short>(distance(istream_iterator<string>(iss), istream_iterator<string>()));
}
short MjStr::words_count() { return words_count(_data); }

short MjStr::capitals_count(const string &str) {
    return static_cast<short>(count_if(str.begin(), str.end(), [](char chr) -> int {
        return isupper(static_cast<unsigned char>(chr));
    }));
}
short MjStr::capitals_count() { return capitals_count(_data); }

short MjStr::smalls_count(const string &str) {
    return static_cast<short>(count_if(str.begin(), str.end(), [](char chr) -> int {
        return islower(static_cast<unsigned char>(chr));
    }));
}
short MjStr::smalls_count() { return smalls_count(_data); }

short MjStr::letters_count(const string &str) {
    return static_cast<short>(count_if(str.begin(), str.end(), [](char chr) -> int {
        return isalpha(static_cast<unsigned char>(chr));
    }));
}
short MjStr::letters_count() { return letters_count(_data); }

short MjStr::count_specific_letter(const string &str, const char &target) {
    return static_cast<short>(count(str.begin(), str.end(), target));
}
short MjStr::count_specific_letter(const char &target) {
    return count_specific_letter(_data, target);
}

short MjStr::vowels_count(const string &str) {
    return static_cast<short>(count_if(str.begin(), str.end(), [](char chr) {
        char lower = static_cast<char>(std::tolower(chr));
        return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
    }));
}
short MjStr::vowels_count() { return vowels_count(_data); }

string MjStr::invert_caps(string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char chr) {
        return isupper(chr) ? tolower(chr) : toupper(chr);
    });
    return str;
}
string MjStr::invert_caps() { return invert_caps(_data); }

char MjStr::invert_char(const char &chr) {
    return (isupper(chr) != 0) ? static_cast<char>(tolower(chr)) : static_cast<char>(toupper(chr));
}

bool MjStr::is_vowel(const char &chr) {
    char lower = static_cast<char>(std::tolower(chr));
    return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
}

short MjStr::length(const string &str) {
    short count = 0;
    for (auto it = str.begin(); it != str.end(); ++it) {
        ++count;
    }
    return count;
}
short MjStr::length() { return length(_data); }

string MjStr::to_lower_string(string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char chr) { return tolower(chr); });
    return str;
}
string MjStr::to_lower_string() { return to_lower_string(_data); }

string MjStr::to_upper_string(string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char chr) { return toupper(chr); });
    return str;
}
string MjStr::to_upper_string() { return to_upper_string(_data); }

string MjStr::lower_word_intials(const string &str) {
    istringstream iss(str);
    vector<string> words;

    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(words));

    for (auto &word: words) {
        word[0] = static_cast<char>(tolower(word[0]));
    }
    return join_strings(words, " ");
}
string MjStr::lower_word_intials() { return lower_word_intials(_data); }

// string MjStr::replace(const string &str, const char &target, const char &rep) {
//     // Split the input string into words.
//     vector<string> words = Split(str, " ");

//     // Process each word.
//     for (string &word: words) {
//         if (matchCase) {
//             // If matching is case-sensitive, compare directly.
//             if (word == wordToReplace) {
//                 word = replacement;
//             }
//         } else {
//             // If matching is case-insensitive, compare the lowercase versions.
//             if (LowerAllString(word) == LowerAllString(wordToReplace)) {
//                 word = replacement;
//             }
//         }
//     }

//     // Rejoin the words into a single string using a space as the delimiter.
//     return JoinString(words, " ");
// }
