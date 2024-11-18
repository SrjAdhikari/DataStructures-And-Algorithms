# Question : [Longest Increasing Subsequence - (LeetCode : 300)](https://leetcode.com/problems/longest-increasing-subsequence/description/)

Given an integer array `nums`, return *the length of the longest **strictly increasing subsequence***.

### Example 1

```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```

### Example 2

```
Input: nums = [0,1,0,3,2,3]
Output: 4
```

### Example 3

```
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```

### Constraints

-   `1 <= nums.length <= 2500`
-   `-10^4 <= nums[i] <= 10^4`

**Follow up**
Can you come up with an algorithm that runs in `O(n log(n))` time complexity?

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& nums, int curr, int prev) {
        // Base case: If curr reach the end of array, return 0 (no increasing subsequence possible).
        if(curr >= nums.size())
            return 0;
        
        // Variable to track the LIS including the current element.
        int include = 0;

        // Check if we can include the current element:
        // Either the previous element index is -1 (meaning there is no previous element),
        // or the current element is greater than the previous element (maintaining an increasing subsequence)
        if(prev == -1 || nums[curr] > nums[prev]) {
            // Include the current element and move to the next element (curr+1) and (prev = curr).
            include = 1 + recursion(nums, curr+1, curr);
        }

        // Variable to track the LIS excluding the current element.
        // Move to the next element without changing 'prev'
        int exclude = 0 + recursion(nums, curr+1, prev);
        
        // Return the maximum of including or excluding the current element
        return max(include, exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        return recursion(nums, curr, prev);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
   int memoization(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp) {
        // Base case: If curr reach the end of array, return 0 (no increasing subsequence possible).
        if(curr >= nums.size())
            return 0;

        // Check if the result for this (curr, prev) pair is already computed, if yes, return it.
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        // Variable to track the LIS including the current element.
        int include = 0;

        // If the previous element exists and is smaller than the current element (ensuring increasing order).
        if(prev == -1 || nums[curr] > nums[prev]) {
            // Include the current element and move to the next one.
            include = 1 + memoization(nums, curr+1, curr, dp);
        }

        // Variable to track the LIS excluding the current element.
        // Move to the next element without including the current one.
        int exclude = 0 + memoization(nums, curr+1, prev, dp);

        // Store the result for this (curr, prev) pair in the DP array and return it.
        return dp[curr][prev+1] = max(include, exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return memoization(nums, curr, prev, dp);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& nums) {
        int n = nums.size();

        // DP table where dp[i][j] represents the length of LIS ending at index i, having previous element at index j
        // We initialize the table with 0 because the minimum LIS length for any index is 0
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Iterate over the array start from the last element and fill the DP table in reverse order
        // Iterate backwards from the last index
        for(int curr = n-1; curr >= 0; curr--) {
            // Iterate backwards for previous indices
            for(int prev = curr-1; prev >= -1; prev--) {

                // Variable to track the LIS including the current element.
                int include = 0;

                // If the previous element exists and is smaller than the current element (ensuring increasing order).
                if(prev == -1 || nums[curr] > nums[prev]) {
                    // Include the current element and move to the next one.
                    include = 1 + dp[curr+1][curr+1];
                }

                // Variable to track the LIS excluding the current element.
                // Move to the next element without including the current one.
                int exclude = 0 + dp[curr+1][prev+1];

                // Store the computed LIS length for the current position in the DP array
                dp[curr][prev+1] = max(include, exclude);
            }
        }

        // Return the final result at dp[0][0], representing the LIS for the entire array
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        return tabulation(nums);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(vector<int>& nums) {
        int n = nums.size();

        // Use two 1D arrays to store results for the current and next rows of the DP table.
        vector<int> currRow(n+1, 0);  // Stores results for the current row.
        vector<int> nextRow(n+1, 0);  // Stores results for the next row.

       // Iterate over the array start from the last element and fill the DP table in reverse order
       // Iterate backwards from the last index
        for(int curr = n-1; curr >= 0; curr--) {
            // Iterate backwards for previous indices
            for(int prev = curr-1; prev >= -1; prev--) {

                // Variable to track the LIS including the current element.
                int include = 0;

                // If the previous element exists and is smaller than the current element (ensuring increasing order).
                if(prev == -1 || nums[curr] > nums[prev]) {
                    // Include the current element and move to the next one.
                    include = 1 + nextRow[curr+1];
                }

                // Variable to track the LIS excluding the current element.
                // Move to the next element without including the current one.
                int exclude = 0 + nextRow[prev+1];

                // Store the maximum of including or excluding the current element in the current row.
                currRow[prev+1] = max(include, exclude);
            }

            // Move the current row to next row for the next iteration
            nextRow = currRow;
        }

        // Return the LIS length for the entire strings
        return nextRow[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        return spaceOptimization(nums);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n)
```

### Binary Search Approach

```Cpp
class Solution {
public:
    int binarySearch(vector<int>& nums) {
        vector<int> ans;            // This will store the increasing subsequence.
        ans.push_back(nums[0]);     // Start by adding the first element to the subsequence.

        // Iterate over the array starting from the second element.
        for(int i = 1; i < nums.size(); i++) {
            // If the current element is greater than the last element in the subsequence,
            if(nums[i] > ans.back()) {
                // Add the current element to the subsequence
                ans.push_back(nums[i]);
            }
            // If the current element is smaller or equal to the last element,
            else {
                // find the correct position to replace it using binary search.
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();

                // Replace the element at the found position.
                ans[index] = nums[i];
            }
        }

        // Return the size of the array, which represents the length of the longest increasing subsequence.
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        return binarySearch(nums);
    }
};

Time Complexity = O(nlogn)
Space Complexity = O(n)
```