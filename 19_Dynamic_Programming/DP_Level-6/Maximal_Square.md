# Question : [Maximal Square - (LeetCode : 221)](https://leetcode.com/problems/maximal-square/description/)

Given an `m x n` binary `matrix` filled with `0`'s and `1`'s, _find the largest square containing only `1`'s and return its area_.

### Example 1

![](https://assets.leetcode.com/uploads/2020/11/26/max1grid.jpg)

```
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
```

### Example 2

![](https://assets.leetcode.com/uploads/2020/11/26/max2grid.jpg)

```
Input: matrix = [["0","1"],["1","0"]]
Output: 1
```

### Example 3

```
Input: matrix = [["0"]]
Output: 0
```

### Constraints

-   `m == matrix.length`
-   `n == matrix[i].length`
-   `1 <= m, n <= 300`
-   `matrix[i][j]` is `'0'` or `'1'`.

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<vector<char>>& matrix, int i, int j, int& maxSquare) {
        int row = matrix.size();        // Get the number of rows in the matrix.
        int col = matrix[0].size();     // Get the number of columns in the matrix.

        // Base case: If indices go out of bounds, return 0.
        if (i >= row || j >= col)
            return 0;

        // Recursive calls to check squares in the right, diagonal, and down directions.
        int checkRight = recursion(matrix, i, j + 1, maxSquare);
        int checkDiagonal = recursion(matrix, i + 1, j + 1, maxSquare);
        int checkDown = recursion(matrix, i + 1, j, maxSquare);

        // If the current cell contains '1', calculate the size of the square.
        if (matrix[i][j] == '1') {
            // Calculate the size of the square ending at this cell.
            int square = 1 + min(checkRight, min(checkDiagonal, checkDown));

            // Update the maximum square size.
            maxSquare = max(square, maxSquare);

            // Return the calculated square size for this cell.
            return square;
        }
        else {
            // If current cell is '0', no square is possible.
            return 0;
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // Variable to store the size of the largest square.
        int maxSquare = 0;
        recursion(matrix, 0, 0, maxSquare);
        return maxSquare * maxSquare;
    }
};

Time Complexity = O(3^(row * col))
Space Complexity = O(row + col)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<vector<char>>& matrix, int i, int j, int& maxSquare, vector<vector<int>>& dp) {
        int row = matrix.size();            // Get the number of rows in the matrix.
        int col = matrix[0].size();         // Get the number of columns in the matrix.

        // Base case: If indices go out of bounds, return 0.
        if (i >= row || j >= col)
            return 0;

        // If the result for this cell is already computed, return it.
        if (dp[i][j] != -1)
            return dp[i][j];

        // Recursive calls to check squares in the right, diagonal, and down directions.
        int checkRight = memoization(matrix, i, j + 1, maxSquare, dp);
        int checkDiagonal = memoization(matrix, i + 1, j + 1, maxSquare, dp);
        int checkDown = memoization(matrix, i + 1, j, maxSquare, dp);

        // If the current cell contains '1', calculate the size of the square.
        if (matrix[i][j] == '1') {
            // Calculate the size of the square ending at this cell.
            int square = 1 + min(checkRight, min(checkDiagonal, checkDown));

            // Update the maximum square size.
            maxSquare = max(square, maxSquare);

            // Store the result in the dp table and return it.
            return dp[i][j] = square;
        }
        else {
            // If current cell is '0', no square is possible.
            return dp[i][j] = 0;
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // Variable to store the size of the largest square.
        int maxSquare = 0;
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row, vector<int>(col, -1));
        memoization(matrix, 0, 0, maxSquare, dp);

        return maxSquare * maxSquare;
    }
};

Time Complexity = O(row * col)
Space Complexity = O(row * col)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<vector<char>>& matrix, int& maxSquare) {
        int row = matrix.size();            // Get the number of rows in the matrix.
        int col = matrix[0].size();         // Get the number of columns in the matrix.

        // DP table with an extra row and column for boundary cases.
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

        // Iterate from bottom to top rows.
        for (int i = row - 1; i >= 0; i--) {
            // Iterate from right to left columns.
            for (int j = col - 1; j >= 0; j--) {
                // Compute values for right, diagonal, and downward cells from the DP table.
                int checkRight = dp[i][j + 1];
                int checkDiagonal = dp[i + 1][j + 1];
                int checkDown = dp[i + 1][j];

                // If the current cell contains '1', calculate the size of the square.
                if (matrix[i][j] == '1') {
                    // Calculate the size of the square ending at this cell.
                    dp[i][j] = 1 + min(dp[i][j + 1], min(dp[i + 1][j + 1], dp[i + 1][j]));

                    // Update the maximum square size.
                    maxSquare = max(dp[i][j], maxSquare);
                }
                else {
                    // If the current cell is '0', no square is possible.
                    dp[i][j] = 0;
                }
            }
        }
        // Return the result from the top-left corner.
        return dp[0][0];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // Variable to store the size of the largest square.
        int maxSquare = 0;
        tabulation(matrix, maxSquare);
        return maxSquare * maxSquare;
    }
};

Time Complexity = O(row * col)
Space Complexity = O(row * col)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(vector<vector<char>>& matrix, int& maxSquare) {
        int row = matrix.size();            // Get the number of rows in the matrix.
        int col = matrix[0].size();         // Get the number of columns in the matrix.

        vector<int> curr(col + 1, 0);       // Vector to store the current row's results.
        vector<int> next(col + 1, 0);       // Vector to store the next row's results.

        // Iterate from bottom to top rows.
        for (int i = row - 1; i >= 0; i--) {
            // Iterate from right to left columns.
            for (int j = col - 1; j >= 0; j--) {
                // Compute values for right, diagonal, and downward cells using next and curr rows.
                int checkRight = curr[j + 1];
                int checkDiagonal = next[j + 1];
                int checkDown = next[j];

                // If the current cell contains '1', calculate the size of the square.
                if (matrix[i][j] == '1') {
                    // Calculate the size of the square ending at this cell.
                    curr[j] = 1 + min(curr[j + 1], min(next[j + 1], next[j]));

                    // Update the maximum square size.
                    maxSquare = max(curr[j], maxSquare);
                }
                else {
                    // If the current cell is '0', no square is possible.
                    curr[j] = 0;
                }
            }
            // Move the current row results to the next row for the next iteration.
            next = curr;
        }
        // Return the value stored in the last row.
        return next[0];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // Variable to store the size of the largest square.
        int maxSquare = 0;
        spaceOptimization(matrix, maxSquare);
        return maxSquare * maxSquare;
    }
};

Time Complexity = O(row * col)
Space Complexity = O(col)
```
