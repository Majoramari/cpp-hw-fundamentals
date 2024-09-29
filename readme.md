# Date End Check - Problem #15

> ### ☑️ Tasks
> - [x] Solved. - Sun, 29 Sep 2024
> - [x] Code Explanation. - Sun, 29 Sep 2024

## Required Task

The program asks the user for a date and determines whether the given date is the last day of the month and whether it is the last month of the year. It provides a simple verification by checking the day and month against the corresponding values.

---

## Code Explanation

### `struct Date`

```cpp
struct Date {
	unsigned short year, month, day;
};
```

This structure represents a date with three components: `year`, `month`, and `day`.

---

### `read_month_number`

```cpp
unsigned short read_month_number() {
	unsigned short month = 1;
	do {
		if (month < 1 || month > 12)
			cout << endl << "Invalid month number, try again: " << endl;

		cout << "Please enter a month number: ";
		cin >> month;
	} while (month < 1 || month > 12);
	return month;
}
```

This function prompts the user to enter a valid month (1–12). It ensures that the input is within the valid range and returns the month number.

---

### `read_day_number`

```cpp
unsigned short read_day_number() {
	unsigned short day = 1;
	do {
		if (day < 1 || day > 31)
			cout << endl << "Invalid day number, try again: ";

		cout << "Please enter a day number: ";
		cin >> day;
	} while (day < 1 || day > 31);
	return day;
}
```

This function prompts the user to enter a valid day (1–31). It ensures that the input is within the valid range and returns the day number.

---

### `is_leap_year`

```cpp
bool is_leap_year(unsigned short year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
```

This function checks if a year is a leap year, which is important for determining the number of days in February.

---

### `get_month_days`

```cpp
unsigned short get_month_days(unsigned short month, unsigned short year) {
	unsigned short days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (is_leap_year(year) && month == 2)
		return 29;

	return days_in_month[month - 1];
}
```

This function returns the number of days in a given month, accounting for leap years if the month is February.

---

### `get_month_name`

```cpp
string get_month_name(const unsigned short month) {
	string months[] = {
		"",
		"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November",
		"December"
	};
	return months[month];
}
```

This function returns the name of the month based on its number (1–12), using an array of month names.

---

### `read_date`

```cpp
Date read_date() {
	const unsigned short day = read_day_number();
	const unsigned short month = read_month_number();
	const unsigned short year = utils::get_number("Please enter a year: ");
	return {year, month, day};
}
```

This function reads a valid date from the user, returning it as a `Date` struct.

---

### `is_equal`

```cpp
bool is_equal(const Date &date1, const Date &date2) {
	return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}
```

This function checks whether two dates are equal by comparing their `year`, `month`, and `day` fields.

---

### `is_last_day`

```cpp
bool is_last_day(const Date &date) {
	return date.day == get_month_days(date.month, date.year);
}
```

This function determines whether the specified date is the last day of the month by comparing the day against the total number of days in that month.

---

### `is_last_month`

```cpp
bool is_last_month(const Date &date) {
	return date.month == 12;
}
```

This function checks if the month of the specified date is December, indicating it is the last month of the year.

---

### `main`

```cpp
int main() {
	const Date date = read_date(); // Read the date

	cout << endl;

	if (is_last_day(date))
		cout << "Yes, " << date.day << " is last day in " << get_month_name(date.month) << endl;
	else
		cout << "No, " << date.day << " is not last day in " << get_month_name(date.month) << endl;

	if (is_last_month(date))
		cout << "Yes, " << date.month << " is last month in year " << date.year << endl;
	else
		cout << "No, " << date.month << " is not last month in year " << date.year << endl;

	return 0;
}
```

In the `main` function:
1. The program reads a date using `read_date`.
2. It checks if that date is the last day of the month and whether it is the last month of the year.
3. Results are printed to the user.

---

## Example Usage

1. **User Input**:
   ```
   Please enter a day number: 30
   Please enter a month number: 9
   Please enter a year: 2024
   ```

2. **Program Output**:
   ```
   Yes, 30 is last day in September
   No, 9 is not last month in year 2024
   ```

---

## Notes

- The program does not check for invalid date ranges (e.g., February 30).
- Only basic validation (days between 1-31 and months between 1-12) is performed.
