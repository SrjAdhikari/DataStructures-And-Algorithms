# Question : [Partition Equal Subset Sum - (LeetCode : 416)](https://leetcode.com/problems/partition-equal-subset-sum/description/)

Given an integer array `nums`, return `true` *if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or* `false` *otherwise*.

### Example 1

```
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
```

### Example 2

```
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
```

### Constraints

-   `1 <= nums.length <= 200`
-   `1 <= nums[i] <= 100`

### Recursive Approach

```Cpp

class Solution {
public:
    bool recursion(vector<int>& nums, int index, int currSum, int target) {
        // Base case 1: If we have processed all the elements and not found a valid subset, return false
        if (index >= nums.size())
            return false;

        // Base case 2: If the current sum exceeds the target, this path is invalid, return false
        if (currSum > target)
            return false;

        // Base case 3: If the current sum matches the target, we have found a valid subset, return true
        if (currSum == target)
            return true;

        // Recursive case 1: Include the current element in the subset and move to the next index.
        bool include = recursion(nums, index + 1, currSum + nums[index], target);

        // Recursive case 2: Exclude the current element and move to the next index.
        bool exclude = recursion(nums, index + 1, currSum, target);

        // Return true if either including or excluding the current element leads to a solution
        return include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        // Variable to store the total sum of the array.
        int totalSum = 0; 

        // Step 1: Calculate the total sum of all elements.
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        // Step 2: If the total sum is odd, it is impossible to partition the array into two equal subsets.
        if (totalSum & 1) return false;

        // Step 3: Set the target sum for each subset to half of the total sum.
        int target = totalSum / 2;

        return recursion(nums, 0, 0, target);
    }
};

Time Complexity = O(2^N)
Space Complexity = O(N)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    bool memoization(vector<int>& nums, int index, int currSum, int target, vector<vector<int>>& dp) {
        // Base case 1: If we have processed all the elements and not found a valid subset, return false
        if (index >= nums.size())
            return false;

        // Base case 2: If the current sum exceeds the target, this path is invalid, return false
        if (currSum > target)
            return false;

        // Base case 3: If the current sum matches the target, we have found a valid subset, return true
        if (currSum == target)
            return true;

        // Check if the result for this state (index, currSum) is already computed., if yes, return it
        if (dp[index][currSum] != -1)
            return dp[index][currSum];

        // Recursive case 1: Include the current element in the subset and move to the next index.
        bool include = memoization(nums, index + 1, currSum + nums[index], target, dp);

        // Recursive case 2: Exclude the current element and move to the next index.
        bool exclude = memoization(nums, index + 1, currSum, target, dp);

        // Store and return true if either including or excluding the current element leads to a solution
        return dp[index][currSum] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        // Variable to store the total sum of the array.
        int totalSum = 0; 

        // Step 1: Calculate the total sum of all elements.
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        // Step 2: If the total sum is odd, it is impossible to partition the array into two equal subsets.
        if (totalSum & 1) return false;

        // Step 3: Set the target sum for each subset to half of the total sum.
        int target = totalSum / 2;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
        return memoization(nums, 0, 0, target, dp);
    }
};

Time Complexity = O(N * target)
Space Complexity = O(N * target)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& nums, int target) {
        // Number of elements in the input array.
        int n = nums.size();

        // Create a DP table where dp[i][j] indicates whether we can achieve sum 'j' using the first 'i' elements.
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base case: It's always possible to achieve a sum of 0 (select no elements)
        // For every row, if the sum is 0, we set dp[row][0] to true.
        for (int row = 0; row <= n; row++) {
            dp[row][target] = 1;
        }

        // Fill the DP table in reverse order (bottom-up approach).
        // Loop through all elements from last to first
        for (int index = n - 1; index >= 0; index--) {
            // Loop through all possible sums from target to 0
            for (int currSum = target; currSum >= 0; currSum--) {
                bool include = 0;
                if (currSum + nums[index] <= target)
                    // Include the current element in the subset and move to the next index.
                    include = dp[index + 1][currSum + nums[index]];

                // Exclude the current element and move to the next index.
                bool exclude = dp[index + 1][currSum];

                // Store the current sum in the DP array.
                dp[index][currSum] = include || exclude;
            }
        }

        // The answer is stored in dp[0][0].
        return dp[0][0];
    }

    bool canPartition(vector<int>& nums) {
        // Variable to store the total sum of the array.
        int totalSum = 0; 

        // Step 1: Calculate the total sum of all elements.
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        // Step 2: If the total sum is odd, it is impossible to partition the array into two equal subsets.
        if (totalSum & 1) return false;

        // Step 3: Set the target sum for each subset to half of the total sum.
        int target = totalSum / 2;

        return tabulation(nums, target);
    }
};

Time Complexity = O(N * target)
Space Complexity = O(N * target)
```


### Space Optimized Approach

```Cpp
class Solution {
public:
    bool spaceOptimization(vector<int>& nums, int target) {
        // Number of elements in the input array.
        int n = nums.size();

        // Use two 1D arrays: one for the current state and one for the previous state
        vector<bool> curr(target + 1, 0);   // Current row for DP table
        vector<bool> next(target + 1, 0);   // Previous row for DP table

        // Base case: It's always possible to achieve a sum of 0
        curr[target] = 1;
        next[target] = 1;

        // Process elements from the last one to the first
        for (int index = n - 1; index >= 0; index--) {
            for (int currSum = target; currSum >= 0; currSum--) {
                bool include = 0;
                if (currSum + nums[index] <= target)
                    // Include the current element in the subset and move to the next index.
                    include = next[currSum + nums[index]];

                // Exclude the current element and move to the next index.
                bool exclude = next[currSum];

                // Update the current state for the current sum.
                curr[currSum] = include || exclude;
            }

            // Move current state to the next state for the next iteration.
            next = curr;
        }

        // The result is stored in `next[0]`, indicating whether the target sum is achievable.
        return next[0];
    }

    bool canPartition(vector<int>& nums) {
        // Variable to store the total sum of the array.
        int totalSum = 0; 

        // Step 1: Calculate the total sum of all elements.
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        // Step 2: If the total sum is odd, it is impossible to partition the array into two equal subsets.
        if (totalSum & 1) return false;

        // Step 3: Set the target sum for each subset to half of the total sum.
        int target = totalSum / 2;

        return spaceOptimization(nums, target);
    }
};

Time Complexity = O(N * target)
Space Complexity = O(target)
```