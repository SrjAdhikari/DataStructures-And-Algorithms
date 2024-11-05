# Question : [Min Cost Climbing Stairs - (LeetCode : 746)](https://leetcode.com/problems/min-cost-climbing-stairs/description/)

You are given an integer array `cost` where `cost[i]` is the cost of `ith` step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index `0`, or the step with index `1`.

Return _the minimum cost to reach the top of the floor_.

### Example 1

```
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
```

### Example 2

```
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
```

### Constraints

-   `2 <= cost.length <= 1000`
-   `0 <= cost[i] <= 999`

### Recursive Approach

```Cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // Base case: When n is 0 or 1, we are already at the starting point,
        // so no additional cost is required to reach the top from here.
        if(n <= 1)
            return 0;

        // Recursive case: Calculate the minimum cost by either:
        // 1. Taking one step from (n-1), and adding cost of step (n-1)
        // 2. Taking two steps from (n-2), and adding cost of step (n-2)
        // Recursively compute these values and return the minimum.
        return min(cost[n - 1] + recursion(n - 1, cost), cost[n - 2] + recursion(n - 2, cost));
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(int n, vector<int>& cost, vector<int>& dp) {
        // Base case: When n is 0 or 1, we are already at the starting point,
        // so no additional cost is required to reach the top from here.
        if(n <= 1)
            return 0;

        // If the result for step n is already computed, return it.
        if(dp[n] != -1)
            return dp[n];

        // Compute the minimum cost to reach the nth step and store it in dp[n]
        dp[n] = min(cost[n - 1] + memoization(n - 1, cost, dp), cost[n - 2] + memoization(n - 2, cost, dp));

        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return memoization(n, cost, dp);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(int n, vector<int>& cost) {
        // Initialize a dp array where dp[i] represents the minimum cost to reach step i.
        vector<int> dp(n + 1, -1);

        // Analyze the base cases and fill the dp array
        // No cost is required to start at step 0 or 1.
        dp[0] = 0;
        dp[1] = 0;

        // Fill the dp array from step 2 to n
        for(int i = 2; i <= n; i++) {
            // The minimum cost to reach step i is the minimum cost of either:
            // - Taking a single step from (i - 1) plus the cost at (i - 1)
            // - Taking two steps from (i - 2) plus the cost at (i - 2)
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        }

        // Return the minimum cost to reach the nth step, which is stored in dp[n]
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return tabulation(n, cost);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(int n, vector<int>& cost) {
        // Edge case: When n is 0 or 1, we are already at the starting point,
        // so no additional cost is required to reach the top from here.
        if(n <= 1)
            return 0;

        // Initialize two variables to store the minimum cost for the last two steps
        int prev = 0;       // Represents dp[i-1] (minimum cost to reach the previous step)
        int prev1 = 0;      // Represents dp[i-2] (minimum cost to reach two steps before)
        int curr;           // Will represent dp[i] in each iteration

        // Loop to calculate the minimum cost for each step up to n
        for(int i = 2; i <= n; i++) {
            // Compute the current step cost by finding the minimum of:
            // 1. Taking one step from (i-1), adding cost of step (i-1)
            // 2. Taking two steps from (i-2), adding cost of step (i-2)
            curr = min(cost[i - 1] + prev, cost[i - 2] + prev1);

            // Update the previous steps for the next iteration
            prev1 = prev;
            prev = curr;
        }

        // The last computed `curr` value will be the minimum cost to reach the nth step
        return curr;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return spaceOptimization(n, cost);
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
