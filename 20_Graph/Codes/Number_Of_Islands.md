# Question : [Number Of Islands - (LeetCode : 200)](https://leetcode.com/problems/number-of-islands/description/)

Given an `m x n` 2D binary grid `grid` which represents a map of `'1's` (land) and `'0's` (water), return *the number of islands.*

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

### Example 1
```plaintext
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

### Example 2
```plaintext
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

### Constraints
`m == grid.length`
`n == grid[i].length`
`1 <= m, n <= 300`
`grid[i][j] is '0' or '1'.`


## Solution

```Cpp
Using BFS Traversal :

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();      // Get the number of rows in the grid
        int col = grid[0].size();    // Get the number of columns in the grid

        queue<pair<int, int>> q;    // Queue to perform BFS
        int count = 0;              // Variable to count the number of islands

        // Array to represent the 4 possible directions (up, down, left, right)
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Array to represent the 8 possible directions (up, down, left, right, and diagonals)
        // int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, // up, down, left, right
        //                         {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}; // diagonals

        // Traverse the entire grid
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                
                // If the cell contains '1', it means it's part of an island
                if (grid[i][j] == '1') {
                    count++;         // Increment the island count

                    // Start BFS from this cell
                    q.push({i, j});
                    grid[i][j] = '0';       // Mark the cell as visited by setting it to '0'

                    // Process all cells in the current island
                    while (!q.empty()) {
                        // Get the current cell coordinates
                        int rowIndex = q.front().first;
                        int colIndex = q.front().second;
                        q.pop();

                        // Check all 4 possible directions
                        for (auto dir : directions) {
                            int newRow = rowIndex + dir[0]; 
                            int newCol = colIndex + dir[1];

                            // If the new cell is within bounds and contains '1'
                            if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && grid[newRow][newCol] == '1') {
                                // Mark the new cell as visited
                                grid[newRow][newCol] = '0';
                                // Add the new cell to the queue for further processing
                                q.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }
        // Return the total number of islands found
        return count;
    }
};

Time Complexity = O(row * col)
Space Complexity = O(row * col)
```