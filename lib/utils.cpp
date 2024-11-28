#include "utils.h"
#include <iostream>
#include <limits>
#include <random>

using std::cin;
using std::cout;
using std::string;
using std::uniform_int_distribution;

namespace utils {
    static int read_number(const string &message) {
        int number = 0;
        cout << message;
        cin >> number;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Invalid number, try again: ";
            cin >> number;
        }
        return number;
    }

    static string read_string(const string &message) {
        string input;
        cout << message;
        getline(cin, input);

        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Invalid string, try again: ";
            getline(cin, input);
        }

        return input;
    }

    int gen_random_int(const int &min, const int &max) {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        uniform_int_distribution<int> distribution(min, max);

        return distribution(generator);
    }
} // namespace utils
