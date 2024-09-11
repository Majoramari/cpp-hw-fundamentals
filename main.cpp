#include <iostream>
#include <vector>

using namespace std;

struct Employee {
	string first_name;
	string last_name;
	int salary{};
};

void read_employees(vector<Employee> &employees) {
	bool add_more_employees = true;

	while (add_more_employees) {
		Employee employee;

		cout << "Enter employee first name: ";
		cin >> employee.first_name;
		cout << "Enter employee last name: ";
		cin >> employee.last_name;

		cout << "Enter employee salary: ";
		while (!(cin >> employee.salary) || employee.salary < 0) {
			cout << "Invalid input! Please enter a valid salary: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		employees.push_back(employee);

		char user_input;
		cout << "\nDo you want to add another employee? (y/n): ";
		cin >> user_input;
		user_input = tolower(user_input);
		cout << endl;

		if (user_input != 'y')
			add_more_employees = false;
	}
}

void print_employees(vector<Employee> &employees) {
	for (auto &[first_name, last_name, salary]: employees) {
		cout << "Employee's first name: " << first_name << endl;
		cout << "Employee's last name: " << last_name << endl;
		cout << "Employee's salary: " << salary << endl;
		cout << endl;
	}
}

int main() {
	vector<Employee> employees;

	read_employees(employees);
	print_employees(employees);
}
