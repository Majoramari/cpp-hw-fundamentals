#include <iostream>

using namespace std;

string remove_punctuation(const string &str) {
	string result;
	for (const char c: str) {
		if (!ispunct(c))
			result += c;
	}
	return result;
}

int main() {
	const string str = "Hello, World! Welcome to C++ programming.";

	cout << remove_punctuation(str) << endl;

	return 0;
}
