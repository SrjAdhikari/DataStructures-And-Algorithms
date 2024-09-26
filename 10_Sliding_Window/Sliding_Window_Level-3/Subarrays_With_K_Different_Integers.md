# Question : [Subarrays with K Different Integers - (LeetCode : 992)](https://leetcode.com/problems/subarrays-with-k-different-integers/description/)

Given an integer array `nums` and an integer `k`, return *the number of **good subarray** of* `nums`.

A **good array** is an array where the number of different integers in that array is exactly `k`.

- For example, `[1,2,3,1,2]` has 3 different integers: `1`, `2`, and `3`.

A **subarray** is a **contiguous** part of an array.

### Example 1

```
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: 
[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
```

### Example 2

```
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: 
[1,2,1,3], [2,1,3], [1,3,4].
```

### Constraints

-   `1 <= nums.length <= 2 * 10^4`
-   `1 <= nums[i], k <= nums.length`

## Solution

```Cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Step 1: Initialize necessary variables.
        int total = 0;                 // This will store the count of subarrays with exactly k distinct elements.
        unordered_map<int, int> freq;  // Hash map to track the frequency of elements in the current window.
        int start = 0, end = 0;        // Two pointers for the sliding window.
        int count = 0;                 // To count the number of distinct elements in the current window.

        // Step 2: First sliding window loop to find subarrays with exactly k distinct elements.
        while(end < nums.size()) {
            // Add the current element at 'end' to the frequency map.
            freq[nums[end]]++;

            // If this is the first occurrence of nums[end], increment the distinct count.
            if(freq[nums[end]] == 1) {
                count++;
            }

            // Step 3: If the number of distinct elements equals k, process the subarrays.
            // The inner loop shrinks the window from the left (start pointer) until there are fewer than k distinct elements.
            while(count == k) {
                // Add all subarrays starting from 'start' to the end of the array (nums.size() - end).
                total += nums.size() - end;

                // Remove the element at 'start' from the window by decrementing its frequency.
                freq[nums[start]]--;

                // If the frequency of nums[start] becomes 0, it means the element is no longer in the window,
                // so decrement the count of distinct elements.
                if(freq[nums[start]] == 0) {
                    count--;
                }

                // Move the start pointer to shrink the window.
                start++;
            }

            // Move the end pointer to expand the window.
            end++;
        }

        // Step 4: Reset variables to find subarrays with exactly (k+1) distinct elements (we do this to remove those cases from the total).
        start = 0, end = 0, count = 0;
        freq.clear();  // Clear the frequency map for reuse.
        k++;           // Increment k to handle subarrays with exactly (k+1) distinct elements.

        // Step 5: Second sliding window loop to remove subarrays with exactly (k+1) distinct elements.
        while(end < nums.size()) {
            // Add the current element at 'end' to the frequency map.
            freq[nums[end]]++;

            // If this is the first occurrence of nums[end], increment the distinct count.
            if(freq[nums[end]] == 1) {
                count++;
            }

            // Process subarrays where the number of distinct elements equals (k+1).
            while(count == k) {
                // Subtract all subarrays starting from 'start' to the end of the array (nums.size() - end)
                // since these subarrays have more than k distinct elements.
                total -= nums.size() - end;

                // Remove the element at 'start' from the window by decrementing its frequency.
                freq[nums[start]]--;

                // If the frequency of nums[start] becomes 0, decrement the count of distinct elements.
                if(freq[nums[start]] == 0) {
                    count--;
                }

                // Move the start pointer to shrink the window.
                start++;
            }

            // Move the end pointer to expand the window.
            end++;
        }

        // Step 6: Return the total count of subarrays with exactly k distinct elements.
        return total;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```
