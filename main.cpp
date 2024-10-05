#include <iostream>

using namespace std;

struct Application {
	int age;
	bool has_driver_license;
	bool has_recommendation;
};

Application read_applicant_data() {
	Application app{};
	cout << "How old are you?: ";
	cin >> app.age;
	cout << "Do you have a driver license? (1 for yes, 0 for no): ";
	cin >> app.has_driver_license;
	cout << "Do you have a recommendation? (1 for yes, 0 for no): ";
	cin >> app.has_recommendation;
	return app;
}

void check_approval_criteria(const Application &app) {
	if ((app.age >= 21 && app.has_driver_license) || app.has_recommendation)
		cout << "Application approved!" << endl;
	else
		cout << "Application denied..." << endl;
}

int main() {
	const Application app = read_applicant_data();
	check_approval_criteria(app);
	return 0;
}
