# Question : [Maximize The Cut Segments - GFG](https://www.geeksforgeeks.org/problems/cutted-segments1642/1)

Given an integer `n` denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either `x`, `y` or `z`. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum. Return the maximum number of cut segments possible.

**Note**: if no segment can be cut then return 0.

### Example 1

```
Input: n = 4, x = 2, y = 1, z = 1
Output: 4
Explanation: Total length is 4, and the cut lengths are 2, 1 and 1.  
We can make maximum 4 segments each of length 1.
```

### Example 2

```
Input: n = 5, x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and the cut lengths are 5, 3 and 2. 
We can make two segments of lengths 3 and 2.
```

### Example 3

```
Input: n = 7, x = 8, y = 9, z = 10
Output: 0
Explanation: Here the total length is 7, and the cut lengths are 8, 9, and 10. 
We cannot cut the segment into lengths that fully utilize the segment, so the output is 0.
```

### Constraints

`1 <= n, x, y, z <= 10^4`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(int n, int x, int y, int z) {
        // Base case: If the rod length is exactly 0, no more cuts can be made.
        if (n == 0)
            return 0;

        // Base case: If the rod length becomes negative, this path is invalid.
        if (n < 0)
            return INT_MIN;

        // Recursively try cutting the rod of length 'n' with lengths x, y, and z respectively.
        // Add 1 to the result to account for the current cut.
        int xCut = 1 + recursion(n - x, x, y, z);   // Cut of size x
        int yCut = 1 + recursion(n - y, x, y, z);   // Cut of size y
        int zCut = 1 + recursion(n - z, x, y, z);   // Cut of size z

        // Take the maximum of all possible cuts.
        int maxCut = max(xCut, max(yCut, zCut));

        // Return the maximum number of cuts possible for the given rod length n.
        return maxCut;
    }

    int maximizeTheCuts(int n, int x, int y, int z) {
        int ans = recursion(n, x, y, z);
        return ans < 0 ? 0 : ans;
    }
};

Time Complexity = O(3^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(int n, int x, int y, int z, vector<int>& dp) {
        // Base case: If the rod length is exactly 0, no more cuts can be made.
        if (n == 0)
            return 0;

        // Base case: If the rod length becomes negative, this path is invalid.
        if (n < 0)
            return INT_MIN;

        // If the result for this length has already been calculated, return it.
        if (dp[n] != -1)
            return dp[n];

        // Recursively try cutting the rod of length 'n' with lengths x, y, and z respectively.
        // Add 1 to the result to account for the current cut.
        int xCut = 1 + memoization(n - x, x, y, z, dp);     // Cut of size x
        int yCut = 1 + memoization(n - y, x, y, z, dp);     // Cut of size y
        int zCut = 1 + memoization(n - z, x, y, z, dp);     // Cut of size z

        // Store the result for this length in the dp array.
        dp[n] = max(xCut, max(yCut, zCut));

        // Return the maximum number of cuts possible for the given rod length n.
        return dp[n];
    }

    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int>dp(n+1, -1);
        int ans = memoization(n, x, y, z, dp);
        return ans < 0 ? 0 : ans;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(int n, int x, int y, int z) {
        // Initialize a dp array to store the maximum number of cuts for each rod length from 0 to n.
        // Initialize all values to INT_MIN to handle cases where no valid cuts are possible.
        vector<int> dp(n + 1, INT_MIN);

        // Base case: If the rod length is 0, no cuts are required. so dp[0] is initialized to 0.
        dp[0] = 0;

        // Iterate through all lengths of the rod from 1 to n.
        for (int i = 1; i <= n; i++) {
            // Check if a cut of size x is possible, if possible update dp[i].
            if (i - x >= 0)
                dp[i] = max(dp[i], 1 + dp[i - x]);

            // Check if a cut of size y is possible, if possible update dp[i].
            if (i - y >= 0)
                dp[i] = max(dp[i], 1 + dp[i - y]);

            // Check if a cut of size z is possible, if possible update dp[i].
            if (i - z >= 0)
                dp[i] = max(dp[i], 1 + dp[i - z]);
        }

        // If no valid cuts were found (dp[n] is still INT_MIN), return 0return 0, Otherwise return dp[n].
        return dp[n] < 0 ? 0 : dp[n];
    }

    int maximizeTheCuts(int n, int x, int y, int z) {
        return tabulation(n, x, y, z);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```