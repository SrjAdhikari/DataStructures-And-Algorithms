# Question : [Coin Change - (LeetCode : 322)](https://leetcode.com/problems/coin-change/description/)

You are given an integer array coins representing `coins` of different denominations and an integer `amount` representing a total amount of money.

Return _the fewest number of coins that you need to make up that amount_. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

### Example 1

```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```

### Example 2

```
Input: coins = [2], amount = 3
Output: -1
```

### Example 3

```
Input: coins = [1], amount = 0
Output: 0
```

### Constraints

-   `1 <= coins.length <= 12`
-   `1 <= coins[i] <= 2^31 - 1`
-   `0 <= amount <= 10^4`

### Recursive Approach

```Cpp
class Solution {
public:
    // This function Recursive function to finds the minimum number of coins needed to make up the given amount.
    int recursion(vector<int>& coins, int amount) {
        // Base case: If amount is 0, no coins are needed
        if(amount == 0) {
            return 0;
        }

        // Initialize minCoins to a large value
        int minCoins = INT_MAX;

        // Try each coin and see the result of including it
        for(int coin : coins) {
            // Only proceed if the coin value is less than or equal to the current amount
            if(amount >= coin) {
                // Recursively find the minimum coins needed for the remaining amount (amount - coin)
                int result = recursion(coins, amount - coin);

                // If the result is not -1 (meaning it's possible to form the remaining amount)
                if(result != -1) {
                    // Update minCoins with the minimum value between current minCoins and result + 1 (which includes the current coin).
                    minCoins = min(minCoins, result + 1);
                }
            }
        }

        // If minCoins is still INT_MAX, it means no solution was found
        return minCoins == INT_MAX ? -1 : minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        return recursion(coins, amount);
    }
};

Time Complexity = O(N^amount)
Space Complexity = O(amount)
N => Number of coins
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& coins, int amount, vector<int>& dp) {
        // Base case: no coins needed if amount is zero.
        if (amount == 0) {
            return 0;
        }

        // If the result is already computed for this amount, return it from dp
        if (dp[amount] != -1)
            return dp[amount];

        // Initialize minCoins to a large value
        int minCoins = INT_MAX;

        // Try each coin and see the result of including it
        for (int coin : coins) {
            // Only proceed if the coin value is less than or equal to the current amount
            if (amount >= coin) {
                // Recursively find the minimum coins needed for the remaining amount (amount - coin)
                int result = memoization(coins, amount - coin, dp);

                // If the result is not -1 (meaning it's possible to form the remaining amount)
                if (result != -1)
                    // Update minCoins with the minimum value between current minCoins and result + 1 (which includes the current coin).
                    minCoins = min(minCoins, 1 + result);
            }
        }
        // Store the result in dp array and return it.
        dp[amount] = minCoins == INT_MAX ? -1 : minCoins;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        return memoization(coins, amount, dp);
    }
};

Time Complexity = O(N * amount)
Space Complexity = O(amount)
N => Number of coins
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& coins, int amount) {
        // Initialize dp array
        vector<int> dp(amount + 1, -1);

        // Base case: no coins are needed to make amount 0
        dp[0] = 0;

        // Fill dp array from 1 up to the target amount
        for (int i = 1; i <= amount; i++) {
            int minCoins = INT_MAX;

            // Check each coin to determine if it can contribute to amount i
            for (int j = 0; j < coins.size(); j++) {
                // Only proceed if the coin value is less than or equal to the current amount
                if (i >= coins[j]) {
                    // Find the minimum coins needed for the remaining amount (i - coins[j])
                    int result = dp[i - coins[j]];
                    
                    // If the result is not -1 (meaning it's possible to form the remaining amount)
                    if (result != -1) {
                        // Update minCoins with the minimum value between current minCoins and result + 1 (which includes the current coin).
                        minCoins = min(minCoins, 1 + result);
                    }
                }
            }
            // If no valid combination is found, set dp[i] to -1, else update with minimum coins found
            dp[i] = minCoins == INT_MAX ? -1 : minCoins;
        }
        // Return the minimum coins required for the target amount, dp[amount]
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        return tabulation(coins, amount);
    }
};

Time Complexity = O(N * amount)
Space Complexity = O(amount)
N => Number of coins
```
