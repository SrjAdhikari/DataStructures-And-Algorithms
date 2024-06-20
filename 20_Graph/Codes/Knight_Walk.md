# Question : [Knight Walk - GFG](https://www.geeksforgeeks.org/problems/knight-walk4521/1)

Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.If it cannot reach the target position return -1.

***Note :***
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

### Example 1
![](https://media.geeksforgeeks.org/wp-content/uploads/KnightChess.jpg)
```plaintext
Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:
Knight takes 3 step to reach from
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1). 
```

### Example 2
```plaintext
Input:
N=8
knightPos[ ] = {7, 7}
targetPos[ ] = {1, 5}
Output:
4
Explanation:
Knight takes 4 steps to reach from
(7, 7) to (1, 5):
(4, 5) -> (6, 5) -> (5, 3) -> (7, 2) -> (1, 5).
```

### Your task:
You don't need to read input or print anything. Your task is to complete the function ***minStepToReachTarget()*** which takes the inital position of Knight (KnightPos), the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position.If it cannot reach the target position return -1.

```plaintext
Expected Time Complexity : O(N^2)
Expected Auxiliary Space : O(N^2)
```

### Constraints
`1 <= N <= 1000`
`1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N`

## Solution 1

```Cpp
Using BFS Traversal :

class Solution {
public:

    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {

        // Convert positions from 1-based indexing to 0-based indexing
        KnightPos[0]--;  // Convert knight's row
        KnightPos[1]--;  // Convert knight's column
        TargetPos[0]--;  // Convert target's row
        TargetPos[1]--;  // Convert target's column
    
        // Base Case: If the knight is already at the target position, no steps are needed
        if(TargetPos[0] == KnightPos[0] && TargetPos[1] == KnightPos[1])
            return 0;
    
        // Queue to perform BFS, storing the current row and column of the knight
        queue<pair<int, int>> q;

        // Matrix to keep track of visited cells
        vector<vector<bool>> chessBoard(N, vector<bool>(N, 0));

        // Initialize BFS by marking the starting position as visited and pushing it into the queue
        q.push({KnightPos[0], KnightPos[1]});
        chessBoard[KnightPos[0]][KnightPos[1]] = 1;
    
        // Initialize step counter to track the number of moves
        int step = 0;
        
        // Possible directions of knight movement: up-right, up-left, down-right, down-left, etc.
        int directions[8][2] = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };
    
        // Perform BFS
        while(!q.empty()) {
            int count = q.size();  // Number of nodes at the current level of BFS
    
            // Process all nodes at the current level
            while(count--) {
                // Get the front element of the queue
                int rowIndex = q.front().first;
                int colIndex = q.front().second;
                q.pop();  // Remove the front element from the queue
    
                // Explore all eight possible knight moves
                for (auto dir : directions) {
                    int newRow = rowIndex + dir[0];  // Calculate new row index
                    int newCol = colIndex + dir[1];  // Calculate new column index
    
                    // Check if the new cell is within bounds and not visited
                    if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && chessBoard[newRow][newCol] == 0) {
                        // If the destination cell is reached, return the number of steps
                        if(newRow == TargetPos[0] && newCol == TargetPos[1])
                            return step + 1;
    
                        // Mark the new cell as visited and add it to the queue
                        chessBoard[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
            // Increment the step counter after exploring all nodes at the current level
            step++;
        }
        // If the destination is not reachable, return -1
        return -1;
    }
};

Time Complexity = O(N^2)
Space Complexity = O(N^2)
```