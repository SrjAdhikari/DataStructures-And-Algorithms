# Question : [Longest Palindromic Subsequence - (LeetCode : 516)](https://leetcode.com/problems/longest-palindromic-subsequence/description/)

Given a string `s`, find *the longest palindromic **subsequence***'s length in `s`.

A **subsequence** is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

### Example 1

```
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
```

### Example 2

```
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
```

### Constraints

-   `1 <= s.length <= 1000`
-   `s` consists of only lowercase English characters.

### Approach of the problem
```
The problem is a variation of the Longest Common Subsequence (LCS) problem, 
where we need to find the longest common subsequence between `s` and its reverse string (`s` reversed).

The logic: 
    - To find the longest palindromic subsequence (LPS),
      we reverse the string and apply the Longest Common Subsequence (LCS) algorithm.

Reason: 
    - A palindromic subsequence is the same when read forward or backward.
    - Finding the LCS between the original string and its reverse gives the LPS length.
```

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(string& str1, string& str2, int i, int j) {
        // Base case: if we reach the end of either string, return 0 (no common subsequence possible)
        if(i >= str1.length() || j >= str2.length())
            return 0;

        // Variable to store the length of the longest common subsequence
        int length = 0;

        // If characters at current indices of both strings match
        if(str1[i] == str2[j])
            // Move both indices forward and add 1 to the LCS length
            length = 1 + recursion(str1, str2, i+1, j+1);
        
        // If characters don't match, try two cases: 
        else
            // 1. Move i forward, 2. Move j forward, and take the maximum result
            length = 0 + max(recursion(str1, str2, i, j+1), recursion(str1, str2, i+1, j));
        
        // Return the computed length of LCS
        return length;
    }

    int longestPalindromeSubseq(string s) {
        string str = s;
        reverse(str.begin(), str.end()); 

        return recursion(s, str, 0, 0);
    }
};

Time Complexity = O(2^m+n)
Space Complexity = O(m + n)
m = length of text1
n = length of text2
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(string& str1, string& str2, int i, int j, vector<vector<int>>& dp) {
        // Base case: if we reach the end of either string, return 0 (no common subsequence possible)
        if(i >= str1.length() || j >= str2.length())
            return 0;

        // Check if the result is already computed for this subproblem, return it
        if(dp[i][j] != -1)
            return dp[i][j];

        // Variable to store the length of the longest common subsequence
        int length = 0;

        // If characters at current indices of both strings match
        if(str1[i] == str2[j])
            // Move both indices forward and add 1 to the LCS length
            length = 1 + memoization(str1, str2, i+1, j+1, dp);
        
        // If characters don't match, try two cases: 
        else
            // 1. Move i forward, 2. Move j forward, and take the maximum result
            length = 0 + max(memoization(str1, str2, i, j+1, dp), memoization(str1, str2, i+1, j, dp));
        
        // Store the computed result in the dp array for memoization and return it
        dp[i][j] = length;
        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        string str = s;
        reverse(str.begin(), str.end()); 
        
        int row = s.length();
        int col = str.length();
        vector<vector<int>>dp(row+1, vector<int>(col+1, -1));
        return memoization(s, str, 0, 0, dp);
    }
};

Time Complexity = O(m * n)
Space Complexity = O(m * n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(string& str1, string& str2) {
        int row = str1.length();    // Length of the first string
        int col = str2.length();    // Length of the second string

        // Initialize a dp array where dp[i][j] represents the LCS length of str1[0...i] and str2[0...j]
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));

        // Fill the DP table from bottom-right to top-left
        for(int i = row-1; i >= 0; i--) {
            for(int j = col-1; j >= 0; j--) {
                // Variable to store the LCS length for the current position
                int length = 0;

                // If characters at current indices of both strings match
                if(str1[i] == str2[j])
                    // Move both indices forward and add 1 to the LCS length
                    length = 1 + dp[i+1][j+1];
                
                // If characters don't match, try two cases:
                else
                    // 1. Move i forward, 2. Move j forward, and take the maximum result
                    length = 0 + max(dp[i][j+1], dp[i+1][j]);
                
                // Store the computed LCS length for the current position
                dp[i][j] = length;
            }
        }
        // Return the final result at dp[0][0], representing the LCS for the entire strings
        return dp[0][0];
    }

    int longestPalindromeSubseq(string s) {
        string str = s;
        reverse(str.begin(), str.end()); 

        return tabulation(s, str);
    }
};

Time Complexity = O(m * n)
Space Complexity = O(m * n)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(string& str1, string& str2) {
        int row = str1.length();        // Length of the first string
        int col = str2.length();        // Length of the second string

        vector<int> next(row+1, 0);     // Stores results for the next row
        vector<int> curr(row+1, 0);     // Stores results for the current row

        // Fill the dp array from bottom-up, processing each column in reverse order
        for(int j = col-1; j >= 0; j--) {
            for(int i = row-1; i >= 0; i--) {
                // Variable to store the LCS length for the current position
                int length = 0;

                // If characters at current indices of both strings match
                if(str1[i] == str2[j])
                    // Move both indices forward and add 1 to the LCS length
                    length = 1 + next[i+1];

                // If characters don't match, try two cases:
                else
                    // 1. Move i forward, 2. Move j forward, and take the maximum result
                    length = 0 + max(next[i], curr[i+1]);
                
                // Update current row's result
                curr[i] = length;
            }
            // Move the current row to next row for the next iteration
            next = curr;
        }
        // Return the LCS length for the entire strings
        return next[0];
    }

    int longestPalindromeSubseq(string s) {
        string str = s;
        reverse(str.begin(), str.end()); 

        return spaceOptimization(s, str);
    }
};

Time Complexity = O(m * n)
Space Complexity = O(n)
```