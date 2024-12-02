# Question : [Combination Sum IV - (LeetCode : 377)](https://leetcode.com/problems/combination-sum-iv/description/)

Given an array of **distinct** integers `nums` and a target integer `target`, return _the number of possible combinations that add up to_ `target`.

The test cases are generated so that the answer can fit in a **32-bit** integer.

### Example 1

```
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
```

### Example 2

```
Input: nums = [9], target = 3
Output: 0
```

### Constraints

-   `1 <= nums.length <= 200`
-   `1 <= nums[i] <= 1000`
-   All the elements of `nums` are unique.
-   `1 <= target <= 1000`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& nums, int target) {
        // Base case 1: If target becomes 0, we found a valid combination.
        if (target == 0) return 1;

        // Base case 2: If target becomes negative, it's not a valid combination.
        if (target < 0) return 0;

        // Initialize sum to keep track of the number of combinations.
        int sum = 0;

        // Iterate through all numbers in the input array `nums`.
        for (int num : nums) {
            // Recursively reduce the target by `num` and add the result to `sum`.
            sum += recursion(nums, target - num);
        }

        // Return the total number of combinations for the current target.
        return sum;
    }

    int combinationSum4(vector<int>& nums, int target) {
        return recursion(nums, target);
    }
};

Time Complexity = O(n^target)
Space Complexity = O(target)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& nums, int target, vector<int>& dp) {
        // Base case 1: If target becomes 0, we found a valid combination.
        if (target == 0) return 1;

        // Base case 2: If target becomes negative, it's not a valid combination.
        if (target < 0) return 0;

        // If the result for the current target is already computed, return it.
        if (dp[target] != -1) return dp[target];

        // Initialize sum to keep track of the number of combinations.
        int sum = 0;

        // Iterate through all numbers in the input array `nums`.
        for (int num : nums) {
            // Recursively reduce the target by `num` and add the result to `sum`.
            sum += memoization(nums, target - num, dp);
        }

        // Store the computed result in the dp array and return it.
        return dp[target] = sum;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return memoization(nums, target, dp);
    }
};

Time Complexity = O(n * target)
Space Complexity = O(target)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& nums, int target) {
        // Create a dp array to store results for all targets from 0 to target
        vector<int> dp(target + 1, 0);

        // Base case: There is exactly one way to form the sum 0 (by taking no elements).
        dp[0] = 1;

        // Fill the dp array for all target values from 1 to target
        for (int aim = 1; aim <= target; aim++) {
            long long sum = 0;  // Use long long to prevent potential integer overflow.

            // Iterate through all numbers in the input array `nums`.
            for (int num : nums) {
                // If the current number can contribute to the sum (aim - num >= 0),
                // add the number of ways to form the smaller target (dp[aim - num]) to the sum.
                if (aim - num >= 0)
                    sum += dp[aim - num];
            }

            // Store the computed result for the current `aim` in the dp array.
            dp[aim] = sum;
        }

        // Return the total combinations for the given target.
        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        return tabulation(nums, target);
    }
};

Time Complexity = O(n * target)
Space Complexity = O(target)
```
