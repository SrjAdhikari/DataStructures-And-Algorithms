# Question : [Subarray Product Less Than K - (LeetCode : 713)](https://leetcode.com/problems/subarray-product-less-than-k/description/)

Given an array of integers `nums` and an integer `k`, return _the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than_ `k`.

### Example 1

```
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
```

### Example 2

```
Input: nums = [1,2,3], k = 0
Output: 0
```

### Constraints

-   `1 <= nums.length <= 3 * 10^4`
-   `1 <= nums[i] <= 1000`
-   `0 <= k <= 10^6`

## Solution 1 : Brute-force Approach

```Cpp
class Solution {
public:
    // Function to count the number of subarrays whose product is less than k
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int total = 0;  // Variable to store the total count of subarrays with product < k

        // Outer loop: Iterate over each starting index of the subarray
        for(int i = 0; i < nums.size(); i++) {
            int product = 1;  // Initialize the product of the current subarray

             // Inner loop: Iterate from the current starting index `i` to the end of the array
            for(int j = i; j < nums.size(); j++) {
                product *= nums[j];  // Multiply the current element to the product

                // If the product is less than k, it means the subarray from i to j has a valid product
                if(product < k) {
                    total++;    // Increment the count of valid subarrays
                }
                // If the product becomes greater than or equal to k, stop extending this subarray
                // since any further extensions will only increase the product
                else {
                    break;
                }
            }
        }

        // Return the total number of subarrays whose product is less than k
        return total;
    }
};

Time Complexity = O(N^2)
Space Complexity = O(1)
```

## Solution 2 : Optimized Approach

```Cpp
class Solution {
public:
    // Function to count the number of subarrays whose product is less than k
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Edge case: if k is less than or equal to 1, no subarray can have a product less than k.
        if (k <= 1) return 0;

        int start = 0;      // Left boundary of the sliding window
        int end = 0;        // Right boundary of the sliding window
        int product = 1;    // Variable to store the product of the current subarray
        int count = 0;      // Variable to store the total count of subarrays

        // Iterate over the array with the 'end' pointer
        while (end < nums.size()) {
            // Multiply the current element at 'end' to the product
            product *= nums[end];

            // If the product is greater than or equal to k, shrink the window from the left (by moving `start`)
            // until the product becomes less than k.
            while (product >= k && start <= end) {
                product /= nums[start];     // Divide the element at `start` to reduce the product
                start++;                    // Move the left boundary of the window to the right
            }

            // The number of subarrays with product less than k ending at `end` is (end - start + 1)
            count += end - start + 1;

            // Expand the window by moving the right boundary to the right
            end++;
        }

        // Return the total number of subarrays whose product is less than k
        return count;
    }
};

Time Complexity = O(N)
Space Complexity = O(K)
```
