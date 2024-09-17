#include <iostream>

#include "utils.h"

using namespace std;

void fill_array_with_random_numbers(int arr[100], int &arr_length) {
	arr_length = utils::get_number("Enter number of elements: ");

	for (int i = 0; i < arr_length; i++)
		arr[i] = utils::gen_random_int(1, 100);
}

void fill_order_array(int arr[100], const int &arr_length) {
	for (int i = 0; i < arr_length + 1; i++)
		arr[i] = i + 1;
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

int main() {
	int arr[100], arr2[100], arr_length;

	cout << "Enter number of elements: ";
	cin >> arr_length;

	fill_order_array(arr, arr_length);
	cout << endl << "Array: " << endl;
	print_array(arr, arr_length);

	cout << endl << endl;

	copy_reversed_array(arr, arr2, arr_length);

	cout << endl << "Reversed array: " << endl;
	print_array(arr2, arr_length);

	return 0;
}
