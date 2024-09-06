# Question : [Minimum Add to Make Parentheses Valid - (LeetCode : 921)](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/)

A parentheses string is valid if and only if:

-   It is the empty string,
-   It can be written as `AB` (`A`concatenated with`B`), where `A`and`B` are valid strings, or
-   It can be written as `(A)`, where `A` is a valid string.

You are given a parentheses string `s`. In one move, you can insert a parenthesis at any position of the string.

-   For example, if `s = "()))"`, you can insert an opening parenthesis to be `"(()))"` or a closing parenthesis to be `"())))"`.

Return _the minimum number of moves required to make `s` valid_.

### Example 1

```
Input: s = "())"
Output: 1
```

### Example 2

```
Input: s = "((("
Output: 3
```

### Constraints

-   `1 <= s.length <= 1000`
-   `s[i]` is either `'('` or `')'`

## Solution

```Cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        // Step 1: Create a stack to keep track of open parentheses '('
        stack<char> st;

        // Step 2: Initialize a counter to track the number of unmatched closing parentheses ')'
        int count = 0;

        // Step 3: Iterate through the string 's'
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // If the current character is an open parenthesis '(', push it onto the stack
                st.push(s[i]);
            }
            else { // The current character is a closing parenthesis ')'
                if (st.empty()) {
                    // If the stack is empty, it means there is no matching open parenthesis for this closing parenthesis
                    // Increment the count to reflect that this closing parenthesis is unmatched
                    count++;
                }
                else {
                    // If the stack is not empty, we have a matching open parenthesis for this closing parenthesis
                    // Pop the open parenthesis from the stack to mark it as matched
                    st.pop();
                }
            }
        }

        // Step 4: The total number of additions needed is the sum of:
        // - 'count' (the number of unmatched closing parentheses)
        // - 'st.size()' (the number of unmatched open parentheses left in the stack)
        return count + st.size();
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
