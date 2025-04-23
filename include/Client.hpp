#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include "Person.hpp"

using std::string;

class Client : public Person {
public:
    enum class Mode { EMPTY, UPDATE };

    Client(string first_name,
           string last_name,
           string email,
           string phone,
           string account_id,
           string pin_code,
           float balance,
           Mode mode);

    // Getters
    [[nodiscard]] string get_account_id() const;
    [[nodiscard]] string get_pin_code() const;
    [[nodiscard]] float get_balance() const;

    // Setters
    void set_pin_code(const string &pin_code);
    void set_balance(float balance);

    // Methods
    [[nodiscard]] bool is_empty() const;
    void print_info() const;

    static Client find(string &account_id);

private:
    string _account_id;
    string _pin_code;
    float _balance;
    Mode _mode;
};


#endif // CLIENT_HPP