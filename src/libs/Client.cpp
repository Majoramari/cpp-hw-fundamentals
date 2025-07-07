#include "Client.hpp"

#include <IO.hpp>
#include <Utils.hpp>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
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
    : Person(std::move(first_name), std::move(last_name), std::move(email), std::move(phone)),
      _account_id(std::move(account_id)),
      _pin_code(std::move(pin_code)),
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
Client Client::line_to_object(const std::string &line) {
    auto fields = Utils::split(line, "#//#");

    if (fields.size() != 7) {
        throw std::invalid_argument("Malformed client record: expected 7 fields, got "
                                    + std::to_string(fields.size()) + ": '" + line + "'");
    }

    float balance = 0.0F;
    try {
        balance = std::stof(fields[6]);
    } catch (const std::exception &e) {
        throw std::runtime_error(std::string("Invalid balance value '") + fields[6]
                                 + "': " + e.what());
    }

    return Client{
            fields[0], // first_name
            fields[1], // last_name
            fields[2], // email
            fields[3], // phone
            fields[4], // account_id
            fields[5], // pin_code
            balance, // balance
            Mode::UPDATE // mode
    };
}


string Client::object_to_line(const Client &client) {
    return client.p_first_name + "#//#" + client.p_last_name + "#//#" + client.p_email + "#//#"
           + client.p_phone + "#//#" + client._account_id + "#//#" + client._pin_code + "#//#"
           + std::to_string(client._balance);
}

void Client::prompt_update_fields() {
    std::string first_name = IO::get_string("Enter first name: ");
    std::string last_name = IO::get_string("Enter last name: ");
    std::string email;
    while (true) {
        email = IO::get_string("Enter email: ");

        if (email.find('@') != std::string::npos && email.find('.') != std::string::npos) {
            break;
        }

        std::cout << "Invalid email; try again.\n";
    }
    std::string phone = IO::get_string("Enter phone: ");

    set_first_name(first_name);
    set_last_name(last_name);
    set_email(email);
    set_phone(phone);
}

vector<Client> Client::load_clients_from_file() {
    vector<Client> clients;

    ifstream file("clients.txt");
    if (!file) {
        throw std::runtime_error{"Could not open clients.txt"};
    }

    for (string line; getline(file, line);) {
        clients.emplace_back(line_to_object(line));
    }

    return clients;
}

void Client::save_clients_to_file(const vector<Client> &clients) {
    ofstream file("clients.txt", std::ios::trunc);
    if (!file) {
        throw std::runtime_error{"Could not open clients.txt"};
    }

    for (Client client: clients) {
        string line = object_to_line(client);
        file << line << '\n';
        if (file.fail()) {
            throw std::runtime_error{"Failed to write to clients.txt"};
        }
    }
}

// Public methods
Client Client::find(const string &account_id) {
    ifstream file("clients.txt");
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

bool Client::is_exist(const string &account_id) {
    ifstream file("clients.txt");
    if (!file.is_open()) {
        std::cerr << "Can't open clients file\n";
        return false;
    }

    string line;
    while (getline(file, line)) {
        try {
            const Client client = line_to_object(line);
            if (client.get_account_id() == account_id) {
                return true;
            }
        } catch (const std::exception &e) {
            std::cerr << "Skipping invalid client record: " << e.what() << "\nLine: " << line
                      << endl;
        }
    }
    return false;
}

Client::SaveResult Client::save() {
    if (_mode == Mode::EMPTY) {
        return Client::SaveResult::FAIL_EMPTY_OBJ;
    }

    if (_mode == Mode::UPDATE) {
        vector<Client> clients = load_clients_from_file();

        for (Client &client: clients) {
            if (client.get_account_id() == _account_id) {
                client = *this;
                break;
            }
        }

        save_clients_to_file(clients);
        return Client::SaveResult::SUCCEED;
    }

    return Client::SaveResult::FAIL_UNKNOWN;
}

void Client::update() {
    string account_id = IO::get_string("Enter your account number: ");

    while (!is_exist(account_id)) {
        cout << "Client " << account_id << " doesn't exist\n";
        account_id = IO::get_string("Enter your account number: ");
    };

    Client client = find(account_id);

    client.print_info();

    std::cout << "\n\nUpdate Client Info:\n"
              << "-------------------\n";

    client.prompt_update_fields();

    client.save();
}
