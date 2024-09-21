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

string join_string(string arr[100], const int arr_length, string delimiter) {
	string result;

	for (int i = 0; i < arr_length; i++) {
		result += arr[i] + delimiter;
	}

	return result.substr(0, result.length() - delimiter.length());
}

int main() {
	const vector<string> vector_string = {"Muhannad", "Hassan", "Elbolaky"};
	string arr[100]{"Muhannad", "Hassan", "Elbolaky"};

	cout << "Vector after join: " << endl;
	cout << join_string(vector_string, ", ") << endl;

	cout << endl;

	cout << "Array after join: " << endl;
	cout << join_string(arr, 3, ", ") << endl;

	return 0;
}
