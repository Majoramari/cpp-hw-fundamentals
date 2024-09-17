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

void print_array(int arr[100], const int arr_length) {
	for (int i = 0; i < arr_length; i++)
		cout << arr[i] << " ";
}

void print_array_keys(string arr[100], const int arr_length) {
	for (int i = 0; i < arr_length; i++)
		cout << "Array[" << i << "]: " << arr[i] << endl;
}

int main() {
	string arr[100];
	int arr_length;

	cout << "Enter number of elements: ";
	cin >> arr_length;

	fill_array_with_keys(arr, arr_length);

	cout << endl << "Array elements: " << endl;
	print_array_keys(arr, arr_length);

	return 0;
}
