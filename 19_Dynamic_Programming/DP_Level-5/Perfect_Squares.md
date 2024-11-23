# Question : [Perfect Squares - (LeetCode : 279)](https://leetcode.com/problems/perfect-squares/description/)

Given an integer `n`, return *the least number of perfect square numbers that sum to* `n`.

A **perfect square** is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, `1`, `4`, `9`, and `16` are perfect squares while `3` and `11` are not.

### Example 1

```
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
```

### Example 2

```
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

### Constraints

- `1 <= n <= 10^4`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(int n) {
        // Base Case 1: If the number `n` becomes 0, no squares are required, return 0.
        if (n == 0)
            return 0;

        // Base Case 2: If `n` is negative, the solution is invalid.
        if (n < 0)
            return 0;
        
        int start = 1;                // Start iterating from 1
        int end = sqrt(n);            // Limit iterations to sqrt(n), as larger numbers won't contribute valid squares
        int ans = INT_MAX;            // Initialize the minimum answer to a large value

        // Iterate through all numbers from 1 to sqrt(n) and calculate the minimum result
        for (int i = start; i <= end; i++) {
            // Compute the square of the current number
            int square = i * i;

            // Recursive call: Subtract the square from `n` and calculate for the remaining value
            // Add 1 to account for the square used in this step
            ans = min(ans, 1 + recursion(n - square));
        }

        // Return the minimum number of squares
        return ans;
    }

    int numSquares(int n) {
        return recursion(n); 
    }
};

Time Complexity = O(n^sqrt(n))
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(int n, vector<int>& dp) {
        // Base Case 1: If the number `n` becomes 0, no squares are required, return 0.
        if (n == 0)
            return 0;

        // Base Case 2: If `n` is negative, the solution is invalid.
        if (n < 0)
            return 0;

        // Check if the result for this value of `n` is already computed, if yes, return it.
        if (dp[n] != -1)
            return dp[n];
        
        int start = 1;                // Start iterating from 1
        int end = sqrt(n);            // Limit iterations to sqrt(n), as larger numbers won't contribute valid squares
        int ans = INT_MAX;            // Initialize the minimum answer to a large value

        // Iterate through all numbers from 1 to sqrt(n) and calculate the minimum result
        for (int i = start; i <= end; i++) {
            // Compute the square of the current number
            int square = i * i;

            // Recursive call: Subtract the square from `n` and calculate for the remaining value
            // Add 1 to account for the square used in this step
            ans = min(ans, 1 + memoization(n - square, dp));
        }

        // Store the result in the `dp` array and return it
        return dp[n] = ans;
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return memoization(n, dp);
    }
};

Time Complexity = O(n * sqrt(n))
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(int n) {
        // Initialize a `dp` array to store results for all numbers from 0 to `n`.
        vector<int> dp(n + 1, -1);

        // Base case: 0 numbers are needed to represent the sum 0
        dp[0] = 0;

        // Iterate through all numbers from 1 to n
        for (int num = 1; num <= n; num++) {
            // The maximum number to consider is sqrt(num)
            int end = sqrt(num);

            // Initialize the minimum answer to a large value
            int ans = INT_MAX;

            // Iterate through all numbers from 1 to sqrt(num) and calculate the minimum result
            for (int i = 1; i <= end; i++) {
                // Compute the square of the current number
                int square = i * i;

                // Update the minimum result
                ans = min(ans, 1 + dp[num - square]);
            }

            // Store the result for the current number in the `dp` array
            dp[num] = ans;
        }

        // Return the result for n
        return dp[n];
    }

    int numSquares(int n) {
        return tabulation(n);
    }
};

Time Complexity = O(n * sqrt(n))
Space Complexity = O(n)
```