# Date Increment - Problem #15

> ### ☑️ Tasks
> - [x] Solved. - Sun, 29 Sep 2024
> - [x] Code Explanation. - Sun, 29 Sep 2024

## Required Task

The program prompts the user to input a date and calculates the date after incrementing it by one day. It handles month transitions, year transitions, and leap years accurately.

---

## Code Explanation

### `struct Date`

```cpp
struct Date {
	unsigned short year, month, day;
};
```

This structure holds the components of a date: year, month, and day.

---

### `is_leap_year`

```cpp
bool is_leap_year(const unsigned short year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
```

This function checks if a given year is a leap year. It returns `true` if the year is a leap year and `false` otherwise.

---

### `get_month_days`

```cpp
unsigned short get_month_days(const unsigned short month, const unsigned short year) {
	const unsigned short days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (is_leap_year(year) && month == 2)
		return 29;

	return days_in_month[month - 1];
}
```

This function returns the number of days in a specified month of a year. It correctly handles leap years, returning 29 days for February if the year is a leap year.

---

### `read_day_number` and `read_month_number`

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

These functions prompt the user to input valid day and month numbers, ensuring they are within acceptable ranges.

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

This function reads a complete date from the user, retrieving the day, month, and year through the respective input functions, and returns the constructed `Date` struct.

---

### `is_last_day`

```cpp
bool is_last_day(const Date &date) {
	return date.day == get_month_days(date.month, date.year);
}
```

This function checks if the given date is the last day of the month by comparing the day with the total days in that month.

---

### `is_last_month`

```cpp
bool is_last_month(const Date &date) {
	return date.month == 12;
}
```

This function checks if the given date falls in December, which is the last month of the year.

---

### `increase_date_by_one_day`

```cpp
Date increase_date_by_one_day(Date date) {
	if (is_last_day(date) && is_last_month(date))
		++date.year;

	if (is_last_day(date))
		date.day = 1;
	else
		++date.day;

	if (is_last_month(date))
		date.month = 1;
	else
		++date.month;

	return date;
}
```

This function takes a `Date` object and increments it by one day. It checks if the current date is the last day of the month and updates the month and year accordingly:
- If the date is the last day of December, it increments the year.
- If the date is the last day of any month, it resets the day to 1 and increments the month.
- If it's not the last day, it simply increments the day.

---

### `main`

```cpp
int main() {
	const Date date = read_date();

	cout << endl;

	const auto [year, month, day] = increase_date_by_one_day(date);
	cout << "Date after one day: " << day << "/" << month << "/" << year << endl;

	return 0;
}
```

In the `main` function, the user is prompted to enter a date. The program then calls the `increase_date_by_one_day` function to compute the date one day later and outputs the result in the format `day/month/year`.

---

## Example Usage

1. **User Input**:
   ```
   Please enter a year: 2024
   Please enter a month number: 12
   Please enter a day number: 31
   ```

2. **Program Output**:
   ```
   Date after one day: 1/1/2025
   ```