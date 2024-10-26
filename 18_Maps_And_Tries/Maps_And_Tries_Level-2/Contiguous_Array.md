# Question : [Contiguous Array - (LeetCode : 525)](https://leetcode.com/problems/contiguous-array/description/)

Given a binary array `nums`, return *the maximum length of a contiguous subarray with an equal number of `0` and `1`*.

### Example 1

```
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
```

### Example 2

```
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
```

### Constraints

-   `1 <= nums.length <= 10^5`
-   `nums[i] is either 0 or 1`.

## Solution

```Cpp
class Solution {
public:
    // Function to find the maximum length of a contiguous subarray with an equal number of 0s and 1s.
    int findMaxLength(vector<int>& nums) {
        // Initialize a variable to keep track of the cumulative sum.
        int sum = 0;

        // Variable to store the maximum length of subarrays found.
        int maxLength = 0;

        // Create an unordered map to store the first occurrence of each cumulative sum.
        unordered_map<int, int> mp;

        // Initialize with sum 0 occurring at index -1 to handle cases where the entire subarray is valid.
        mp[0] = -1;

        // Traverse the input array.
        for (int i = 0; i < nums.size(); i++) {
            // Treat 1s and 0s differently:
            // Increment the cumulative sum for a 1, and decrement for a 0.
            if(arr[i] == 1)
                sum++;      // For a 1, we consider it as +1.
            else 
                sum--;      // For a 0, we consider it as -1.

            // Check if this cumulative sum has been seen before.
            if (mp.count(sum)) {
                // If the sum has been seen before, calculate the length of the subarray
                // from the index of the first occurrence to the current index i.
                maxLength = max(maxLength, i - mp[sum]);
            } 
            else {
                // If this is the first time we encounter this sum,
                // store the index of its first occurrence.
                mp[sum] = i;
            }
        }

        // Return the maximum length of contiguous subarray with equal number of 0s and 1s.
        return maxLength;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```