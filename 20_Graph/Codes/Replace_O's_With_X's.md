# Question : [Replace O's with X's - GFG](https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1)

Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

### Example 1
```plaintext
Input: 
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix. 
```

### Example 2
```plaintext
Input: 
n = 5, m = 4
mat = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix.
```

### Your task
You do not need to read input or print anything. Your task is to complete the function fill() which takes N, M and mat as input parameters ad returns a 2D array representing the resultant matrix.

```
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
```

### Constraints
`11 ≤ n, m ≤ 500`

## Solution

```Cpp
Using BFS Traversal :

class Solution {
public:

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {

        int row = n;  // Number of rows in the matrix
        int col = m;  // Number of columns in the matrix
    
        // Directions array for moving up, down, left, and right
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Queue for performing BFS
        queue<pair<int, int>> q;
    
        // Check the first row for 'O' and mark them as visited ('V'), then push into queue
        for (int firstRow = 0; firstRow < col; firstRow++) {
            if (mat[0][firstRow] == 'O') {
                q.push({0, firstRow});
                mat[0][firstRow] = 'V';  // Mark as visited
            }
        }
    
        // Check the first column for 'O' and mark them as visited ('V'), then push into queue
        for (int firstCol = 1; firstCol < row; firstCol++) {
            if (mat[firstCol][0] == 'O') {
                q.push({firstCol, 0});
                mat[firstCol][0] = 'V';  // Mark as visited
            }
        }
    
        // Check the last row for 'O' and mark them as visited ('V'), then push into queue
        for (int lastRow = 1; lastRow < col; lastRow++) {
            if (mat[row - 1][lastRow] == 'O') {
                q.push({row - 1, lastRow});
                mat[row - 1][lastRow] = 'V';  // Mark as visited
            }
        }
    
        // Check the last column for 'O' and mark them as visited ('V'), then push into queue
        for (int lastCol = 1; lastCol < row - 1; lastCol++) {
            if (mat[lastCol][col - 1] == 'O') {
                q.push({lastCol, col - 1});
                mat[lastCol][col - 1] = 'V';  // Mark as visited
            }
        }
    
        // Perform BFS to mark all connected 'O's starting from the boundary 'O's
        while (!q.empty()) {
            int rowIndex = q.front().first;
            int colIndex = q.front().second;
            q.pop();
    
            // Check all 4 possible directions
            for (auto dir : directions) {
                int newRow = rowIndex + dir[0];
                int newCol = colIndex + dir[1];
    
                // If the new cell is within bounds and contains 'O', mark it as visited and push into queue
                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && mat[newRow][newCol] == 'O') {
                    mat[newRow][newCol] = 'V';  // Mark as visited
                    q.push({newRow, newCol});
                }
            }
        }
    
         // Change all remaining 'O's to 'X' (since they are not connected to boundary 'O's)
        // and revert visited 'V's back to 'O'
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 'O') {
                    mat[i][j] = 'X';  // Convert 'O' to 'X'
                } else if (mat[i][j] == 'V') {
                    mat[i][j] = 'O';  // Convert 'V' back to 'O'
                }
            }
        }

        return mat;     // Return the modified matrix
    }
};

Time Complexity = O(n * m)
Space Complexity = O(n * m)
```