# Question : [Minimum Sideway Jumps - (LeetCode : 1824)](https://leetcode.com/problems/minimum-sideway-jumps/description/)

There is a **3 lane road** of length `n` that consists of `n + 1` **points** labeled from `0` to `n`. A frog **starts** at point `0` in the **second** lane and wants to jump to point `n`. However, there could be obstacles along the way.

You are given an array `obstacles` of length `n + 1` where each `obstacles[i]` (**ranging from 0 to 3**) describes an obstacle on the lane `obstacles[i]` at point `i`. If `obstacles[i] == 0`, there are no obstacles at point `i`. There will be at most one obstacle in the 3 lanes at each point.

-   For example, if `obstacles[2] == 1`, then there is an obstacle on lane 1 at point 2.

The frog can only travel from point `i` to point ` + 1` on the same lane if there is not an obstacle on the lane at point `i + 1`. To avoid obstacles, the frog can also perform a **side jump** to jump to **another** lane (even if they are not adjacent) at the **same** point if there is no obstacle on the new lane.

-   For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.

Return _the **minimum number of side jumps** the frog needs to reach **any lane** at point n starting from lane `2` at point 0_.

**Note**: There will be no obstacles on points `0` and `n`.

### Example 1

![](https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex1.png)

```
Input: obstacles = [0,1,2,3,0]
Output: 2
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).
```

### Example 2

![](https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex2.png)

```
Input: obstacles = [0,1,1,3,3,0]
Output: 0
Explanation: There are no obstacles on lane 2. No side jumps are required.
```

### Example 3

![](https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex3.png)

```
Input: obstacles = [0,2,1,0,3,0]
Output: 2
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps.
```

### Constraints

-   `obstacles.length == n + 1`
-   `1 <= n <= 5 * 10^5`
-   `0 <= obstacles[i] <= 3`
-   `obstacles[0] == obstacles[n] == 0`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& obstacles, int currLane, int currPos) {
        // The last index of the obstacles
        int n = obstacles.size()-1;

        // Base case: if we've reached the last position, no further jump is needed.
        if(currPos == n)
            return 0;

        // If the next position is not blocked in the current lane, just move to the next position
        if(obstacles[currPos + 1] != currLane) {
            // Continue to next position without changing lanes
            return recursion(obstacles, currLane, currPos+1);
        }
        // If the next position is blocked, check for other lanes to jump to
        else {
            // Initialize the minimum jump value to a large number.
            int minJump = INT_MAX;

            // Try to jump to each of the three lanes (1, 2, 3) to find the best option
            for(int lane = 1; lane <= 3; lane++) {
                // Only jump to a lane if it’s not the current lane and if no obstacle is in that lane
                if(currLane != lane && obstacles[currPos] != lane) {
                    // Add 1 to the number of jumps (because we are jumping to a new lane) and
                    // Recursively find the min number of jumps from the next position in this lane
                    minJump = min(minJump, 1 + recursion(obstacles, lane, currPos));
                }
            }
            // Return the minimum jumps found
            return minJump;
        }
    }

    int minSideJumps(vector<int>& obstacles) {
        return recursion(obstacles, 2, 0);
    }
};

Time Complexity = O(3^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& obstacles, int currLane, int currPos, vector<vector<int>>& dp) {
        // The last index of the obstacles
        int n = obstacles.size()-1;

        // Base case: if we've reached the last position, no further jump is needed.
        if(currPos == n)
            return 0;

        // If the result is already computed, return the stored value.
        if(dp[currLane][currPos] != -1)
            return dp[currLane][currPos];

        // If the next position is not blocked in the current lane, just move to the next position
        if(obstacles[currPos + 1] != currLane) {
            // Continue to next position without changing lanes
            return memoization(obstacles, currLane, currPos+1, dp);
        }
        // If the next position is blocked, check for other lanes to jump to
        else {
            // Initialize the minimum jump value to a large number.
            int minJump = INT_MAX;

            // Try to jump to each of the three lanes (1, 2, 3) to find the best option
            for(int lane = 1; lane <= 3; lane++) {
                // Only jump to a lane if it’s not the current lane and if no obstacle is in that lane
                if(currLane != lane && obstacles[currPos] != lane) {
                    // Add 1 to the number of jumps (because we are jumping to a new lane) and
                    // Recursively find the min number of jumps from the next position in this lane
                    minJump = min(minJump, 1 + memoization(obstacles, lane, currPos, dp));
                }
            }
            // Store the result in DP table and return it.
            return dp[currLane][currPos] = minJump;
        }
    }

    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>>dp(4, vector<int>(obstacles.size(), -1));
        return memoization(obstacles, 2, 0, dp);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& obstacles) {
        // The last index of the obstacles
        int n = obstacles.size()-1;

        // DP table to store the minimum number of jumps needed at each lane and position
        // dp[i][j] represents the minimum jumps at position j when currently in lane i
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), INT_MAX));

        // Base case: no jumps required at the last position (since we're already at the goal)
        dp[0][n] = dp[1][n] = dp[2][n] = dp[3][n] = 0;

        // Iterate through all positions starting from the second-to-last position to the first position
        for(int currPos = n-1; currPos >= 0; currPos--) {
            for(int currLane = 1; currLane <= 3; currLane++) {
                // If the next position is free to continue in the same lane, move to the next position.
                if(obstacles[currPos+1] != currLane) {
                    dp[currLane][currPos] = dp[currLane][currPos+1];
                }
                // If the next position is blocked, check for other lanes to jump to
                else {
                    // Initialize the minimum number of jumps.
                    int minJump = INT_MAX;

                    // Try to jump to each of the three lanes (1, 2, 3) to find the best option
                    for(int lane = 1; lane <= 3; lane++) {
                        // Only jump to a lane if it’s not the current lane and if no obstacle is in that lane
                        if(currLane != lane && obstacles[currPos] != lane)
                            // Add 1 to the number of jumps (because we are jumping to a new lane) and check the result
                            minJump = min(minJump, 1 + dp[lane][currPos+1]);
                    }
                    // Store the minimum number of jumps for the current state
                    dp[currLane][currPos] = minJump;
                }
            }
        }
        // Return the minimum jumps to reach the last position starting from lane 1, 2, or 3
        return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
    }

    int minSideJumps(vector<int>& obstacles) {
        return tabulation(obstacles);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(vector<int>& obstacles) {
        int n = obstacles.size() - 1;       // The last index of the obstacles
        vector<int> curr(4, INT_MAX);       // Current DP row for the current position
        vector<int> next(4, INT_MAX);       // Next DP row for the next position

        // Base case: no jumps are needed at the final position
        next[0] = next[1] = next[2] = next[3] = 0;

        // Iterate through all positions starting from the second-to-last position to the first position
        for(int currPos = n-1; currPos >= 0; currPos--) {
            for(int currLane = 1; currLane <= 3; currLane++) {
                // If the next position is free to continue in the same lane, move to the next position.
                if(obstacles[currPos+1] != currLane) {
                    curr[currLane] = next[currLane];
                }
                // If the next position is blocked, check for other lanes to jump to
                else {
                    // Initialize the minimum number of jumps.
                    int minJump = INT_MAX;

                    // Try to jump to each of the three lanes (1, 2, 3) to find the best option
                    for(int lane = 1; lane <= 3; lane++) {
                        // Only jump to a lane if it’s not the current lane and if no obstacle is in that lane
                        if(currLane != lane && obstacles[currPos] != lane)
                            // Add 1 to the number of jumps (because we are jumping to a new lane) and check the result
                            minJump = min(minJump, 1 + next[lane]);
                    }
                    // Store the minimum number of jumps for the current state
                    curr[currLane] = minJump;
                }
            }
            // Move the current result to next for the next iteration
            next = curr;
        }
        // Return the minimum jumps to reach the last position starting from lane 1, 2, or 3
        return min(next[2], min(1+next[1], 1+next[3]));
    }

    int minSideJumps(vector<int>& obstacles) {
        return spaceOptimization(obstacles);
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
