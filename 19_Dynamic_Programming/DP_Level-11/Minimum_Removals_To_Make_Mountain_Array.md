# Question : [Minimum Number of Removals to Make Mountain Array - (LeetCode : 1671)](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/)

You may recall that an array `arr` is a **mountain array** if and only if:

-   `arr.length >= 3`
-   There exists some index i (**0-indexed**) with `0 < i < arr.length - 1` such that:
    -   `arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
    -   `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

Given an integer array `nums`​​​, return _the **minimum** number of elements to remove to make `nums`​​​ a_ **_mountain array_**.

### Example 1

```
Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.
```

### Example 2

```
Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5,
making the array nums = [1,5,6,3,1].
```

### Constraints

-   `3 <= nums.length <= 1000`
-   `1 <= nums[i] <= 10^9`
-   It is guaranteed that you can make a mountain array out of `nums`.

### Binary Search Approach

```Cpp
class Solution {
public:
    // Function to find the length of the Longest Increasing Subsequence (LIS).
    int binarySearchApproach(vector<int>& arr, vector<int>& lis) {
        // If the array is empty, return 0 as there's no LIS
        if(arr.size() == 0)
            return 0;

        // Vector to store the LIS result
        vector<int> result;

        // `lis` stores the length of LIS ending at each index.
        // Initialize the LIS for the first element as 1.
        lis.push_back(1);

        // Start the LIS with the first element of the array.
        // First element of the LIS is the first element of the array
        result.push_back(arr[0]);

        // Iterate over the array to compute LIS using binary search.
        for(int i = 1; i < arr.size(); i++) {
            // If the current element is greater than the last element in `result`, extends the LIS.
            if(arr[i] > result.back()) {
                result.push_back(arr[i]);           // Add current element to LIS
                lis.push_back(result.size());       // Store the length of LIS at this position
            }
            // Otherwise, find the position in `result` where `arr[i]` can replace
            // an element to maintain the LIS property.
            else {
                // find the correct position to replace it using binary search.
                int index = lower_bound(result.begin(), result.end(), arr[i]) - result.begin();

                // Replace the element at the found position
                result[index] = arr[i];

                // Update LIS length for this index.
                lis.push_back(index + 1);
            }
        }

        // Return the length of the LIS, which is the length of the longest increasing subsequence
        return result.size();
    }

    // Function to calculate the minimum number of removals to make a mountain array.
    int minimumMountainRemovals(vector<int>& nums) {
        // `lis` = Longest Increasing Subsequence lengths for each index.
        // `lds` = Longest Decreasing Subsequence lengths for each index.
        vector<int> lis, lds;

        // Calculate LIS from left to right
        binarySearchApproach(nums, lis);

        // Reverse the array and calculate LIS (which will be LDS in the original array)
        reverse(nums.begin(), nums.end());
        binarySearchApproach(nums, lds);

        // Initialize the largest valid mountain size to a very small value.
        int largestMountain = INT_MIN;

        // Iterate through each index to find the largest mountain subsequence.
        for(int i = 0; i < nums.size(); i++) {
            // Skip elements where the LIS or LDS value is 1 (no valid mountain) at the same index.
            if(lis[i] == 1 || lds[nums.size() - i - 1] == 1)
                continue;

            // Compute the size of the mountain at index `i`.
            // Subtract 1 to avoid double-counting the peak element.
            largestMountain = max(largestMountain, lis[i] + lds[nums.size() - i - 1] - 1);
        }

        // Calculate the minimum removals required to form the mountain array.
        int minRemovals = nums.size() - largestMountain;

        return minRemovals;
    }
};

Time Complexity = O(nlogn)
Space Complexity = O(n)
```
