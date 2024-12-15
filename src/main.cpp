#include <iostream>

using namespace std;

class Person {
private:
    int id_;
    string first_name_;
    string last_name_;
    string email_;
    string phone_number_;

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

    string first_name() { return first_name_; }

    void set_first_name(string value) { first_name_ = value; }

    string last_name() { return last_name_; }

    void set_last_name(string value) { last_name_ = value; }

    string email() { return email_; }

    void set_email(string value) { email_ = value; }

    string phone_number() { return phone_number_; }

    void set_phone_number(string value) { phone_number_ = value; }

    string full_name() { return first_name_ + " " + last_name_; }

    void print() {
        cout << "Info:" << endl;
        cout << "___________________" << endl;
        cout << "ID           : " << id() << endl;
        cout << "FirstName    : " << first_name() << endl;
        cout << "LastName     : " << last_name() << endl;
        cout << "Full Name    : " << full_name() << endl;
        cout << "Email        : " << email() << endl;
        cout << "Phone Number : " << phone_number() << endl;
        cout << endl << "___________________" << endl;
    }

    void send_email(string subject, string body) {
        cout << "\nThe following message sent successfully to email: "
             << email_;
        cout << "\nSubject: " << subject;
        cout << "\nBody: " << body << endl;
    }

    void send_sms(string text_message) {
        cout << "\nThe following SMS sent successfully to phone: "
             << phone_number_;
        cout << "\n" << text_message << endl;
    }
};

class Employee : public Person {
public:
    enum class Department { IT, FINANCE, MARKETING, HR, CEO };

private:
    string title_;
    Department department_;
    float salary_;

public:
    Employee(int identifier,
             string first_name,
             string last_name,
             string email,
             string phone_number,
             string title,
             Department department,
             float salary) :
        Person(identifier, first_name, last_name, email, phone_number) {
        title_ = title;
        department_ = department;
        salary_ = salary;
    }

    string title() { return title_; }

    void set_title(string value) { title_ = value; }

    string department() {
        switch (department_) {
            case Department::IT:
                return "IT";
            case Department::FINANCE:
                return "Finance";
            case Department::MARKETING:
                return "Marketing";
            case Department::HR:
                return "Hr";
            case Department::CEO:
                return "Ceo";
        }
    }

    void set_department(Department value) { department_ = value; }

    void set_salary(float salary) { salary_ = salary; }

    [[nodiscard]] float salary() const { return salary_; }

    void print() {
        cout << "Info:" << endl;
        cout << "___________________" << endl;
        cout << "ID           : " << id() << endl;
        cout << "FirstName    : " << first_name() << endl;
        cout << "LastName     : " << last_name() << endl;
        cout << "Full Name    : " << full_name() << endl;
        cout << "Email        : " << email() << endl;
        cout << "Phone Number : " << phone_number() << endl;
        cout << "Title        : " << title() << endl;
        cout << "Department   : " << department() << endl;
        cout << "Salary       : " << salary() << endl;
        cout << endl << "___________________" << endl;
    }
};

class Developer : public Employee {
public:
    enum class ProgrammingLanguage { JAVA, C, CPLUSPLUS, GOLANG, TYPESCRIPT };

private:
    ProgrammingLanguage main_programming_language_;

public:
    Developer(int identifier,
              string first_name,
              string last_name,
              string email,
              string phone_number,
              string title,
              Department department,
              float salary,
              ProgrammingLanguage programming_language) :
        Employee(identifier,
                 first_name,
                 last_name,
                 email,
                 phone_number,
                 title,
                 department,
                 salary) {
        main_programming_language_ = programming_language;
    };

    string main_programming_language() {
        switch (main_programming_language_) {
            case ProgrammingLanguage::JAVA:
                return "Java";
            case ProgrammingLanguage::C:
                return "C";
            case ProgrammingLanguage::CPLUSPLUS:
                return "C++";
            case ProgrammingLanguage::GOLANG:
                return "Go";
            case ProgrammingLanguage::TYPESCRIPT:
                return "TypeScript";
        }
    }

    void set_main_programming_language(ProgrammingLanguage value) {
        main_programming_language_ = value;
    }


    void print() {
        cout << "Info:" << endl;
        cout << "___________________" << endl;
        cout << "ID                        : " << id() << endl;
        cout << "FirstName                 : " << first_name() << endl;
        cout << "LastName                  : " << last_name() << endl;
        cout << "Full Name                 : " << full_name() << endl;
        cout << "Email                     : " << email() << endl;
        cout << "Phone Number              : " << phone_number() << endl;
        cout << "Title                     : " << title() << endl;
        cout << "Department                : " << department() << endl;
        cout << "Salary                    : " << salary() << endl;
        cout << "Main Programming Language : " << main_programming_language()
             << endl;
        cout << "___________________" << endl;
    }
};

int main() {
    Developer developer(1, "Muhannad", "Elbolaky", "j3z5d@example.com",
                        "+201055555555", "Software Engineer",
                        Employee::Department::IT, 50000,
                        Developer::ProgrammingLanguage::GOLANG);

    developer.print();

    return 0;
}

