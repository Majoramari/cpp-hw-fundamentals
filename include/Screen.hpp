#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <string>

using std::string;

class Screen {
protected:
    static void screen_header(const string &title, const string &sub_title = "");
    static void clear_screen();
};

#endif // SCREEN_HPP
