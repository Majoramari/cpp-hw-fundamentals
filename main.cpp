#include <iostream>
#include <vector>

using namespace std;

struct Client {
	string name = "Unnamed";
	int account_number = 0;
	int pin_code = 0;
	int phone_number = 0;
	float balance = 0.0f;
};

Client create_client() {
	Client client;
	cout << "Enter account name: ";
	cin >> client.name;

	cout << "Enter account number: ";
	cin >> client.account_number;

	cout << "Enter pin-code: ";
	cin >> client.pin_code;

	cout << "Enter phone number: ";
	cin >> client.phone_number;

	cout << "Enter balance: ";
	cin >> client.balance;

	return client;
}

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

string convert_from_record(const Client &client, const string &separator) {
	string line;

	line += client.name + separator;
	line += to_string(client.account_number) + separator;
	line += to_string(client.pin_code) + separator;
	line += to_string(client.phone_number) + separator;
	line += to_string(client.balance);

	return line;
}

Client convert_from_line(const string &line, const string &separator) {
	Client client;
	vector<string> client_data = split(line, separator);

	client.name = client_data[0];
	client.account_number = stoi(client_data[1]);
	client.pin_code = stoi(client_data[2]);
	client.phone_number = stoi(client_data[3]);
	client.balance = stof(client_data[4]);

	return client;
}

void print_client_data(const Client &client) {
	cout << "Name: " << client.name << endl;
	cout << "Account: " << client.account_number << endl;
	cout << "Pin: " << client.pin_code << endl;
	cout << "Phone: " << client.phone_number << endl;
	cout << "Balance: " << client.balance << endl;
}

int main() {
	const string line = "Muhannad#//#512#//#2848#//#10966#//#200.000000";

	const Client client = convert_from_line(line, "#//#");

	print_client_data(client);

	return 0;
}
