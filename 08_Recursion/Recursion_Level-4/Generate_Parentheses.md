# Question : [Generate Parentheses - (LeetCode : 22)](https://leetcode.com/problems/generate-parentheses/description/)

Given `n` pairs of parentheses, write a function to *generate all combinations of well-formed parentheses*.

### Example 1
```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

### Example 2
```
Input: n = 1
Output: ["()"]
```

### Constraints

-   `1 <= n <= 8`

## Solution

```Cpp

class Solution {
public:
    void parenthesis(int n, int left, int right, vector<string>& ans, string& temp) {
        // Base case: If the current string has reached the length of 2 * n
        if(left + right == 2 * n) {
            // Add the current valid combination to the answer list
            ans.push_back(temp);
            return;
        }

        // If the number of left parentheses used is less than n
        if(left < n) {
            // Add a left parenthesis to the current string
            temp.push_back('(');
            // Recur with the updated string and counts
            parenthesis(n, left + 1, right, ans, temp);
            // Backtrack: Remove the last added left parenthesis
            temp.pop_back();
        }

        // If the number of right parentheses used is less than the number of left parentheses
        if(right < left) {
            // Add a right parenthesis to the current string
            temp.push_back(')');
            // Recur with the updated string and counts
            parenthesis(n, left, right + 1, ans, temp);
            // Backtrack: Remove the last added right parenthesis
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int left = 0;
        int right = 0;
        vector<string> ans;
        string temp = "";
        parenthesis(n, left, right, ans, temp);
        return ans;        
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```