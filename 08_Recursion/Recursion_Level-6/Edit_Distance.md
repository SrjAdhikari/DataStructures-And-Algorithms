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

**Note**: This recursive solution lead to a time limit exceeded (TLE) error on large inputs because of the exponential time complexity. In the future, we will solve this problem using dynamic programming to optimize the solution and pass all test cases.

## Solution

```Cpp

class Solution {
public:
    // Recursive function to compute the minimum number of operations needed
    // to convert word1 into word2 using insertions, deletions, and replacements.
    int minOperation(const string& word1, const string& word2, int i, int j) {
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

        // If the current characters of both strings match
        // No new operation is needed, move to the next characters in both strings.
        if (word1[i] == word2[j]) {
            return minOperation(word1, word2, i + 1, j + 1);
        }
        else {
            // Case 1: Insert the character from word2 into word1
            // Move to the next character in word2 while keeping the index in word1 the same.
            int insert = 1 + minOperation(word1, word2, i, j + 1);

            // Case 2: Remove the character from word1
            // Move to the next character in word1 while keeping the index in word2 the same.
            int remove = 1 + minOperation(word1, word2, i + 1, j);

            // Case 3: Replace the character in word1 with the character in word2
            // Move to the next character in both strings.
            int replace = 1 + minOperation(word1, word2, i + 1, j + 1);

            // Return the minimum number of operations needed from the three cases
            return min(insert, min(remove, replace));
        }
    }

    // Function to initialize the recursion with starting indices of 0
    int minDistance(const string& word1, const string& word2) {
        int i = 0;  // Start index for word1
        int j = 0;  // Start index for word2
        return minOperation(word1, word2, i, j);
    }
};

Time Complexity = O(m * n)
Space Complexity = O(m * n)
=> where m and n are the lengths of word1 and word2, respectively.
```
