#include <iostream>
#include <vector>
#include <fstream>

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
	getline(cin >> ws, client.name);

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
	const vector<string> client_data = split(line, separator);

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

void save_client_data(const string &file_name, const string &client_data) {
	fstream file;
	file.open(file_name, ios::out | ios::app);

	if (file.is_open()) {
		file << client_data << endl;
		file.close();
	}
}

void add_new_client() {
	const Client client = create_client();
	const string client_data = convert_from_record(client, "#//#");

	save_client_data("client.txt", client_data);
}

void add_client() {
	char add_more = 'Y';

	do {
		system("clear");
		cout << "Client info: " << endl << endl;

		add_new_client();

		cout << endl << "Do you want to save another? ";
		cin >> add_more;
	} while (toupper(add_more) == 'Y');
}

int main() {
	add_client();
	return 0;
}
