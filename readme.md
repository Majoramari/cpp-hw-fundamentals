## remove_punctuation function

### **Goal**:
The function removes punctuation from a given string and returns a new string without punctuation.

### **Step-by-Step Thought Process**:

- **Input and Output**:
    - The function takes a `string` (text) as input and returns a new `string` with all punctuation characters removed.

- **Start with a basic idea**:
    - You need to check each character in the input string and decide if it’s punctuation.
    - If it’s not punctuation, you add it to the result string.

- **Create an empty string**:
    - You'll need an empty `result` string that will store the final version of the input string, but without punctuation.

- **Loop through the input string**:
    - You should examine each character in the input string one by one. A `for` loop works perfectly for this.

- **Check each character**:
    - For each character, check if it’s a punctuation mark. In C++, the function `ispunct(c)` helps you determine if a character is a punctuation symbol.

- **Add non-punctuation characters**:
    - If the character is not punctuation (i.e., `ispunct(c)` returns `false`), you add it to the `result` string.

- **Return the result**:
    - Once the loop has finished checking all characters, return the `result` string.
  
```cpp
string remove_punctuation(const string &str) {
	string result;
	for (const char c: str) {
		if (!ispunct(c))
			result += c;
	}
	return result;
}
```
