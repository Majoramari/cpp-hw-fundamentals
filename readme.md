# Year Calendar - Problem #9

> ### ☑️ Tasks
> - [x] Solved. - Sun, 29 Sep 2024
> - [x] Explanation. - Sun, 29 Sep 2024

## Required Task

The program generates a calendar for a specific year, displaying each month in a user-friendly format. It correctly accounts for leap years and presents the entire year at a glance.

### Inputs
- **Year**: A valid year (e.g., 2024) of type `unsigned short`.

### Outputs
- **Year**: The specified year displayed at the top of the calendar.
- **Months**: The complete calendar for each month of the specified year, formatted into weeks starting from Sunday.

## Functions and Their Responsibilities

### is_leap_year
```cpp
bool is_leap_year(const unsigned short int &year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
```
**Purpose**: This function checks if the given year is a leap year. It returns `true` for leap years and `false` otherwise, which is critical for determining the number of days in February.

**Input**:
- `year`: An unsigned short integer representing the year.

**Output**:
- Returns `true` if the year is a leap year, otherwise returns `false`.

---

### read_month_number
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
**Purpose**: This function prompts the user to enter a valid month number (between 1 and 12) and ensures the input is correct. It uses a `do-while` loop for input validation.

**Input**:
- User input for the month number.

**Output**:
- Returns a valid month number (1-12).

---

### get_month_days
```cpp
unsigned short get_month_days(const unsigned short int &month, const unsigned short int &year) {
    static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return month == 2 && is_leap_year(year) ? 29 : days_in_month[month - 1];
}
```
**Purpose**: This function returns the number of days in the specified month of the specified year. It adjusts for leap years when determining the days in February.

**Input**:
- `month`: The month number (1-12) of type `unsigned short`.
- `year`: The year as an unsigned short integer.

**Output**:
- Returns the number of days in the specified month.

---

### calc_day_order
```cpp
unsigned short calc_day_order(const unsigned short &day, const unsigned short &month, const unsigned short &year) {
    const unsigned short a = (14 - month) / 12;
    const unsigned short y = year - a;
    const unsigned short m = month + 12 * a - 2;

    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}
```
**Purpose**: This function calculates the day of the week for the first day of the specified month using a formula, returning a number between 0 (Sunday) and 6 (Saturday).

**Input**:
- `day`: The day of the month (1) of type `unsigned short`.
- `month`: The month number (1-12) of type `unsigned short`.
- `year`: The year as an unsigned short integer.

**Output**:
- Returns an unsigned short representing the day of the week (0-6).

---

### get_shortmonth_name
```cpp
string get_shortmonth_name(const unsigned short &month) {
    string months_of_year[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    return months_of_year[month];
}
```
**Purpose**: This function retrieves the abbreviated name of the month corresponding to the input month number.

**Input**:
- `month`: The month number (1-12) of type `unsigned short`.

**Output**:
- Returns a string representing the abbreviated name of the month.

---

### print_month_calendar
```cpp
void print_month_calendar(const unsigned short &month, const unsigned short &year) {
    const unsigned short number_of_days = get_month_days(month, year);
    const unsigned short first_day_of_month = calc_day_order(1, month, year);

    cout << endl << " ===============[" << get_shortmonth_name(month) << "]=============== " << endl;
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

    unsigned short i;
    for (i = 0; i < first_day_of_month; i++)
        cout << "     ";

    for (int j = 1; j <= number_of_days; j++) {
        cout << setw(5) << j;

        if (++i == 7) {
            i = 0;
            cout << endl;
        }
    }

    cout << " =================================== " << endl;
}
```
**Purpose**: This function prints the formatted calendar for the specified month and year. It lays out the days in a grid format, starting with the correct day of the week.

**Input**:
- `month`: The month number (1-12) of type `unsigned short`.
- `year`: The year as an unsigned short integer.

**Output**:
- Prints the month calendar to the console.

---

### print_year_calendar
```cpp
void print_year_calendar(const unsigned short &year) {
    cout << " =================================== " << endl;
    cout << "\t\t\tCalendar - " << year << endl;
    cout <<  " =================================== " << endl;

    for (int i = 1; i <= 12; i++)
        print_month_calendar(i, year);
}
```
**Purpose**: This function prints the complete calendar for the specified year by calling the `print_month_calendar` function for each month.

**Input**:
- `year`: The year as an unsigned short integer.

**Output**:
- Prints the complete year calendar to the console.

---

### main
```cpp
int main() {
    const unsigned short year = utils::get_number("Please enter a year: ");

    print_year_calendar(year);
    return 0;
}
```
**Purpose**: This is the main function of the program, coordinating all user inputs and calculations. It prompts for the year and finally prints the calendar for the entire year.

**Input**:
- User input for the year.

**Output**:
- Outputs the calendar for the specified year.

---

## Example Usage

1. **User Input**:
```
Please enter a year: 2024
```

2. **Program Output**:
```
 =================================== 
	   Calendar - 2024
 =================================== 

 ===============[Jan]=============== 
  Sun  Mon  Tue  Wed  Thu  Fri  Sat
                   1    2    3    4
    5    6    7    8    9   10   11
   12   13   14   15   16   17   18
   19   20   21   22   23   24   25
   26   27   28   29   30   31
 =================================== 

 ===============[Feb]=============== 
  Sun  Mon  Tue  Wed  Thu  Fri  Sat
                                   1
    2    3    4    5    6    7    8
    9   10   11   12   13   14   15
   16   17   18   19   20   21   22
   23   24   25   26   27   28   29
 =================================== 

 (continued for all months...)
```