# Question : [Backspace String Compare - (LeetCode : 844)](https://leetcode.com/problems/backspace-string-compare/description/)

Given two strings `s` and `t`, return `true` _if they are equal when both are typed into empty text editors_. `'#'` means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

### Example 1

```
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
```

### Example 2

```
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
```

### Example 3

```
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
```

### Constraints

-   `1 <= s.length, t.length <= 200`
-   `s` and `t` only contain lowercase letters and `'#'` characters.

**Follow up**: Can you solve it in `O(n)` time and `O(1)` space?

## Solution

```Cpp
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // Step 1: Create two stacks to process the strings 's' and 't'
        stack<char> st1;  // Stack to process string 's'
        stack<char> st2;  // Stack to process string 't'

        // Step 2: Process each character of string 's'
        for (int i = 0; i < s.size(); i++) {
            // If the current character is not a backspace '#', push it onto stack st1
            if (s[i] != '#') {
                st1.push(s[i]);
            }
            // If the current character is a backspace '#', pop from stack st1 if it's not empty
            else {
                if (!st1.empty()) {
                    st1.pop();  // Remove the most recent character (if any) from stack st1
                }
            }
        }

        // Step 3: Process each character of string 't'
        for (int i = 0; i < t.size(); i++) {
            // If the current character is not a backspace '#', push it onto stack st2
            if (t[i] != '#') {
                st2.push(t[i]);
            }
            // If the current character is a backspace '#', pop from stack st2 if it's not empty
            else {
                if (!st2.empty()) {
                    st2.pop();  // Remove the most recent character (if any) from stack st2
                }
            }
        }

        // Step 4: Compare the two stacks to determine if the final processed strings are identical
        // If the stacks are equal, it means the processed strings are identical, so return true
        // If the stacks are not equal, return false
        return (st1 == st2);
    }
};

Time Complexity = O(n + m)
Space Complexity = O(n * m)
```
