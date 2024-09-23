#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "utils.h"

using namespace std;

const string FILE_NAME = "client.txt";

struct Client {
	string name, account_number, pin_code, phone;
	double account_balance{};
};

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

Client decompress_client(const string &line, const string &separator = "#//#") {
	Client client;
	const vector<string> client_data = split(line, separator);

	client.name = client_data[0];
	client.account_number = client_data[1];
	client.pin_code = client_data[2];
	client.phone = client_data[3];
	client.account_balance = stod(client_data[4]);

	return client;
}

string compress_client(const Client &client, const string &separator = "#//#") {
	string compressed_client_data;

	compressed_client_data += client.name + separator;
	compressed_client_data += client.account_number + separator;
	compressed_client_data += client.pin_code + separator;
	compressed_client_data += client.phone + separator;
	compressed_client_data += to_string(client.account_balance);

	return compressed_client_data;
}

vector<Client> load_clients_data() {
	vector<Client> clients;

	fstream file;
	file.open(FILE_NAME, ios::in);

	if (file.is_open()) {
		Client client;
		string line;

		while (getline(file, line)) {
			client = decompress_client(line);
			clients.push_back(client);
		}

		file.close();
	}

	return clients;
}

void save_client_data(const Client &client) {
	fstream file;
	file.open(FILE_NAME, ios::out | ios::app);

	if (file.is_open()) {
		file << compress_client(client) << endl;
		file.close();
	}
}

void show_main_menu();

void print_client_record(const Client &client) {
	cout << "| " << setw(20) << left << client.name
			<< "| " << setw(15) << left << client.account_number
			<< "| " << setw(10) << left << client.pin_code
			<< "| " << setw(12) << left << client.phone
			<< "| " << setw(12) << left << fixed << setprecision(2) << client.account_balance;
}

void return_to_menu() {
	system("read -n 1 -s -p \"Press any key to go back to main menu...\"");
	show_main_menu();
}

bool client_already_exists(const string &account_number) {
	fstream file;

	file.open(FILE_NAME, ios::in);

	if (file.is_open()) {
		string line;
		Client client;

		while (getline(file, line)) {
			client = decompress_client(line, "#//#");

			if (client.account_number == account_number) {
				file.close();
				return true;
			}
		}
		file.close();
	}
	return false;
}

void show_all_clients() {
	vector<Client> clients = load_clients_data();

	cout << endl << "\t\t\tClient list: (" << clients.size() << ") Clients.";
	cout << endl << "--------------------------------------------------------";
	cout << "-------------------------" << endl;
	cout << "| " << left << setw(20) << "Name"
			<< "| " << left << setw(15) << "Account No"
			<< "| " << left << setw(10) << "Pin Code"
			<< "| " << left << setw(12) << "Phone"
			<< "| " << left << setw(12) << "Balance" << " |" << endl;
	cout << endl << "--------------------------------------------------------";
	cout << "-------------------------" << endl;

	if (clients.empty()) {
		cout << "\t\t\t\tClient list is empty." << endl;
	} else {
		for (const Client &client: clients) {
			print_client_record(client);
			cout << " |" << endl;
		}
		cout << "--------------------------------------------------------";
		cout << "-------------------------" << endl;
	}
}

void add_client() {
	Client client;

	cout << endl << "Enter new client name: ";
	getline(cin >> ws, client.name);

	while(client_already_exists(client.account_number)) {
		cout << endl<<"Client with ["<< client.account_number << "] already exists, Enter another Account No" << endl;
		getline(cin >> ws, client.account_number);
	}

	cout << endl << "Enter account number: ";
	cin >> client.account_number;

	cout << endl << "Enter pin-code: ";
	cin >> client.pin_code;

	cout << endl << "Enter phone: ";
	cin >> client.phone;

	cout << endl << "Enter account balance: ";
	cin >> client.account_balance;

	save_client_data(client);
}

void prompt_to_add_clients() {
	char add_more = 'y';

	do {
		add_client();
		cout << "Client added successfully, do you want to add more? Y/N: ";
		cin >> add_more;
	} while (tolower(add_more) == 'y');
}

void show_add_new_clients() {
	cout << "---------------------------------" << endl;
	cout << "\tAdd new client" << endl;
	cout << "---------------------------------" << endl;

	prompt_to_add_clients();
}

enum class client_option {
	list = 1,
	add,
	remove,
	update,
	find,
	exit
};

void perform_option(const client_option option) {
	system("clear");
	switch (option) {
		case client_option::list:
			show_all_clients();
			return_to_menu();
			break;
		case client_option::add:
			show_add_new_clients();
			return_to_menu();
			break;
		case client_option::remove:
			return_to_menu();
			break;
		case client_option::update:
			return_to_menu();
			break;
		case client_option::find:
			return_to_menu();
			break;
		case client_option::exit:
			show_main_menu();
	}
}

void show_main_menu() {
	system("clear");

	cout << "================================" << endl;
	cout << "\tMain menu screen" << endl;
	cout << "================================" << endl;
	cout << "\t[1] Show Client List." << endl;
	cout << "\t[2] Add New Client." << endl;
	cout << "\t[3] Delete Client." << endl;
	cout << "\t[4] Update Client info." << endl;
	cout << "\t[5] Find Client." << endl;
	cout << "\t[6] Exit." << endl;
	cout << "================================" << endl;

	perform_option(
		static_cast<client_option>(
			utils::get_number(
				"Choose what do you want to do [1 to 6]: "
			)
		)
	);
}

int main() {
	show_main_menu();
	return 0;
}
