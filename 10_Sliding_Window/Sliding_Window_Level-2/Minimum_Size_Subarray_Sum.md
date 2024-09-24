# Question : [Minimum Size Subarray Sum - (LeetCode : 209)](https://leetcode.com/problems/minimum-size-subarray-sum/description/)

Given an array of positive integers `nums` and a positive integer `target`, return _the ***minimal length*** of a subarray whose sum is greater than or equal to_ `target`. If there is no such subarray, return `0` instead.

### Example 1

```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
```

### Example 2

```
Input: target = 4, nums = [1,4,4]
Output: 1
```

### Example 3

```
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
```

### Constraints

-   `1 <= target <= 10^9`
-   `1 <= nums.length <= 10^5`
-   `1 <= nums[i] <= 10^4`

**Follow up** : If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

## Solution 1 : Brute-force Approach

```Cpp
class Solution {
public:
    // Function to find the minimum length of a contiguous subarray
    int minSubArrayLen(int target, vector<int>& nums) {
        // Initialize length to store the minimum length of subarray
        int length = INT_MAX;

        // Outer loop to set the starting point of the subarray
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;    // Initialize sum for the subarray starting at index i

            // Inner loop to find the sum of subarray starting from index i to j
            for(int j = i; j < nums.size(); j++) {
                // Add the current element to the subarray sum
                sum += nums[j];

                // If the current subarray sum is greater than or equal to the target
                // We calculate the length and update the total with the minimum value
                if(sum >= target) {
                    length = min(length, j - i + 1);  // Update minimum length
                }
            }
        }

        // If total was updated, we return it, otherwise we return 0
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
    // Function to find the minimum length of a contiguous subarray
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = INT_MAX;   // Initialize length to store the minimum length of the subarray
        int sum = 0;            // Variable to store the current sum of the window (between start and end)
        int start = 0;          // Start pointer of the sliding window
        int end = 0;            // End pointer of the sliding window

        // Expand the window by moving the 'end' pointer
        while(end < nums.size()) {
            // Add the current element to the sum
            sum += nums[end];

            // Once the sum is greater than or equal to the target,
            // try shrinking the window from the left by moving the start pointer
            while(sum >= target) {
                // Update the minimum length of the subarray
                length = min(length, end - start + 1);

                // Remove the element at 'start' from the sum and shrink the window
                sum -= nums[start];

                // Move the start pointer to the right
                start++;
            }

            // Move the end pointer to the right to expand the window
            end++;
        }

        // Return the minimum length found, or 0 if no such subarray was found
        return length == INT_MAX ? 0 : length;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
