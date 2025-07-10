#include "MainScreen.hpp"
#include <iostream>
#include <limits>
#include <string>
#include "Client.hpp"
#include "IO.hpp"
#include "Utils.hpp"

// NOTE: Private

using std::cin;
using std::cout;

unsigned short MainScreen::get_user_choice() {
    unsigned short choice = IO::get_short_in_range("\t\tChoose an option [1-8]: ", 1, 8);
    return choice;
}

void MainScreen::back_to_main() {
    cout << "\n\n\tPress Enter to go back to Main Menu... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

void MainScreen::show_client_list() {
    auto clients = Client::get_clients();
    screen_header("Client List Screen", "(" + std::to_string(clients.size()) + ") Client");
    Client::list();
}

void MainScreen::add_client() { cout << "Add Client"; }

void MainScreen::remove_client() { cout << "Remove Client"; }

void MainScreen::update_client() { cout << "Update client"; }

void MainScreen::find_client() { cout << "Find Client"; }

void MainScreen::transactions() { cout << "Transactions"; }

void MainScreen::manage_users() { cout << "Manage Users"; }

void MainScreen::logout() { cout << "Logout"; }

void MainScreen::perform_option(const MainMenuOptions &choice) {
    switch (choice) {
        case MainMenuOptions::SHOW_CLIENT_LIST:
            clear_screen();
            show_client_list();
            back_to_main();
            break;
        case MainMenuOptions::ADD_CLIENT:
            clear_screen();
            add_client();
            back_to_main();
            break;
        case MainMenuOptions::REMOVE_CLIENT:
            clear_screen();
            remove_client();
            back_to_main();
            break;
        case MainMenuOptions::UPDATE_CLIENT:
            clear_screen();
            update_client();
            back_to_main();
            break;
        case MainMenuOptions::FIND_CLIENT:
            clear_screen();
            find_client();
            back_to_main();
            break;
        case MainMenuOptions::TRANSACTIONS:
            clear_screen();
            transactions();
            back_to_main();
            break;
        case MainMenuOptions::MANAGE_USERS:
            clear_screen();
            manage_users();
            back_to_main();
            break;
        case MainMenuOptions::LOGOUT:
            clear_screen();
            logout();
            back_to_main();
            break;
    }
}

// NOTE: PUBLIC

void MainScreen::init() {
    while (true) {
        clear_screen();
        screen_header("Main Screen");

        Utils::print_row({{"\t[1] Show Client List", 51}});
        Utils::print_row({{"\t[2] Add New Client", 51}});
        Utils::print_row({{"\t[3] Remove Client", 51}});
        Utils::print_row({{"\t[4] Update Client Info", 51}});
        Utils::print_row({{"\t[5] Find Client", 51}});
        Utils::print_row({{"\t[6] Transactions", 51}});
        Utils::print_row({{"\t[7] Manage Users", 51}});
        Utils::print_row({{"\t[8] Logout", 51}});

        Utils::print_separator(60, false);

        perform_option(static_cast<MainMenuOptions>(get_user_choice()));
    }
}
