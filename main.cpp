#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void save_vector_to_file(const string &file_name, const vector<string> &file_content) {
	fstream file;
	file.open(file_name, ios::out);

	if (file.is_open()) {
		for (const string &line: file_content) {
			if (!line.empty()) {
				file << line << endl;
			}
		}

		file.close();
	}
}

void load_data_from_file_to_vector(const string &file_name, vector<string> &file_content) {
	fstream file;
	file.open(file_name, ios::in);

	if (file.is_open()) {
		string line;

		while (getline(file, line)) {
			file_content.push_back(line);
		}

		file.close();
	}
	save_vector_to_file(file_name, file_content);
}

void delete_record_from_file(const string &file_name, const string &record) {
	vector<string> file_content;
	load_data_from_file_to_vector(file_name, file_content);

	for (string &line: file_content) {
		if (line == record) {
			line = "";
		}
	}

	save_vector_to_file(file_name, file_content);
}

void print_file_content(const string &file_name) {
	fstream file;

	file.open(file_name, ios::in);

	if (file.is_open()) {
		string line;

		while (getline(file, line)) {
			cout << line << endl;
		}

		file.close();
	}
}

int main() {
	cout << "File Content before delete." << endl;
	print_file_content("myfile.txt");

	delete_record_from_file("myfile.txt", "Ali");

	cout << endl << endl << "File Content after delete." << endl;
	print_file_content("myfile.txt");

	return 0;
}
