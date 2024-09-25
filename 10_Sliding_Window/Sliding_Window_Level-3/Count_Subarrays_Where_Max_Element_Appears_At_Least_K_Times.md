# Question : [Count Subarrays Where Max Element Appears at Least K Times - (LeetCode : 2962)](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/)

You are given an integer array `nums` and a **positive** integer `k`.

Return *the number of subarrays where the ***maximum*** element of `nums` appears ***at least*** `k` times in that subarray*.

A **subarray** is a contiguous sequence of elements within an array.

### Example 1

```
Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: 
[1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
```

### Example 2

```
Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
```

### Constraints

-   `1 <= nums.length <= 10^5`
-   `1 <= nums[i] <= 10^6`
-   `1 <= k <= 10^5`

## Solution

```Cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // Step 1: Find the maximum element in the array.
        int maxNum = INT_MIN;               // Variable to hold the maximum number found in the array
        for(int i = 0; i < nums.size(); i++) {
            maxNum = max(maxNum, nums[i]);  // Update maxNum if a larger element is found
        }

        // Step 2: Initialize sliding window pointers and variables.
        int start = 0, end = 0;         // Two pointers representing the sliding window
        int maxNumCount = 0;            // Variable to count occurrences of maxNum in the current window
        long long totalSubarrays = 0;   // Total number of valid subarrays

        // Step 3: Sliding window approach to find all subarrays with exactly k occurrences of maxNum.
        while(end < nums.size()) {
            // If the current element nums[end] is equal to maxNum, increment the count of maxNum..
            if(nums[end] == maxNum) {
                maxNumCount++;
            }

            // If we have exactly k occurrences of maxNum in the current window.
            while(maxNumCount == k) {
                // Calculate the number of subarrays starting from index 'start' that end at 'end' or later.
                totalSubarrays += nums.size() - end;

                // If the element at 'start' is equal to maxNum, decrease its count and shrink the window from the left.
                if(nums[start] == maxNum) {
                    maxNumCount--;
                }

                // Move the start pointer to the right to shrink the window
                start++;  
            }
            
            // Expand the window by moving the end pointer to the right.
            end++;
        }

        // Step 4: Return the total number of subarrays found.
        return totalSubarrays;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
