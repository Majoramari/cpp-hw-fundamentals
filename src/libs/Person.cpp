#include "Person.hpp"
#include <string>
#include <utility>

using std::move;
using std::string;

Person::Person(string first_name, std::string last_name, std::string email, std::string phone)
    : p_first_name(move(first_name)),
      p_last_name(move(last_name)),
      p_email(move(email)),
      p_phone(move(phone)) {}

// Getters implementations
string Person::get_first_name() const { return p_first_name; }
string Person::get_last_name() const { return p_last_name; }
string Person::get_email() const { return p_email; }
string Person::get_phone() const { return p_phone; }

// Setters implementations
void Person::set_first_name(const string &first_name) { p_first_name = first_name; }
void Person::set_last_name(const string &last_name) { p_last_name = last_name; }
void Person::set_email(const string &email) { p_email = email; }
void Person::set_phone(const string &phone) { p_phone = phone; }
