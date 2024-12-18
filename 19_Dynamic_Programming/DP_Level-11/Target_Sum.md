# Question : [Target Sum - (LeetCode : 494)](https://leetcode.com/problems/target-sum/description/)

You are given an integer array `nums` and an integer `target`.

You want to build an **expression** out of nums by adding one of the symbols `'+'` and `'-'` before each integer in nums and then concatenate all the integers.

-   For example, if `nums = [2, 1]`, you can add a `'+'` before `2` and a `'-'` before `1` and concatenate them to build the expression `"+2-1"`.

Return the number of different **expressions** that you can build, which evaluates to `target`.

### Example 1

```
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

### Example 2

```
Input: nums = [1], target = 1
Output: 1
```

### Constraints

-   `1 <= nums.length <= 20`
-   `0 <= nums[i] <= 1000`
-   `0 <= sum(nums[i]) <= 1000`
-   `-1000 <= target <= 1000`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& nums, int target, int index) {
        // Base case: If we've processed all elements and the target is 0, we've found a valid solution
        if(index == nums.size() && target == 0)
            return 1;

        // If we've processed all elements but the target is not 0, there's no valid solution
        if(index >= nums.size())
            return 0;

        // Try adding the current number to the target and proceed to the next number
        int addOne = recursion(nums, target + nums[index], index + 1);

        // Try subtracting the current number from the target and proceed to the next number
        int minusOne = recursion(nums, target - nums[index], index + 1);

        // Return the sum of both possibilities
        return addOne + minusOne;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return recursion(nums, target, 0);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& nums, int target, int index, map<pair<int, int>, int>& dp) {
        // Base case: If we've processed all elements and the target is 0, we've found a valid solution
        if(index == nums.size() && target == 0)
            return 1;

        // If we've processed all elements but the target is not 0, there's no valid solution
        if(index >= nums.size())
            return 0;

        // Check if the result for the current state is already computed, if yes return it.
        if(dp.count({target, index}))
            return dp[{target, index}];

        // Try adding the current number to the target and proceed to the next number
        int addOne = memoization(nums, target + nums[index], index + 1, dp);

        // Try subtracting the current number from the target and proceed to the next number
        int minusOne = memoization(nums, target - nums[index], index + 1, dp);

        // Store the result in the DP array and return it
        return dp[{target, index}] = addOne + minusOne;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        return memoization(nums, target, 0, dp);
    }
};

Time Complexity = O(n * T)
Space Complexity = O(n * T)
=> 'T' is the range of possible target values
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& nums, int target) {
        // Map-based DP to store the count of ways for {index, target}
        map<pair<int, int>, int> dp;

        // Base case: If we've processed all numbers and the target is 0, one valid way
        dp[{nums.size(), 0}] = 1;

        // Calculate the total sum of the numbers, as the possible target range is from -total to +total
        int total = 0;
        for(auto num : nums) total += num;

        // Iterate from the last index to the first index
        for(int index = nums.size() - 1; index >= 0; index--) {
            // Iterate over all possible target values, from -total to +total
            for(int target = -total; target <= total; target++) {
                // Check if adding the current number is valid and get its result
                int addOne = dp.count({index + 1, target + nums[index]}) ? dp[{index + 1, target + nums[index]}] : 0;

                // Check if subtracting the current number is valid and get its result
                int minusOne = dp.count({index + 1, target - nums[index]}) ? dp[{index + 1, target - nums[index]}] : 0;

                // Update the DP array with the sum of both possibilities
                dp[{index, target}] = addOne + minusOne;
            }
        }

        // Return the number of ways to achieve the target from the first index
        return dp[{0, target}];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return tabulation(nums, target);
    }
};

Time Complexity = O(n * T)
Space Complexity = O(n * T)
=> 'T' is the range of possible target values
```
