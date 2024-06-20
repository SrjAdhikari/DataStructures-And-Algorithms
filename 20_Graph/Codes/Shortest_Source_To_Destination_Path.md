# Question : [Shortest Source To Destination Path - GFG](https://www.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1)

Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that ***contain 1.***

### Example 1
```plaintext
Input:
N=3, M=4
A=[[1,0,0,0], 
   [1,1,0,1],
   [0,1,1,1]]
X=2, Y=3 
Output:
5
Explanation:
The shortest path is as follows:
(0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).
```

### Example 2
```plaintext
Input:
N=3, M=4
A=[[1,1,1,1],
   [0,0,0,1],
   [0,0,0,1]]
X=0, Y=3
Output:
3
Explanation:
The shortest path is as follows:
(0,0)->(0,1)->(0,2)->(0,3).
```

### Your task:
You don't need to read input or print anything. Your task is to complete the function ***shortestDistance()*** which takes the integer N, M, X, Y, and the 2D binary matrix A as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.

```plaintext
Expected Time Complexity : O(N * M)
Expected Auxiliary Space : O(N * M)
```

### Constraints
`1 <= N,M <= 250`
`0 <= X < N`
`0 <= Y < M`
`0 <= A[i][j] <= 1`

## Solution 1

```Cpp
Using BFS Traversal :

class Solution {
public:

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
    
        // If the starting point (0,0) is blocked, return -1 as there is no path
        if(A[0][0] == 0)
            return -1;
        
        // If the destination is the starting point, return 0 as no steps are needed
        if(X == 0 && Y == 0)
            return 0;
    
        // Queue to perform BFS, storing the current row, current column, and the number of steps taken so far
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        
        // Matrix to keep track of visited cells
        vector<vector<bool>> visited(N, vector<bool>(M, 0));
        visited[0][0] = 1;
        
        // Possible directions of movement: up, down, left, right
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Perform BFS
        while(!q.empty()) {
            // Get the front element of the queue
            int rowIndex = q.front().first;
            int colIndex = q.front().second.first;
            int step = q.front().second.second;
            q.pop(); // Remove the front element from the queue
            
            // Explore all four possible directions
            for (auto dir : directions) {
                int newRow = rowIndex + dir[0];     // Calculate new row index
                int newCol = colIndex + dir[1];     // Calculate new column index
                
                // Check if the new cell is within bounds, not blocked, and not visited
                if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && A[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                    // If the destination is reached, return the number of steps
                    if(newRow == X && newCol == Y)
                        return step + 1;
                    
                    // Mark the cell as visited and add it to the queue with incremented step count
                    visited[newRow][newCol] = 1;
                    q.push({newRow, {newCol, step + 1}});
                }
            }
        }
        // If the destination is not reachable, return -1
        return -1;
    }
};

Time Complexity = O(N * M)
Space Complexity = O(N * M)
```

## Solution 2

```Cpp
Optimise BFS Traversal :

class Solution {
public:

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
    
        // If the starting point (0,0) is blocked, return -1 as there is no path
        if(A[0][0] == 0)
            return -1;
        
        // If the destination is the starting point, return 0 as no steps are needed
        if(X == 0 && Y == 0)
            return 0;

        // Initialize a queue for BFS, storing the current row and column
        queue<pair<int, int>> q;
        q.push({0, 0});     // Start from the top-left corner
        int step = 0;       // Initialize step counter
        
        // Mark the starting cell as visited by setting it to 0 (blocked)
        A[0][0] = 0;
        
        // Possible directions of movement: up, down, left, right
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Perform BFS until the queue is empty
        while(!q.empty()) {
            int count = q.size();   // Number of nodes at the current level

            while(count--) {
                // Get the front element of the queue
                int rowIndex = q.front().first;
                int colIndex = q.front().second;
                q.pop();    // Remove the front element from the queue
                
                // Explore all four possible directions from the current cell
                for (auto dir : directions) {
                    int newRow = rowIndex + dir[0];     // Calculate new row index
                    int newCol = colIndex + dir[1];     // Calculate new column index
                    
                    // Check if the new cell is within bounds, not blocked, and not visited
                    if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && A[newRow][newCol] == 1) {
                        // If the destination cell is reached, return the number of steps taken
                        if(newRow == X && newCol == Y)
                            return step + 1;
                        
                        // Mark the new cell as visited by setting it to 0 (blocked)
                        A[newRow][newCol] = 0;
                        // Add the new cell to the queue for further exploration
                        q.push({newRow, newCol});
                    }
                }
            }
            // Increment the step counter after exploring all nodes at the current level
            step++;
        }
        // If the destination is not reachable after BFS completes, return -1
        return -1;
    }
};

Time Complexity = O(N * M)
Space Complexity = O(min(N, M))
```