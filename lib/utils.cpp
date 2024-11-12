#include "utils.h"
#include <limits>
#include <random>
#include <iostream>

using namespace std;

namespace utils {
    int get_number(const string &message) {
        int number = 0;
        cout << message;
        cin >> number;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid number, try again: ";
            cin >> number;
        }
        return number;
    }

    string get_string(const string &message) {
        string input;
        cout << message;
        getline(cin, input);

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid string, try again: ";
            getline(cin, input);
        }

        return input;
    }

    int gen_random_int(const int &min, const int &max) {
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> distribution(min, max);

        return distribution(generator);
    }
}
