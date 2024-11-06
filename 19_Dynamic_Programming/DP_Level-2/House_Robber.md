# Question : [House Robber - (LeetCode : 198)](https://leetcode.com/problems/house-robber/description/)

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return _the maximum amount of money you can rob tonight_ **_without alerting the police_**.

### Example 1

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

### Example 2

```
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
```

### Constraints

-   `1 <= nums.length <= 100`
-   `0 <= nums[i] <= 400`

### Recursive Approach

```Cpp
class Solution {
public:
    // Recursive function to calculate the maximum amount we can rob up to the given index.
    int recursion(vector<int>& nums, int index) {
        // Base case: If there is only one house, return its value.
        if (index == 0)
            return nums[0];

        // Base case: If there are two houses, return the max value of robbing either one.
        if (index == 1)
            return max(nums[0], nums[1]);

        // Recursive case:
        // Choice 1: Rob the current house and add the result from index - 2 (to avoid adjacent robbery).
        int robHouse = nums[index] + recursion(nums, index - 2);

        // Choice 2: Skip the current house and take the maximum value up to index - 1.
        int skipHouse = 0 + recursion(nums, index - 1);

        // Return the maximum of the both choices.
        return max(robHouse, skipHouse);
    }

    int rob(vector<int>& nums) {
        // Start the recursion from the last house (index n-1)
        return recursion(nums, n - 1);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& nums, int index, vector<int>& dp) {
        // Base case: If there is only one house, return its value.
        if (index == 0)
            return nums[0];

        // Base case: If there are two houses, return the max value of robbing either one.
        if (index == 1)
            return max(nums[0], nums[1]);

        // Check if the result for the current index is already computed, if yes, return it.
        if (dp[index] != -1)
            return dp[index];

        // Rob the current house and add the result from index - 2 (to avoid adjacent robbery).
        int robHouse = nums[index] + memoization(nums, index - 2, dp);

        // Skip the current house and take the maximum value up to index - 1.
        int skipHouse = 0 + memoization(nums, index - 1, dp);

        // Store the maximum of both choices in dp array and return it.
        dp[index] = max(robHouse, skipHouse);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return memoization(nums, n-1, dp);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        // Edge case: If there's only one house, rob it and return its value.
        if (n == 1)
            return nums[0];

        // Initialize the base cases:
        dp[0] = nums[0];                      // Maximum amount when there's only the first house.
        dp[1] = max(nums[0], nums[1]);        // Maximum amount when there are two houses.

        // Build the dp array iteratively starting from the third house.
        for (int i = 2; i < n; i++) {
            // Rob the current house, add amount from non-adjacent house (i-2).
            int robHouse = nums[i] + dp[i - 2];

            // Skip current house, take max amount up to previous house (i-1).
            int skipHouse = 0 + dp[i - 1];

            // Store the maximum result of robbing or skipping in dp[i].
            dp[i] = max(robHouse, skipHouse);
        }

        // The result is stored at the last index, which represents the max value up to the last house.
        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        return tabulation(nums);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    // Space-optimized version of the tabulation approach.
    int spaceOptimization(vector<int>& nums) {
        int n = nums.size();

        // Edge case: If there's only one house, rob it and return its value.
        if (n == 1)
            return nums[0];

        // Edge case: If there are two houses, rob the one with higher value.
        if (n == 2)
            return max(nums[0], nums[1]);

        // Initialize variables to hold the max values up to the previous two houses.
        int prev2 = nums[0];                  // Max amount for the first house.
        int prev1 = max(nums[0], nums[1]);    // Max amount for the first two houses.
        int curr;                             // Variable to store the current max amount.

        // Calculate maximum value iteratively for each house starting from the third.
        for (int i = 2; i < n; i++) {
            // Rob current house and add result from two houses before (prev2).
            int robHouse = nums[i] + prev2;

            // Skip current house and take result up to the previous house (prev1).
            int skipHouse = 0 + prev1;

            // Current max is the maximum of robbing or skipping the current house.
            curr = max(robHouse, skipHouse);

            // Update prev2 and prev1 to the next values in sequence.
            prev2 = prev1;
            prev1 = curr;
        }

        // Return the final result stored in curr, representing the maximum money robbed up to the last house.
        return curr;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        return spaceOptimization(nums);
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
