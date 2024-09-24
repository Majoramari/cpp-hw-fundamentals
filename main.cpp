// ReSharper disable CppUseStructuredBinding
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
	bool mark_for_delete = false;
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

Client decompress_client(const string &data_line, const string &separator = "#//#") {
	Client client;
	const vector<string> client_data = split(data_line, separator);

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
		string data_line;

		while (getline(file, data_line)) {
			client = decompress_client(data_line);
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

void transaction_menu();

void print_client_record(const Client &client) {
	cout << "| " << setw(20) << left << client.name
			<< "| " << setw(15) << left << client.account_number
			<< "| " << setw(10) << left << client.pin_code
			<< "| " << setw(12) << left << client.phone
			<< "| " << setw(12) << left << fixed << setprecision(2) << client.account_balance;
}

vector<Client> save_clients_data(vector<Client> clients) {
	fstream file;
	file.open(FILE_NAME, ios::out);

	if (file.is_open()) {
		for (Client &c: clients) {
			if (c.mark_for_delete == false) {
				string data_line = compress_client(c);
				file << data_line << endl;
			}
		}

		file.close();
	}

	return clients;
}

void return_to_menu() {
	system("read -n 1 -s -p \"Press any key to go back to main menu...\"");
	show_main_menu();
}

bool client_already_exists(const string &account_number) {
	fstream file;

	file.open(FILE_NAME, ios::in);

	if (file.is_open()) {
		string data_line;
		Client client;

		while (getline(file, data_line)) {
			client = decompress_client(data_line, "#//#");

			if (client.account_number == account_number) {
				file.close();
				return true;
			}
		}
		file.close();
	}
	return false;
}

void list_clients() {
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

	while (client_already_exists(client.account_number)) {
		cout << endl << "Client with [" << client.account_number << "] already exists, Enter another Account No" <<
				endl;
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

void add_clients_menu() {
	cout << "---------------------------------" << endl;
	cout << "\tAdd new client" << endl;
	cout << "---------------------------------" << endl;

	prompt_to_add_clients();
}

void print_client(const Client &client) {
	cout << endl << "The Client details:" << endl;
	cout << "-----------------------------------";
	cout << endl << "Name         : " << client.name;
	cout << endl << "Account Number: " << client.account_number;
	cout << endl << "Pin Code     : " << client.pin_code;
	cout << endl << "Phone        : " << client.phone;
	cout << endl << "Account Balance: " << client.account_balance;
	cout << endl << "-----------------------------------" << endl;
}

bool find_client(const string &account_number, Client &client) {
	vector<Client> clients = load_clients_data();

	for (const Client &c: clients) {
		if (c.account_number == account_number) {
			client = c;
			return true;
		}
	}
	return false;
}

bool mark_for_delete_by(const string &account_number, vector<Client> &clients) {
	for (Client &c: clients) {
		if (c.account_number == account_number) {
			c.mark_for_delete = true;
			return true;
		}
	}
	return false;
}

bool remove_client_by_account_number(const string &account_number) {
	vector<Client> clients = load_clients_data();


	if (Client client; find_client(account_number, client)) {
		print_client(client);

		char answer;
		cout << endl << endl << "Are you sure you want to delete this client? Y/N: ";
		cin >> answer;

		if (tolower(answer) == 'y') {
			mark_for_delete_by(account_number, clients);
			save_clients_data(clients);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
		cout << "\nDeletion cancelled";
	} else {
		cout << "\nClient with Account Number (" << account_number << ") is not found!";
	}
	return false;
}

string get_account_number() {
	string account_number;
	cout << "Enter Account Number: ";
	cin >> account_number;
	return account_number;
}

void remove_client_menu() {
	cout << "---------------------------------" << endl;
	cout << "\tRemove client" << endl;
	cout << "---------------------------------" << endl;

	const string account_number = get_account_number();
	remove_client_by_account_number(account_number);
}

Client apply_client_changes(const string &account_number) {
	Client client;

	client.account_number = account_number;

	cout << "Enter name: " << endl;
	getline(cin >> ws, client.name);

	cout << "Enter pin-code: " << endl;
	getline(cin, client.pin_code);

	cout << "Enter phone: " << endl;
	getline(cin, client.phone);

	cout << "Enter account balance: " << endl;
	cin >> client.account_balance;

	return client;
}

bool update_client(const string &account_number) {
	vector<Client> clients = load_clients_data();

	if (Client client; find_client(account_number, client)) {
		char answer = 'n';
		print_client(client);

		cout << endl << endl << "Are you sure you want update this client? Y/N: ";
		cin >> answer;

		if (tolower(answer) == 'y') {
			for (Client &c: clients) {
				if (c.account_number == account_number) {
					c = apply_client_changes(account_number);
					break;
				}
			}

			save_clients_data(clients);

			cout << endl << endl << "Client Updated Successfully.";
			return true;
		}
		cout << endl << "Update client cancelled.";
	} else {
		cout << endl << "Client with Account Number [" << account_number << "] is Not Found!";
	}
	return false;
}

void update_client_menu() {
	cout << "---------------------------------" << endl;
	cout << "\tUpdate client" << endl;
	cout << "---------------------------------" << endl;

	const string account_number = get_account_number();
	update_client(account_number);
}

void find_client_menu() {
	cout << "---------------------------------" << endl;
	cout << "\tUpdate client" << endl;
	cout << "---------------------------------" << endl;

	const string account_number = get_account_number();

	if (Client client; find_client(account_number, client))
		print_client(client);
	else
		cout << endl << endl << "Client not found.";
}

bool update_client_balance(const string &account_number, const double &amount) {
	char answer = 'n';
	cout << "Are you sure you want to perform this action? Y/N:";
	cin >> answer;

	if (tolower(answer) == 'y') {
		vector<Client> clients = load_clients_data();
		for (Client &c: clients) {
			if (c.account_number == account_number) {
				c.account_balance += amount;
				save_clients_data(clients);

				return true;
			}
		}
	}
	return false;
}

void display_deposit_menu() {
	system("clear");
	cout << "================================" << endl;
	cout << "\tDeposit menu" << endl;
	cout << "================================" << endl;
}

void deposit_menu() {
	display_deposit_menu();

	Client client;
	string account_number = get_account_number();

	while (!find_client(account_number, client)) {
		display_deposit_menu();
		cout << endl << "Client with [" << account_number << "] not found." << endl << endl;
		account_number = get_account_number();
	}

	display_deposit_menu();

	print_client(client);

	double amount;
	cout << "Enter deposit amount: ";
	cin >> amount;

	if (update_client_balance(account_number, amount)) {
		cout << "Deposit successfully." << endl << endl;
	}
}

void display_withdraw_menu() {
	system("clear");
	cout << "================================" << endl;
	cout << "\tWithdraw menu" << endl;
	cout << "================================" << endl;
}

void withdraw_menu() {
	display_withdraw_menu();

	Client client;
	string account_number = get_account_number();

	while (!find_client(account_number, client)) {
		display_withdraw_menu();
		cout << endl << "Client with [" << account_number << "] not found." << endl << endl;
		account_number = get_account_number();
	}

	display_withdraw_menu();

	print_client(client);

	double amount;
	cout << "Enter withdraw amount: ";
	cin >> amount;

	while (amount > client.account_balance) {
		display_withdraw_menu();
		print_client(client);

		cout << endl << "Amount exceeds the balance!" << endl;
		cout << "Enter withdraw amount: ";
		cin >> amount;
	}

	if (update_client_balance(account_number, amount * -1)) {
		cout << "Withdrawal successfully." << endl << endl;
	}
}

void print_client_record_balance_line(const Client &client) {
	cout << "| " << setw(20) << left << client.name
			<< "| " << setw(15) << left << client.account_number
			<< "| " << setw(12) << left << fixed << setprecision(2) << client.account_balance;
}

void display_total_balance() {
	vector<Client> clients = load_clients_data();

	cout << endl << "\t\t\tBalances list: (" << clients.size() << ") Clients.";
	cout << endl << "-------------------------------------------------------" << endl;
	cout << "| " << left << setw(20) << "Name"
			<< "| " << left << setw(15) << "Account No"
			<< "| " << left << setw(12) << "Balance" << " |" << endl;
	cout << "-------------------------------------------------------" << endl;

	if (clients.empty()) {
		cout << endl << endl << "No clients found." << endl << endl;
	} else {
		double total_balance = 0;
		for (const Client &c: clients) {
			print_client_record_balance_line(c);
			total_balance += c.account_balance;
			cout << " |" << endl;
		}
	}

	cout << "-------------------------------------------------------" << endl;
}

enum class transactions_option {
	deposit = 1,
	withdraw,
	total_balances,
	main_menu,
};

void return_to_transactions_menu() {
	system("read -n 1 -s -p \"Press any key to go back to main menu...\"");
	transaction_menu();
};

void perform_transactions_option(const transactions_option option) {
	system("clear");

	switch (option) {
		case transactions_option::deposit:
			deposit_menu();
			return_to_transactions_menu();
			break;
		case transactions_option::withdraw:
			withdraw_menu();
			return_to_menu();
			break;
		case transactions_option::total_balances:
			display_total_balance();
			return_to_menu();
			break;
		case transactions_option::main_menu:
			show_main_menu();
			break;
	}
}

void transaction_menu() {
	system("clear");

	cout << "================================" << endl;
	cout << "\tTransaction menu" << endl;
	cout << "================================" << endl;
	cout << "\t[1] Deposit." << endl;
	cout << "\t[2] Withdraw." << endl;
	cout << "\t[3] Total Balances." << endl;
	cout << "\t[4] Main Menu." << endl;
	cout << "================================" << endl;

	perform_transactions_option(
		static_cast<transactions_option>(
			utils::get_number(
				"Choose what do you want to do [1 to 4]: "
			)
		)
	);
}

void exit_app() {
	cout << "---------------------------------" << endl;
	cout << "\tSee you soon" << endl;
	cout << "---------------------------------" << endl;

	exit(0);
}

enum class client_option {
	list = 1,
	add,
	remove,
	update,
	find,
	transactions,
	exit
};

void perform_main_option(const client_option option) {
	system("clear");
	switch (option) {
		case client_option::list:
			list_clients();
			return_to_menu();
			break;
		case client_option::add:
			add_clients_menu();
			return_to_menu();
			break;
		case client_option::remove:
			remove_client_menu();
			return_to_menu();
			break;
		case client_option::update:
			update_client_menu();
			return_to_menu();
			break;
		case client_option::find:
			find_client_menu();
			return_to_menu();
			break;
		case client_option::transactions:
			transaction_menu();
			break;
		case client_option::exit:
			exit_app();
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
	cout << "\t[6] Transactions." << endl;
	cout << "\t[7] Exit." << endl;
	cout << "================================" << endl;

	perform_main_option(
		static_cast<client_option>(
			utils::get_number(
				"Choose what do you want to do [1 to 7]: "
			)
		)
	);
}

int main() {
	show_main_menu();
	return 0;
}
