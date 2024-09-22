# Question : [Subarray Sum Equals K - (LeetCode : 560)](https://leetcode.com/problems/subarray-sum-equals-k/description/)

Given an array of integers `nums` and an integer `k`, *return the total number of subarrays whose sum equals to* `k`.

A subarray is a contiguous **non-empty** sequence of elements within an array.

### Example 1

```
Input: nums = [1,1,1], k = 2
Output: 2
```

### Example 2

```
Input: nums = [1,2,3], k = 3
Output: 2
```

### Constraints

- `1 <= nums.length <= 2 * 10^4`
- `-1000 <= nums[i] <= 1000`
- `-10^7 <= k <= 10^7`

## Solution 1 : Brute-force Approach

```Cpp
class Solution {
public:
    // Function to count the number of subarrays whose sum is equal to a given value `k`
    int subarraySum(vector<int>& nums, int k) {
        int total = 0; // Stores the total count of subarrays with sum equal to `k`

        // Outer loop: Iterate over each starting index of the subarray
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;    // Initialize sum for the current subarray starting at index `i`

            // Inner loop: Iterate from the current starting index `i` to the end of the array
            for (int j = i; j < nums.size(); j++) {
                // Add the current element `nums[j]` to the sum of the subarray
                sum += nums[j];

                // If the sum of the current subarray is equal to `k`, increment the total count
                if (sum == k)
                    total++;
            }
        }

        // Return the total count of subarrays whose sum is equal to `k`
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
    int subarraySum(vector<int>& nums, int k) {
        int subArrayCount = 0;          // This variable stores the total count of subarrays with sum equal to k
        int prefixSum = 0;              // Stores the cumulative sum of elements up to the current index
        unordered_map<int, int> map;    // HashMap to store the frequency of each prefix sum
        map[0] = 1;                     // Initialize the map with 0 sum, which helps in case the subarray starts from index 0

        // Loop through the array to calculate the prefix sum
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];       // Update the prefix sum by adding the current element

            // Check if the prefix sum minus k exists in the map.
            // If it does, it means there is a subarray ending at the current index whose sum is equal to k.
            if (map.count(prefixSum - k)) {
                // Add the count of such prefix sums to the result
                subArrayCount += map[prefixSum - k]; 
            }

            // Increment the frequency of the current prefix sum in the map
            // If it exists, increment; if not, add it with a count of 1
            map[prefixSum]++;
        }

        // Return the total number of subarrays with sum equal to k
        return subArrayCount;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```
