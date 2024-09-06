# Question : [Reverse String - (LeetCode : 344)](https://leetcode.com/problems/reverse-string/description/)

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array in-place with `O(1)` extra memory.

### Example 1

```
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

### Example 2

```
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```

### Constraints

-   `1 <= s.length <= 10^5`
-   `s[i]` is a printable ascii character.

## Solution

```Cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        // Declare a stack to store the characters
        stack<char> st;

        // Iterate through the entire string (vector of characters)
        // and push each character onto the stack.
        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);  // Pushing each character onto the stack
        }

        // At the end of this loop, the stack will contain all characters of 's',
        // but in reverse order (since stacks follow the Last In First Out (LIFO) principle).

        // Now, pop characters from the stack (which gives them in reverse order)
        // and overwrite the original string with these characters.
        int i = 0;              // Index to track position in the original vector 's'
        while (!st.empty()) {
            s[i] = st.top();    // Set the i-th character of 's' to the top of the stack
            st.pop();           // Remove the top element from the stack
            i++;                // Move to the next position in the vector
        }
        // When the loop finishes, 's' will have its characters in reverse order.
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
