# Question : [Longest Substring Without Repeating Characters - (LeetCode : 3)](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

Given a string `s`, find the length of the **longest substring** without repeating characters.

### Example 1

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

### Example 2

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

### Example 3

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

### Constraints

- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols and spaces.

## Solution 1 : Brute-force Approach

```Cpp
class Solution {
public:
    // This function checks if the substring s[start...end-1] contains all unique characters.
    bool allUnique(string s, int start, int end) {
        // Loop through each character in the substring starting from 'start' index.
        for (int i = start; i < end; i++) {
            // For each character at position 'i', check every character after it (from i+1 to end-1).
            for (int j = i + 1; j < end; j++) {
                // If a duplicate character is found (s[i] == s[j]), return false.
                if (s[i] == s[j]) {
                    return false;
                }
            }
        }
        // If no duplicate characters are found, return true.
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int n = s.size();  // Get the total length of the input string.
        int maxLen = 0;    // Variable to store the maximum length of a substring without repeating characters.
        
        // Loop through the string using 'i' as the starting point for the substrings.
        for (int i = 0; i < n; i++) {
            // For each 'i', loop through every possible end point of the substring (from i+1 to n)
            for (int j = i + 1; j <= n; j++) {
                // Check if the substring s[i...j-1] contains all unique characters
                if (allUnique(s, i, j)) {
                    // If the substring is unique, update the maximum length (j - i is the length of the current substring).
                    maxLen = max(maxLen, j - i);
                }
            }
        }
        // After checking all substrings, return the maximum length of a substring without repeating characters
        return maxLen;
    }
};

Time Complexity = O(N^3)
Space Complexity = O(1)
```

## Solution 2 : Optimized Approach

```Cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Initialize variable to store the maximum length of the substring without repeating characters
        int length = 0;
        
        // 'first' is the left pointer, and 'second' is the right pointer for the sliding window technique.
        int first = 0, second = 0;
        
        // Frequency array to keep track of the characters in the current window.
        // We use a vector of size 256 (since there are 256 possible ASCII characters) and initialize it with zeros.
        // If a character is present in the current window, we mark it as 1.
        vector<int> freq(256, 0);
        
        // Loop through the string with the 'second' pointer
        // This loop runs until the 'second' pointer reaches the end of the string.
        while (second < s.length()) {
            
            // Check if the current character s[second] is already in the substring (i.e., its frequency is non-zero).
            while (freq[s[second]]) {
                
                // If the character s[second] is already in the substring, reset the frequency of the character at s[first] to 0 as it is no longer part of the window and move the 'first' pointer (left of the window) to the next character.
                freq[s[first]] = 0;
                
                // move the 'first' pointer to the next character to shrink the window and eliminate the duplicate character.
                first++;
            }
            
            // Mark the current character s[second] as part of the window by setting its frequency to 1.
            // Because the character at s[second] is appearing for the first time in the current window.
            freq[s[second]] = 1;
            
            // Calculate the current window size, which is the distance between 'second' and 'first' pointers, 
            length = max(length, second - first + 1);
            
            // Move the 'second' pointer to expand the window by considering the next character.
            second++;
        }
        
        // After processing the entire string, return the maximum length of the substring found.
        return length;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
