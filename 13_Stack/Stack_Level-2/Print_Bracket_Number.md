# Question : [Print Bracket Number - GFG](https://www.geeksforgeeks.org/problems/print-bracket-number4058/1)

Given a string `str`, the task is to find the bracket numbers, i.e., for each bracket in str, return `i` if the bracket is the `ith` opening or closing bracket to appear in the string.

### Example 1

```
Input:  str = "(aa(bdc))p(dee)"
Output: 1 2 2 1 3 3
Explanation: The highlighted brackets in
the given string (aa(bdc))p(dee) are
assigned the numbers as: 1 2 2 1 3 3.
```

### Example 2

```
Input:  str = "(((()("
Output: 1 2 3 4 4 5
Explanation: The highlighted brackets in
the given string (((()( are assigned
the numbers as: 1 2 3 4 4 5
```

```
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)
```

### Constraints

-   `1 <= |str| <= 10^5`
-   `str` contains lowercase English alphabets, and `'('`, `')'` characters
-   At any index, the number of opening brackets is greater than or equal to closing brackets

## Solution

```Cpp
class Solution {
public:
    vector<int> bracketNumbers(string str) {
        // Step 1: Initialize a counter to assign unique numbers to each opening parenthesis
        int count = 0;

        // Step 2: Create a stack to keep track of the opening parenthesis numbers
        stack<int> st;

        // Step 3: Create a vector to store the bracket numbers corresponding to the parentheses in the input string
        vector<int> ans;

        // Step 4: Iterate through the input string 'str'
        for (int i = 0; i < str.size(); i++) {
            // If the current character is an opening parenthesis '('
            if (str[i] == '(') {
                count++;                // Increment the counter
                st.push(count);         // Push the current count onto the stack
                ans.push_back(count);   // Store the current count in the result vector
            }
            // If the current character is a closing parenthesis ')'
            else if (str[i] == ')') {
                ans.push_back(st.top()); // Retrieve the number associated with the matching opening parenthesis
                st.pop();                // Pop the stack to remove the matched opening parenthesis
            }
        }

        // Step 5: Return the result vector containing bracket numbers
        return ans;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
