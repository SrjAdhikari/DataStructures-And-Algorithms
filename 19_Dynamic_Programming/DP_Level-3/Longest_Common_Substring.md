# Question : [Longest Common Substring - GFG](https://www.geeksforgeeks.org/problems/longest-common-substring1452/1)

You are given two strings `s1` and `s2`. Your task is to find the length of the `longest common substring` among the given strings.

### Example 1

```
Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" with a length of 4.
```

### Example 2

```
Input: s1 = "abc", s2 = "acb"
Output: 1
Explanation: The longest common substrings are "a", "b", "c" all having length 1.
```

### Example 3

```
Input: s1 = "YZ", s2 = "yz"
Output: 0
```

```
Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)
```

### Constraints

- `1 <= s1.size(), s2.size() <= 10^3`
- Both strings may contain upper and lower case alphabets.

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(int n, int m, string& s1, string& s2, int& ans) {
        // Base Case: If either string is exhausted, no common substring is possible and return 0.
        if (n == 0 || m == 0)
            return 0;

        // Variable to track the length of the current common substring.
        int length = 0;

        // Check if characters at current indices of both strings match
        if (s1[n - 1] == s2[m - 1]) {
            // Include this character in the LCS and move both i and j backwards.
            length = 1 + recursion(n - 1, m - 1, s1, s2, ans);

            // Update the global maximum length found so far.
            ans = max(ans, length);
        }

        // Explore other possibilities by skipping one character in either string.
        recursion(n - 1, m, s1, s2, ans);       // Skip a character in s1.
        recursion(n, m - 1, s1, s2, ans);       // Skip a character in s2.

        // Return the length of the current common substring (0 if no match).
        return length;
    }

    int longestCommonSubstr(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int ans = 0;
        
        recursion(n, m, s1, s2, ans);
        return ans;
    }
};

Time Complexity = O(2^(n + m))
Space Complexity = O(n + m)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(int n, int m, string& s1, string& s2, int& ans, vector<vector<int>>& dp) {
        // Base Case: If either string is exhausted, no common substring is possible and return 0.
        if (n == 0 || m == 0)
            return 0;

        // Check if the result is already computed for this subproblem, return it
        if (dp[n][m] != -1)
            return dp[n][m];

        // Variable to track the length of the current common substring.
        int length = 0;

        // Check if characters at current indices of both strings match
        if (s1[n - 1] == s2[m - 1]) {
            // Include this character in the LCS and move both i and j backwards.
            length = 1 + memoization(n - 1, m - 1, s1, s2, ans, dp);

            // Update the global maximum length found so far.
            ans = max(ans, length);
        }

        // Explore other possibilities by skipping one character in either string.
        memoization(n - 1, m, s1, s2, ans, dp);     // Skip a character in s1.
        memoization(n, m - 1, s1, s2, ans, dp);     // Skip a character in s2.

        // Return the length of the current common substring (0 if no match).
        return dp[n][m] = length;
    }

    int longestCommonSubstr(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int ans = 0;
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        memoization(n, m, s1, s2, ans, dp);
        return ans;
    }
};

Time Complexity = O(n * m)
Space Complexity = O(n * m)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(string& s1, string& s2, int& ans) {
        int n = s1.size();
        int m = s2.size();

        // Create a DP table with dimensions (n+1) x (m+1), initialized to 0.
        // dp[i][j] represents the length of the longest common substring
        // ending at indices i-1 in s1 and j-1 in s2.
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Iterate through every character of both strings.
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Check if characters at current indices of both strings match
                if (s1[i - 1] == s2[j - 1]) {
                    // Include this character in the LCS and move both i and j backwards.
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                    // Update the global maximum length found so far.
                    ans = max(ans, dp[i][j]); 
                } 
                // If characters don't match, set the length for current cell to 0
                else {
                    dp[i][j] = 0;
                }
            }
        }
        // Return the maximum length of the common substring found.
        return ans;
    }

    int longestCommonSubstr(string s1, string s2) {
        int ans = 0;
        
        tabulation(s1, s2, ans);
        return ans;
    }
};

Time Complexity = O(n * m)
Space Complexity = O(n * m)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(string& s1, string& s2, int& ans) {
        int n = s1.size();
        int m = s2.size();

        // Two 1D arrays to store results of the current and previous rows.
        vector<int> prev(m + 1, 0);     // Stores results of the previous row.
        vector<int> curr(m + 1, 0);     // Stores results of the current row.

        // Iterate through every character of both strings.
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Check if characters at current indices of both strings match
                if (s1[i - 1] == s2[j - 1]) {
                    // Include this character in the LCS and move both i and j backwards.
                    curr[j] = 1 + prev[j - 1];

                    // Update the global maximum length found so far.
                    ans = max(ans, curr[j]);
                } 
                // If characters don't match, set the length for current cell to 0
                else {
                    curr[j] = 0;
                }
            }
            // Move to the next row: Copy current row into previous row.
            prev = curr;
        }
        // Return the maximum length of the common substring found.
        return ans;
    }

    int longestCommonSubstr(string s1, string s2) {
        int ans = 0;
        
        spaceOptimization(s1, s2, ans);
        return ans;
    }
};

Time Complexity = O(n * m)
Space Complexity = O(m)
```