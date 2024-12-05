# Question : [Best Time to Buy and Sell Stock II - (LeetCode : 122)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/)

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

On each day, you may decide to buy and/or sell the stock. You can only hold **at most one** share of the stock at any time. However, you can buy it then immediately sell it on the **same day**.

Find and return _the **maximum** profit you can achieve_.

### Example 1

```
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
```

### Example 2

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
```

### Example 3

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit,
so we never buy the stock to achieve the maximum profit of 0.
```

### Constraints

-   `1 <= prices.length <= 3 * 10^4`
-   `0 <= prices[i] <= 10^4`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& prices, int index, int buy) {
        // Base case: If we've reached the end of the array, no further profit can be made
        if(index >= prices.size())
            return 0;

        // Initialize profit for the current step
        int profit = 0;

        // If we are allowed to buy
        if(buy) {
            // Option 1: Buy the stock at the current price
            int buyIt = -prices[index] + recursion(prices, index + 1, 0);

            // Option 2: Skip buying and move to the next day
            int skip = recursion(prices, index + 1, 1);

            // Choose the maximum profit
            profit = max(buyIt, skip);
        }
        // If we are allowed to sell
        else {
            // Option 1: Sell the stock at the current price
            int sellIt = prices[index] + recursion(prices, index + 1, 1);

            // Option 2: Skip selling and move to the next day
            int skip = recursion(prices, index + 1, 0);

            // Choose the maximum profit
            profit = max(sellIt, skip);
        }

        // Return the maximum profit
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return recursion(prices, 0, 1);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& prices, int index, int buy, vector<vector<int>>& dp) {
        // Base case: If we've reached the end of the array, no further profit can be made
        if(index >= prices.size())
            return 0;

        // If we've already computed the result for this state (index, buy), return it.
        if(dp[index][buy] != -1)
            return dp[index][buy];

        // Initialize profit for the current step
        int profit = 0;

        // If we are allowed to buy
        if(buy) {
            // Option 1: Buy the stock at the current price
            int buyIt = -prices[index] + memoization(prices, index + 1, 0, dp);

            // Option 2: Skip buying and move to the next day
            int skip = memoization(prices, index + 1, 1, dp);

            // Choose the maximum profit
            profit = max(buyIt, skip);
        }
        // If we are allowed to sell
        else {
            // Option 1: Sell the stock at the current price
            int sellIt = prices[index] + memoization(prices, index + 1, 1, dp);

            // Option 2: Skip selling and move to the next day
            int skip = memoization(prices, index + 1, 0, dp);

            // Choose the maximum profit
            profit = max(sellIt, skip);
        }

        // Store the result in dp for the current (index, buy) state and return it.
        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return memoization(prices, 0, 1, dp);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& prices) {
        int n = prices.size();

        // Initialize a DP table with (n+1) rows and 2 columns (buy or not buy)
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Fill the DP table from the last day (index = n-1) to the first day (index = 0).
        for(int index = n - 1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {
                if(buy) {
                    int buyIt = -prices[index] + dp[index+1][0];
                    int skip = 0 + dp[index+1][1];
                    profit = max(buyIt, skip);
                }
                else {
                     int sellIt = prices[index] + dp[index+1][1];
                    int skip = 0 + dp[index+1][0];
                    profit = max(sellIt, skip);
                }
                // Store the computed profit in the DP table for the current day (index) and buy state.
                dp[index][buy] = profit;
            }
        }

        // Return the maximum profit at the first day, where we are allowed to buy.
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        return tabulation(prices);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(vector<int>& prices) {
        int n = prices.size();

        // Two arrays to hold current and next results.
        vector<int> curr(2, 0), next(2, 0);

        // Iterate from the last day (index = n-1) to the first day (index = 0).
        for(int index = n - 1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {
                if(buy) {
                    int buyIt = -prices[index] + next[0];
                    int skip = 0 + next[1];
                    profit = max(buyIt, skip);
                }
                else {
                    int sellIt = prices[index] + next[1];
                    int skip = 0 + next[0];
                    profit = max(sellIt, skip);
                }

                // Update the current array with the computed profit for the current day and buy state.
                curr[buy] = profit;
            }

            // Update next to current for the next iteration.
            next = curr;
        }

        // Return the maximum profit on the first day, where we are allowed to buy.
        return next[1];
    }

    int maxProfit(vector<int>& prices) {
        return spaceOptimization(prices);
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```

### Greedy Approach

```Cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        // Loop through the prices array and accumulate profits for every positive difference.
        for(int i = 1; i < n; i++) {
            // If the price goes up, we add the difference to profit.
            if(prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }

        // Return the total profit
        return profit;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
