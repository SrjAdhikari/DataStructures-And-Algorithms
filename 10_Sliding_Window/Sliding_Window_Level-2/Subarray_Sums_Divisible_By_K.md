# Question : [Subarray Sums Divisible by K - (LeetCode : 974)](https://leetcode.com/problems/subarray-sums-divisible-by-k/description/)

Given an integer array `nums` and an integer `k`, return _the number of non-empty subarrays that have a sum divisible by_ `k`.

A **barray** is a **contiguous** part of an array.

### Example 1

```
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
```

### Example 2

```
Input: nums = [5], k = 9
Output: 0
```

### Constraints

-   `1 <= nums.length <= 3 * 10^4`
-   `-10^4 <= nums[i] <= 10^4`
-   `2 <= k <= 10^4`

## Solution 1 : Brute-force Approach

```Cpp
class Solution {
public:
    // Function to count the number of subarrays whose sum is divisible by `k`
    int subarraysDivByK(vector<int>& nums, int k) {
        int total = 0;      // Stores the total count of subarrays whose sum is divisible by `k`

        // Outer loop: Iterate over each starting index of the subarray
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;    // Initialize the sum for the current subarray starting at index `i`

            // Inner loop: Iterate from the current starting index `i` to the end of the array
            for (int j = i; j < nums.size(); j++) {
                // Add the current element `nums[j]` to the sum of the subarray
                sum += nums[j];

                // If the sum of the subarray is divisible by `k`, increment the total count
                if (sum % k == 0)
                    total++;
            }
        }

        // Return the total number of subarrays whose sum is divisible by `k`
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
    // Function to count the number of subarrays whose sum is divisible by `k`
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> map;    // Hash map to store the frequency of remainders
        map[0] = 1;                     // Initialize with 0 remainder for the prefix sum starting from index 0

        int prefixSum = 0;  // Variable to store cumulative sum of elements up to the current index
        int remainder = 0;  // Variable to store the remainder when prefixSum is divided by `k`
        int total = 0;      // Count of subarrays whose sum is divisible by `k`

        // Loop through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];       // Update the cumulative sum up to the current index
            remainder = prefixSum % k;  // Compute the remainder when prefixSum is divided by `k`

            // Handling negative remainders:
            // If the remainder is negative, add `k` to make it positive
            if (remainder < 0)
                remainder += k;

            // Check if this remainder has been seen before
            if (map.count(remainder)) {
                // If the remainder was seen before, it means there are subarrays ending at index `i`
                // whose sum is divisible by `k`. Add the count of such subarrays.
                total += map[remainder];
            }

            // Increment the count of the current remainder in the hash map
            map[remainder]++;
        }

        // Return the total number of subarrays whose sum is divisible by `k`
        return total;
    }
};

Time Complexity = O(N)
Space Complexity = O(K)
```
