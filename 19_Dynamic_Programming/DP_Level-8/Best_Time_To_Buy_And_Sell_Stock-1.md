# Question : [Best Time to Buy and Sell Stock - (LeetCode : 121)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return _the maximum profit you can achieve from this transaction_. If you cannot achieve any profit, return `0`.

### Example 1

```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

### Example 2

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

### Constraints

-   `1 <= prices.length <= 10^5`
-   `0 <= prices[i] <= 10^4`

### Solution

```Cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize `minPrice` with the price of the first day.
        // This variable will keep track of the minimum price encountered so far.
        int minPrice = prices[0];

        // Initialize `profit` to 0, as initially, there is no profit.
        int profit = 0;

        // Iterate through the array starting from the second day (index 1)
        for (int i = 1; i < prices.size(); i++) {
            // Calculate the potential profit if we sell on the current day.
            int priceDiff = prices[i] - minPrice;

            // Update `profit` to the maximum of the current `profit` and `priceDiff`.
            profit = max(profit, priceDiff);

            // Update `minPrice` to the minimum of the current `minPrice` and prices[i].
            minPrice = min(minPrice, prices[i]);
        }

        // Return the maximum profit found.
        return profit;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
