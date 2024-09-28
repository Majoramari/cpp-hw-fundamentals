# Leap Year Calculator - Problem #3 : #6

> ### ☑️ Tasks
> - [x] Solved. - Sat, 28 Sep 2024
> - [x] Explanation. - Sat, 28 Sep 2024

## Overview

The provided code defines a set of functions to calculate the duration of a year and the duration of a specific month within that year.

### Purpose
The program aims to:
- Determine whether a year is a leap year.
- Calculate and display the number of days, hours, minutes, and seconds in a given month of a specified year.

## Functions and Their Responsibilities

### 1. `is_leap_year`
```cpp
bool is_leap_year(const unsigned short int &year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
```
**Purpose**: This function checks if a given year is a leap year based on established criteria:
- A year is a leap year if:
   - It is divisible by `4` AND
   - It is NOT divisible by `100` UNLESS it is also divisible by `400`.

### 2. `read_month_number`
```cpp
unsigned short int read_month_number() {
	unsigned short int month;
	do {
		cout << "Please enter a month number: ";
		cin >> month;
	} while (month < 1 || month > 12);
	return month;
}
```
**Purpose**: This function prompts the user to enter a month number and ensures it is valid (between `1` and `12`). It uses a loop to repeatedly ask for input until a valid month is provided.

### 3. `get_month_days`
```cpp
int get_month_days(const unsigned short int &year, const unsigned short int &month) {
	static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	return month == 2 && is_leap_year(year) ? 29 : days_in_month[month - 1];
}
```
**Purpose**: This function calculates the number of days in a specific month of a given year. It uses a static array for the days in each month, adjusting February to account for leap years:
- If the month is February (month `2`), it checks if the year is a leap year. If so, it returns `29`, otherwise, it returns `28`.
- For all other months, it returns the value from the `days_in_month` array.

### 4. `get_days_in_year`
```cpp
int get_days_in_year(const unsigned short int &year) {
	return is_leap_year(year) ? 366 : 365;
}
```
**Purpose**: This function returns the total number of days in the specified year, using the `is_leap_year` function to determine if it should return `366` or `365`.

### 5. `get_hours_in_year`
```cpp
int get_hours_in_year(const unsigned short int &year) {
	return get_days_in_year(year) * 24;
}
```
**Purpose**: This function calculates the total number of hours in a year by multiplying the number of days by `24`.

### 6. `get_minutes_in_year`
```cpp
int get_minutes_in_year(const unsigned short int &year) {
	return get_hours_in_year(year) * 60;
}
```
**Purpose**: This function calculates the total number of minutes in a year by multiplying the total hours by `60`.

### 7. `get_seconds_in_year`
```cpp
int get_seconds_in_year(const unsigned short int &year) {
	return get_minutes_in_year(year) * 60;
}
```
**Purpose**: This function calculates the total number of seconds in a year by multiplying the total minutes by `60`.

### 8. `print_year_duration` (Unused)
```cpp
void print_year_duration(const unsigned short int &year) {
	cout << "Number of Days: " << get_days_in_year(year) << endl;
	cout << "Number of Hours: " << get_hours_in_year(year) << endl;
	cout << "Number of Minutes: " << get_minutes_in_year(year) << endl;
	cout << "Number of Seconds: " << get_seconds_in_year(year) << endl;
}
```
**Purpose**: Although defined, this function is not called in the main program. It would print the total duration of the specified year in days, hours, minutes, and seconds.

### 9. `print_month_duration`
```cpp
void print_month_duration(const unsigned short int &year, const unsigned short int &month) {
	cout << "Number of Days: " << get_month_days(year, month) << endl;
	cout << "Number of Hours: " << get_month_days(year, month) * 24 << endl;
	cout << "Number of Minutes: " << get_month_days(year, month) * 24 * 60 << endl;
	cout << "Number of Seconds: " << get_month_days(year, month) * 24 * 60 * 60 << endl;
}
```
**Purpose**: This function calculates and displays the number of days, hours, minutes, and seconds for the specified month of a given year.

### Main Function
```cpp
int main() {
	const unsigned short int year = utils::get_number("Please enter a year to check: ");
	const unsigned short int month = read_month_number();

	print_month_duration(year, month);

	return 0;
}
```
**Purpose**: The `main` function coordinates the user interaction:
1. It prompts the user to enter a year using `utils::get_number`.
2. It reads a valid month number using `read_month_number`.
3. It calls `print_month_duration` to display the duration of the specified month in the given year.

## Example Execution
When the program runs:
1. It prompts the user with `"Please enter a year to check: "`.
2. The user inputs `2024`, followed by entering `2` for February.
3. The output will be:
   ```
   Number of Days: 29
   Number of Hours: 696
   Number of Minutes: 41760
   Number of Seconds: 2505600
   ```
   This shows the duration for February in a leap year.