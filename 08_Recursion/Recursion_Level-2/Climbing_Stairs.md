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

## Solution 1

```Cpp
Using Recursion : This solution throws a Time Limit Exceeded error.
                We will solve this problem later using Dynamic Programming (DP).

class Solution {
public:
    // Function to calculate the number of ways to climb n stairs
    int climbStairs(int n) {
        // Base cases: If n is 1 or 2, return n
        // There's 1 way to climb 1 stair, and 2 ways to climb 2 stairs (1+1 or 2)
        if (n == 1 || n == 2) {
            return n;
        }

        // Recursive case: The number of ways to climb n stairs is the sum of ways to climb (n-1) and (n-2) stairs
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

## Solution 2

```Cpp
Iterative Approach :

class Solution {
public:
    // Function to calculate the number of ways to climb n stairs using an iterative approach
    int climbStairs(int n) {
        // Base cases: If n is 1 or 2, return n
        // There's 1 way to climb 1 stair, and 2 ways to climb 2 stairs (1+1 or 2)
        if (n <= 2) {
            return n;
        }

        // Initialize variables for the first two steps
        int first = 1;      // Number of ways to climb 1 stair
        int second = 2;     // Number of ways to climb 2 stairs
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
        return second;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
