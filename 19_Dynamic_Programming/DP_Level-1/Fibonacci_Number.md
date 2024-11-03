# Question : [Fibonacci Number - (LeetCode : 509)](https://leetcode.com/problems/fibonacci-number/description/)

The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.

Given `n`, calculate `F(n)`.

### Example 1

```
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
```

### Example 2

```
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
```

### Example 3

```
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

### Constraints

-   `0 <= n <= 30`

### Recursive Approach

```Cpp
class Solution {
public:
    // Function to calculate the nth Fibonacci number
    int fib(int n) {
        // Base case: For n = 0 or 1, the Fibonacci number is n itself
        if (n == 0 || n == 1) {
            return n;
        }
        // Recursive case: Sum of the (n-1)th and (n-2)th Fibonacci numbers
        return fib(n - 1) + fib(n - 2);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    // Top-Down (Memoization) Approach to calculate the nth Fibonacci number
    int memoization(int n, vector<int>& dp) {
        // Base case: For n = 0 or 1, the Fibonacci number is n itself
        if (n == 0 || n == 1)
            return n;

        // Step 3: Check if the value is already exists in the dp array, if yes, return it
        // If `dp[n]` is not -1, it means we've computed Fibonacci(n) before, so we can return it directly.
        if (dp[n] != -1)
            return dp[n];

        // Step 2: Store and return the result using dp array
        dp[n] = memoization(n - 1, dp) + memoization(n - 2, dp);

        // Step 4: Return the computed Fibonacci value for n.
        return dp[n];
    }

    // Function to calculate the nth Fibonacci number
    int fib(int n) {
        // Step 1: Create a dp (memoization) array
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
    // Bottom-Up (Tabulation) Approach to calculate the nth Fibonacci number
    int tabulation(int n) {
        // Step 1: Create a dp array
        vector<int> dp(n + 1, -1);

        // Edge case: If single element is given, return that element
        if (n == 0) 
            return 0;

        // Step 2: Analyze the base cases and fill the dp array
        dp[0] = 0;  // Fibonacci(0) = 0, Base case for n = 0
        dp[1] = 1;  // Fibonacci(1) = 1, Base case for n = 1

        // Step 3: Build the dp array from the bottom up.
        for(int i = 2; i <= n; i++) {
            // Compute Fibonacci(i) as the sum of previous two values.
            dp[i] = dp[i-1] + dp[i-2];
        }

        // Step 4: Return the computed Fibonacci value for n
        return dp[n];
    }

    // Function to calculate the nth Fibonacci number
    int fib(int n) {
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
    // Space Optimized Approach to calculate the nth Fibonacci number
    int spaceOptimized(int n) {
        // Base case: For n = 0 or 1, the Fibonacci number is n itself
        if(n <= 1)
            return n;

        // Initialize variables to hold previous two Fibonacci numbers.
        int curr;          // `curr` will hold the current Fibonacci number as we calculate it.
        int prev1 = 1;     // `prev1` represents Fibonacci(n-1).
        int prev2 = 0;     // `prev2` represents Fibonacci(n-2).

        // The loop starts from i = 2 because we have already handled the base cases for i = 0 and i = 1.
        for(int i = 2; i <= n; i++) {
            // Calculate the current Fibonacci number.
            curr = prev1 + prev2;

            // Update the previous two Fibonacci numbers.
            prev2 = prev1;
            prev1 = curr;
        }

        // By the end of the loop, `curr` holds Fibonacci(n).
        return curr;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```