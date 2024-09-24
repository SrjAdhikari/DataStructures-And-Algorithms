# Question : [Minimum Window Substring - (LeetCode : 76)](https://leetcode.com/problems/minimum-window-substring/description/)

Given two strings `s` and `t` of lengths `m` and `n` respectively, return *the ***minimum window substring*** of `s` such that every character in `t` (***including duplicates***) is included in the window*. If there is no such substring, return *the empty string* `""`.

The testcases will be generated such that the answer is **unique**.

### Example 1

```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

### Example 2

```
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
```

### Example 3

```
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
```

### Constraints

-   `m == s.length`
-   `n == t.length`
-   `1 <= m, n <= 10^5`
-   `s` and `t` consist of uppercase and lowercase English letters.

**Follow up** : Could you find an algorithm that runs in O(m + n) time?

## Solution

```Cpp
class Solution {
public:
    string minWindow(string s, string t) {
        // Map to store frequency of characters in string t
        unordered_map<char, int> map;
        // vector<int> map(256, 0); // Alternative of unordered_map
        
        // `start` and `end` represent the sliding window
        int start = 0, end = 0;
        
        // `length` stores the minimum length of valid window found
        int length = INT_MAX;
        
        // `index` stores the starting index of the smallest valid window
        int index = -1;
        
        // `total` represents the number of characters in t that are yet to be matched
        int total = t.size();

        // Initialize the frequency map for string t
        for(int i = 0; i < t.size(); i++) {
            map[t[i]]++;  // Increase the count of each character in t
        }

        // Start the sliding window approach
        while(end < s.size()) {
            // Decrease the frequency of the current character in s from the map
            map[s[end]]--;
            
            // If the current character in s matches a character in t (map[s[end]] >= 0),
            // decrease `total` as one more character is matched
            if(map[s[end]] >= 0) {
                total--;
            }

            // Once all characters of t are matched (`total == 0`), try to shrink the window
            while(total == 0 && start <= end) {
                // If the current window is smaller than the previously found window, update the length of the substring and index
                if(length > end - start + 1){
                    length = end - start + 1;  // Update the smallest length
                    index = start;             // Update the starting index of this window
                }
                
                // Now move the `start` pointer to the right to shrink the window
                // Increase the frequency of the character that will be removed from the window
                map[s[start]]++;

                // If the character removed is in t (map[s[start]] > 0), it means the window is no longer valid,
                // so increase `total` as this character needs to be matched again
                if(map[s[start]] > 0) {
                    total++;
                }
                
                // Move the `start` pointer to shrink the window
                start++;
            }

            // Move the `end` pointer to expand the window
            end++;
        }

        // If `index` was never updated, it means no valid window was found, return an empty string
        if(index == -1)
            return "";

        // Build and return the smallest valid window substring from the original string s
        string str = "";
        for(int i = index; i < index + length; i++) {
            str += s[i];  // Append each character in the window to the result string
        }

        return str;
    }
};

Time Complexity = O(m + n)
Space Complexity = O(n) => While using an unordered_map
Space Complexity = O(1) => While using vector
```