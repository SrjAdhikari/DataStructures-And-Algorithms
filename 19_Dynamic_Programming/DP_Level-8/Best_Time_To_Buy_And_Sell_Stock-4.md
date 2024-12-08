# Question : [Best Time to Buy and Sell Stock IV - (LeetCode : 188)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/)

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day, and an integer `k`.

Find the maximum profit you can achieve. You may complete at most `k` transactions: i.e. you may buy at most `k` times and sell at most `k` times.

**Note**: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

### Example 1

```
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
```

### Example 2

```
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```

### Constraints

-   `1 <= k <= 100`
-   `1 <= prices.length <= 1000`
-   `0 <= prices[i] <= 1000`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& prices, int index, int buy, int k) {
        // Base case: If we've reached the end of the array, no more profit can be made
        if(index >= prices.size())
            return 0;

        // Base case: If no transactions are left to make, return 0
        if(k == 0)
            return 0;

        int profit = 0;

        // If it's the 'buy' phase (we can buy a stock)
        if(buy) {
            // Option 1: Buy the stock at the current index and move to the next day (switch to 'sell' state)
            int buyIt = -prices[index] + recursion(prices, index+1, 0, k);

            // Option 2: Skip this day and stay in the 'buy' state
            int skip = 0 + recursion(prices, index+1, 1, k);

            // Choose the option that gives the maximum profit
            profit = max(buyIt, skip);
        }
        // If it's the 'sell' phase (we can sell a stock)
        else {
            // Option 1: Sell the stock at the current index and move to the next day (reduce k, switch to 'buy' state)
            int sellIt = prices[index] + recursion(prices, index+1, 1, k-1);

            // Option 2: Skip this day and stay in the 'sell' state
            int skip = 0 + recursion(prices, index+1, 0, k);

            // Choose the option that gives the maximum profit
            profit = max(sellIt, skip);
        }

        // Return the maximum profit
        return profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        return recursion(prices, 0, 1, k);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& prices, int index, int buy, int k, vector<vector<vector<int>>>& dp) {
        // Base case: If we've reached the end of the array, no more profit can be made
        if(index >= prices.size())
            return 0;

        // Base case: If no transactions are left to make, return 0
        if(k == 0)
            return 0;

        // If the result has already been computed, return it.
        if(dp[index][buy][k] != -1)
            return dp[index][buy][k];

        int profit = 0;

        // If it's the 'buy' phase (we can buy a stock)
        if(buy) {
            // Option 1: Buy the stock at the current index and move to the next day (switch to 'sell' state)
            int buyIt = -prices[index] + memoization(prices, index+1, 0, k, dp);

            // Option 2: Skip this day and stay in the 'buy' state
            int skip = 0 + memoization(prices, index+1, 1, k, dp);

            // Choose the option that gives the maximum profit
            profit = max(buyIt, skip);
        }
        // If it's the 'sell' phase (we can sell a stock)
        else {
            // Option 1: Sell the stock at the current index and move to the next day (reduce k, switch to 'buy' state)
            int sellIt = prices[index] + memoization(prices, index+1, 1, k-1, dp);

            // Option 2: Skip this day and stay in the 'sell' state
            int skip = 0 + memoization(prices, index+1, 0, k, dp);

            // Choose the option that gives the maximum profit
            profit = max(sellIt, skip);
        }

        // Store the result in the dp array and return it
        return dp[index][buy][k] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return memoization(prices, 0, 1, k, dp);
    }
};

Time Complexity = O(n * k)
Space Complexity = O(n * k)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(int k, vector<int>& prices) {
        int n = prices.size();

        // 3D DP array: dp[index][buy][limit] will store the maximum profit for the subproblem
        // n: number of days, buy: whether we can buy (1) or sell (0), limit: number of remaining transactions
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        // Fill the DP table from the last day to the first day
        for(int index = n-1; index >= 0; index--) {
            // Iterate for both 'buy' and 'sell' states
            for(int buy = 0; buy <= 1; buy++) {
                 // Iterate for all possible transaction limits
                for(int limit = 1; limit <= k; limit++) {
                    int profit = 0;

                    // If it's the 'buy' phase (we can buy a stock)
                    if(buy) {
                        // Option 1: Buy the stock at the current index
                        int buyIt = -prices[index] + dp[index+1][0][limit];

                        // Option 2: Skip this day and stay in the 'buy' state
                        int skip = 0 + dp[index+1][1][limit];

                        // Choose the option that gives the maximum profit
                        profit = max(buyIt, skip);
                    }
                    // If it's the 'sell' phase (we can sell a stock)
                    else {
                        // Option 1: Sell the stock at the current index and reduce transaction limit
                        int sellIt = prices[index] + dp[index+1][1][limit-1];

                        // Option 2: Skip this day and stay in the 'sell' state
                        int skip = 0 + dp[index+1][0][limit];

                        // Choose the option that gives the maximum profit
                        profit = max(sellIt, skip);
                    }

                    // Store the computed profit in the DP array
                    dp[index][buy][limit] = profit;
                }
            }
        }

        // The result will be stored in dp[0][1][k], where 0 is the starting index,
        // 1 means we are in the 'buy' phase, and k is the remaining transaction limit.
        return dp[0][1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        return tabulation(k, prices);
    }
};

Time Complexity = O(n * k)
Space Complexity = O(n * k)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(int k, vector<int>& prices) {
        int n = prices.size();

        // Two 2D arrays to store the current and next day's profits
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));

        // Fill the DP table from the last day to the first day
        for(int index = n-1; index >= 0; index--) {
            // Iterate for both 'buy' and 'sell' states
            for(int buy = 0; buy <= 1; buy++) {
                 // Iterate for all possible transaction limits
                for(int limit = 1; limit <= k; limit++) {
                    int profit = 0;

                    // If it's the 'buy' phase (we can buy a stock)
                    if(buy) {
                        // Option 1: Buy the stock at the current index
                        int buyIt = -prices[index] + next[0][limit];

                        // Option 2: Skip this day and stay in the 'buy' state
                        int skip = 0 + next[1][limit];

                        // Choose the option that gives the maximum profit
                        profit = max(buyIt, skip);
                    }
                    // If it's the 'sell' phase (we can sell a stock)
                    else {
                        // Option 1: Sell the stock at the current index and reduce transaction limit
                        int sellIt = prices[index] + next[1][limit-1];

                        // Option 2: Skip this day and stay in the 'sell' state
                        int skip = 0 + next[0][limit];

                        // Choose the option that gives the maximum profit
                        profit = max(sellIt, skip);
                    }

                    // Store the computed profit in the current DP array
                    curr[buy][limit] = profit;
                }
            }

            // Move the current array to the next array for the next iteration
            next = curr;
        }

         // Return the maximum profit for the initial state (starting at index 0, with buying state and k transactions)
        return next[1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        return spaceOptimization(k, prices);
    }
};

Time Complexity = O(n * k)
Space Complexity = O(k)
```
