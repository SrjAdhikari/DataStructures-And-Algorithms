# Question : [Best Time to Buy and Sell Stock III - (LeetCode : 123)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/)

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete **at most two transactions**.

**Note**: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

### Example 1

```
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```

### Example 2

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time.
You must sell before buying again.
```

### Example 3

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

### Constraints

-   `1 <= prices.length <= 10^5`
-   `0 <= prices[i] <= 10^5`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& prices, int index, int buy, int limit) {
        // Base case: If we have gone through all days or have no remaining transactions
        if(index >= prices.size() || limit == 0)
            return 0;

        int profit = 0;

        // If we are allowed to buy
        if(buy) {
            // Option 1: Buy the stock at the current price, then move to the next day with one less transaction
            int buyIt = -prices[index] + recursion(prices, index+1, 0, limit);

            // Option 2: Skip buying the stock and move to the next day
            int skip = 0 + recursion(prices, index+1, 1, limit);

            // Max profit by either buying or skipping
            profit = max(buyIt, skip);
        }
        // If we are allowed to sell
        else {
            // Option 1: Sell the stock at the current price and reduce the transaction limit by 1
            int sellIt = prices[index] + recursion(prices, index+1, 1, limit-1);

            // Option 2: Skip selling the stock and move to the next day
            int skip = 0 + recursion(prices, index+1, 0, limit);

            // Max profit by either selling or skipping
            profit = max(sellIt, skip);
        }

        // Return the maximum profit
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return recursion(prices, 0, 1, 2);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& prices, int index, int buy, int limit, vector<vector<vector<int>>>& dp) {
        // Base case: If we have gone through all days or have no remaining transactions
        if(index >= prices.size() || limit == 0)
            return 0;

        // Check if the result is already calculated for this state, if yes return it.
        if(dp[index][buy][limit] != -1)
            return dp[index][buy][limit];

        int profit = 0;

        // If we are allowed to buy
        if(buy) {
            // Option 1: Buy the stock at the current price, then move to the next day with one less transaction
            int buyIt = -prices[index] + memoization(prices, index+1, 0, limit, dp);

            // Option 2: Skip buying the stock and move to the next day
            int skip = 0 + memoization(prices, index+1, 1, limit, dp);

            // Max profit by either buying or skipping
            profit = max(buyIt, skip);
        }
        // If we are allowed to sell
        else {
            // Option 1: Sell the stock at the current price and reduce the transaction limit by 1
            int sellIt = prices[index] + memoization(prices, index+1, 1, limit-1, dp);

            // Option 2: Skip selling the stock and move to the next day
            int skip = 0 + memoization(prices, index+1, 0, limit, dp);

            // Max profit by either selling or skipping
            profit = max(sellIt, skip);
        }

        // Store the result for the current state and return it
        return dp[index][buy][limit] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return memoization(prices, 0, 1, 2, dp);
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

        // 3D DP table to store profit for each state: [index][buy][limit]
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Fill the DP table from the last day to the first day
        for(int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if(buy) {
                        // Option 1: Buy the stock at the current price, then move to the next day with one less transaction
                        int buyIt = -prices[index] + dp[index+1][0][limit];

                        // Option 2: Skip buying the stock and move to the next day
                        int skip = 0 + dp[index+1][1][limit];

                        // Max profit by either buying or skipping
                        profit = max(buyIt, skip);
                    }
                    else {
                        // Option 1: Sell the stock at the current price and reduce the transaction limit by 1
                        int sellIt = prices[index] + dp[index+1][1][limit-1];

                        // Option 2: Skip selling the stock and move to the next day
                        int skip = 0 + dp[index+1][0][limit];

                        // Max profit by either selling or skipping
                        profit = max(sellIt, skip);
                    }

                    // Store the result in the DP array
                    dp[index][buy][limit] = profit;
                }
            }
        }

        // The result is stored in the first day, with 2 transactions left and the ability to buy
        return dp[0][1][2];
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

        // Two 2D arrays to store the current and next day's profits
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        // Fill the DP table from the last day to the first day
        for(int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if(buy) {
                        // Option 1: Buy the stock at the current price, then move to the next day with one less transaction
                        int buyIt = -prices[index] + next[0][limit];

                        // Option 2: Skip buying the stock and move to the next day
                        int skip = 0 + next[1][limit];

                        // Max profit by either buying or skipping
                        profit = max(buyIt, skip);
                    }
                    else {
                        // Option 1: Sell the stock at the current price and reduce the transaction limit by 1
                        int sellIt = prices[index] + next[1][limit-1];

                        // Option 2: Skip selling the stock and move to the next day
                        int skip = 0 + next[0][limit];

                        // Max profit by either selling or skipping
                        profit = max(sellIt, skip);
                    }

                    // Store the result in the current array
                    curr[buy][limit] = profit;
                }
            }

            // Move the current array to the next array for the next iteration
            next = curr;
        }

        // Return the maximum profit on the first day, where we are allowed to buy with 2 transactions allowed.
        return next[1][2];
    }

    int maxProfit(vector<int>& prices) {
        return spaceOptimization(prices);
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
