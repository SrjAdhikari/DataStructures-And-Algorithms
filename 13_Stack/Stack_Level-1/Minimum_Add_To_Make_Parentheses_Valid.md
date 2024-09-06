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

## Solution 1

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

## Solution 2

```Cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBracketCount = 0;   // Keeps track of the number of unmatched open brackets '('
        int count = 0;              // Keeps track of the number of unmatched close brackets ')'

        // Iterate through each character in the string 's'
        for (int i = 0; i < s.size(); i++) {
            // Check if the character is ')'
            if (s[i] == '(') {
                // This indicates the start of a new open bracket that needs to be matched.
                // Increase `openBracketCount` to account for this unmatched open bracket.
                openBracketCount++;
            }
            // Else the character is ')'
            else {
                // Check if there are unmatched open brackets to pair with the current close bracket
                if (openBracketCount == 0) {
                    // There are no unmatched open brackets available to pair with this close bracket,
                    // so this close bracket is considered unmatched. Increment `count` to reflect this.
                    count++;
                }
                // If `openBracketCount` is greater than 0
                else {
                    // There are unmatched open brackets available. This close bracket can pair with one of them,
                    // so decrease `openBracketCount` by 1 to reflect this matching.
                    openBracketCount--;
                }
            }
        }

        // The total number of additions needed to balance the string is the sum of:
        // 1. `openBracketCount` will hold the number of unmatched open brackets.
        // 2. `count` will hold the number of unmatched close brackets.
        return count + openBracketCount;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
