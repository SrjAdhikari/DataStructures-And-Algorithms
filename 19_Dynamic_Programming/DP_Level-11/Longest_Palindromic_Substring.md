# Question : [Longest Palindromic Substring - (LeetCode : 5)](https://leetcode.com/problems/longest-palindromic-substring/description/)

Given a string `s`, return _the longest palindromic substring_ in `s`.

### Example 1

```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```

### Example 2

```
Input: s = "cbbd"
Output: "bb"
```

### Constraints

-   `1 <= s.length <= 1000`
-   `s` consists of only digits and English letters.

### Recursive Approach

```Cpp
class Solution {
public:
    bool recursion(string& s, int start, int end, int& startPoint, int& maxLength) {
        // Base case: If start index is greater than or equal to end index, it is a palindrome.
        // Return true since an empty or single-character substring is a palindrome.
        if (start >= end)
            return true;

        // Initialize flag to indicate whether the substring is a palindrome.
        bool flag = false;

        // Check if characters at `start` and `end` indices are the same.
        if (s[start] == s[end])
            flag = recursion(s, start + 1, end - 1, startPoint, maxLength);

        // If the substring is a palindrome, update maxLength and startPoint.
        if (flag) {
            // Calculate the length of the current palindrome.
            int currLength = end - start + 1;

            // Check if the current palindrome is longer than the previous maximum.
            if (currLength > maxLength) {
                maxLength = currLength;                 // Update maxLength.
                startPoint = start;                     // Update startPoint to the beginning of the current palindrome.
            }
        }
        // Return whether the substring is a palindrome.
        return flag;
    }

    string longestPalindrome(string s) {
        int n = s.size();               // Get the length of the input string.
        int startPoint = 0;             // Initialize the starting index of the longest palindrome.
        int maxLength = 1;              // Initialize the maximum length of the palindrome as 1 (minimum valid length).

        // Iterate over all possible starting indices of substrings.
        // Outer loop for the starting index of the substring.
        for (int i = 0; i < n; i++) {
            // Inner loop for the ending index of the substring.
            for (int j = i; j < n; j++) {
                // Check if the substring `s[i...j]` is a palindrome using recursion.
                recursion(s, i, j, startPoint, maxLength);
            }
        }

        // Extract and return the longest palindromic substring using `startPoint` and `maxLength`.
        // `substr` extracts the substring starting at `startPoint` with length `maxLength`.
        return s.substr(startPoint, maxLength);
    }
};

Time Complexity = O(end - start)
Space Complexity = O(end - start)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(string& s, int start, int end, int& startPoint, int& maxLength, vector<vector<int>>& dp) {
        // Base case: If start index is greater than or equal to end index, it is a palindrome.
        // Return true since an empty or single-character substring is a palindrome.
        if (start >= end)
            return true;

        // If the result for this substring is already computed, return it.
        if (dp[start][end] != -1)
            return dp[start][end];

        // Initialize flag to indicate whether the substring is a palindrome.
        bool flag = false;

        // Check if characters at `start` and `end` indices are the same.
        if (s[start] == s[end])
            flag = memoization(s, start + 1, end - 1, startPoint, maxLength, dp);

        // If the substring is a palindrome, update maxLength and startPoint.
        if (flag) {
            // Calculate the length of the current palindrome.
            int currLength = end - start + 1;

            // Check if the current palindrome is longer than the previous maximum.
            if (currLength > maxLength) {
                maxLength = currLength;             // Update maxLength.
                startPoint = start;                 // Update startPoint to the beginning of the current palindrome.
            }
        }
        // Cache the result and return whether the substring is a palindrome.
        return dp[start][end] = flag;
    }

    string longestPalindrome(string s) {
        int n = s.size();                   // Get the length of the input string.
        int startPoint = 0;                 // Initialize the starting index of the longest palindrome.
        int maxLength = 1;                  // Initialize the maximum length of the palindrome as 1 (minimum valid length).

        // Create a DP table of size n x n, initialized to -1 to indicate uncomputed results.
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Iterate over all possible starting indices of substrings.
        // Outer loop for the starting index of the substring.
        for (int i = 0; i < n; i++) {
            // Inner loop for the ending index of the substring.
            for (int j = i; j < n; j++) {
                // Check if the substring `s[i...j]` is a palindrome using memoization.
                memoization(s, i, j, startPoint, maxLength, dp);
            }
        }

        // Extract and return the longest palindromic substring using `startPoint` and `maxLength`.
        // `substr` extracts the substring starting at `startPoint` with length `maxLength`.
        return s.substr(startPoint, maxLength);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```
