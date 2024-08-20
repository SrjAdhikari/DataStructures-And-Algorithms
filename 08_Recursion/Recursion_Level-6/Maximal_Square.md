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

**Note**: This recursive solution lead to a time limit exceeded (TLE) error on large inputs because of the exponential time complexity. In the future, we will solve this problem using dynamic programming to optimize the solution and pass all test cases.

## Solution

```Cpp

class Solution {
public:
    // Function to find the maximum size of the square that can end at position (i, j)
    // in the matrix and update the maxSquare variable to keep track of the largest square found.
    int findMaxSquare(vector<vector<char>>& matrix, int i, int j, int row, int col, int& maxSquare) {
        // Base case: If the current indices are out of bounds of the matrix, return 0
        if (i >= row || j >= col) {
            return 0;
        }

        // Recursive calls to explore the possible square sizes from the adjacent cells
        // right: to the right of the current cell
        // diagonal: to the diagonal bottom-right cell
        // down: to the cell directly below
        int right = findMaxSquare(matrix, i, j + 1, row, col, maxSquare);
        int diagonal = findMaxSquare(matrix, i + 1, j + 1, row, col, maxSquare);
        int down = findMaxSquare(matrix, i + 1, j, row, col, maxSquare);

        // If the current cell contains '1', it can be part of a square
        if (matrix[i][j] == '1') {
            // Calculate the size of the square ending at (i, j)
            // The size is 1 plus the minimum size of the squares that can end at the right, diagonal, and down cells
            int square = 1 + min({right, diagonal, down});

            // Update the maximum size of the square found so far
            maxSquare = max(square, maxSquare);

            // Return the size of the square ending at (i, j)
            return square;
        } else {
            // If the current cell is '0', no square can end here
            return 0;
        }
    }

    // Function to find the largest square of '1's in the matrix
    int maximalSquare(vector<vector<char>>& matrix) {
        // Initialize indices and dimensions
        int i = 0, j = 0;
        int row = matrix.size();       // Number of rows in the matrix
        int col = matrix[0].size();    // Number of columns in the matrix
        int maxSquare = 0;             // Variable to keep track of the maximum size of the square found

        // Start the recursion from the top-left corner of the matrix
        // The result from this call is not used directly since maxSquare is updated within the function
        int ans = findMaxSquare(matrix, i, j, row, col, maxSquare);

        // Return the area of the largest square found
        // The area is the square of the maximum size of the square
        return maxSquare * maxSquare;
    }
};

Time Complexity = O(m * n * min(m, n))
Space Complexity = O(m * n)
=> where 𝑚 is the number of rows and n is the number of columns
```
