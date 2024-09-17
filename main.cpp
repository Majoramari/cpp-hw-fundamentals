#include <iostream>

#include "utils.h"

using namespace std;

enum char_type {
	small_letter = 1,
	capital_letter = 2,
	special_character = 3,
	digit = 4
};

void fill_array_with_random_numbers(int arr[100], int &arr_length) {
	arr_length = utils::get_number("Enter number of elements: ");

	for (int i = 0; i < arr_length; i++)
		arr[i] = utils::gen_random_int(1, 100);
}

void fill_order_array(int arr[100], const int &arr_length) {
	for (int i = 0; i < arr_length + 1; i++)
		arr[i] = i + 1;
}

char get_random_character(const char_type char_type) {
	switch (char_type) {
		case small_letter:
			return static_cast<char>(utils::gen_random_int(97, 122));
		case capital_letter:
			return static_cast<char>(utils::gen_random_int(65, 90));
		case special_character:
			return static_cast<char>(utils::gen_random_int(33, 47));
		case digit:
			return static_cast<char>(utils::gen_random_int(48, 57));
	}
	return '0';
}

string generate_word(const char_type char_type, const short length) {
	string word;
	for (int i = 1; i <= length; i++) {
		word += get_random_character(char_type);
	}
	return word;
}

string generate_key() {
	string key = generate_word(capital_letter, 4) + "-";
	key = key + generate_word(capital_letter, 4) + "-";
	key = key + generate_word(capital_letter, 4) + "-";
	key = key + generate_word(capital_letter, 4);
	return key;
}

void swap(int &num_one, int &num_two) noexcept {
	const int temp = num_one;
	num_one = num_two;
	num_two = temp;
}

void shuffle_array(int arr[100], const int &arr_length) {
	for (int i = 0; i < arr_length; i++) {
		swap(
			arr[utils::gen_random_int(1, arr_length - 1)],
			arr[utils::gen_random_int(1, arr_length - 1)]
		);
	}
}

void fill_two_arrays_with_random_numbers(int arr[100], int arr2[100], int &arr_length) {
	arr_length = utils::get_number("Enter number of elements: ");

	for (int i = 0; i < arr_length; i++)
		arr[i] = utils::gen_random_int(1, 100);

	for (int i = 0; i < arr_length; i++)
		arr2[i] = utils::gen_random_int(1, 100);
}

void fill_array_with_keys(string arr[100], const int &arr_length) {
	for (int i = 0; i < arr_length; i++) {
		arr[i] = generate_key();
	}
}

void copy_prime_numbers(int main_array[100], const int arr_length, int prime_array[100], int &arr2_length) {
	int counter = 0;
	for (int i = 0; i < arr_length; i++) {
		if (utils::is_prime(main_array[i])) {
			prime_array[counter] = main_array[i];
			counter++;
		}
	}
	arr2_length = --counter;
}

void copy_reversed_array(const int main_array[100], int reversed_array[100], const int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		reversed_array[i] = main_array[(arr_length - 1) - i];
	}
}

void sum_two_arrays(const int arr[100], const int arr2[100], int arr3[100], const int &arr_length) {
	for (int i = 0; i < arr_length; i++) {
		arr3[i] = arr[i] + arr2[i];
	}
}

void find_num(int arr[100], int &arr_length, const int target_number) {
	for (int i = 0; i < arr_length; i++) {
		if (arr[i] == target_number) {
			cout << "Found " << arr[i] << " at index " << i << endl;
			return;
		}
	}
	cout << "There is no such number " << endl;
}

void fill_array_as_needed(int arr[100], int &arr_length) {
	bool add_more = true;
	do {
		const int number = utils::get_number();

		arr_length++;
		arr[arr_length - 1] = number;

		cout << "Do you want to add more number? 0=No 1=Yes";
		cin >> add_more;
	} while (add_more);
}

void add_array_element(const int number, int arr[100], int &arr_length) {
	arr_length++;
	arr[arr_length - 1] = number;
}

void copy_array(int arr_source[100], int arr_destination[100], const int arr_length, int &arr_destination_length) {
	for (int i = 0; i < arr_length; i++)
		add_array_element(arr_source[i], arr_destination, arr_destination_length);
}

void copy_odd_to_array(int arr_source[100], int arr_destination[100], const int arr_length,
                       int &arr_destination_length) {
	for (int i = 0; i < arr_length; i++) {
		if (arr_source[i] % 2 != 0)
			add_array_element(arr_source[i], arr_destination, arr_destination_length);
	}
}

void print_array(int arr[100], const int arr_length) {
	for (int i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

void print_array_keys(string arr[100], const int arr_length) {
	for (int i = 0; i < arr_length; i++)
		cout << "Array[" << i << "]: " << arr[i] << endl;
}

int main() {
	int arr[100], arr2[100], arr_length, arr2_length = 0;

	fill_array_with_random_numbers(arr, arr_length);

	cout << endl;

	cout << "Array after filling random numbers" << endl;
	print_array(arr, arr_length);

	cout << endl << endl;

	copy_odd_to_array(arr, arr2, arr_length, arr2_length);
	cout << "Array after copying odd numbers" << endl;
	print_array(arr2, arr2_length);

	cout << endl;

	return 0;
}
