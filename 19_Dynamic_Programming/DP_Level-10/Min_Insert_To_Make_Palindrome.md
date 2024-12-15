# Question : [Minimum Insertion Steps to Make a String Palindrome - (LeetCode : 1312)](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/)

Given a string `s`. In one step you can insert any character at any index of the string.

Return _the minimum number of steps_ to make `s` palindrome.

A **Palindrome String** is one that reads the same backward as well as forward.

### Example 1

```
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
```

### Example 2

```
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
```

### Example 3

```
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
```

### Constraints

-   `1 <= s.length <= 500`
-   `s` consists of lowercase English letters.

### Optimize Solution

```Cpp
class Solution {
public:
    // Optimize computation of Longest Palindromic Subsequence (LPS)
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

    // Calculate the length of the Longest Palindromic Subsequence
    int longestPalindromeSubseq(string& s) {
        string reversedS = s;
        reverse(reversedS.begin(), reversedS.end());
        return spaceOptimization(s, reversedS);
    }

    // Calculate minimum insertions to make the string a palindrome
    int minInsertions(string s) {
        // Calculate the length of the longest palindromic subsequence (LPS)
        int LPS_length = longestPalindromeSubseq(s);

        // Minimum insertions needed is the difference between the string size and the LPS length
        return s.size() - LPS_length;
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n)
```
