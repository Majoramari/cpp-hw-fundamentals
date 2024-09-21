# include <iostream>
#include <vector>

using namespace std;

vector<string> split(const string &str, const string &delimiter) {
	vector<string> tokens;
	string::size_type start = 0, end;

	while ((end = str.find(delimiter, start)) != string::npos) {
		if (string token = str.substr(start, end - start); !token.empty())
			tokens.push_back(token);

		start = end + delimiter.length();
	}

	if (start < str.length())
		tokens.push_back(str.substr(start));

	return tokens;
}


string reverse_words(const string &str) {
	vector<string> words = split(str, " ");
	string result;

	auto iterator = words.end();

	while (iterator != words.begin()) {
		--iterator;
		result += *iterator + " ";
	}

	result = result.substr(0, result.length() - 1);

	return result;
}

int main() {
	const string str = "Hello, My name is Muhannad & my nickname is Major Amari";

	cout << reverse_words(str) << endl;

	return 0;
}
