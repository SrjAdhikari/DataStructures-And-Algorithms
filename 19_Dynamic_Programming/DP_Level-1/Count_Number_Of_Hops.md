# Question : [Count number of hops - GFG](https://www.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1)

A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top of `nth` step.

### Example 1

```
Input: n = 4
Output: 7
Explanation:Below are the 7 ways to reach 4th step:
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step
```

### Example 2

```
Input: n = 2
Output: 2
Explanation:Below are the 2 ways to reach 2nd step:
1 step + 1 step
2 step
```

### Example 3

```
Input: n = 1
Output: 1
```

### Constraints

`1 ≤ n ≤ 30`

### Recursive Approach

```Cpp
class Solution {
public:
    // Function to count the number of ways in which frog can reach the top.
    int countWays(int n) {
        // Base cases:
        // If the frog is at the 0th or 1st step, there's only 1 way to stay or move to the next.
        if (n <= 1)
            return 1;

        // If n == 2, the frog can reach step 2 in two ways: (1+1) or (2).
        if (n == 2)
            return 2;

        // Recursive case: Sum the ways of reaching step n by jumping (n-1), (n-2), and (n-3) steps from the prior steps.
        return recursion(n - 1) + recursion(n - 2) + recursion(n - 3);
    }
};

Time Complexity = O(3^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(int n, vector<int>& dp) {
        // Base cases:
        // If the frog is at the 0th or 1st step, there's only 1 way to stay or move to the next.
        if (n <= 1)
            return 1;

        // If n == 2, the frog can reach step 2 in two ways: (1+1) or (2).
        if (n == 2)
            return 2;

        // If we've already computed the number of ways for step `n`, return it
        if (dp[n] != -1)
            return dp[n];

        // Recursively compute and store the result for step n to avoid recomputation
        dp[n] = memoization(n - 1, dp) + memoization(n - 2, dp) + memoization(n - 3, dp);

        return dp[n];
    }

    // Function to count the number of ways in which frog can reach the top.
    int countWays(int n) {
        vector<int> dp(n + 1, -1);
        return memoization(n, dp);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(int n) {
        // Initialize a dp array where dp[i] represents the number of ways to reach step i
        vector<int> dp(n + 1, -1);

        // Edge cases: If there’s only one step (n = 1), there’s only one way for the frog to reach it (one jump to step 1).
        if (n == 1)
            return 1;

        dp[0] = 1;      // Only 1 way to be at step 0 (stay there)
        dp[1] = 1;      // Only 1 way to reach step 1
        dp[2] = 2;      // Two ways to reach step 2: (1 + 1) or (2)

        // Fill the dp array from step 3 to step n
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        // dp[n] holds the result for reaching the top (step n)
        return dp[n];
    }

    // Function to count the number of ways in which frog can reach the top.
    int countWays(int n) {
        return tabulation(n);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    // Function to count the number of ways in which frog can reach the top.
    int countWays(int n) {
        // Edge cases:
        // If the frog is at the 0th or 1st step, there's only 1 way to stay or move to the next.
        if (n <= 1)
            return 1;

        // If n == 2, the frog can reach step 2 in two ways: (1+1) or (2).
        if (n == 2)
            return 2;

        // Initialize variables to store the last three results
        int prev = 2;    // Represents dp[i-1] (ways to reach (i-1)th step)
        int prev1 = 1;   // Represents dp[i-2] (ways to reach (i-2)th step)
        int prev2 = 1;   // Represents dp[i-3] (ways to reach (i-3)th step)
        int curr;        // Will represent dp[i] in each iteration

        // Loop through each step from 3 to n, updating only the last three values
        for (int i = 3; i <= n; i++) {
            curr = prev + prev1 + prev2;    // Sum of the last three steps
            prev2 = prev1;                  // Move dp[i-2] to dp[i-3] position
            prev1 = prev;                   // Move dp[i-1] to dp[i-2] position
            prev = curr;                    // Move dp[i] to dp[i-1] position
        }

        // `curr` now holds the number of ways to reach the top (step n)
        return curr;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
