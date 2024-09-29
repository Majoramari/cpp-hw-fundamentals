# Date Addition - Problem #12

> ### ☑️ Tasks
> - [x] Solved. - Sun, 29 Sep 2024
> - [x] Code Explanation. - Sun, 29 Sep 2024

## Required Task

The program asks the user for a date and a number of days to add. It calculates the new date by adding the specified
number of days to the input date, correctly handling month and year transitions, as well as leap years.

---

## Code Explanation

### `struct Date`

```cpp
struct Date {
	unsigned short year, month, day;
};
```

This structure holds the date components: year, month, and day.

---

### `is_leap_year`

```cpp
bool is_leap_year(const unsigned short &year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
```

This function checks if a year is a leap year. It is used to determine if February should have 29 days.

---

### `read_month_number` and `read_day_number`

```cpp
unsigned short read_month_number() {
	unsigned short month = 1;
	do {
		if (month < 1 || month > 12)
			cout << endl << "Invalid month number, try again: " << endl;;

		cout << "Please enter a month number: ";
		cin >> month;
	} while (month < 1 || month > 12);
	return month;
}
```
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

These functions are used to read valid day and month numbers from the user, ensuring they are within valid ranges.

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

This function reads a valid date from the user by prompting for the day, month, and year. The date is returned as a
`Date` struct.

---

### `get_month_days`

```cpp
unsigned short get_month_days(const unsigned short &month, const unsigned short &year) {
	static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return month == 2 && is_leap_year(year) ? 29 : days_in_month[month - 1];
}
```

This function returns the number of days in a specific month. It takes into account leap years, ensuring February has 29
days if the year is a leap year.

---

### `get_days_passed`

```cpp
unsigned short get_days_passed(const Date date) {
	unsigned short days_passed = 0;
	for (int i = 1; i <= date.month; i++) {
		if (date.month != i)
			days_passed += get_month_days(i, date.year);
		else
			days_passed += date.day;
	}
	return days_passed;
}
```

This function calculates the number of days passed from the start of the year to the specified date. It adds up the days
from previous months and the days from the current month.

---

### `add_days`

```cpp
Date add_days(const unsigned short days_to_add, Date date) {
	unsigned short remaining_days = days_to_add + get_days_passed(date);
	date.month = 1;

	while (remaining_days > 0) {
		const unsigned short month_days = get_month_days(date.month, date.year);

		if (remaining_days > month_days) {
			remaining_days -= month_days;
			date.month++;

			if (date.month > 12) {
				date.month = 1;
				date.year++;
			}
		} else {
			date.day = remaining_days;
			break;
		}
	}

	return date;
}
```

This function takes a number of days to add and the current date, and calculates the resulting date after the addition.
It handles:

- Month and year transitions (i.e., when adding days causes the date to cross into the next month or year).
- Leap years, ensuring February has 29 days when necessary.

It works by first calculating the total days passed since the start of the year, then iterating through each month,
subtracting the days from each month until the remaining days fit within a month, and finally setting the day and
adjusting the month and year as needed.

---

### `main`

```cpp
int main() {
	Date date = read_date(); // Read the initial date
	const unsigned short days_to_add = utils::get_number("How many days you want to add: "); // Read days to add

	date = add_days(days_to_add, date); // Add the days to the date
	cout << "Days after adding [" << days_to_add << "] days: "
			<< date.day << "/"
			<< date.month << "/"
			<< date.year << endl; // Output the new date

	return 0;
}
```

The `main` function reads the initial date and the number of days the user wants to add. It calls `add_days` to
calculate the resulting date and prints the new date.

---

## Example Usage

1. **User Input**:
   ```
   Please enter a year: 2024
   Please enter a month number: 9
   Please enter a day number: 29
   How many days you want to add: 60
   ```

2. **Program Output**:
   ```
   Days after adding [60] days: 28/11/2024
   ```