#ifndef STR_HPP
#define STR_HPP

#include <string>

class Str {
private:
    std::string _data;

public:
    Str(const char *str);

    friend std::ostream &operator<<(std::ostream &osys, const Str &str);

    std::string get_value();
    void set_value(const char *str);

    static short words_count(const std::string &str);
    short words_count();

    static short capitals_count(const std::string &str);
    short capitals_count();

    static short smalls_count(const std::string &str);
    short smalls_count();

    static short letters_count(const std::string &str);
    short letters_count();

    static short count_specific_letter(const std::string &str, const char &target);
    short count_specific_letter(const char &target);

    static short vowels_count(const std::string &str);
    short vowels_count();

    static char invert_char(const char &chr);

    static std::string invert_caps(std::string str);
    std::string invert_caps();

    static bool is_vowel(const char &chr);

    static short length(const std::string &str);
    short length();

    static std::string to_lower_string(std::string str);
    std::string to_lower_string();

    static std::string to_upper_string(std::string str);

    std::string to_upper_string();

    static std::string lower_word_intials(const std::string &str);
    std::string lower_word_intials();

    template<typename Container>
    static std::string join_strings(const Container &container, const std::string &delim = "");
};

#include "str.tpp"

#endif // STR_HPP
