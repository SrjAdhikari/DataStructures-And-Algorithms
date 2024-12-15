# Question : [Interleaving String - (LeetCode : 97)](https://leetcode.com/problems/interleaving-string/description/)

Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an **interleaving** of `s1` and `s2`.

An **interleaving** of two strings `s` and `t` is a configuration where `s` and `t` are divided into `n` and `m` substrings respectively, such that:

-   `s = s1 + s2 + ... + sn`
-   `t = t1 + t2 + ... + tm`
-   `|n - m| <= 1`
-   The **interleaving** is `s1 + t1 + s2 + t2 + s3 + t3 + ...` or `t1 + s1 + t2 + s2 + t3 + s3 + ...`

Note: `a + b` is the concatenation of strings `a` and `b`.

### Example 1

![](https://assets.leetcode.com/uploads/2020/09/02/interleave.jpg)

```
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
```

### Example 2

```
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
```

### Example 3

```
Input: s1 = "", s2 = "", s3 = ""
Output: true
```

### Constraints

-   `0 <= s1.length, s2.length <= 100`
-   `0 <= s3.length <= 200`
-   `s1`, `s2`, and `s3` consist of lowercase English letters.

### Recursive Approach

```Cpp
class Solution {
public:
    bool recursion(string& s1, string& s2, string& s3, int i , int j, int k) {
        // Base case: If we've reached the end of all strings, we return true
        if(i == s1.size() && j == s2.size() && k == s3.size())
            return true;

        // Case 1: Check if the current character in s1 matches the current character in s3
        if(i < s1.size() && s1[i] == s3[k]) {
            // If match, recursively move to the next characters in s1 and s3
            if(recursion(s1, s2, s3, i+1, j, k+1))
                // If a valid interleaving is found, return true
                return true;
        }

        // Case 2: Check if the current character in s2 matches the current character in s3
        if(j < s2.size() && s2[j] == s3[k]) {
            // If match, recursively move to the next characters in s2 and s3
            if(recursion(s1, s2, s3, i, j+1, k+1))
                // If a valid interleaving is found, return true
                return true;
        }

        // If no match is found, return false
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        return recursion(s1, s2, s3, 0, 0, 0);
    }
};

Time Complexity = O(2^(s1+s2))
Space Complexity = O(s1 + s2 + s3)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    bool memoization(string& s1, string& s2, string& s3, int i , int j, int k, vector<vector<vector<int>>>& dp) {
        // Base case: If we've reached the end of all strings, return true
        if(i == s1.size() && j == s2.size() && k == s3.size())
            return true;

        // If the result for this subproblem has already been computed, return it
        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        // Case 1: Check if the current character in s1 matches the current character in s3
        if(i < s1.size() && s1[i] == s3[k]) {
            // If match, recursively move to the next characters in s1 and s3
            if(memoization(s1, s2, s3, i+1, j, k+1, dp))
                // If a valid interleaving is found, Store the result and return true
                return dp[i][j][k] = true;
        }

        // Case 2: Check if the current character in s2 matches the current character in s3
        if(j < s2.size() && s2[j] == s3[k]) {
            // If match, recursively move to the next characters in s2 and s3
            if(memoization(s1, s2, s3, i, j+1, k+1, dp))
                // If a valid interleaving is found, Store the result and return true
                return dp[i][j][k] = true;
        }

        // If no match is found, store the result and return false
        return dp[i][j][k] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int s1Size = s1.size();
        int s2Size = s2.size();
        int s3Size = s3.size();

        vector<vector<vector<int>>> dp(s1Size+1, vector<vector<int>>(s2Size+1, vector<int>(s3Size+1, -1)));
        return memoization(s1, s2, s3, 0, 0, 0, dp);
    }
};

Time Complexity = O(s1 * s2 * s3)
Space Complexity = O(s1 * s2 * s3)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    bool tabulation(string& s1, string& s2, string& s3) {
        // Get the sizes of s1, s2, and s3
        int s1Size = s1.size();
        int s2Size = s2.size();
        int s3Size = s3.size();

        // Initialize a 3D DP table, with dimensions (s1Size+1) x (s2Size+1) x (s3Size+1) and with all values set to 0
        vector<vector<vector<int>>> dp(s1Size+1, vector<vector<int>>(s2Size+1, vector<int>(s3Size+1, 0)));

        // Base case: If all strings are processed, set the DP value to true (1)
        dp[s1Size][s2Size][s3Size] = 1;

        // Start filling the DP table from the end to the start of the strings
        for(int i = s1Size; i >= 0; i--) {              // Iterate over s1
            for(int j = s2Size; j >= 0; j--) {          // Iterate over s2
                for(int k = s3Size; k >= 0; k--) {      // Iterate over s3

                    // Skip the base case when all strings are processed, because it's already handled
                    if(i == s1.size() && j == s2.size() && k == s3.size()) continue;

                    // Flag to check if a valid interleaving is found
                    bool flag = false;

                    // Case 1: If current character in s1 matches the current character in s3
                    if(i < s1.size() && s1[i] == s3[k])
                        // If match, check if the rest can form a valid interleaving
                        flag = flag || dp[i+1][j][k+1];

                    // Case 2: If current character in s2 matches the current character in s3
                    if(j < s2.size() && s2[j] == s3[k])
                        // If match, check if the rest can form a valid interleaving
                        flag = flag || dp[i][j+1][k+1];

                    // Store the result in the DP table (true/false)
                    dp[i][j][k] = flag;
                }
            }
        }

        // Return the final result stored in dp[0][0][0]
        return dp[0][0][0];
    }

    bool isInterleave(string s1, string s2, string s3) {
        return tabulation(s1, s2, s3);
    }
};

Time Complexity = O(s1 * s2 * s3)
Space Complexity = O(s1 * s2 * s3)
```
