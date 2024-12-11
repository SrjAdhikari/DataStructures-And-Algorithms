# Question : [Word Break - (LeetCode : 139)](https://leetcode.com/problems/word-break/description/)

Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

**Note** that the same word in the dictionary may be reused multiple times in the segmentation.

### Example 1

```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```

### Example 2

```
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
```

### Example 3

```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```

### Constraints

-   `1 <= s.length <= 300`
-   `1 <= wordDict.length <= 1000`
-   `1 <= wordDict[i].length <= 20`
-   `s` and `wordDict[i]` consist of only lowercase English letters.
-   All the strings of `wordDict` are **unique**.

### Recursive Approach

```Cpp
class Solution {
public:
    bool recursion(string s, unordered_set<string>& dict, int index) {
        // Base case: If we reach the end of the string, return true as the word can be segmented.
        if (index == s.size())
            return true;

        // Temporary variable to build substrings
        string word;

        // Try every possible substring starting from `index`.
        for (int i = index; i < s.size(); i++) {
            // Build the substring character by character.
            word += s[i];

            // Check if the current substring exists in the dictionary.
            if (dict.count(word)) {
                // Recur for the remaining substring starting from the next index.
                if (recursion(s, dict, i + 1))
                    // If recursion finds a valid segmentation, return true.
                    return true;
            }
        }

        // If no valid segmentation is found, return false.
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return recursion(s, dict, 0);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    bool memoization(string s, unordered_set<string>& dict, int index, vector<int>& dp) {
        // Base case: If we reach the end of the string, return true as the word can be segmented.
        if (index == s.size())
            return true;

        // If the result for the current index is already computed, return it.
        if (dp[index] != -1)
            return dp[index];

        // Temporary variable to build substrings.
        string word;

        // Try every possible substring starting from `index`.
        for (int i = index; i < s.size(); i++) {
            // Build the substring character by character.
            word += s[i];

            // Check if the current substring exists in the dictionary.
            if (dict.count(word)) {
                // Recur for the remaining substring starting from the next index.
                if (memoization(s, dict, i + 1, dp))
                    // Store and return true if valid segmentation is found.
                    return dp[index] = true;
            }
        }

        // If no valid segmentation is found, store and return false.
        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.size();
        vector<int>dp(n+1, -1);
        return memoization(s, dict, 0, dp);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(string s, unordered_set<string>& dict) {
        // Length of the input string.
        int n = s.size();

        // DP table initialized to 0. `dp[i]` represents if `s[i...]` can be segmented.
        vector<int> dp(n + 1, 0);

        // Base case: Empty substring can always be segmented.
        dp[n] = 1;

        // Iterate from the end of the string towards the beginning.
        for (int index = n - 1; index >= 0; index--) {
            // Temporary variable to build substrings.
            string word;

            // Try every possible substring starting from `index`.
            for (int i = index; i < s.size(); i++) {
                // Build the substring character by character.
                word += s[i];

                // Check if the current substring exists in the dictionary.
                if (dict.count(word)) {
                    // If the remaining substring can also be segmented, update DP and break.
                    if (dp[i + 1]) {
                        dp[index] = true;       // Mark current index as valid.
                        break;                  // No need to check further substrings from this index.
                    }
                }
            }
        }

        // Return whether the entire string can be segmented.
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return tabulation(s, dict);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n)
```
