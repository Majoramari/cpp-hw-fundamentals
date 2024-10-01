# Date Difference Calculator - Problem #19

> ### Tasks
> - [x] Solved. - Tue, 1 Oct 2024
> - [x] Code Explanation. - Tue, 1 Oct 2024

## Required Task

The program calculates the difference in days between two dates provided by the user.

## Code Explanation

### `struct Date`

```cpp
struct Date {
    short year, month, day;
};
```

This structure holds the components of a date: year, month, and day. It is part of the `mdate.h` library.

### `get_system_date`

```cpp
Date get_system_date() {
    const auto now = chrono::system_clock::now();
    const std::time_t t = chrono::system_clock::to_time_t(now);
    const std::tm local_tm = *localtime(&t);

    return Date{
        static_cast<short>(local_tm.tm_year + 1900),
        static_cast<short>(local_tm.tm_mon + 1),
        static_cast<short>(local_tm.tm_mday)
    };
}
```

This function retrieves the current system date using the `chrono` library and returns a `Date` object with the year, month, and day.

### `sum`

```cpp
int sum() {
    return 0;
}
```

The `sum` function is a placeholder function that currently returns 0. It is not used in the main logic.

### `main`

```cpp
int main() {
    const Date date1 = read_date();
    const Date date2 = read_date();

    cout << "Difference in days: " << calc_diff_days(date1, date2, true) << endl;

    return 0;
}
```

In the `main` function, the user is prompted to input two dates. The program then calculates the difference in days between the two dates using the `calc_diff_days` function. The third parameter of `calc_diff_days` is set to `true`, which includes the first day in the count.

## Example Usage

1. **User Input**:
   ```
   Please enter a day number: 1
   Please enter a month number: 1
   Please enter a year: 2023
   
   Please enter a day number: 1
   Please enter a month number: 10
   Please enter a year: 2024
   ```

2. **Output**:
   ```
   Difference in days: 274
   ```

The program calculates that the difference between January 1, 2023, and October 1, 2024, is 274 days (inclusive of the first day). The actual output will vary based on the user input.