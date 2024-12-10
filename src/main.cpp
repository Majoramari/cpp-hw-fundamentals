#include <cmath>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Person {
private:
    int id_;
    string first_name_, last_name_, email_, phone_number_;

public:
    Person(int identifier,
           string first_name,
           string last_name,
           string email,
           string phone_number) {
        id_ = identifier;
        first_name_ = first_name;
        last_name_ = last_name;
        email_ = email;
        phone_number_ = phone_number;
    }

    [[nodiscard]] int id() const { return id_; }

    [[nodiscard]] string first_name() const { return first_name_; }

    [[nodiscard]] string last_name() const { return last_name_; }

    [[nodiscard]] string full_name() const {
        return first_name_ + " " + last_name_;
    }

    [[nodiscard]] string email() const { return email_; }

    [[nodiscard]] string phone_number() const { return phone_number_; }

    void print() const {
        cout << "Info:" << endl;
        cout << "______________" << endl;
        cout << "ID:           " << id() << endl;
        cout << "First Name:   " << first_name() << endl;
        cout << "Last Name:    " << last_name() << endl;
        cout << "Full Name:    " << full_name() << endl;
        cout << "Email:        " << email() << endl;
        cout << "Phone Number: " << phone_number() << endl;
        cout << "______________" << endl;
    };

    void send_email(string subject, string message) const {
        cout << endl << "The message was sent to " << email() << endl;
        cout << "Subject: " << subject << endl;
        cout << "Message: " << message << endl;
    }

    void send_sms(string message) const {
        cout << endl
             << "Sending SMS to " << phone_number()
             << " with message: " << message << endl;
    }
};

int main() {

    Person person(10, "John", "Doe", "oY5Z0@example.com", "+1234567890");
    person.print();

    person.send_sms("Hello");
    person.send_email("Hi", "How are you?");

    return 0;
}
