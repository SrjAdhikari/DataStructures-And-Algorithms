# Question : [Expression contains redundant bracket or not - GFG](https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1)

Given a string of balanced expression `str`, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Return `1` if it contains a redundant parenthesis, else `0`.

**Note** : Expression may contain `+ , - , *,` and `/` operators. Given expression is `valid` and there are `no white` spaces present.

### Example 1

```
Input:
exp = ((a+b))
Output:
Yes
Explanation:
((a+b)) can reduced to (a+b).
```

### Example 2

```
Input:
exp = (a+b+(c+d))
Output:
No
Explanation:
(a+b+(c+d)) doesn't have any redundant or multiple
brackets.
```

### Your Task:

You don't have to read input or print anything. Your task is to complete the function `checkRedundancy()` which takes the string `s` as input and returns `1` if it contains redundant parentheses else `0`.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
```

### Constraints

-   `1<=|str|<=10^4`

## Solution

```Cpp
class Solution {
public:
    int checkRedundancy(string s) {
        // Create a stack to store characters (operators and parentheses)
        stack<char> st;

        // Loop through each character in the string 's'
        for (int i = 0; i < s.length(); i++) {
            // If the current character is an opening bracket '('
            // or an operator (+, -, *, /), push it onto the stack.
            if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                st.push(s[i]);
            }
            // If the current character is a closing parenthesis, we need to check
            // for redundancy inside the parentheses.
            else if (s[i] == ')') {
                // Initialize a counter to track how many operators exist between the parentheses
                int operatorCount = 0;

                // Pop from the stack until we encounter the opening parenthesis '('
                // Check if there's at least one operator between the parentheses.
                while (!st.empty() && st.top() != '(') {
                    char currTop = st.top();

                    // Check if the current top element is an operator
                    // If the top of the stack is an operator, increment the operator count.
                    if (currTop == '+' || currTop == '-' || currTop == '*' || currTop == '/') {
                        operatorCount++;
                    }

                    // Pop the current top element from the stack
                    st.pop();
                }

                // Pop the opening parenthesis '(' from the stack
                st.pop();

                // If no operators were found between the parentheses, this means the parentheses
                // were redundant (e.g., "(a)" without any operator). In such a case, return 1.
                if (operatorCount == 0)
                    return 1;
            }
        }

        // If we looped through the entire string and no redundancy was found, return 0.
        return 0;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```
