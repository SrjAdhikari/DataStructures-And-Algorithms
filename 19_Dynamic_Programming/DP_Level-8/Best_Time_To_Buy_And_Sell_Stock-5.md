# Question : [Best Time to Buy and Sell Stock with Transaction Fee - (LeetCode : 714)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith day`, and an integer `fee` representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

**Note**:

-   You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
-   The transaction fee is only charged once for each stock purchase and sale.

### Example 1

```
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```

### Example 2

```
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
```

### Constraints

-   `1 <= prices.length <= 5 * 10^4`
-   `1 <= prices[i] < 5 * 10^4`
-   `0 <= fee < 5 * 10^4`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& prices, int fee, int index, int buy) {
        // Base case: If we've processed all the days, return 0 profit
        if(index >= prices.size())
            return 0;

        int profit = 0;

        // If it's the 'buy' phase (we can buy a stock)
        if(buy) {
            // Option 1: Buy the stock at current price, move to the next day and change the state to 'sell'
            int buyIt = -prices[index] + recursion(prices, fee, index+1, 0);

            // Option 2: Skip buying and move to the next day while remaining in the 'buy' state
            int skip = 0 + recursion(prices, fee, index+1, 1);

            // Choose the option that gives the maximum profit
            profit = max(buyIt, skip);
        }
        // If it's the 'sell' phase (we can sell a stock)
        else {
            // Option 1: Sell the stock at current price, deduct the transaction fee, move to the next day
            int sellIt = prices[index] + recursion(prices, fee, index+1, 1) - fee;

            // Option 2: Skip selling and move to the next day while remaining in the 'sell' state
            int skip = 0 + recursion(prices, fee, index+1, 0);

            // Choose the option that gives the maximum profit
            profit = max(sellIt, skip);
        }
        return profit;
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& prices, int fee, int index, int buy, vector<vector<int>>& dp) {
        // Base case: If we've processed all the days, return 0 profit
        if(index >= prices.size())
            return 0;

        // Check if the result for the current state (index, buy) is already computed, if yes return it
        if(dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;

        // If it's the 'buy' phase (we can buy a stock)
        if(buy) {
            // Option 1: Buy the stock at current price, move to the next day and change the state to 'sell'
            int buyIt = -prices[index] + memoization(prices, fee, index+1, 0, dp);

            // Option 2: Skip buying and move to the next day while remaining in the 'buy' state
            int skip = 0 + memoization(prices, fee, index+1, 1, dp);

            // Choose the option that gives the maximum profit
            profit = max(buyIt, skip);
        }
        // If it's the 'sell' phase (we can sell a stock)
        else {
            // Option 1: Sell the stock at current price, deduct the transaction fee, move to the next day
            int sellIt = prices[index] + memoization(prices, fee, index+1, 1, dp) - fee;

            // Option 2: Skip selling and move to the next day while remaining in the 'sell' state
            int skip = 0 + memoization(prices, fee, index+1, 0, dp);

            // Choose the option that gives the maximum profit
            profit = max(sellIt, skip);
        }

        // Store the computed result in the DP table
        return dp[index][buy] = profit;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& prices, int fee) {
        int n = prices.size();

        // Initialize 2D DP array: dp[i][buy] stores the max profit at day i with the given buy/sell state
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        // Iterate over the days in reverse order (from last day to first day).
        for(int index = n-1; index >= 0; index--) {
            // For each day, iterate over the two possible states: whether to buy (buy = 1) or not (buy = 0).
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if(buy) {
                    // Option 1: Buy the stock at current price, move to the next day and change the state to 'sell'
                    int buyIt = -prices[index] + dp[index+1][0];

                    // Option 2: Skip buying and move to the next day while remaining in the 'buy' state
                    int skip = 0 + dp[index+1][1];

                    // Choose the option that gives the maximum profit
                    profit = max(buyIt, skip);
                }
                else {
                    // Option 1: Sell the stock at current price, deduct the transaction fee, move to the next day
                    int sellIt = prices[index] + dp[index+1][1] - fee;

                    // Option 2: Skip selling and move to the next day while remaining in the 'sell' state
                    int skip = 0 + dp[index+1][0];

                    // Choose the option that gives the maximum profit
                    profit = max(sellIt, skip);
                }

                // Store the computed result in the DP array
                dp[index][buy] = profit;
            }
        }

        // Return the result stored in dp[0][1], which represents the maximum profit starting from day 0 with the 'buy' state
        return dp[0][1];
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(vector<int>& prices, int fee) {
        int n = prices.size();

        // Initialize two 1D arrays: curr and next to store the results for the current and next day
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        // Iterate over the days in reverse order (from last day to first day).
        for(int index = n-1; index >= 0; index--) {
            // For each day, iterate over the two possible states: whether to buy (buy = 1) or not (buy = 0).
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if(buy) {
                    // Option 1: Buy the stock at current price, move to the next day and change the state to 'sell'
                    int buyIt = -prices[index] + next[0];

                    // Option 2: Skip buying and move to the next day while remaining in the 'buy' state
                    int skip = 0 + next[1];

                    // Choose the option that gives the maximum profit
                    profit = max(buyIt, skip);
                }
                else {
                    // Option 1: Sell the stock at current price, deduct the transaction fee, move to the next day
                    int sellIt = prices[index] + next[1] - fee;

                    // Option 2: Skip selling and move to the next day while remaining in the 'sell' state
                    int skip = 0 + next[0];

                    // Choose the option that gives the maximum profit
                    profit = max(sellIt, skip);
                }

                // Store the computed result in the current array
                curr[buy] = profit;
            }

            // Move the current array to the next array for the next iteration
            next = curr;
        }

        // Return the result stored in next[1], which represents the maximum profit starting from day 0 with the 'buy' state
        return next[1];
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
