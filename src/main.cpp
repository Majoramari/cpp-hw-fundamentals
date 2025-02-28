#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "str.hpp"

using std::cout;
using std::endl;

int main() {
    Str custom_str = "a string";
    std::vector<std::string> vec_strs = {"Hello", "This", "is", "a", "vector", "of", "strings."};
    std::array<std::string, 7> arr_strs = {"Hello", "This", "is", "a", "array", "of", "strings."};

    cout << "Custom string before change: " << custom_str << endl;

    custom_str = "A Custom String We Will Work On.";

    cout << "Custom string after change: " << custom_str << endl;

    cout << "Word count is: " << custom_str.words_count() << endl;
    cout << "Captials is: " << custom_str.capitals_count() << endl;
    cout << "Smalls is: " << custom_str.smalls_count() << endl;
    cout << "Letters is: " << custom_str.letters_count() << endl;
    cout << "O's count is: " << custom_str.count_specific_letter('o') << endl;
    cout << "Vowels count is: " << custom_str.vowels_count() << endl;
    cout << "Inverted string is: " << custom_str.invert_caps() << endl;
    cout << "Invert a character is: " << Str::invert_char('a') << endl;
    cout << "Invert A character is: " << Str::invert_char('A') << endl;
    cout << "Is A vowel: " << (Str::is_vowel('A') ? "Yes" : "No") << endl;
    cout << "Is B vowel: " << (Str::is_vowel('B') ? "Yes" : "No") << endl;
    cout << "Joined vec strs: " << Str::join_strings(vec_strs, " ") << endl;
    cout << "Joined arr strs: " << Str::join_strings(arr_strs, " ") << endl;
    cout << "Length of string: " << custom_str.length() << endl;
    cout << "Lower string: " << custom_str.to_lower_string() << endl;
    cout << "Upper string: " << custom_str.to_upper_string() << endl;
    cout << "Lower word intials: " << custom_str.lower_word_intials() << endl;
}
