#ifndef MJ_STR_HPP
#define MJ_STR_HPP

#include <array>
#include <string>
#include <vector>

using std::array;
using std::string;
using std::vector;

class MjStr {
private:
    string _data;

public:
    MjStr(const char *str);

    friend std::ostream &operator<<(std::ostream &osys, const MjStr &str);

    string get_value();
    void set_value(const char *str);

    static short words_count(const string &str);
    short words_count();

    static short capitals_count(const string &str);
    short capitals_count();

    static short smalls_count(const string &str);
    short smalls_count();

    static short letters_count(const string &str);
    short letters_count();

    static short count_specific_letter(const string &str, const char &target);
    short count_specific_letter(const char &target);

    static short vowels_count(const string &str);
    short vowels_count();

    static char invert_char(const char &chr);

    static string invert_caps(string str);
    string invert_caps();

    static bool is_vowel(const char &chr);

    static short length(const string &str);
    short length();

    static string to_lower_string(string str);
    string to_lower_string();

    static string to_upper_string(string str);
    string to_upper_string();

    static string lower_word_intials(const string &str);
    string lower_word_intials();

    // static string replace(const string &str, const char &target, const char &rep);
    // string replace(const char &target, const char &rep);

    // Learn templates here https://youtu.be/I-hZkUa9mIs
    template<typename Container>
    static string join_strings(const Container &container, const string &delim = "") {
        if (container.empty()) {
            return "";
        }
        return accumulate(next(container.begin()),
                          container.end(),
                          *container.begin(),
                          [&delim](const string &first, const string &second) {
                              return first + delim + second;
                          });
    }
};

#endif // MJ_STR_HPP
