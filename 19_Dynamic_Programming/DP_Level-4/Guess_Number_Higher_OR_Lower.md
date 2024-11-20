# Question : [Guess Number Higher or Lower II - (LeetCode : 375)](https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/)

We are playing the Guessing Game. The game will work as follows:

1. I pick a number between `1` and `n`.
2. You guess a number.
3. If you guess the right number, **you win the game**.
4. If you guess the wrong number, then I will tell you whether the number I picked is **higher or lower**, and you will continue guessing.
5. Every time you guess a wrong number `x`, you will pay `x` dollars. If you run out of money, **you lose the game**.

Given a particular `n`, return *the minimum amount of money you need **to guarantee a win regardless of what number I pick***.

### Example 1

![](https://assets.leetcode.com/uploads/2020/09/10/graph.png)

```
Input: n = 10
Output: 16
Explanation: The winning strategy is as follows:
- The range is [1,10]. Guess 7.
    - If this is my number, your total is $0. Otherwise, you pay $7.
    - If my number is higher, the range is [8,10]. Guess 9.
        - If this is my number, your total is $7. Otherwise, you pay $9.
        - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
        - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
    - If my number is lower, the range is [1,6]. Guess 3.
        - If this is my number, your total is $7. Otherwise, you pay $3.
        - If my number is higher, the range is [4,6]. Guess 5.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
            - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
        - If my number is lower, the range is [1,2]. Guess 1.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
            - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.
```

### Example 2

```
Input: n = 1
Output: 0
Explanation: There is only one possible number, so you can guess 1 and not have to pay anything.
```

### Example 3

```
Input: n = 2
Output: 1
Explanation: There are two possible numbers, 1 and 2.
- Guess 1.
    - If this is my number, your total is $0. Otherwise, you pay $1.
    - If my number is higher, it must be 2. Guess 2. Your total is $1.
The worst case is that you pay $1.
```

### Constraints

-   `1 <= n <= 200`

### Recursive Approach

```Cpp

class Solution {
public:
    int recursion(int start, int end) {
        // Base case: If the range is invalid or contains only one number, no cost is required
        if (start >= end)
            return 0;

        // Variable to store the minimum amount to guarantee a win
        int minAmount = INT_MAX;

        // Iterate through each number in the range [start, end]
        for (int i = start; i <= end; i++) {
            // Cost of guessing `i` as a wrong answer is `i` itself, plus the maximum cost of left and right range.
            // Recurse on left range [start, i-1], Recurse on right range [i+1, end]
            int cost = i + max(recursion(start, i - 1), recursion(i + 1, end));

            // Update the minimum amount to guarantee a win
            minAmount = min(minAmount, cost);
        }

        // Return the minimum amount to guarantee a win
        return minAmount;
    }

    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        return recursion(start, end);
    }
};

Time Complexity = O(2^N)
Space Complexity = O(N)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(int start, int end, vector<vector<int>>& dp) {
        // Base case: If the range is invalid or contains only one number, no cost is required
        if (start >= end)
            return 0;

        // If the result for the current state is already computed, if yes return it
        if (dp[start][end] != -1)
            return dp[start][end];

        // Variable to store the minimum amount to guarantee a win
        int minAmount = INT_MAX;

        // Iterate through each number in the range [start, end]
        for (int i = start; i <= end; i++) {
            // Cost of guessing `i` as a wrong answer is `i` itself, plus the maximum cost of left and right range.
            // Recurse on left range [start, i-1], Recurse on right range [i+1, end]
            int cost = i + max(memoization(start, i - 1, dp), memoization(i + 1, end, dp));

            // Update the minimum amount to guarantee a win
            minAmount = min(minAmount, cost);
        }

        // Store and return the minimum amount to guarantee a win
        return dp[start][end] = minAmount;
    }

    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return memoization(start, end, dp);
    }
};

Time Complexity = O(N^3)
Space Complexity = O(N^2)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(int n) {
        // Create a DP table where dp[start][end]` stores the minimum cost to guess the correct number in range [start, end]
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

        // Iterate over all possible ranges from bottom to top and left to right
        for (int start = n - 1; start >= 1; start--) {
            for (int end = 1; end <= n; end++) {
                // Skip invalid ranges
                if (start >= end)
                    continue;

                // Variable to store the minimum amount to guarantee a win
                int minAmount = INT_MAX;

                // Iterate through each number in the current range [start, end]
                for (int i = start; i <= end; i++) {
                    // Cost of guessing `i` as a wrong answer is `i` itself, plus the maximum cost of left and right range.
                    // Recurse on left range [start, i-1], Recurse on right range [i+1, end]
                    int cost = i + max(dp[start][i - 1], dp[i + 1][end]);

                    // Update the minimum amount to guarantee a win
                    minAmount = min(minAmount, cost);
                }

                // Store the minimum amount to guarantee a win
                dp[start][end] = minAmount;
            }
        }

        // The result for the range [1, n] is stored in dp[1][n], return it
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        return tabulation(n);
    }
};

Time Complexity = O(N^3)
Space Complexity = O(N^2)
```