# Question : [Group Anagrams - (LeetCode : 49)](https://leetcode.com/problems/group-anagrams/description/)

Given an array of strings `strs`, group the anagrams together. You can return the answer in **any order**.

### Example 1

```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
 ● There is no string in strs that can be rearranged to form "bat".
 ● The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
 ● The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
```

### Example 2

```
Input: strs = [""]
Output: [[""]]
```

### Example 3

```
Input: strs = ["a"]
Output: [["a"]]
```

### Constraints

-   `1 <= strs.length <= 10^4`
-   `0 <= strs[i].length <= 100`
-   `strs[i]` consists of lowercase English letters.


## Solution

```Cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Initialize an unordered_map to store groups of anagrams.
        unordered_map<string, vector<string>> mp;

        // Loop through each string in the input vector `strs`
        for (int i = 0; i < strs.size(); i++) {
            string original = strs[i];  // Take the original string
            string copy = strs[i];      // Make a copy of the string to sort and use as a key

            // Sort the characters of the copied string
            // This sorted version serves as the "anagram signature" that will
            // group all anagrams together as they share the same sorted key
            sort(copy.begin(), copy.end());

            // Use the sorted string as the key in the map and push the original string
            // into the vector associated with this key
            mp[copy].push_back(original);
        }

        // Prepare the output vector to store grouped anagrams
        vector<vector<string>> ans;
        
        // Loop through the map to retrieve all anagram groups
        // Each map entry contains a vector of strings that are anagrams of each other
        for (auto& str : mp) {
            ans.push_back(str.second);  // Push the vector of anagrams into the result
        }

        // Return the grouped anagrams
        return ans;
    }
};

Time Complexity = O(N * M log M)
Space Complexity = O(N * M)
=> N is the number of strings and M is the length of each string.
```