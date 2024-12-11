# Question : [Distinct Subsequences - (LeetCode : 115)](https://leetcode.com/problems/distinct-subsequences/description/)

Given two strings s and t, return _the number of distinct **subsequences** of s which equals t_.

The test cases are generated so that the answer fits on a 32-bit signed integer.

### Example 1

```
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
```

### Example 2

```
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
```

### Constraints

-   `1 <= s.length, t.length <= 1000`
-   `s` and `t` consist of English letters.

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(string& s, string& t, int i, int j) {
        // If all characters of `t` are matched, return 1 as a valid subsequence is found.
        if (j == t.size())
            return 1;

        // If end of `s` is reached without fully matching `t`, return 0.
        if (i == s.size())
            return 0;

        // Initialize the count of valid subsequences.
        int count = 0;

        // If characters match, recursively find subsequences with and without the current match.
        if (s[i] == t[j])
        // Include current character, move to the next character in both `s` and `t`.
            count += recursion(s, t, i + 1, j + 1);

        // Exclude current character, move to the next character in `s` without moving character in `t`.
        count += recursion(s, t, i + 1, j);

        // Return the total count of subsequences.
        return count;
    }

    int numDistinct(string s, string t) {
        return recursion(s, t, 0, 0);
    }
};

Time Complexity = O(2^(n+m))
Space Complexity = O(n + m)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        // If all characters of `t` are matched, return 1 as a valid subsequence is found.
        if (j == t.size())
            return 1;

        // If end of `s` is reached without fully matching `t`, return 0.
        if (i == s.size())
            return 0;

        // Check if the result is already calculated for current subsequences, if yes return it.
        if (dp[i][j] != -1)
            return dp[i][j];

        // Initialize the count of valid subsequences.
        int count = 0;

        // If characters match, recursively find subsequences with and without the current match.
        if (s[i] == t[j])
        // Include current character, move to the next character in both `s` and `t`.
            count += memoization(s, t, i + 1, j + 1, dp);

        // Exclude current character, move to the next character in `s` without moving character in `t`.
        count += memoization(s, t, i + 1, j, dp);

        // Store the result in dp array and return it.
        return dp[i][j] = count;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return memoization(s, t, 0, 0, dp);
    }
};

Time Complexity = O(n * m)
Space Complexity = O(n * m)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(string& s, string& t) {
        int n = s.size();       // Length of string `s`.
        int m = t.size();       // Length of string `t`.

        // DP table where dp[i][j] stores the count of subsequences of `t[j...]` in `s[i...]`.
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: If `t` is empty, there is one way to match it (empty subsequence).
        for (int i = 0; i <= n; i++)
            dp[i][m] = 1;

        // Fill the DP table in reverse order (bottom-up approach).
        // Iterate over `s` from the end.
        for (int i = n - 1; i >= 0; i--) {
            // Iterate over `t` from the end.
            for (int j = m - 1; j >= 0; j--) {
                // Initialize the count of subsequences.
                long long count = 0;

                // If characters match, recursively find subsequences with and without the current match.
                if (s[i] == t[j])
                    // Include current character, move to the next character in both `s` and `t`.
                    count += dp[i + 1][j + 1];

                // Exclude current character, move to the next character in `s` without moving character in `t`.
                count += dp[i + 1][j];

                // Update DP array with total count.
                dp[i][j] = count;
            }
        }

        // Result is stored at `dp[0][0]`, which represents `t` in `s`.
        return dp[0][0];
    }

    int numDistinct(string s, string t) {
        return tabulation(s, t);
    }
};

Time Complexity = O(n * m)
Space Complexity = O(n * m)
```
