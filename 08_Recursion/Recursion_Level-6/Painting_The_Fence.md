# Question : [Painting the Fence - GFG](https://www.geeksforgeeks.org/problems/painting-the-fence3727/1)

Given a fence with `n` posts and `k` colors, find out the number of ways of painting the fence so that `not more than two` consecutive posts have the same colors. Since the answer can be large return it `modulo 10^9 + 7`.

### Example 1

```
Input:
n = 3
k = 2
Output: 6
Explanation:
Let the 2 colours be 'R' and 'B'.
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
Input:
n = 2
k = 4
Output: 16
Explanation:
After coloring first post with 4 possible combinations, you can still color next posts with all 4 colors. Total possible combinations will be 4x4=16
```

### Your Task:

Since, this is a function problem. You don't need to take any input or print anything, as it is already accomplished by the driver code. You just need to complete the function **countWays()** that takes **n and k** as parameters and returns the number of ways in which the fence can be painted **(modulo 109 + 7)**.

```
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
```

**Note**: This recursive solution lead to a time limit exceeded (TLE) error on large inputs because of the exponential time complexity. In the future, we will solve this problem using dynamic programming to optimize the solution and pass all test cases.

### Constraints

`1 ≤ N ≤ 10^5`
`1 ≤ K ≤ 10^5`

## Solution

```Cpp
class Solution {
public:
    // Recursive function to count the number of ways to paint a fence of length n with k colors
    long long countWays(int n, int k) {
        // Base case: If there is only one post, it can be painted in any of the k colors
        if (n == 1) {
            return k;
        }

        // Base case: If there are two posts, the first post can be painted in k colors.
        // The second post can be painted in (k - 1) colors (must be different from the first post),
        // So the total number of ways is k (for the first post) * (k - 1) (for the second post)
        if (n == 2) {
            return k * (k - 1) + k; // k * (k - 1) for all combinations of two different colors and k for both same color
        }

        // Recursive case: For more than two posts:
        // We need to consider two scenarios:
        // 1. The last two posts have different colors.
        //    In this case, there are (k - 1) choices for the color of the last post (it must differ from the second last post).
        //    The number of ways to paint the remaining (n - 1) posts is countWays(n - 1, k).
        // 2. The last two posts have the same color.
        //    Here, the last color must be the same as the (n - 1)th post, and the number of ways to paint the remaining (n - 2) posts is countWays(n - 2, k).
        // Combine these two scenarios:
        // The number of ways to paint n posts is:
        //   (k - 1) * (countWays(n - 1, k) + countWays(n - 2, k))
        long long ans = (k - 1) * (countWays(n - 1, k) + countWays(n - 2, k));

        // Return the result modulo 1000000007 to handle large numbers and avoid overflow
        return ans % 1000000007;
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```
