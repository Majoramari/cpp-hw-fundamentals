# Date Equality Check - Problem #14

> ### ☑️ Tasks
> - [x] Solved. - Sun, 29 Sep 2024
> - [x] Code Explanation. - Sun, 29 Sep 2024

## Required Task

The program asks the user to input two dates and compares them to check if they are equal. It verifies whether both the day, month, and year of the two dates match.

---

## Code Explanation

### `struct Date`

```cpp
struct Date {
	unsigned short year, month, day;
};
```

This structure holds the date components: `year`, `month`, and `day`.

---

### `read_month_number` and `read_day_number`

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

These functions prompt the user for a valid day (1–31) and month (1–12). The values are validated to ensure they are within valid ranges.

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

This function reads a valid date by calling `read_day_number`, `read_month_number`, and asking for the year. It returns a `Date` struct containing the user's input.

---

### `is_equal`

```cpp
bool is_equal(const Date &date1, const Date &date2) {
	return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}
```

This function checks if two dates are equal by comparing their `year`, `month`, and `day` fields. It returns `true` if both dates are the same, and `false` otherwise.

---

### `main`

```cpp
int main() {
	const Date date1 = read_date(); // Read the first date

	cout << endl;

	const Date date2 = read_date(); // Read the second date

	cout << endl << date1.year << "/" << date1.month << "/" << date1.day
			<< " is " << (is_equal(date1, date2) ? "equal" : "NOT equal") << " "
			<< date2.year << "/" << date2.month << "/" << date2.day << endl;

	return 0;
}
```

In the `main` function:
1. The program reads two dates using `read_date`.
2. It calls `is_equal` to compare the two dates.
3. The result is displayed to the user, indicating whether the two dates are equal or not.

---

## Example Usage

1. **User Input**:
   ```
   Please enter a day number: 15
   Please enter a month number: 8
   Please enter a year: 2023

   Please enter a day number: 15
   Please enter a month number: 8
   Please enter a year: 2023
   ```

2. **Program Output**:
   ```
   2023/8/15 is equal 2023/8/15
   ```

---

## Notes

- The program does not account for invalid date ranges (e.g., February 30).
- Only basic validation (days between 1-31 and months between 1-12) is performed.
