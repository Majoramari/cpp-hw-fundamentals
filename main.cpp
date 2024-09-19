#include <iostream>

#include "utils.h"

using namespace std;

vector<string> split(string str, const string &delimiter) {
	vector<string> tokens;

	string::size_type pos = 0;

	while ((pos = str.find(delimiter)) != string::npos) {
		if (string token = str.substr(0, pos); !token.empty())
			tokens.push_back(token);

		str.erase(0, pos + delimiter.length());
	}

	if (!str.empty())
		tokens.push_back(str);

	return tokens;
}


int main() {
	vector vector_string = split(utils::get_string(), " ");

	for (string &s: vector_string) {
		cout << s << endl;
	}

	return 0;
}
