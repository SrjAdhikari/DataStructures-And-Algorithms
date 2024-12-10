# Question : [Wildcard Matching - (LeetCode : 44)](https://leetcode.com/problems/wildcard-matching/description/)

Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for `'?'` and `'*'` where:

-   `'?'` Matches any single character.
-   `'*'` Matches any sequence of characters (including the empty sequence).
    The matching should cover the entire input string (not partial).

### Example 1

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

### Example 2

```
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
```

### Example 3

```
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
```

### Constraints

-   `0 <= s.length, p.length <= 2000`
-   `s` contains only lowercase English letters.
-   `p` contains only lowercase English letters, `'?'` or `'*'`.

### Recursive Approach

```Cpp
class Solution {
public:
    bool recursion(string& str, string& pattern, int i, int j) {
        // Base case: If both string and pattern are exhausted, it's a match
        if(i == 0 && j == 0)
            return true;

        // If string is not empty but pattern is exhausted, it can't match
        if(i > 0 && j == 0)
            return false;

        // If string is exhausted but pattern has remaining characters
        // Check if they are all '*' characters, as '*' can match an empty string
        if(i == 0 && j > 0) {
            for(int k = 1; k <= j; k++) {
                if(pattern[k-1] != '*')
                    // If any character is not '*', return false
                    return false;
            }
            // All remaining pattern characters are '*', return true
            return true;
        }

        // If the current characters match or the pattern has '?', which matches any character
        if(str[i-1] == pattern[j-1] || pattern[j] == '?')
            // Move both string and pattern pointers back
            return recursion(str, pattern, i-1, j-1);

        // If pattern has '*' which can match zero or more characters
        else if(pattern[j-1] == '*')
            // Two choices:
            // 1. '*' matches one character from the string, so we reduce the string size (i-1)
            // 2. '*' matches zero characters, so we move to the next character in the pattern (j-1)
            return (recursion(str, pattern, i-1, j) || recursion(str, pattern, i, j-1));

        // If no conditions match, return false
        else
            return false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        return recursion(s, p, n, m);
    }
};

Time Complexity = O(2^(n+m))
Space Complexity = O(n + m)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    bool memoization(string& str, string& pattern, int i, int j, vector<vector<int>>& dp) {
        // Base case: If both string and pattern are exhausted, it's a match
        if(i == 0 && j == 0)
            return true;

        // If string is not empty but pattern is exhausted, it can't match
        if(i > 0 && j == 0)
            return false;

        // If string is exhausted but pattern has remaining characters
        // Check if they are all '*' characters
        if(i == 0 && j > 0) {
            for(int k = 1; k <= j; k++) {
                if(pattern[k-1] != '*')
                    return false;
            }
            return true;
        }

        // If the result has already been calculated, return it
        if(dp[i][j] != -1)
            return dp[i][j];

        // If the current characters match or the pattern has '?', which matches any character
        if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
            // Move both string and pattern pointers back
            return dp[i][j] =  memoization(str, pattern, i-1, j-1, dp);

        // If pattern has '*' which can match zero or more characters
        else if(pattern[j-1] == '*')
            // Two choices:
            // 1. '*' matches one character from the string, so we reduce the string size (i-1)
            // 2. '*' matches zero characters, so we move to the next character in the pattern (j-1)
            return dp[i][j] = (memoization(str, pattern, i-1, j, dp) || memoization(str, pattern, i, j-1, dp));

        // If no conditions match, return false
        else
            return false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return memoization(s, p, n, m, dp);
    }
};

Time Complexity = O(n * m)
Space Complexity = O(n * m)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    bool tabulation(string& str, string& pattern) {
        int n = str.size();
        int m = pattern.size();

        // DP table to store whether str[0...i] matches pattern[0...j]
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Base case: both string and pattern are empty
        dp[0][0] = true;

        // Fill the first row of DP array, where the string is empty
        // If the pattern is all '*', then it matches the empty string
        for(int j = 1; j <= m; j++) {
            bool flag = true;
            for(int k = 1; k <= j; k++) {
                if(pattern[k-1] != '*')
                    flag = false;
            }
            // If all characters are '*' till current position, it's a match
            dp[0][j] = flag;
        }

        // Fill the DP table for non-empty string and pattern
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // If the current characters match or the pattern has '?'
                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];

                // If pattern has '*' which can match zero or more characters
                else if(pattern[j-1] == '*')
                    // We have two choices:
                    // 1. '*' matches one character from the string (dp[i-1][j])
                    // 2. '*' matches zero characters (dp[i][j-1])
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);

                // If no conditions match, return false
                else
                    dp[i][j] = false;
            }
        }
        // The result is stored in dp[n][m], representing if str[0...n-1] matches pattern[0...m-1]
        return dp[n][m];
    }

    bool isMatch(string s, string p) {
        return tabulation(s, p);
    }
};

Time Complexity = O(n * m)
Space Complexity = O(n * m)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    bool spaceOptimization(string& str, string& pattern) {
        int n = str.size();
        int m = pattern.size();

        // Two 1D arrays to store current and previous row results
        vector<int> curr(m+1, 0);
        vector<int> prev(m+1, 0);

        // Base case: both string and pattern are empty, so return true
        prev[0] = true;

        // Fill the first row of prev (when string is empty)
        // The pattern must contain only '*' characters to match an empty string
        for(int j = 1; j <= m; j++) {
            bool flag = true;
            for(int k = 1; k <= j; k++) {
                if(pattern[k-1] != '*')
                    flag = false;
            }
            // If all characters are '*' till current position, it's a match
            prev[j] = flag;
        }

        // Iterate over the string and pattern to fill the current row
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // If the current characters match or the pattern has '?'
                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
                    curr[j] = prev[j-1];

                // If pattern has '*' which can match zero or more characters
                else if(pattern[j-1] == '*')
                    // we have two choices:
                    // 1. '*' matches one character from the string (prev[j])
                    // 2. '*' matches zero characters (curr[j-1])
                    curr[j] = (prev[j] || curr[j-1]);

                // If no conditions match, return false
                else
                    curr[j] = false;
            }
            // Move current results to previous row for next iteration
            prev = curr;
        }
        // The result is stored in prev[m], representing if str[0...n-1] matches pattern[0...m-1]
        return prev[m];
    }

    bool isMatch(string s, string p) {
        return spaceOptimization(s, p);
    }
};

Time Complexity = O(n * m)
Space Complexity = O(m)
```
