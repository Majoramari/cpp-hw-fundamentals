# Date Difference Calculator - Problem #17

> ### ☑️ Tasks
> - [x] Solved. - Mon, 30 Sep 2024
> - [x] Code Explanation. - Mon, 30 Sep 2024

## Required Task

The program prompts the user to input two dates and calculates the difference in days between them. It handles month transitions, year transitions, and leap years accurately.

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

This function prompts the user to input a valid month number (1-12) and returns it.

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

This function prompts the user to input a valid day number (1-31) and returns it.

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

### `is_date_before`

```cpp
bool is_date_before(const Date &date1, const Date &date2) {
    return date1.year < date2.year ||
           (date1.year == date2.year && date1.month < date2.month) ||
           (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day);
}
```

This function compares two dates and checks if the first date is earlier than the second date.

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
    if (is_last_day(date)) {
        date.day = 1;

        if (is_last_month(date)) {
            date.month = 1;
            date.year++;
        } else {
            date.month++;
        }
    } else {
        date.day++;
    }

    return date;
}
```

This function takes a `Date` object and increments it by one day. It checks if the current date is the last day of the month and updates the month and year accordingly:
- If the date is the last day of December, it increments the year.
- If the date is the last day of any month, it resets the day to 1 and increments the month.
- If it's not the last day, it simply increments the day.

---

### `calc_diff_days`

```cpp
unsigned short calc_diff_days(Date date1, const Date date2, const bool include_1st = false) {
    unsigned short days = 0;

    while (is_date_before(date1, date2)) {
        days++;
        date1 = increase_date_by_one_day(date1);
    }

    return include_1st ? days + 1 : days;
}
```

This function calculates the difference in days between two dates. It iteratively increases the first date until it reaches the second date, counting the number of days in the process. It can also include the first day in the count if specified.

---

### `main`

```cpp
int main() {
    const Date date1 = read_date();

    cout << endl;

    const Date date2 = read_date();

    cout << "Difference in days: " << calc_diff_days(date1, date2) << endl;
    cout << "Difference in days (including 1st day): " << calc_diff_days(date1, date2, true) << endl;

    return 0;
}
```

In the `main` function, the user is prompted to enter two dates. The program then calculates and outputs the difference in days between the two dates, both with and without including the first day.

---

## Example Usage

1. **User Input**:
   ```
   Please enter a day number: 15
   Please enter a month number: 5
   Please enter a year: 2024
   ```

   ```
   Please enter a day number: 20
   Please enter a month number: 6
   Please enter a year: 2024
   ```

2. **Program Output**:
   ```
   Difference in days: 36
   Difference in days (including 1st day): 37
   ```