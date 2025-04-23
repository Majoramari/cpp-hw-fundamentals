#include "Client.hpp"

#include <Utils.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::move;
using std::string;
using std::vector;

Client::Client(string first_name,
               string last_name,
               string email,
               string phone,
               string account_id,
               string pin_code,
               const float balance,
               const Mode mode)
    : Person(move(first_name), move(last_name), move(email), move(phone)),
      _account_id(move(account_id)),
      _pin_code(move(pin_code)),
      _balance(balance),
      _mode(mode) {}

// Getter
string Client::get_account_id() const { return _account_id; }
string Client::get_pin_code() const { return _pin_code; }
float Client::get_balance() const { return _balance; }

// Setter
void Client::set_pin_code(const string &pin_code) { _pin_code = pin_code; }
void Client::set_balance(const float balance) { _balance = balance; }

bool Client::is_empty() const { return _mode == Mode::EMPTY; }

void Client::print_info() const {
    cout << "\nClient Information:\n";
    cout << "-------------------\n";
    cout << "First Name: " << p_first_name << endl;
    cout << "Last Name: " << p_last_name << endl;
    cout << "Email: " << p_email << endl;
    cout << "Phone: " << p_phone << endl;
    cout << "Account ID: " << _account_id << endl;
    cout << "PIN Code: " << _pin_code << endl;
    cout << "Balance: " << _balance << endl;
    cout << "-------------------\n";
}

// Private Methods
Client Client::line_to_object(const string &line) {
    vector<string> tokens = Utils::split(line, "#//#");

    if (tokens.size() != 7) {
        throw std::invalid_argument("Invalid client record format");
    }

    try {
        const float balance = stof(tokens[6]);
        return {tokens[0],
                tokens[1],
                tokens[2],
                tokens[3],
                tokens[4],
                tokens[5],
                balance,
                Mode::UPDATE};
    } catch (const std::exception &e) {
        throw std::runtime_error(string("Conversion error: ") + e.what());
    }
}

string Client::object_to_line(const Client &client) {
    return client.p_first_name + "#//#" + client.p_last_name + "#//#" + client.p_email + "#//#"
           + client.p_phone + "#//#" + client._account_id + "#//#" + client._pin_code + "#//#"
           + std::to_string(client._balance);
}

// Public methods
Client Client::find(const string &account_id) {
    std::ifstream file("clients.txt");
    if (!file.is_open()) {
        std::cerr << "No client found, create a new client...\n";
        return {"", "", "", "", "", "", 0.0F, Mode::EMPTY};
    }

    vector<Client> clients;
    string line;

    while (getline(file, line)) {
        try {
            clients.push_back(line_to_object(line));
        } catch (const std::exception &e) {
            std::cerr << "Skipping invalid client record: " << e.what() << "\nLine: " << line
                      << endl;
        }
    }

    for (const auto &client: clients) {
        if (client.get_account_id() == account_id) {
            return client;
        }
    }

    return {"", "", "", "", "", "", 0.0F, Mode::EMPTY};
}
