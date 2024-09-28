# Day of the Week Calculator - Problem Solution

> ### ☑️ Tasks
> - [x] Solved. - Sat, 28 Sep 2024
> - [x] Explanation. - Sat, 28 Sep 2024

## Required Task

The program reads a date and prints the name of the day of the week corresponding to that date.

### Inputs
- **Year**: A valid year (e.g., 2024).
- **Month**: A valid month number (1-12).
- **Day**: A valid day number (1-31).

### Outputs
- **Date**: Supplied by the user.
- **Day Order**: The calculated index of the day of the week (1 for Sunday, 7 for Saturday).
- **Day Name**: The name of the day of the week corresponding to the entered date (e.g., "Saturday").

## Functions and Their Responsibilities

### 1. **`read_month_number`**
```cpp
unsigned short read_month_number() {
	unsigned short int month = 1;
	do {
		if (month < 1 || month > 12)
			cout << endl << "Invalid month number, try again: ";

		cout << "Please enter a month number: ";
		cin >> month;
	} while (month < 1 || month > 12);
	return month;
}
```
**Purpose**: This function prompts the user for a valid month number (between 1 and 12) and ensures the input is correct. It uses a `do-while` loop to handle incorrect input.

### 2. **`read_day_number`**
```cpp
unsigned short read_day_number() {
	unsigned short int day = 1;
	do {
		if (day < 1 || day > 31)
			cout << endl << "Invalid day number, try again: ";

		cout << "Please enter a day number: ";
		cin >> day;
	} while (day < 1 || day > 31);
	return day;
}
```
**Purpose**: This function works similarly to `read_month_number`, but it prompts the user for a valid day (between 1 and 31) and validates that input.

### 3. **`calc_day_order`**
```cpp
unsigned short calc_day_order(const unsigned short &day, const unsigned short &month, const unsigned short &year) {
	const unsigned short a = (14 - month) / 12;
	const unsigned short y = year - a;
	const unsigned short m = month + 12 * a - 2;

	return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}
```
**Purpose**: Using **Zeller’s Congruence**, this function calculates the day of the week based on the given date. The result is a number between 0 and 6, where 0 represents Sunday and 6 represents Saturday.

### 4. **`get_day_name`**
```cpp
string get_day_name(const unsigned short &day_index) {
	string days_of_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	return days_of_week[day_index];
}
```
**Purpose**: This function converts the numeric result of `calc_day_order` into the name of the day, such as "Monday" or "Friday," by mapping the number to a string array of day names.

### 5. **`main`**
```cpp
int main() {
	const unsigned short year = utils::get_number("Please enter a year to check: ");
	const unsigned short month = read_month_number();
	const unsigned short day = read_day_number();

	cout << "Date: " << day << "/" << month << "/" << year << endl;
	cout << "Day order: " << calc_day_order(day, month, year) + 1 << endl;
	cout << "Day name: " << get_day_name(calc_day_order(day, month, year)) << endl;

	return 0;
}
```
**Purpose**: This is the main function of the program, coordinating all the user inputs and calculations. It:
- Prompts the user for the year, month, and day.
- Calculates the day of the week using `calc_day_order`.
- Displays the final results to the user (the date, day index, and day name).

---

## Example Usage

1. **User Input**:
   ```
   Please enter a year to check: 2024
   Please enter a month number: 9
   Please enter a day number: 28
   ```

2. **Program Output**:
   ```
   Date: 28/9/2024
   Day order: 7
   Day name: Saturday
   ```