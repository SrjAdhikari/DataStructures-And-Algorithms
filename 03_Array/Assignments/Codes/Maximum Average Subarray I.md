# Question : [Maximum Average Subarray I - (LeetCode : 643)](https://leetcode.com/problems/maximum-average-subarray-i/description/)

You are given an integer array `nums` consisting of `n` elements, and an integer `k`.

Find a contiguous subarray whose **length is equal to** `k` that has the maximum average value and return _this value_. Any answer with a calculation error less than `10`<sup>`-5`</sup> will be accepted.

### Example 1

```plaintext
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
```

### Example 2

```plaintext
Input: nums = [5], k = 1
Output: 5.00000
```

### Constraints

`n == nums.length`

`1 <= k <= n <= 10^5`

`-10^4 <= nums[i] <= 10^4`

## Solution 1

```Cpp
Brute Force Approach : 

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN;   // Initialize maxSum to the smallest integer value
        int i = 0, j = k - 1;   // Initialize pointers for the sliding window

        // Iterate over the array using a sliding window approach
        while (j < nums.size()) {
            
            int sum = 0; // Initialize the sum of the current window

            // Calculate the sum of elements in the current window
            for (int l = i; l <= j; l++) {
                sum += nums[l];
            }

            // Update maxSum if the current window sum is greater
            maxSum = max(maxSum, sum);

            // Move the sliding window forward
            i++, j++;
        }

        // Calculate the maximum average by dividing maxSum by k
        double maxAvg = maxSum / (double) k;
        return maxAvg;  // Return the maximum average
    }
};

Time Complexity = O(n^2)
Space Complexity = O(1)
```

## Solution 2

```Cpp
Sliding Window Approach : 

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int& k) {
        int start = 0, end = k - 1;     // Initialize two pointers to mark the start and end of the subarray
        int sum = 0;                    // Variable to store the sum of current subarray

        // Calculate the sum of the first subarray of length k
        for(int i = start; i <= end; i++)
            sum += nums[i];

        int maxSum = sum;   // Initialize maxSum with the sum of the first subarray
        end++;              // Move end to the next element after the initial subarray

        // Slide the window and find the maximum sum of subarrays of length k
        while(end < nums.size()){
            // Subtract the element at start and add the element at end to update the sum
            sum -= nums[start++];
            sum += nums[end++];
            
            // Update maxSum to store the maximum sum found so far
            maxSum = max(maxSum, sum);
        }

        // Calculate the maximum average by dividing maxSum by k
        double maxAvg = maxSum / (double) k;
        return maxAvg;  // Return the maximum average
    } 
};

Time Complexity = O(n)
Space Complexity = O(1)
```
