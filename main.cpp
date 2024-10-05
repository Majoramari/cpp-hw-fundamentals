#include <iostream>

using namespace std;

string read_name() {
	string name;
	cout << "Please enter your name: ";
	getline(cin, name);
	return name;
}

void print_name(const string &name) {
	cout << "Hello, " << name << "!" << endl;
}

int main() {
	print_name(read_name());
	return 0;
}
