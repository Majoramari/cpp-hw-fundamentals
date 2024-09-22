#include <iostream>

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

string convert_record_to_line(const Client &client, const string &separator) {
	string line;

	line += client.name + separator;
	line += to_string(client.account_number) + separator;
	line += to_string(client.pin_code) + separator;
	line += to_string(client.phone_number) + separator;
	line += to_string(client.balance);

	return line;
}

int main() {
	cout << "Please enter client data: " << endl;

	Client client = create_client();

	cout << convert_record_to_line(client, "#//#") << endl;

	return 0;
}
