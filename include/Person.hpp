#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

using std::string;

class Person {
public:
    Person(string first_name, string last_name, string email, string phone);

    // Getters
    [[nodiscard]] string get_first_name() const;
    [[nodiscard]] string get_last_name() const;
    [[nodiscard]] string get_email() const;
    [[nodiscard]] string get_phone() const;

    // Setters
    void set_first_name(const string &first_name);
    void set_last_name(const string &last_name);
    void set_email(const string &email);
    void set_phone(const string &phone);

protected:
    string p_first_name;
    string p_last_name;
    string p_email;
    string p_phone;
};

#endif // PERSON_HPP
