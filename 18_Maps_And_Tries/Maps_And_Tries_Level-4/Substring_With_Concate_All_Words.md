# Question : [Substring with Concatenation of All Words - (LeetCode : 30)](https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/)

You are given a string s and an array of strings `words`. All the strings of `words` are of **the same length**.

A **concatenated string** is a string that exactly contains all the strings of any permutation of `words` concatenated.
- For example, if `words = ["ab","cd","ef"]`, then "`abcdef`", "`abefcd`", "`cdabef`", "`cdefab`", "`efabcd`", and "`efcdab`" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of `words`.

Return an array of *the starting indices* of all the concatenated substrings in `s`. You can return the answer in **any order**.

### Example 1

```
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation:
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
```

### Example 2

```
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation:
There is no concatenated substring.
```

### Example 3

```
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
Explanation:
The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].
```

### Constraints

-   `1 <= s.length <= 10^4`
-   `1 <= words.length <= 5000`
-   `1 <= words[i].length <= 30`
-   `s` and `words[i]`consist of lowercase English letters.


## Solution

```Cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // Initialize a map to count occurrences of each word in 'words'.
        // This helps in quickly checking if a substring of 's' is a required word and how many times it appears.
        unordered_map<string, int> mp;

        // Vector to store starting indices of substrings that match the concatenation of 'words'.
        vector<int> ans;

        // Populate the map with the frequency of each word in 'words'.
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            mp[word]++;
        }

        // Define the length of each word in 'words' (assumption: all words are of the same length).
        int wordLength = words[0].length();

        // Traverse the string with different starting offsets to ensure all potential substrings are checked.
        // We use offsets from 0 to wordLength - 1 to handle each possible starting position within a word-length block.
        for(int offset = 0; offset < wordLength; offset++) {
            // Track occurrences of words found in the current window.
            unordered_map<string, int> visited;

            // Count of valid words found consecutively in the current window.
            int count = 0;

            // Slide over the string in chunks of wordLength starting from 'offset'.
            for(int i = offset; i + wordLength <= s.length(); i = i + wordLength) {
                // Extract the substring of length 'wordLength' at the current position.
                string str = s.substr(i, wordLength);

                // Check if the extracted substring is a word in 'words'.
                if(mp.find(str) == mp.end()) {
                    // If it's not in 'words', reset the visited map and count.
                    visited.clear();
                    count = 0;
                } 
                // If it is a valid word, ncrement its count in 'visited' and the count of valid words.
                else {
                    visited[str]++;
                    count++;

                    // If a word's count exceeds its required frequency in 'words', adjust the window.
                    while(visited[str] > mp[str]) {
                        // Remove the leftmost word from the window by decreasing its count in 'visited'.
                        string remove = s.substr(i - (count - 1) * wordLength, wordLength);
                        visited[remove]--;

                        // Reduce the valid count as we shrink the window.
                        count--;
                    }

                    // If the current count matches the total words in 'words', add the start index of this substring to 'ans'.
                    if(count == words.size()) {
                        ans.push_back(i - (count - 1) * wordLength);
                    }
                }
            }
        }

        // Return all starting indices where the concatenation of all words in 'words' was found.
        return ans;
    }
};

Time Complexity = O(N * wordLength) => "N" is the length of 's'
Space Complexity = O(L * wordLength) => "L" is the number of unique words in 'words'
```