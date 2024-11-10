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

**Note**: This recursive solution lead to a time limit exceeded (TLE) error on large inputs because of the exponential time complexity. In the future, we will solve this problem using dynamic programming to optimize the solution and pass all test cases.

## Solution

```Cpp
class Solution {
public:
    // This function Recursive function to finds the minimum number of coins needed to make up the given amount.
    int findMinCoins(vector<int>& coins, int amount) {
        // Base case: If amount is 0, no coins are needed
        if(amount == 0) {
            return 0;
        }

        // Base case: If amount is negative, it's not possible to form this amount
        if(amount < 0) {
            return -1;
        }

        // Initialize minCoins to a large value
        int minCoins = INT_MAX;

        // Try each coin and see the result of including it
        for(int coin : coins) {
            // Only proceed if the coin value is less than or equal to the current amount
            if(coin <= amount) {
                // Recursively find the minimum coins needed for the remaining amount (amount - coin)
                int result = findMinCoins(coins, amount - coin);

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
        return findMinCoins(coins, amount);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```
