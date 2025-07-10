#ifndef MAIN_SCREEN_HPP
#define MAIN_SCREEN_HPP

#include "Screen.hpp"

class MainScreen : Screen {
private:
    enum class MainMenuOptions {
        SHOW_CLIENT_LIST = 1,
        ADD_CLIENT,
        REMOVE_CLIENT,
        UPDATE_CLIENT,
        FIND_CLIENT,
        TRANSACTIONS,
        MANAGE_USERS,
        LOGOUT,
    };

    static unsigned short get_user_choice();
    static void back_to_main();
    static void show_client_list();
    static void add_client();
    static void remove_client();
    static void update_client();
    static void find_client();
    static void transactions();
    static void manage_users();
    static void logout();
    static void perform_option(const MainMenuOptions &choice);

public:
    static void init();
};

#endif // MAIN_SCREEN_HPP
