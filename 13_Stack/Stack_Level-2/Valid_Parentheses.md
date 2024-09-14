# Question : [Valid Parentheses - (LeetCode : 20)](https://leetcode.com/problems/valid-parentheses/description/)

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `]'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

### Example 1

```
Input: s = "()"
Output: true
```

### Example 2

```
Input: s = "()[]{}"
Output: true
```

### Example 3

```
Input: s = "(]"
Output: false
```

### Example 4

```
Input: s = "([])"
Output: true
```

### Constraints

-   `1 <= s.length <= 10^4`
-   `s` consists of parentheses only `'()[]{}'`.

## Solution 1

```Cpp
class Solution {
public:
    bool isValid(string s) {
        // Step 1: Create a stack to track opening parentheses
        stack<char> st;

        // Step 2: Iterate through the string 's'
        for (int i = 0; i < s.size(); i++) {
            // Step 3: If the current character is an opening bracket, push it onto the stack
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            // Step 4: If the current character is a closing bracket, check if it matches the top of the stack
            else {
                // If the stack is empty, there is no matching opening bracket
                if (st.empty()) {
                    return false;       // Early return, invalid string
                }
                // Step 5: Check if the closing bracket matches the top of the stack
                if (s[i] == ')') {
                    // Check if the top of the stack is the corresponding opening bracket '('
                    if (st.top() != '(') {
                        return false;   // Mismatched parenthesis
                    } else {
                        st.pop();       // Pop the matching opening bracket from the stack
                    }
                }
                else if (s[i] == '}') {
                    // Check if the top of the stack is the corresponding opening bracket '{'
                    if (st.top() != '{') {
                        return false;   // Mismatched curly brace
                    } else {
                        st.pop();       // Pop the matching opening bracket
                    }
                }
                else { // The current character is ']'
                    // Check if the top of the stack is the corresponding opening bracket '['
                    if (st.top() != '[') {
                        return false;   // Mismatched square bracket
                    } else {
                        st.pop();       // Pop the matching opening bracket
                    }
                }
            }
        }

        // Step 6: If the stack is empty, all brackets were matched and closed properly, so the string is valid
        return st.empty();
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

## Solution 2

```Cpp
class Solution {
public:
    bool isValid(string s) {
        // Step 1: Create a stack to keep track of opening parentheses
        stack<char> st;

        // Step 2: Iterate through each character in the string 's'
        for (int i = 0; i < s.size(); i++) {
            // If the current character is an opening parenthesis, push it onto the stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            // If the current character is a closing parenthesis
            else {
                // Check if the stack is not empty
                if (!st.empty()) {
                    // If the current closing parenthesis matches the top opening parenthesis, Pop the matching opening parenthesis
                    if (s[i] == ')' && st.top() == '(') {
                        st.pop();
                    }
                    // If the current closing parenthesis matches the top opening parenthesis, Pop the matching opening parenthesis
                    else if (s[i] == ']' && st.top() == '[') {
                        st.pop();
                    }
                    // If the current closing parenthesis matches the top opening parenthesis, Pop the matching opening parenthesis
                    else if (s[i] == '}' && st.top() == '{') {
                        st.pop();
                    }
                    // If the closing parenthesis does not match the top opening parenthesis, return false
                    else {
                        return false;
                    }
                }
                else {
                    // If the stack is empty but we encountered a closing parenthesis, return false
                    return false;
                }
            }
        }

        // Step 3: If the stack is empty at the end, all parentheses were matched correctly; otherwise, return false
        return st.empty();
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
