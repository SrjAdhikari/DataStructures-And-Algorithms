# Question : [Burst Balloons - (LeetCode : 312)](https://leetcode.com/problems/burst-balloons/description/)

You are given `n` balloons, indexed from `0` to `n - 1`. Each balloon is painted with a number on it represented by an array `nums`. You are asked to burst all the balloons.

If you burst the `ith` balloon, you will get `nums[i - 1] _ nums[i] _ nums[i + 1]` coins. If `i - 1` or `i + 1` goes out of bounds of the array, then treat it as if there is a balloon with a `1` painted on it.

Return _the maximum coins you can collect by bursting the balloons wisely_.

### Example 1

```
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
```

### Example 2

```
Input: nums = [1,5]
Output: 10
```

### Constraints

-   `n == nums.length`
-   `1 <= n <= 300`
-   `0 <= nums[i] <= 100`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& nums, int start, int end) {
        // Base case: If start exceeds end, no more coins can be collected.
        if(start > end)
            return 0;

        // Initialize maxCoins as minimum value
        int maxCoin = INT_MIN;

        // Try bursting each balloon between start and end, and calculate the maximum coins.
        for(int i = start; i <= end; i++) {
            // Calculate the coins for bursting the current balloon (i)
            int currCoin = nums[start-1] * nums[i] * nums[end+1];

            // Recursively calculate coins for the left and right subarrays (i.e., balloons to the left and right of i).
            int leftCoin = recursion(nums, start, i-1);
            int rightCoin = recursion(nums, i+1, end);

            // Total coins are the current coin + the left and right subarray coin collections.
            int totalCoin = currCoin + leftCoin + rightCoin;

            // Update the maximum coins obtained.
            maxCoin = max(maxCoin, totalCoin);
        }

        // Return the maximum coins collected.
        return maxCoin;
    }

    int maxCoins(vector<int>& nums) {
        // Add two 1s at the beginning and end of the array to simulate the edges as balloons with value 1.
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        int n = nums.size();

        return recursion(nums, 1, n-2);
    }
};

Time Complexity = O(3^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        // Base case: If start exceeds end, no more coins can be collected.
        if(start > end)
            return 0;

        // If the result for this subarray is already computed, return it from the DP array.
        if(dp[start][end] != -1)
            return dp[start][end];

        // Initialize maxCoins as minimum value
        int maxCoin = INT_MIN;

        // Try bursting each balloon between start and end, and calculate the maximum coins.
        for(int i = start; i <= end; i++) {
            // Calculate the coins for bursting the current balloon (i)
            int currCoin = nums[start-1] * nums[i] * nums[end+1];

            // Recursively calculate coins for the left and right subarrays (i.e., balloons to the left and right of i).
            int leftCoin = memoization(nums, start, i-1, dp);
            int rightCoin = memoization(nums, i+1, end, dp);

            // Total coins are the current coin + the left and right subarray coin collections.
            int totalCoin = currCoin + leftCoin + rightCoin;

            // Update the maximum coins obtained.
            maxCoin = max(maxCoin, totalCoin);
        }

        // Store and return the maximum coins collected.
        return dp[start][end] = maxCoin;
    }

    int maxCoins(vector<int>& nums) {
        // Add two 1s at the beginning and end of the array to simulate the edges as balloons with value 1.
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return memoization(nums, 1, n-2, dp);
    }
};

Time Complexity = O(n^3)
Space Complexity = O(n^2)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& nums) {
        // The effective size is n-2 because we added 1 at both ends.
        int n = nums.size() - 2;

        // Create a DP table to store the maximum coins for subarrays [start, end].
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Start iterating from the bottom of the DP table (from the smallest subarrays).
        for (int start = n; start >= 1; start--) {
            for (int end = start; end <= n; end++) {
                // Initialize maxCoins as minimum value
                int maxCoin = INT_MIN;

                // Try bursting each balloon between start and end, and calculate the maximum coins.
                for (int i = start; i <= end; i++) {
                    // Calculate the coins for bursting the current balloon (i)
                    int currCoin = nums[start - 1] * nums[i] * nums[end + 1];

                    // Add the coins obtained by bursting the left and right subarrays.
                    int leftCoin = dp[start][i - 1];
                    int rightCoin = dp[i + 1][end];

                    // Total coins are the current coin + the left and right subarray coin collections.
                    int totalCoin = currCoin + leftCoin + rightCoin;

                    // Update the maximum coins obtained.
                    maxCoin = max(maxCoin, totalCoin);
                }

                // Store the result for this subarray in the DP array.
                dp[start][end] = maxCoin;
            }
        }

        // Return the result for the entire subarray.
        return dp[1][n];
    }

    int maxCoins(vector<int>& nums) {
        // Add two 1s at the beginning and end of the array to simulate the edges as balloons with value 1.
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        // Return the result using the tabulation approach (bottom-up DP).
        return tabulation(nums);
    }
};

Time Complexity = O(n^3)
Space Complexity = O(n^2)
```
