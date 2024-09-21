# Question : [Smallest distinct window - GFG](https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1)

Given a string `s`, your task is to find the `smallest` window length that contains all the characters of the given string at least one time. For eg. A = `aabcbcdbca`, then the result would be 4 as of the smallest window will be `dbca`.

### Example 1

```
Input: "AABBBCBBAC"
Output: 3
Explanation: Sub-string -> "BAC"
```

### Example 2

```
Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"
```

### Example 3

```
Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR"
```

### Your Task:

You don't need to read input or print anything. Your task is to complete the function `findSubString()` which takes the string `str` as input and returns the length of the smallest such window of the string.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
```

### Constraints

- `1 ≤ |Str| ≤ 10^5`
- String may contain both type of English Alphabets.

## Solution 1 : Brute Force Approach

```Cpp
class Solution {
public:
    // Function to find the length of the smallest substring that contains all unique characters from the given string
    int findSubString(string str) {
        int size = str.length();    // Get the length of the input string
        if (size == 0)              // If the string is empty, return 0
            return 0;

        int length = INT_MAX;       // Initialize the length of the smallest substring to maximum integer value
        vector<int> freq(256, 0);   // Frequency array to count occurrences of characters in the string
        int uniqueChar = 0;         // Count of unique characters in the original string

        // Step 1: Count unique characters in the string
        for (int i = 0; i < size; i++) {
            // If this character has not been seen before, increment the unique character count
            if (freq[str[i]] == 0) {
                uniqueChar++;
            }

            // Increment the frequency of the current character
            freq[str[i]]++;
        }

        // Step 2: Iterate over the string to find the smallest substring
        for (int i = 0; i < size; i++) { 
            vector<int> count(256, 0);      // Frequency array for the current substring
            int currUniqueChar = 0;         // Count of unique characters in the current substring

            for (int j = i; j < size; j++) {
                count[str[j]]++;            // Increment the frequency of the current character in the substring

                // If this character is seen for the first time in the current substring, increment the count of unique characters
                if (count[str[j]] == 1) {
                    currUniqueChar++;
                }

                // Step 3: Check if the current substring contains all unique characters
                if (currUniqueChar == uniqueChar) {
                    // Update the minimum length if the current substring is smaller
                    length = min(length, j - i + 1);
                }
            }
        }

        // Step 4: Return the length of the smallest substring found, or 0 if no valid substring exists
        // If length is still INT_MAX, it means no valid substring was found
        return length == INT_MAX ? 0 : length;
    }
};

Time Complexity = O(N^2)
Space Complexity = O(1)
```

## Solution 2 : Optimized Approach

```Cpp
class Solution {
public:
    int findSubString(string str) {
        // Initialize length to maximum possible value to find the minimum later
        int length = INT_MAX;
        
        // Pointers for the sliding window
        int first = 0, second = 0;
        
        // Count of unique characters in the string
        int diffChar = 0;
        
        // Frequency array to count occurrences of each character
        vector<int> freq(256, 0);
        
        // Step 1: Count unique characters in the string
        while (first < str.length()) {
            // If this character hasn't been seen before increase the count of unique characters
            if (freq[str[first]] == 0) {
                diffChar++;
            }
            // Update the frequency of the current character, since we considered the current character
            freq[str[first]]++;

            // Move the first pointer forward to consider the next character
            first++;
        }

        // Step 2: Reset the frequency array for the next phase of searching
        for (int i = 0; i < 256; i++) {
            freq[i] = 0; 
        }
        
        // Reset the first pointer for the next phase
        first = 0;

        // Step 3: Sliding window to find the minimum length substring that contains all unique character
        while (second < str.length()) {
            // Expand the window until all unique characters are included
            while (diffChar && second < str.length()) {
                // If the current character is unique in the window, decrease the unique character count
                if (freq[str[second]] == 0) {
                    diffChar--;
                }
                // Increment the frequency of the current character in the window
                freq[str[second]]++;

                // Move to the next character, expanding the window
                second++;
            }
            
            // Update the minimum length found so far
            length = min(length, second - first);

            // Step 4: Shrink the left end of the window to find the minimum size substring
            // While we have more than 1 unique character in the window
            while (diffChar != 1) {
                // Update the minimum length again after contracting the left end
                length = min(length, second - first);

                // Reduce the frequency of the leftmost character in the window
                freq[str[first]]--;
                
                // If the frequency of this character becomes zero, it means we lost a unique character
                if (freq[str[first]] == 0) {
                    // Increase count because we have removed a unique character
                    diffChar++;
                }

                // Move the first pointer forward to shrink the window
                first++;
            }
        }
        // Return the length of the smallest substring containing all unique characters
        return length == INT_MAX ? 0 : length;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```