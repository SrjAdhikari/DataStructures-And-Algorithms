# Question : [Repeated DNA Sequences - (LeetCode : 187)](https://leetcode.com/problems/repeated-dna-sequences/description/)

The **DNA sequence** is composed of a series of nucleotides abbreviated as `'A'`, `'C'`, `'G'`, and `'T'`.

-  example, `"ACGAATTCCG"` is a **DNA sequence**.

When studying **DNA**, it is useful to identify repeated sequences within the DNA.

Given a string `s` that represents a **DNA sequence**, return all the `10`-**letter-long** sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in **any order**.

### Example 1

```
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
```

### Example 2

```
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
```

### Constraints

-   `1 <= s.length <= 10^5`
-   `s[i]` is either `'A'`, `'C'`, `'G'`, or `'T'`.


## Solution

```Cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // Initialize an unordered_map to store each 10-character substring and its frequency count.
        unordered_map<string, int> map;

        // Vector to store the repeated 10-character sequences.
        vector<string> ans;

        // Edge case: If the string has fewer than 10 characters, no sequences of length 10 can exist.
        if(s.size() < 10)
            return {}; // Return an empty vector.

        // Traverse the string 's' and extract every possible 10-character substring.
        for(int i = 0; i <= s.size() - 10; i++) {
            // Extract a substring of length 10 starting from the current index 'i'.
            string currStrWindow = s.substr(i, 10);

            // Increment the count of the current 10-character substring in the map.
            map[currStrWindow]++;
        }

        // Iterate over the map to collect all substrings that appeared more than once.
        // This indicates that the substring is repeated in 's'.
        for(auto str : map) {
            // If a substring appeared more than once, add it to the answer vector.
            if(str.second > 1)
                ans.push_back(str.first);
        }

        // Alternative way to iterate using structured bindings (C++17 and above).
        // for(auto &[subStr, freq] : map) {
        //     if(freq > 1)
        //         ans.push_back(subStr);
        // }

        // Return the vector of repeated sequences.
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```