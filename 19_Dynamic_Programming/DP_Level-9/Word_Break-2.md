# Question : [Word Break II - (LeetCode : 140)](https://leetcode.com/problems/word-break-ii/description/)

Given a string `s` and a dictionary of strings `wordDict`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in **any order**.

**Note** that the same word in the dictionary may be reused multiple times in the segmentation.

### Example 1

```
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
```

### Example 2

```
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
```

### Example 3

```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
```

### Constraints

-   `1 <= s.length <= 20`
-   `1 <= wordDict.length <= 1000`
-   `1 <= wordDict[i].length <= 10`
-   `s` and `wordDict[i]` consist of only lowercase English letters.
-   All the strings of `wordDict` are **unique**.
-   Input is generated in a way that the length of the answer doesn't exceed 10^5.

### Recursive Approach

```Cpp
class Solution {
public:
    vector<string> recursion(string& s, unordered_set<string>& dict, int index) {
        // Base case: If `index` reaches the end of the string, or the string is empty, return an empty string as a valid result.
        if (index == s.size() || s.empty())
            return {""};

        vector<string> result;      // To store the resulting sentences.
        string prefix;              // To build the current word.

        // Try every possible substring starting from `index`.
        for (int i = index; i < s.size(); i++) {
            // Add the current character to `prefix`.
            prefix += s[i];

            // If the prefix exists in the dictionary, explore further with the remaining string.
            if (dict.count(prefix)) {
                // Recursive call for the remaining substring starting from the next index.
                vector<string> suffixResults = recursion(s, dict, i + 1);

                // Combine the current prefix with each result from the recursive call.
                for (string word : suffixResults) {
                    // If there is a suffix, add a space between words.
                    if (!word.empty())
                        result.push_back(prefix + " " + word);

                    // If the suffix is empty, just add the prefix.
                    else
                        result.push_back(prefix);
                }
            }
        }

        // Return all valid segmentations for the current index.
        return result;
    }

     vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Convert the word dictionary into a hash set for fast lookups.
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
    vector<string> memoization(string& s, unordered_set<string>& dict, int index, unordered_map<int, vector<string>> dp) {
        // Base case: If `index` reaches the end of the string, or the string is empty, return an empty string as a valid result.
        if (index == s.size() || s.empty())
            return {""};

        // If the result for this index is already computed, return it.
        if (dp.find(index) != dp.end())
            return dp[index];

        vector<string> result;      // To store the resulting sentences.
        string prefix;              // To build the current word.

        // Try every possible substring starting from `index`.
        for (int i = index; i < s.size(); i++) {
            // Add the current character to `prefix`.
            prefix += s[i];

            // If the prefix exists in the dictionary, explore further with the remaining string.
            if (dict.count(prefix)) {
                // Recursive call for the remaining substring starting from the next index.
                vector<string> suffixResults = memoization(s, dict, i + 1, dp);

                // Combine the current prefix with each result from the recursive call.
                for (string word : suffixResults) {
                    // If there is a suffix, add a space between words.
                    if (!word.empty())
                        result.push_back(prefix + " " + word);

                    // If the suffix is empty, just add the prefix.
                    else
                        result.push_back(prefix);
                }
            }
        }

        // Store the result for the current index and return it.
        return dp[index] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Convert the word dictionary into a hash set for fast lookups.
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // Map to cache results for memoization.
        unordered_map<int, vector<string>> dp;
        return memoization(s, dict, 0, dp);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n * k)
=> 'k' is the average length of segmentations stored in the DP map.
```
