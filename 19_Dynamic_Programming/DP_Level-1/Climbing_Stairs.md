# Question : [Climbing Stairs - (LeetCode : 70)](https://leetcode.com/problems/climbing-stairs/description/)

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

### Example 1

```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

### Example 2

```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

### Constraints

-   `1 <= n <= 45`

### Recursive Approach

```Cpp
class Solution {
public:
    // Function to calculate the number of ways to climb n stairs
    int climbStairs(int n) {
        // Base cases: If n is 1 or 2, return n
        // There's 1 way to climb 1 stair, and 2 ways to climb 2 stairs (1+1 or 2)
        if(n <= 2) {
            return n;
        }

        // Recursive case: The number of ways to climb n stairs is the sum of ways to climb (n-1) and (n-2) stairs
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(int n, vector<int>& dp) {
        // Base cases: If n is 1 or 2, return n
        // There's 1 way to climb 1 stair, and 2 ways to climb 2 stairs (1+1 or 2)
        if(n <= 2)
            return n;

        // Step 3: Check if the value is already exists in the dp array, if yes, return it
        if(dp[n] != -1)
            return dp[n];

        // Step 2: Calculate and store result in `dp` array
        dp[n] = memoization(n-1, dp) + memoization(n-2, dp);

        // Step 4: Return the computed result
        return dp[n];
    }

    // Function to calculate number of ways to climb stairs
    int climbStairs(int n) {
        // Step 1: Create a dp (memoization) array
        vector<int> dp(n+1, -1);
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
        // Step 1: Create a dp array
        vector<int> dp(n+1, -1);

        // Edge case: If there's only 1 stair (n = 1) return 1, there is only 1 way to climb it.
        if(n == 1)
            return 1;

        // Step 2: Analyze the base cases and fill the dp array
        dp[1] = 1;      // 1 way to reach step 1
        dp[2] = 2;      // 2 ways to reach step 2

        // Step 3: Build the dp array from the bottom up (iteratively from step 3 to `n`).
        for(int i = 3; i <= n; i++) {
            // Sum of ways to reach steps `i-1` and `i-2`
            dp[i] = dp[i-1] + dp[i-2];
        }

        // The result for `n` stairs is now stored in `dp[n]`
        return dp[n];
    }

    // Function to calculate number of ways to climb stairs
    int climbStairs(int n) {
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
    // Function to calculate the number of ways to climb n stairs using an iterative approach
    int climbStairs(int n) {
        // Edge cases: If n is 1 or 2, return n
        // There's 1 way to climb 1 stair, and 2 ways to climb 2 stairs (1+1 or 2)
        if (n <= 2) {
            return n;
        }

        // Initialize variables for the first two steps
        int first = 1;      // Number of ways to climb 1 stair -> Equivalent to dp[i-2]
        int second = 2;     // Number of ways to climb 2 stairs -> Equivalent to dp[i-1]
        int current;

        // Iterate from the 3rd step to the nth step
        for (int i = 3; i <= n; ++i) {
            // Calculate the number of ways to reach the current step
            current = first + second;

            // Update the variables for the next iteration
            first = second;
            second = current;
        }

        // Return the number of ways to reach the nth step
        // `current` contains the final answer for `n`
        return current;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
