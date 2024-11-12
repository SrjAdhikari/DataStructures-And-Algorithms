# Question : [Painting the Fence - GFG](https://www.geeksforgeeks.org/problems/painting-the-fence3727/1)

Given a fence with `n` posts and `k` colors, find out the number of ways of painting the fence so that `not more than two` consecutive posts have the same colors.

### Example 1

```
Input: n = 3, k = 2 
Output: 6
Explanation: Let the 2 colours be 'R' and 'B'. 
We have following possible combinations:
1. RRB
2. RBR
3. RBB
4. BRR
5. BRB
6. BBR
```

### Example 2

```
Input: n = 2, k = 4 
Output: 16
Explanation: After coloring first post with 4 possible combinations, 
you can still color next posts with all 4 colors. 
Total possible combinations will be 4x4=16
```

```
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).
```

### Constraints

`1 ≤ n ≤ 300`
`1 ≤ k ≤ 10^5`

### Recursive Approach

```Cpp
class Solution {
public:
    // Recursive function to count the number of ways to paint a fence of length n with k colors
    int recursion(int n, int k) {
        // Base case: If there is only one post, it can be painted in any of the k colors
        if (n == 1)
            return k;

        // Base case: If there are two posts, the first post can be painted in k colors.
        // The second post can be painted in (k - 1) colors (must be different from the first post),
        // So the total number of ways is k (for the first post) * (k - 1) (for the second post)
        if (n == 2) {
            return k * (k - 1) + k;     // k * (k - 1) for all combinations of two different colors and k for both same color
        }

        // Recursive case: For more than two posts:
        // We need to consider two scenarios:
        // 1. The last two posts have different colors.
            // In this case, there are (k - 1) choices for the color of the last post (it must differ from the second last post).
            // The number of ways to paint the remaining (n - 1) posts is countWays(n - 1, k).
        // 2. The last two posts have the same color.
            // Here, the last color must be the same as the (n - 1)th post, and the number of ways to paint the remaining (n - 2) posts is countWays(n - 2, k).
        // Combine these two scenarios:
        // The number of ways to paint n posts is:
        // (k - 1) * (countWays(n - 1, k) + countWays(n - 2, k))
        int result = (k - 1) * (recursion(n - 1, k) + recursion(n - 2, k));

        // Return the result
        return result;
    }

    int countWays(int n, int k) {
        return recursion(n, k);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    // Memoization function to count the number of ways to paint a fence of length n with k colors
    int memoization(int n, int k, vector<int>& dp) {
        // Base case: If there is only one post, it can be painted in any of the k colors
        if (n == 1)
            return k;

        // Base case: if 2 items, there are k ways for the first item and
        // k*(k-1) ways to paint the second different from the first
        if (n == 2)
            return k + k * (k - 1);

        // If the result is already computed, return it to avoid redundant calculations.
        if (dp[n] != -1)
            return dp[n];

        // Use memoization to store the result of this subproblem in dp array
        dp[n] = (k - 1) * (memoization(n - 1, k, dp) + memoization(n - 2, k, dp));

        // Return the result
        return dp[n];
    }

    int countWays(int n, int k) {
        vector<int> dp(n + 1, -1);
        return memoization(n, k, dp);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    // Tabulation function to count the number of ways to paint a fence of length n with k colors
    int tabulation(int n, int k) {
        // Initialize dp array
        vector<int> dp(n + 1, -1);

        // Base cases:
        dp[1] = k;                  // k ways to color the first post
        dp[2] = k + k * (k - 1);    // k ways for the first post, k*(k-1) for the second post

        // Fill dp array for all posts from 3 to n
        for (int i = 3; i <= n; i++) {
            // Compute the number of ways to paint i posts with k colors
            dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
        }

        // Return the number of ways to color n posts
        return dp[n];
    }

    int countWays(int n, int k) {
        return recursion(n, k);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    // Space-optimized function to count the number of ways to paint a fence of length n with k colors
    int spaceOptimization(int n, int k) {
        // Base case: Only `k` ways to color 1 post
        if (n == 1)
            return k;

        // Base case: k ways for the first post, k*(k-1) ways for the second post
        if (n == 2)
            return k + k * (k - 1);

        // Variables to store last two computed values
        int prev1 = k + k * (k - 1);    // equivalent to dp[2] => Ways to paint two posts
        int prev2 = k;                  // equivalent to dp[1] => Ways to paint one post
        int curr;

        // Iteratively calculate up to n, using only last two results
        for (int i = 3; i <= n; i++) {
            curr = (k - 1) * (prev1 + prev2);   // current result based on last two
            prev2 = prev1;                      // update prev2 to prev1 for the next iteration
            prev1 = curr;                       // update prev1 to curr for the next iteration
        }

        // Return the result for n posts
        return prev1;
    }

    int countWays(int n, int k) {
        return recursion(n, k);
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
