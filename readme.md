# Convert Number of Days to Date - Problem #11

> ### ☑️ Tasks
> - [x] Solved. - Sun, 29 Sep 2024
> - [x] Explanation. - Sun, 29 Sep 2024

## Required Task

The program performs two key operations:
1. **Calculates the number of days passed** in a given year up to a specific date.
2. **Converts a number of days passed** in a year back into a valid date (day, month).

### Inputs
- **Year**: A valid year (e.g., 2024) of type `unsigned short`.
- **Month**: A valid month number (1-12) of type `unsigned short`.
- **Day**: A valid day number (1-31) of type `unsigned short`.
- **Days Passed**: A number representing the days passed since the start of the year.

### Outputs
- **Days Passed**: The number of days passed since the beginning of the specified year until the given date.
- **Converted Date**: A valid date (day, month, year) based on the input number of days passed.

---

## Code Explanation

### `struct Date`
```cpp
struct Date {
    unsigned short year, month, day;
};
```
This structure holds a date with three components: `year`, `month`, and `day`.

---

### `is_leap_year`
```cpp
bool is_leap_year(const unsigned short &year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
```
This function checks if the input year is a leap year. Leap years affect how many days are in February.

---

### `read_month_number` and `read_day_number`
```cpp
unsigned short read_month_number() {
    // Code to read a valid month number between 1 and 12
}
unsigned short read_day_number() {
    // Code to read a valid day number between 1 and 31
}
```
These functions handle input validation for the month and day values, ensuring they are within the valid ranges.

---

### `get_month_days`
```cpp
unsigned short get_month_days(const unsigned short &month, const unsigned short &year) {
    static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return month == 2 && is_leap_year(year) ? 29 : days_in_month[month - 1];
}
```
This function returns the number of days in the given month. If the month is February and the year is a leap year, it returns 29 days; otherwise, it returns the standard number of days for each month.

---

### `get_days_passed`
```cpp
unsigned short get_days_passed(const unsigned short &day, const unsigned short &month, const unsigned short &year) {
    unsigned short days_passed = 0;
    for (int i = 1; i <= month; i++) {
        if (month != i)
            days_passed += get_month_days(i, year);
        else
            days_passed += day;
    }
    return days_passed;
}
```
This function calculates how many days have passed since January 1st of the specified year up to the given date. It sums the days for all previous months and adds the current day.

---

### `get_date_by_days_passed`
```cpp
Date get_date_by_days_passed(unsigned short days_passed, const unsigned short &year) {
    Date date = {year, 1, 1};

    while (days_passed > 0) {
        const unsigned short days_in_month = get_month_days(date.month, date.year);

        if (days_passed > days_in_month) {
            days_passed -= days_in_month;
            ++date.month;
        } else {
            date.day = days_passed;
            break;
        }
    }

    return date;
}
```
This function converts the number of days passed since January 1st into a valid date by iterating through the months of the year and subtracting the days in each month until it reaches the target date.

---

### `main`
```cpp
int main() {
    const unsigned short year = utils::get_number("Please enter a year: ");
    const unsigned short month = read_month_number();
    const unsigned short day = read_day_number();

    const unsigned short days_passed = get_days_passed(day, month, year);

    cout << endl << "Number of days passed since "
         << day << "/" << month << "/" << year << ": "
         << days_passed;

    const Date date = get_date_by_days_passed(days_passed, year);

    cout << endl << endl << "Date for [" << days_passed << "]: "
         << date.day << "/"
         << date.month << "/"
         << date.year
         << endl;

    return 0;
}
```
This is the main function where the program takes the user input (year, month, day), calculates the number of days passed in the year, and then converts that number back into a date. It outputs both the number of days passed and the converted date.

---

## Example Usage

1. **User Input**:
   ```
   Please enter a year: 2024
   Please enter a month number: 9
   Please enter a day number: 29
   ```

2. **Program Output**:
   ```
   Number of days passed since 29/9/2024: 273

   Date for [273]: 29/9/2024
   ```