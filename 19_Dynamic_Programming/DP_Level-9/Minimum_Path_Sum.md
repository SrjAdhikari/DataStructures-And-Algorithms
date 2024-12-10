# Question : [Minimum Path Sum - (LeetCode : 64)](https://leetcode.com/problems/minimum-path-sum/description/)

Given a `m x n` `grid` filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

**Note**: You can only move either down or right at any point in time.

### Example 1

![](https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg)

```
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
```

### Example 2

```
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
```

### Constraints

-   `m == grid.length`
-   `n == grid[i].length`
-   `1 <= m, n <= 200`
-   `0 <= grid[i][j] <= 200`

### Solution

```Cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();       // Number of rows in the grid
        int col = grid[0].size();    // Number of columns in the grid

        // Step 1: Calculate the cumulative sum for the last row
        // Iterate from the second-last column to the first column in the last row
        for(int j = col - 2; j >= 0; j--)
            // Add the value of the cell to the right
            grid[row - 1][j] += grid[row - 1][j + 1];

        // Step 2: Calculate the cumulative sum for the last column
        // Iterate from the second-last row to the first row in the last column
        for(int i = row - 2; i >= 0; i--)
            // Add the value of the cell below
            grid[i][col - 1] += grid[i + 1][col - 1];

        // Step 3: Calculate the cumulative sum for the rest of the grid
        // Start from the second last row and column, and move upwards and leftwards
        for(int i = row - 2; i >= 0; i--) {
            for(int j = col - 2; j >= 0; j--) {
                // Update the cell with the minimum of:
                // - the value of the cell below &
                // - the value of the cell to the right
                grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
            }
        }

        // The top-left cell (0,0) now contains the minimum path sum
        return grid[0][0];
    }
};

Time Complexity = O(n * m)
Space Complexity = O(1)
```
