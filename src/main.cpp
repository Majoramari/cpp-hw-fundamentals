#include <cmath>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Employee {
public:
    enum Department { HR, FINANCE, SALES, MARKETING };

private:
    int id_;
    string first_name_, last_name_, title_, email_, phone_number_;
    float salary_;
    Department department_;

public:
    Employee(int identifier,
             string first_name,
             string last_name,
             string title,
             string email,
             string phone_number,
             float salary,
             Department department) {
        id_ = identifier;
        first_name_ = first_name;
        last_name_ = last_name;
        title_ = title;
        email_ = email;
        phone_number_ = phone_number;
        salary_ = salary;
        department_ = department;
    }

    [[nodiscard]] int id() const { return id_; }

    [[nodiscard]] string first_name() const { return first_name_; }

    void set_first_name(string value) { first_name_ = value; }

    [[nodiscard]] string last_name() const { return last_name_; }

    void set_last_name(string value) { last_name_ = value; }

    [[nodiscard]] string full_name() const {
        return first_name_ + " " + last_name_;
    }

    [[nodiscard]] string email() const { return email_; }

    void set_email(string value) { email_ = value; }

    [[nodiscard]] string title() const { return title_; }

    void set_title(string value) { title_ = value; }

    [[nodiscard]] string phone_number() const { return phone_number_; }

    void set_phone_number(string value) { phone_number_ = value; }

    [[nodiscard]] float salary() const { return salary_; }

    void set_salary(float value) { salary_ = value; }

    [[nodiscard]] string department() const {
        switch (department_) {
            case HR:
                return "Human Resources";
            case FINANCE:
                return "Finance";
            case SALES:
                return "Sales";
            case MARKETING:
                return "Marketing";
        }
    }

    void set_department(Department value) { department_ = value; }

    void print() const {
        cout << "Info:" << endl;
        cout << "______________" << endl;
        cout << "ID:           " << id() << endl;
        cout << "First Name:   " << first_name() << endl;
        cout << "Last Name:    " << last_name() << endl;
        cout << "Full Name:    " << full_name() << endl;
        cout << "Title:        " << title() << endl;
        cout << "Email:        " << email() << endl;
        cout << "Phone Number: " << phone_number() << endl;
        cout << "Salary:       " << salary() << endl;
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

using Department = Employee::Department;

int main() {
    // Create an Employee object
    Employee employee(1, "Muhannad", "Elbolaky", "Software Developer",
                      "4u0yS@example.com", "+201997318", 120000.0,
                      Department::HR);

    // Print the employee's information
    employee.print();

    // Send an email to the employee
    employee.send_email("You're fired!", "Goodbye");

    // Send an SMS to the employee
    employee.send_sms("Hello, It's me");

    return 0;
}
