# Question : [Minimum ASCII Delete Sum for Two Strings - (LeetCode : 712)](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/)

Given two strings `s1` and `s2`, return *the lowest **ASCII** sum of deleted characters to make two strings equal*.

### Example 1

```
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
```

### Example 2

```
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
```

### Constraints

- `1 <= s1.length, s2.length <= 1000`
- `s1` and `s2` consist of lowercase English letters.

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(string s1, string s2, int i, int j) {
        // Initialize the minimum ASCII delete sum for this state.
        int minSum = 0;

        // Base case: If we reach the end of either string, add the remaining ASCII values.
        if (i == s1.size() || j == s2.size()) {
            for (int index = i; index < s1.size(); index++) 
                // Add remaining characters from s1.
                minSum += s1[index];
            
            for (int index = j; index < s2.size(); index++) 
                // Add remaining characters from s2.
                minSum += s2[index];
        }

        // Case 1: when characters at the current indices are equal.
        else if (s1[i] == s2[j]) {
            // Move to the next characters in both strings.
            minSum = recursion(s1, s2, i + 1, j + 1);
        }
        // Case 2: when characters at the current indices are different.
        else {
            // Cost of deleting the current character from s1.
            int s1Sum = s1[i] + recursion(s1, s2, i + 1, j);

            // Cost of deleting the current character from s2.
            int s2Sum = s2[j] + recursion(s1, s2, i, j + 1);

            // Choose the minimum of the two costs.
            minSum = min(s1Sum, s2Sum);
        }

        // Return the calculated minimum delete sum.
        return minSum;
    }

    int minimumDeleteSum(string s1, string s2) {
        return recursion(s1, s2, 0, 0);
    }
};

Time Complexity = O(2^(m+n)) 
Space Complexity = O(m + n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        // Initialize the minimum ASCII delete sum for this state.
        int minSum = 0;

        // Base case: If we reach the end of either string, add the remaining ASCII values.
        if (i == s1.size() || j == s2.size()) {
            for (int index = i; index < s1.size(); index++) 
                // Add remaining characters from s1.
                minSum += s1[index];
            
            for (int index = j; index < s2.size(); index++) 
                // Add remaining characters from s2.
                minSum += s2[index];
        }

        // Check if the result for this state has already been computed, if yes, return it.
        if (dp[i][j] != -1)
            return dp[i][j];

        // Case 1: when characters at the current indices are equal.
        else if (s1[i] == s2[j]) {
            // Move to the next characters in both strings.
            minSum = memoization(s1, s2, i + 1, j + 1);
        }
        // Case 2: when characters at the current indices are different.
        else {
            // Cost of deleting the current character from s1.
            int s1Sum = s1[i] + memoization(s1, s2, i + 1, j, dp);

            // Cost of deleting the current character from s2.
            int s2Sum = s2[j] + memoization(s1, s2, i, j + 1, dp);

            // Choose the minimum of the two costs.
            minSum = min(s1Sum, s2Sum);
        }

        // Store the computed result in the dp array for reuse, and return it.
        return dp[i][j] = minSum;
    }

    int minimumDeleteSum(string s1, string s2) {
        int row = s1.size();
        int col = s2.size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1));
        return memoization(s1, s2, 0, 0, dp);
    }
};

Time Complexity = O(m * n)
Space Complexity = O(m * n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(string s1, string s2) {
        int row = s1.size();    // Number of rows (length of s1).
        int col = s2.size();    // Number of columns (length of s2).

        // Initialize the dp table with dimensions (row + 1) x (col + 1).
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

        // Fill the last column: cost of deleting all remaining characters from s1.
        for (int i = row - 1; i >= 0; i--) {
            dp[i][col] = s1[i] + dp[i + 1][col];
        }

        // Fill the last row: cost of deleting all remaining characters from s2.
        for (int j = col - 1; j >= 0; j--) {
            dp[row][j] = s2[j] + dp[row][j + 1];
        }

        // Fill the dp array from bottom-right to top-left.
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                // If characters match, no deletion is needed. Move to the next characters in both strings
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                // If characters differ, delete the current character either from s1 or s2.
                else {
                    int s1Sum = s1[i] + dp[i + 1][j];   // Delete from s1.
                    int s2Sum = s2[j] + dp[i][j + 1];   // Delete from s2.

                    // Choose the minimum of the two costs.
                    dp[i][j] = min(s1Sum, s2Sum);
                }
            }
        }

        // Return the result stored in the top-left corner of the table.
        return dp[0][0];
    }

    int minimumDeleteSum(string s1, string s2) {
        return tabulation(s1, s2);
    }
};

Time Complexity = O(n * sqrt(n))
Space Complexity = O(n)
```