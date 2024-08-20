# Question : [Rat in a Maze Problem - GFG](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)

Consider a rat placed at **(0, 0)** in a square matrix **mat** of order **n\*n**. It has to reach the destination at **(n - 1, n - 1)**. Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are **'U'(up), 'D'(down), 'L' (left), 'R' (right)**. Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.

**Note**: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output **"-1"** automatically.

### Example 1

```
Input: mat[][] = [[1, 0, 0, 0],
                  [1, 1, 0, 1],
                  [1, 1, 0, 0],
                  [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
```

### Example 2

```
Input: mat[][] = [[1, 0],
                  [1, 0]]
Output: -1
Explanation: No path exists and destination cell is blocked.
```

```
Expected Time Complexity: O(3^n^2)
Expected Auxiliary Space: O(l * x)
Here l = length of the path, x = number of paths.
```

### Constraints

`2 ≤ n ≤ 5`
`0 ≤ mat[i][j] ≤ 1`

## Solution

```Cpp
class Solution {
public:
    // Arrays to store possible movements in terms of rows and columns
    // row[] represents Up, Down, No move, No move
    // col[] represents No move, No move, Left, Right
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    // String representing the directions corresponding to the movements
    string direction = "UDLR";

    // Function to check if the current cell (i, j) is within the matrix bounds
    bool isValid(int i, int j, int n) {
        // If the cell is within the bounds of the matrix, return true; otherwise, return false
        return (i >= 0 && j >= 0 && i < n && j < n);
    }

    // Recursive function to explore all possible paths from (i, j) to (n-1, n-1)
    void totalPath(vector<vector<int>>& matrix, int i, int j, int n, string& path, vector<string>& ans, vector<vector<bool>>& visited) {
        // Base case: If the rat reaches the destination cell (n-1, n-1), add the path to the result list
        if(i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        // Mark the current cell as visited
        visited[i][j] = true;

        // Explore all 4 possible directions: Up, Down, Left, Right
        for(int k = 0; k < 4; k++) {
            // Calculate the next cell coordinates
            int newRow = i + row[k];
            int newCol = j + col[k];

            // Check if the next cell is valid, not blocked, and not visited
            if(isValid(newRow, newCol, n) && matrix[newRow][newCol] && !visited[newRow][newCol]) {
                // Add the current direction to the path
                path.push_back(direction[k]);

                // Recursively explore the next cell
                totalPath(matrix, newRow, newCol, n, path, ans, visited);

                // Backtrack: Remove the last direction from the path to explore other possibilities
                path.pop_back();
            }
        }

        // Unmark the current cell as visited for other paths
        visited[i][j] = false;
    }

    // Function to find all paths from the top-left to the bottom-right of the matrix
    vector<string> findPath(vector<vector<int>>& mat) {
        int i = 0, j = 0;       // Starting point (0, 0)
        int n = mat.size();     // Size of the matrix
        string path;            // To store the current path
        vector<string> ans;     // To store all valid paths
        vector<vector<bool>> visited(n, vector<bool>(n, false));  // Visited matrix to track cells that have been visited

        // Edge case: If the start or end cell is blocked, return an empty list
        if(mat[i][j] == 0 || mat[n - 1][n - 1] == 0)
            return ans;

        // Start the recursive exploration of all paths
        totalPath(mat, i, j, n, path, ans, visited);
        return ans;
    }
};

Time Complexity = O(3^n^2)
Space Complexity = O(n^2)
```
