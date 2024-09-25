# Question : [Binary Subarrays With Sum - (LeetCode : 930)](https://leetcode.com/problems/binary-subarrays-with-sum/description/)

Given a binary array `nums` and an integer `goal`, return *the number of non-empty **subarrays** with a sum* `goal`.

A **subarray** is a contiguous part of the array.

### Example 1

```
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
```

### Example 2

```
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
```

### Constraints

-   `1 <= nums.length <= 3 * 10^4`
-   `nums[i]` is either `0` or `1`.
-   `0 <= goal <= nums.length`

## Solution

```Cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int start = 0, end = 0;        // Two pointers for the sliding window.
        int prefixZero = 0;            // To count consecutive zeros before the start of the subarray with a sum equal to the goal.
        int count = 0;                 // To store the total count of valid subarrays with the sum equal to the goal.
        int sum = 0;                   // To track the sum of the current window.

        // Sliding window loop: Traverse the array to find subarrays with the sum equal to the goal.
        while(end < nums.size()) {
            // Add the current element (nums[end]) to the sum.
            sum += nums[end];

            // Shrink the window if the sum exceeds the goal or if there are leading zeros in the window.
            while(start < end && (sum > goal || nums[start] == 0)) {
                // If the element at start is 1, reset the count of prefix zeros.
                if(nums[start] == 1) {
                    prefixZero = 0;
                }
                // If the element is 0, increment the prefixZero count (counting leading zeros).
                else {
                    prefixZero += 1;
                }

                // Remove the element at the start pointer from the current sum, and move the start pointer forward to shrink the window.
                sum -= nums[start];
                start++;
            }

            // Check if the current sum equals the goal.
            // If the sum of the current window equals the goal, count all valid subarrays.
            if(sum == goal) {
                // Include the current subarray and any subarrays starting with prefix zeros.
                count += prefixZero + 1;
            }

            // Expand the window by moving the end pointer forward.
            end++;
        }

        // Return the total count of valid subarrays with the sum equal to the goal.
        return count;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```