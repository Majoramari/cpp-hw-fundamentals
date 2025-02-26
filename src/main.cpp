#include <iostream>
#include <string>
#include "utils.hpp"

using std::cout;
using std::endl;
using std::string;

using namespace utils;

int main() {
    cout << "Random number between 1 and 100: " << gen_random_number(1, 100) << endl;
    cout << "Random char: " << gen_random_char() << endl;
    cout << "Generate word: " << gen_word(10) << endl;
    cout << "Generate serial: " << gen_serial() << endl;

    // Swap
    int int_var1 = 5;
    int int_var2 = 10;
    cout << "Before swap: a = " << int_var1 << ", b = " << int_var2 << endl;
    utils::swap(int_var1, int_var2);
    cout << "After swap: a = " << int_var1 << ", b = " << int_var2 << endl;

    string str_var1 = "Hello";
    string str_var2 = "World";
    cout << "Before swap: a = " << str_var1 << ", b = " << str_var2 << endl;
    utils::swap(str_var1, str_var2);
    cout << "After swap: a = " << str_var1 << ", b = " << str_var2 << endl;

    // Shuffle Array
    array<int, 5> int_arr = {1, 2, 3, 4, 5};
    cout << "Before shuffle: ";
    for (const auto &elem: int_arr) {
        cout << elem << " ";
    }
    cout << endl;

    utils::shuffle_array(int_arr);

    cout << "After shuffle: ";
    for (const auto &elem: int_arr) {
        cout << elem << " ";
    }
    cout << endl;


    // Fill array
    array<int, 5> int_arr2{};
    cout << "Before fill: ";
    for (const auto &elem: int_arr2) {
        cout << elem << " ";
    }
    cout << endl;

    utils::fill_array(int_arr2, 10, 20);

    cout << "After fill: ";
    for (const auto &elem: int_arr2) {
        cout << elem << " ";
    }
    cout << endl;
}
