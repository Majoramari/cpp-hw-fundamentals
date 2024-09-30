# Get Your Age in Days - Problem #18

> ### Tasks
> - [x] Solved. - Tue, 1 Oct 2024
> - [x] Code Explanation. - Tue, 1 Oct 2024

## Required Task

The program calculates the user's age in days, given their birthdate.

## Code Explanation

### `struct Date`

```cpp
struct Date {
    unsigned short year, month, day;
};
```

This structure holds the components of a date: year, month, and day.

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

### `get_system_date`

```cpp
Date get_system_date() {
    const auto now = chrono::system_clock::now();
    const std::time_t t = chrono::system_clock::to_time_t(now);
    // ReSharper disable once CppUseStructuredBinding
    const std::tm local_tm = *localtime(&t);

    return Date{
        static_cast<unsigned short>(local_tm.tm_year + 1900),
        static_cast<unsigned short>(local_tm.tm_mon + 1),
        static_cast<unsigned short>(local_tm.tm_mday)
    };
}
```

This function returns the current system date.

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

### `main`

```cpp
int main() {
    const Date birthdate = read_date();
    const Date current_date = get_system_date();

    cout << "You are " << calc_diff_days(birthdate, current_date) << " days old." << endl;

    return 0;
}
```

In the `main` function, the user is prompted to enter their birthdate. The program then calculates and outputs the user's age in days, given their birthdate and the current system date.

## Example Usage

1. **User Input**:
   ```
   Please enter a day number: 15
   Please enter a month number: 5
   Please enter a year: 1990
   ```

2. **Output**:
   ```
   You are 12345 days old.
   ```

Note: The actual output will depend on the current system date.