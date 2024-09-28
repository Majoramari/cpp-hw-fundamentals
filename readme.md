# Leap Year Checker Function

## Overview

The `is_leap_year` function determines whether a given year is a leap year or not based on specific criteria.

### Purpose
The primary goal of the `is_leap_year` function is to evaluate any integer year and return a boolean indicating whether it is a leap year. For example:
- `2020` is a leap year.
- `1900` is not a leap year.
- `2000` is a leap year.

### Leap Year Criteria
A year is considered a leap year if it satisfies the following conditions:

1. **Divisibility by 4**: The year must be divisible by `4`. This means when you divide the year by `4`, there should be no remainder. For example:
    - `2020 ÷ 4 = 505` (no remainder, so `2020` is a candidate for a leap year)
    - `2019 ÷ 4 = 504.75` (has a remainder, so `2019` is **not** a candidate)

2. **Exclusion by 100**: If a year is divisible by `100`, it is **not** considered a leap year unless it also satisfies the next condition. For example:
    - `1900 ÷ 100 = 19` (no remainder, so `1900` is **not** a leap year)
    - `2100 ÷ 100 = 21` (also not a leap year)

3. **Inclusion by 400**: If a year is divisible by `400`, it is considered a leap year, even if it is also divisible by `100`. For example:
    - `2000 ÷ 400 = 5` (no remainder, so `2000` is a leap year)
    - `2400 ÷ 400 = 6` (also a leap year)

### Thought Process and Structure

### Step 1: Implementing the Leap Year Logic
The logic for determining a leap year is concise and can be expressed using a single boolean expression:
```cpp
return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
```
This expression checks:
- If the year is divisible by `4` and **not** by `100`, or
- If the year is divisible by `400`.

### Step 2: Main Function Usage
In the `main` function, we first prompt the user to enter a year. This is achieved using `utils::get_number`, which presumably handles user input.

### Step 3: Displaying the Result
After obtaining the year, we call `is_leap_year(year)` to evaluate whether it is a leap year. We then display a message based on the result:
```cpp
cout << year << (is_leap_year(year) ? " is a Leap Year" : " is not a Leap Year");
```
This line utilizes the ternary operator to choose between two string outputs, making the code concise and readable.

## Example Execution
When the program runs:
1. It prompts the user with `"Please enter a year: "`.
2. If the user enters `2020`, the output will be:
   ```
   2020 is a Leap Year
   ```
3. If the user enters `1900`, the output will be:
   ```
   1900 is not a Leap Year
   ```