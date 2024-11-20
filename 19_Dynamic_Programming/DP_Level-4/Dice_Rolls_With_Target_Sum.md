# Question : [Number of Dice Rolls With Target Sum - (LeetCode : 1155)](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/)

You have `n` dice, and each dice has `k` faces numbered from `1` to `k`.

Given three integers `n`, `k`, and `target`, return *the number of possible ways (out of the `k^n` total ways) to roll the dice, so the sum of the face-up numbers equals* `target`. Since the answer may be too large, return it **modulo** `10^9 + 7`.

### Example 1

```
Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
```

### Example 2

```
Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
```

### Example 2

```
Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.
```

### Constraints

-   `1 <= n, k <= 30`
-   `1 <= target <= 1000`

### Recursive Approach

```Cpp

class Solution {
public:
    long long int MOD = 1000000007;
    int recursion(int n, int k, int target) {
        // Base case 1: If we have no dice left (n == 0) and the target is 0, there is exactly 1 way to achieve the target.
        if(target == 0 && n == 0)   return 1;

        // Base case 2: If there are no dice left (n == 0) but the target is non-zero, there is no way to achieve the target.
        if(target != 0 && n == 0)   return 0;

        // Base case 3: If there are dice left (n != 0) but the target is 0, there is no way to achieve the target.
        if(target == 0 && n != 0)   return 0;

        int totalWays = 0;

        // Try every possible face value of the current dice from 1 to k.
        // For each dice face (i), we reduce the target by i and recursively solve for the remaining dice and the new target.
        for(int i = 1; i <= k; i++) {
            totalWays += recursion(n-1, k, target-i);
        }
        
        // Return the total ways, modulo MOD to avoid overflow
        return totalWays % MOD;
    }

    int numRollsToTarget(int n, int k, int target) {
        return recursion(n, k, target);
    }
};

Time Complexity = O(k^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    long long int MOD = 1000000007;
    int memoization(int n, int k, int target, vector<vector<int>>& dp) {
        // Base case 1: If we have no dice left (n == 0) and the target is 0, there is exactly 1 way to achieve the target.
        if(target == 0 && n == 0)   return 1;

        // Base case 2: If there are no dice left (n == 0) but the target is non-zero, there is no way to achieve the target.
        if(target != 0 && n == 0)   return 0;

        // Base case 3: If there are dice left (n != 0) but the target is 0, there is no way to achieve the target.
        if(target == 0 && n != 0)   return 0;

        // If the result for this state (n, target) is already computed, return it
        if(dp[n][target] != -1)
            return dp[n][target];

        int totalWays = 0;

        // Try every possible face value of the current dice from 1 to k.
        // If the face value doesn't exceed the current target, subtract it and solve for the remaining dice and new target
        for(int i = 1; i <= k; i++) {
            // Only process if the target is non-negative
            if(target-i >= 0)
                totalWays = (totalWays + memoization(n-1, k, target-i, dp)) % MOD;
        }

        // Store and return the result for the current state
        return dp[n][target] = totalWays;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return memoization(n, k, target, dp);
}
};

Time Complexity = O(n * target * k)
Space Complexity = O(n * target)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    long long int MOD = 1000000007;
    int tabulation(int n, int k, int target) {
        // Initialize a DP table with (n+1) rows and (target+1) columns
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        // Base case: 1 way to achieve target 0 with 0 dice (by doing nothing)
        dp[0][0] = 1;

        // Loop through all possible dice counts from 1 to n
        for(int dice = 1; dice <= n; dice++) {
            // Loop through all possible target sums from 0 to target
            for(int sum = 0; sum <= target; sum++) {
                int totalWays = 0;
                // Try every possible face value of the current dice from 1 to k.
                for(int face = 1; face <= k; face++) {
                    // If the sum minus the current face is non-negative, add the number of ways to achieve that sum
                    if(sum - face >= 0)                    
                        totalWays = (totalWays + dp[dice - 1][sum - face]) % MOD;
                }
                // Store the result for the current dice and sum in the DP array
                dp[dice][sum] = totalWays;
            }
        }

        // Return the result for n dice and the target sum from the DP array
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        return tabulation(n, k, target);
    }
};

Time Complexity = O(n * target * k)
Space Complexity = O(n * target)
```


### Space Optimized Approach

```Cpp
class Solution {
public:
    long long int MOD = 1000000007;
    int spaceOptimization(int n, int k, int target) {
        // Use two 1D arrays to store the previous and current rows of the DP table
        vector<int> prev(target+1, 0), curr(target+1, 0);
        
        // Base case: There is 1 way to achieve sum 0 with 0 dice
        prev[0] = 1;

         // Loop through all possible dice counts from 1 to n
        for(int dice = 1; dice <= n; dice++) {
            // Loop through all possible target sums from 0 to target
            for(int sum = 0; sum <= target; sum++) {
                int totalWays = 0;
                // Try every possible face value of the current dice from 1 to k
                for(int face = 1; face <= k; face++) {
                    // If the sum minus the current face is non-negative, add the number of ways to achieve that sum
                    if(sum - face >= 0)                    
                        totalWays = (totalWays + prev[sum - face]) % MOD;
                }
                // Store the result for the current sum in the current row
                curr[sum] = totalWays;
            }

            // Move the previous row to the current row for the next iteration
            prev = curr;
        }

        // Return the result for the target sum using the last dice
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        return spaceOptimization(n, k, target);
    }
};

Time Complexity = O(n * target * k)
Space Complexity = O(target)
```