# Question : [Longest Arithmetic Subsequence of Given Difference - (LeetCode : 1218)](https://leetcode.com/problems/longest-arithmetic-subsequence/description/)

Given an integer array `arr` and an integer `difference`, return the length of the longest subsequence in `arr` which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals `difference`.

A **subsequence** is a sequence that can be derived from `arr` by deleting some or no elements without changing the order of the remaining elements.

### Example 1

```
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].
```

### Example 2

```
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.
```

### Example 3

```
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
```

### Constraints

-   `1 <= arr.length <= 10^5`
-   `-10^4 <= arr[i], difference <= 10^4`

### Solution

```Cpp
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // A hash map to store the length of the longest subsequence that ends with a specific element.
        unordered_map<int, int> dp;

        // Variable to keep track of the maximum length of any valid subsequence.
        int length = 0;

        // Iterate over each element in the array to build the longest subsequence dynamically.
        for(int i = 0; i < arr.size(); i++) {
            // Calculate the expected previous element in the sequence.
            int element = arr[i] - difference;

            // Initialize the length of the subsequence ending with `element`.
            int diffLength = 0;

            // If the previous element (`element`) exists in `dp`, retrieve its subsequence length.
            if(dp.count(element))
                diffLength = dp[element];

            // Update the DP table for the current element to include itself in the subsequence.
            dp[arr[i]] = 1 + diffLength;

            // Update the overall maximum length if needed.
            length = max(length, dp[arr[i]]);
        }

        // Return the length of the longest subsequence found.
        return length;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
