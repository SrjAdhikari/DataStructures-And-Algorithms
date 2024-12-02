# Question : [Minimum Score Triangulation of Polygon - (LeetCode : 1039)](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/)

You have a convex `n`-sided polygon where each vertex has an integer value. You are given an integer array `values` where `values[i]` is the value of the `ith` vertex in **clockwise order**.

**Polygon triangulation** is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in `n - 2` triangles.

You will **triangulate** the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these _weights_ over all `n - 2` triangles.

Return _the minimum possible score_ that you can achieve with some **triangulation** of the polygon.

### Example 1

```
Input: values = [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.
```

### Example 2

```
Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.
```

### Example 3

```
Input: values = [1,3,1,4,1,5]
Output: 13
Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
```

### Constraints

-   `n == values.length`
-   `3 <= n <= 50`
-   `1 <= values[i] <= 100`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& values, int i, int j) {
        // Base case: If the subarray has only two elements, no triangulation possible.
        if(i+1 == j)
            return 0;

        // Initialize the minimum score to maximum possible value.
        int minScore = INT_MAX;

        // Try every possible point `k` to split the range [i, j] into two sub-problems.
        for(int k = i+1; k < j; k++) {
            // Calculate the cost of the triangle formed by the vertices i, j, k.
            int triangle = values[i] * values[j] * values[k];

            // Recursively calculate the score of the left and right subproblems, and update the minScore.
            minScore = min(minScore, triangle + recursion(values, i, k) + recursion(values, k, j));
        }
        // Return the minimum triangulation score for the range [i, j].
        return minScore;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return recursion(values, 0, n-1);
    }
};

Time Complexity = O(3^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
        // Base case: If the subarray has only two elements, no triangulation possible.
        if(i+1 == j)
            return 0;

        // If the value is already computed, return it from the DP table.
        if(dp[i][j] != -1)
            return dp[i][j];

        // Initialize the minimum score to maximum possible value.
        int minScore = INT_MAX;

        // Try every possible point `k` to split the range [i, j] into two sub-problems.
        for(int k = i+1; k < j; k++) {
            // Calculate the cost of the triangle formed by the vertices i, j, k.
            int triangle = values[i] * values[j] * values[k];

            // Recursively calculate the score of the left and right subproblems, and update the minScore.
            minScore = min(minScore, triangle + memoization(values, i, k, dp) + memoization(values, k, j, dp));
        }

        // Store the result in the DP table and return it.
        return dp[i][j] = minScore;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return memoization(values, 0, n-1, dp);
    }
};

Time Complexity = O(n^3)
Space Complexity = O(n^2)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& values) {
        // Get the number of vertices in the polygon.
        int n = values.size();

        // Initialize a DP table with dimensions (n+1) x (n+1), filled with 0
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Fill the DP table from bottom to top and left to right.
        for(int i = n-1; i >= 0; i--) {
            // j must be at least i + 2 for a valid triangle.
            for(int j = i+2; j < n; j++) {
                // Initialize the minimum score to maximum possible value.
                int minScore = INT_MAX;

                // Try every possible point `k` between i and j to split the range into two sub-problems.
                for(int k = i+1; k < j; k++) {
                    // Calculate the cost of the triangle formed by the vertices i, j, k.
                    int triangle = values[i] * values[j] * values[k];

                    // Calculate the score of the left and right subproblems, and update the minScore.
                    minScore = min(minScore, triangle + dp[i][k] + dp[k][j]);
                }
                // Store the minimum score for the range [i, j] in the DP table
                dp[i][j] = minScore;
            }
        }
        // Return the minimal triangulation score for the entire polygon.
        return dp[0][n-1];
    }

    int minScoreTriangulation(vector<int>& values) {
        return tabulation(values);
    }
};

Time Complexity = O(n^3)
Space Complexity = O(n^2)
```
