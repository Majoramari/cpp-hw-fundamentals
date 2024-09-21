# include <iostream>
#include <vector>

using namespace std;

string join_string(vector<string> strings, string delimiter) {
	string result;

	for (string &s: strings) {
		result += s + delimiter;
	}

	return result.substr(0, result.length() - delimiter.length());
}

int main() {
	vector<string> strings = {"Muhannad", "Hassan", "Elbolaky"};

	cout << "Vector after join: " << endl;
	cout << join_string(strings, ", ") << endl;

	return 0;
}
