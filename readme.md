# Verbalize Number Function -  Problem #1

## Overview

The `verbalize_number` function takes an integer and returns its corresponding English verbalization.

### Purpose
The goal is to convert any integer into its English word representation. For example:
- `15` becomes `"Fifteen"`
- `342` becomes `"Three Hundred Forty Two"`
- `1050000` becomes `"One Million Fifty Thousand"`

## Thought Process and Structure

### Step 1: Base Case for `0`
We start with a base case for the number `0`. If the input is `0`, the function directly returns `"Zero"` without any further processing:
```cpp
if (number == 0)
    return "Zero";
```

### Step 2: Arrays for Word Lookup
To verbalize small numbers, we pre-define two arrays:
1. `under_twenty`: This contains the words for numbers from `1` to `19`. We include an empty string for `0` (since we handle `0` separately).
2. `tens`: This contains words for multiples of ten starting from `20`.

These arrays allow efficient lookup for numbers below 100.

### Step 3: Handling Numbers Below `20`
For numbers between `1` and `19`, we use direct indexing of the `under_twenty` array:
```cpp
if (number < 20) {
    result = under_twenty[number];
}
```
This case is the simplest as no further processing is needed.

### Step 4: Handling Numbers Between `20` and `99`
For numbers between `20` and `99`, the logic is:
1. Get the tens place from the `tens` array.
2. If the number has a non-zero units place, recursively call `verbalize_number` for the units part and append the result.

For example, for `75`, it splits into `Seventy` + `Five`:
```cpp
else if (number < 100) {
    result = tens[number / 10];
    if (number % 10 != 0)
        result += " " + verbalize_number(number % 10);
}
```

### Step 5: Handling Numbers Between `100` and `999`
For numbers in the hundreds, the logic is:
1. Determine the hundreds part using `under_twenty`.
2. Recursively call `verbalize_number` for the remainder.

For example, for `375`, the hundreds part is `"Three Hundred"`, and we call the function recursively to verbalize the remainder, `"Seventy-Five"`:
```cpp
else if (number < 1000) {
    result = under_twenty[number / 100] + " Hundred";
    if (number % 100 != 0)
        result += " " + verbalize_number(number % 100);
}
```

### Step 6: Handling Thousands and Above
The same recursive pattern applies for larger numbers:
- For thousands: `"One Thousand"`, `"Fifty Thousand"`
- For millions: `"One Million"`, `"Three Hundred Million"`
- For billions: `"One Billion"`, `"Five Billion"`

The pattern for each of these ranges involves:
1. Dividing the number by a large power of 10 (like 1000 for thousands, 1,000,000 for millions).
2. Recursively calling `verbalize_number` to handle the remainder:
```cpp
else if (number < 1000000) {
    result = verbalize_number(number / 1000) + " Thousand";
    if (number % 1000 != 0)
        result += " " + verbalize_number(number % 1000);
}
```

### Step 7: Final Concatenation
For all recursive calls, we concatenate the parts properly using a space between the segments. This ensures that the result reads naturally like `"One Hundred Twenty Three"` instead of `"OneHundredTwentyThree"`.

## Main Function Usage
The `main` function demonstrates usage by getting a number using a `utils::get_number` function and printing the result of `verbalize_number`.