#include <iomanip>
#include <iostream>

#include "utils.h"

using namespace std;

void fill_matrix_with_random_numbers(int arr[3][3], const int max_number, const short rows, const short cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = utils::gen_random_int(1, max_number);
		}
	}
}

void print_matrix(int arr[3][3], const short rows, const short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++) {
			printf("  %02d  ", arr[i][j]);
			// cout << setw(2) << setfill('0') << arr[i][j] << "    ";
		}
		cout << endl;
	}
}

void print_middle_row_matrix(int arr[3][3], const short rows, const short cols) {
	const auto middle_row = static_cast<short>(rows / 2);

	for (short i = 0; i < cols; i++) {
		printf("  %02d  ", arr[middle_row][i]);
	}
	cout << endl;
}

void print_middle_col_matrix(int arr[3][3], const short rows, const short cols) {
	const auto middle_col = static_cast<short>(cols / 2);

	for (short i = 0; i < rows; i++) {
		printf("  %02d  ", arr[i][middle_col]);
	}
	cout << endl;
}

int sum_matrix(int arr[3][3], const short rows, const short cols) {
	int sum = 0;
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}

bool is_equal_matrix(int matrix1[3][3], int matrix2[3][3]) {
	const int sum_matrix1 = sum_matrix(matrix1, 3, 3);
	const int sum_matrix2 = sum_matrix(matrix2, 3, 3);

	return sum_matrix1 == sum_matrix2;
}

bool compare_matrix_elements(int matrix1[3][3], int matrix2[3][3], const short rows, const short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++) {
			if (matrix1[i][j] != matrix2[i][j])
				return false;
		}
	}
	return true;
}

bool is_scalar_matrix(int matrix[3][3], const short rows, const short cols) {
	const int first_diagonal_element = matrix[0][0];

	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++) {
			if (i == j && matrix[i][j] != first_diagonal_element)
				return false;
			if (i != j && matrix[i][j] != 0)
				return false;
		}
	}

	return true;
}

int count_number_in_matrix(int matrix[3][3], const int number_to_count, const short rows, const short cols) {
	int counter = 0;

	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++) {
			if (matrix[i][j] == number_to_count)
				counter++;
		}
	}

	return counter;
}

int is_in_matrix(int matrix[3][3], const int number, const short rows, const short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++) {
			if (matrix[i][j] == number)
				return 1;
		}
	}
	return 0;
}

void print_intersected_number(int matrix1[3][3], int matrix2[3][3], const short rows, const short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++) {
			if (const int number = matrix1[i][j]; is_in_matrix(matrix2, number, rows, cols))
				cout << setw(3) << number << "   ";
		}
	}
}

int get_min_number_in_matrix(int matrix[3][3], const short rows, const short cols) {
	int number = matrix[0][0];
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++) {
			if (matrix[i][j] < number)
				number = matrix[i][j];
		}
	}
	return number;
}

int get_max_number_in_matrix(int matrix[3][3], const short rows, const short cols) {
	int number = matrix[0][0];
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++) {
			if (matrix[i][j] > number)
				number = matrix[i][j];
		}
	}
	return number;
}

bool is_palindrome_matrix(int matrix[3][3], const short rows, const short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols / 2; j++) {
			if (matrix[i][j] != matrix[i][cols - 1 - j])
				return false;
		}
	}
	return true;
}

void print_fibonacci_using_loop(const short times_to_loob) {
	int feb_number = 0;
	int previous_fib_number_1 = 1;
	int previous_fib_number_2 = 0;

	cout << "1   ";
	for (short i = 0; i < times_to_loob; ++i) {
		feb_number = previous_fib_number_1 + previous_fib_number_2;

		cout << feb_number << "   ";

		previous_fib_number_2 = previous_fib_number_1;
		previous_fib_number_1 = feb_number;
	}
}

void print_fibonacci_using_recursion(short number, int prevous_1, int previous_2) {
	int feb_number = 0;

	if (number > 0) {
		feb_number = prevous_1 + previous_2;
		previous_2 = prevous_1;
		prevous_1 = feb_number;
		cout << feb_number << "   ";
		print_fibonacci_using_recursion(number - 1, prevous_1, previous_2);
	}
}

int main() {
	// int matrix[3][3]{{1, 2, 1}, {2, 5, 2}, {3, 4, 3}};

	// print_fibonacci_using_loop(10);
	// print_fibonacci_using_recursion(10, 0, 1);

	return 0;
}
