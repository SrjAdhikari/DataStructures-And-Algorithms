# Question : [Edit Distance - (LeetCode : 72)](https://leetcode.com/problems/edit-distance/description/)

Given two strings `word1` and `word2`, _eturn the minimum number of operations required to convert `word1` to `word2`_.

You have the following three operations permitted on a word:

-   Insert a character
-   Delete a character
-   Replace a character

### Example 1

```
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
```

### Example 2

```
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
```

### Constraints

-   `0 <= word1.length, word2.length <= 500`
-   `word1` and `word2` consist of lowercase English letters

### Recursive Approach

```Cpp

class Solution {
public:
    int recursion(string& str1, string& str2, int i, int j) {
        // Base case 1: If we have processed all characters in str1
        // We need to insert the remaining characters of str2 into str1.
        if (i >= str1.length()) {
            return str2.length() - j;
        }

        // Base case 2: If we have processed all characters in str2
        // We need to remove the remaining characters of str1.
        if (j >= word2.length()) {
            return str1.length() - i;
        }

        int operation = 0;

        // If the current characters of both strings match
        // No new operation is needed, move to the next characters in both strings.
        if (str1[i] == str2[j]) {
            operation = 0 + recursion(str1, str2, i + 1, j + 1);
        }
        // If characters don't match, we explore the three possible operations.
        else {
            // Case 1: Replace the character in str1 with the character in str2
            // Move to the next character in both strings.
            int replace = 1 + minOperation(str1, str2, i + 1, j + 1);

            // Case 2: Insert the character from str2 into str1
            // Move to the next character in str2 while keeping the index in str1 the same.
            int insert = 1 + minOperation(word1, word2, i, j + 1);

            // Case 3: Remove the character from str1
            // Move to the next character in str1 while keeping the index in str2 the same.
            int remove = 1 + minOperation(word1, word2, i + 1, j);

            // Store the minimum number of operations needed from the three cases
            operation = min(replace, min(insert, remove));
        }
        // Return the minimum number of operations needed
        return operation;
    }

    int minDistance(string& word1, string& word2) {
        int i = 0;      // Start index for word1
        int j = 0;      // Start index for word2
        return recursion(word1, word2, i, j);
    }
};

Time Complexity = O(3^(m + n))
Space Complexity = O(m + n)
=> where m and n are the lengths of word1 and word2, respectively.
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(string& str1, string& str2, int i, int j, vector<vector<int>>& dp) {
        // Base case 1: If we have processed all characters in word1
        // We need to insert the remaining characters of word2 into word1.
        if (i >= word1.length()) {
            return word2.length() - j;
        }

        // Base case 2: If we have processed all characters in word2
        // We need to remove the remaining characters of word1.
        if (j >= word2.length()) {
            return word1.length() - i;
        }

        // Check if the result for the current pair of indices (i, j) has already been computed.
        // If yes, just return the stored result.
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int operation = 0;

        // If the characters match, no operation is needed, so we move both pointers forward.
        if (str1[i] == str2[j]) {
            operation = 0 + memoization(str1, str2, i + 1, j + 1, dp);
        }
        // If the characters don't match, we explore the three possible operations (replace, insert, remove).
        else {
            int replace = 1 + memoization(str1, str2, i + 1, j + 1, dp);
            int insert = 1 + memoization(str1, str2, i, j + 1, dp);
            int remove = 1 + memoization(str1, str2, i + 1, j, dp);

            // Store the minimum number of operations needed from the three cases
            operation = min(replace, min(insert, remove));
        }

        // Store the result in the dp array to avoid recalculating the same subproblem.
        dp[i][j] = operation;

        // Return the minimum number of operations needed
        return dp[i][j];
    }

    int minDistance(string& word1, string& word2) {
        int row = word1.length();
        int col = word2.length();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1));

        return memoization(word1, word2, 0, 0, dp);
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
        int row = str1.length();
        int col = str2.length();

        // Initialize a 2D dp table with size (row+1) x (col+1). Initially fill it with -1.
        // dp[i][j] will represent the minimum number of operations to convert str1[0..i] to str2[0..j].
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1));

        // Base case 1: When str1 is empty, we need to insert all characters of str2.
        for (int j = 0; j <= col; j++) {
            dp[row][j] = col - j;
        }

        // Base case 2: When str2 is empty, we need to delete all characters of str1.
        for (int i = 0; i <= row; i++) {
            dp[i][col] = row - i;
        }

        // Bottom-up calculation: We start from the bottom-right of the dp table and fill the table.
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                int operation = 0;

                // If characters match, no operation is needed, so we move diagonally in the table.
                if (str1[i] == str2[j]) {
                    operation = 0 + dp[i + 1][j + 1];
                }
                // If characters don't match, we explore the three possible operations (replace, insert, remove).
                else {
                    int replace = 1 + dp[i + 1][j + 1];
                    int insert = 1 + dp[i][j + 1];
                    int remove = 1 + dp[i + 1][j];

                    // Store the minimum number of operations needed from the three cases
                    operation = min(replace, min(insert, remove));
                }

                // Store the result in the dp array
                dp[i][j] = operation;
            }
        }

        // Return the minimum number of operations needed, which is stored in dp[0][0].
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        return tabulation(word1, word2);
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
        int row = str1.length();
        int col = str2.length();

        // Initialize two 1D arrays: 'next' for the previous row and 'curr' for the current row.
        vector<int> next(row + 1, 0);
        vector<int> curr(row + 1, 0);

        // Base case 1: Fill the 'next' array for the last row (when str1 is empty).
        for (int i = 0; i <= row; i++) {
            next[i] = row - i;
        }

        // Bottom-up calculation with reduced space complexity: 
        // We only keep track of the current and previous rows.
        for (int j = col - 1; j >= 0; j--) {
            // Base case 2: Fill the last column of the 'curr' array for when str2 is empty.
            curr[row] = col - j; 

            for (int i = row - 1; i >= 0; i--) {
                int operation = 0;

                // If characters match, no operation is needed, so we move to the next row.
                if (str1[i] == str2[j]) {
                    operation = 0 + next[i + 1];
                }
                // If characters don't match, we explore the three possible operations.
                else {
                    int replace = 1 + next[i + 1];
                    int insert = 1 + next[i];
                    int remove = 1 + curr[i + 1];

                    // Store the minimum number of operations needed from the three cases
                    operation = min(replace, min(insert, remove));
                }

                // Store the result in the current row.
                curr[i] = operation;
            }

            // Move the current row to the next row for the next iteration.
            next = curr;
        }

        // Return the minimum number of operations needed, which is stored in next[0] (i.e. the first element of the 'next' array).
        return next[0];
    }

    int minDistance(string word1, string word2) {
        return spaceOptimization(word1, word2);
    }
};

Time Complexity = O(m * n)
Space Complexity = O(min(m, n))
```