# Days Passed in Year - Problem #10

> ### ☑️ Tasks
> - [x] Solved. - Sun, 29 Sep 2024
> - [x] Explanation. - Sun, 29 Sep 2024

## Required Task

The program calculates the number of days passed in a given year up to a specific date (day and month). It takes into account leap years when determining the number of days in February.

### Inputs
- **Year**: A valid year (e.g., 2024) of type `unsigned short`.
- **Month**: A valid month number (1-12) of type `unsigned short`.
- **Day**: A valid day number (1-31) of type `unsigned short`.

### Outputs
- **Days Passed**: The number of days passed since the beginning of the specified year until the given date.

## Functions and Their Responsibilities

### is_leap_year
```cpp
bool is_leap_year(const unsigned short &year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
```
**Purpose**: This function checks if the given year is a leap year. It returns `true` for leap years and `false` otherwise, which is important for calculating the days in February.

**Input**:
- `year`: An unsigned short integer representing the year.

**Output**:
- Returns `true` if the year is a leap year, otherwise returns `false`.

---

### read_month_number
```cpp
unsigned short read_month_number() {
    unsigned short month = 1;
    do {
        if (month < 1 || month > 12)
            cout << endl << "Invalid month number, try again: ";

        cout << "Please enter a month number: ";
        cin >> month;
    } while (month < 1 || month > 12);
    return month;
}
```
**Purpose**: This function prompts the user to enter a valid month number (between 1 and 12) and ensures that the input is correct. It uses a `do-while` loop to handle input validation.

**Input**:
- User input for the month number.

**Output**:
- Returns a valid month number (1-12).

---

### read_day_number
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
**Purpose**: This function prompts the user to enter a valid day number (between 1 and 31), and it ensures that the input is correct using a `do-while` loop for input validation.

**Input**:
- User input for the day number.

**Output**:
- Returns a valid day number (1-31).

---

### get_month_days
```cpp
unsigned short get_month_days(const unsigned short &month, const unsigned short &year) {
    static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return month == 2 && is_leap_year(year) ? 29 : days_in_month[month - 1];
}
```
**Purpose**: This function returns the number of days in the specified month for the given year. It adjusts for leap years when determining the number of days in February.

**Input**:
- `month`: The month number (1-12) of type `unsigned short`.
- `year`: The year as an unsigned short integer.

**Output**:
- Returns the number of days in the specified month.

---

### get_days_passed
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
**Purpose**: This function calculates the total number of days passed since the beginning of the year up to the given date. It sums the days in each month up to the specified month and adds the day of the month.

**Input**:
- `day`: The day number (1-31) of type `unsigned short`.
- `month`: The month number (1-12) of type `unsigned short`.
- `year`: The year as an unsigned short integer.

**Output**:
- Returns the total number of days passed since the start of the year.

---

### main
```cpp
int main() {
    const unsigned short year = utils::get_number("Please enter a year: ");
    const unsigned short month = read_month_number();
    const unsigned short day = read_day_number();

    cout << "Number of days passed since "
         << month << "/" << day << "/" << year << ": "
         << get_days_passed(day, month, year);

    return 0;
}
```
**Purpose**: This is the main function of the program, coordinating all user inputs and calculations. It prompts the user for the year, month, and day, and then calculates the number of days passed in the given year.

**Input**:
- User input for the year, month, and day.

**Output**:
- Outputs the total number of days passed since the start of the year.

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
   Number of days passed since 9/29/2024: 273
   ```