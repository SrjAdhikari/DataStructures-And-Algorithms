# Question : [Maximum Height by Stacking Cuboids - (LeetCode : 1691)](https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/)

Given `n` `cuboids` where the dimensions of the `ith` cuboid is `cuboids[i] = [widthi, lengthi, heighti]` (**0-indexed**). Choose a **subset** of `cuboids` and place them on each other.

You can place cuboid `i` on cuboid `j` if `widthi <= widthj` and `lengthi <= lengthj` and `heighti <= heightj`. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return *the **maximum height** of the stacked* `cuboids`.

### Example 1

![](https://assets.leetcode.com/uploads/2019/10/21/image.jpg)

```
Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.
```

### Example 2

```
Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.
```

### Example 3

```
Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
Output: 102
Explanation:
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 * 17 = 102.
```

### Constraints

-   `n == cuboids.length`
-   `1 <= n <= 100`
-   `1 <= widthi, lengthi, heighti <= 100`

### Recursive Approach

```Cpp
class Solution {
public:
    // Function to validate if one cuboid can be stacked on top of another
    int validationCheck(vector<int>& curr, vector<int>& prev) {
        // Returns true if the cuboid 'curr' can be placed on top of 'prev'.
        // This ensures that the length, width, and height of 'prev' are all 
        // less than or equal to the corresponding dimensions of 'curr'.
        return (prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]);
    }

    int recursion(vector<vector<int>>& cuboids, int curr, int prev) {
        // Base case: If we have processed all cuboids, return 0 (no height left to add).
        if(curr >= cuboids.size())
            return 0;

        // Variable to track the height if we include the current cuboid in the stack.
        int include = 0;

        // Check if the current cuboid can be placed on top of the previous one.
        // If 'prev' is -1, it means there is no previous cuboid, so we can always include 'curr'.
        if(prev == -1 || validationCheck(cuboids[curr], cuboids[prev])) {
            // Height of the current cuboid.
            int maxHeight = cuboids[curr][2];

            // Include the current cuboid height and move to the next element (curr+1) and (prev = curr).
            include = maxHeight + recursion(cuboids, curr + 1, curr);
        }

        // Variable to track the maximum height excluding the current element.
        // Move to the next element without changing 'prev'
        int exclude = recursion(cuboids, curr + 1, prev);

        // Return the maximum height between including and excluding the current cuboid.
        return max(include, exclude);
    }


    int maxHeight(vector<vector<int>>& cuboids) {
        // Step 1: Sort each cuboid's dimensions to ensure they can only be stacked in sorted order.
        for(auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }

        // Step 2: Sort all cuboids based on their dimensions (length, width, height).
        sort(cuboids.begin(), cuboids.end());

        return recursion(cuboids, 0, -1);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int validationCheck(vector<int>& curr, vector<int>& prev) {
        // Returns true if the cuboid 'curr' can be placed on top of 'prev'.
        // This ensures that the length, width, and height of 'prev' are all 
        // less than or equal to the corresponding dimensions of 'curr'.
        return (prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]);
    }

   int memoization(vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>>& dp) {
        // Base case: If we have processed all cuboids, return 0 (no height left to add).
        if(curr >= cuboids.size())
            return 0;

        // Check if the result for this (curr, prev) pair is already computed, if yes, return it.
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        // Variable to track the height if we include the current cuboid in the stack.
        int include = 0;

        // Check if the current cuboid can be placed on top of the previous one.
        // If 'prev' is -1, it means there is no previous cuboid, so we can always include 'curr'.
        if(prev == -1 || validationCheck(cuboids[curr], cuboids[prev])) {
            // Height of the current cuboid.
            int maxHeight = cuboids[curr][2];

            // Include the current cuboid height and move to the next element (curr+1) and (prev = curr).
            include = maxHeight + memoization(cuboids, curr + 1, curr, dp);
        }

        // Variable to track the maximum height excluding the current element.
        // Move to the next element without changing 'prev'
        int exclude = 0 + memoization(cuboids, curr + 1, prev, dp);

        // Store the result for this (curr, prev) pair in the DP array and return it.
        return dp[curr][prev+1] = max(include, exclude);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return memoization(cuboids, 0, -1, dp);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int validationCheck(vector<int>& curr, vector<int>& prev) {
        // Returns true if the cuboid 'curr' can be placed on top of 'prev'.
        // This ensures that the length, width, and height of 'prev' are all 
        // less than or equal to the corresponding dimensions of 'curr'.
        return (prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]);
    }

    int tabulation(vector<vector<int>>& cuboids) {
        int n = cuboids.size();

        // Create a DP table where dp[curr][prev + 1] stores the max height for cuboids[curr..n-1]
        // with prev being the index of the last included cuboid (or -1 for no previous cuboid)
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Start iterating from the last cuboid back to the first
        for(int curr = n-1; curr >= 0; curr--) {
            // Iterate backwards for previous indices
            for(int prev = curr-1; prev >= -1; prev--) {

                // Variable to track the height if we include the current cuboid in the stack.
                int include = 0;

                // Check if the current cuboid can be placed on top of the previous one.
                // If 'prev' is -1, it means there is no previous cuboid, so we can always include 'curr'.
                if (prev == -1 || validationCheck(cuboids[curr], cuboids[prev])) {
                    // Height of the current cuboid.
                    int maxHeight = cuboids[curr][2];

                    // Include the current height and move to the next one.
                    include = maxHeight + dp[curr + 1][curr + 1];
                }

                // Variable to track the maximum height excluding the current element.
                // Move to the next element without changing 'prev'
                int exclude = dp[curr + 1][prev + 1];

                // Store the computed height for the current position in the DP array
                dp[curr][prev + 1] = max(include, exclude);
            }
        }

        // Return the final result at dp[0][0], representing the max height for the entire array
        return dp[0][0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());

        return tabulation(cuboids);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int validationCheck(vector<int>& curr, vector<int>& prev) {
        // Returns true if the cuboid 'curr' can be placed on top of 'prev'.
        // This ensures that the length, width, and height of 'prev' are all 
        // less than or equal to the corresponding dimensions of 'curr'.
        return (prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]);
    }

    int spaceOptimization(vector<vector<int>>& cuboids) {
        int n = cuboids.size();

        // Two rows: 'currRow' represents the current row being computed,
        // 'nextRow' represents the previously computed row.
        vector<int> currRow(n + 1, 0), nextRow(n + 1, 0);

        // Process cuboids in reverse order, from last to first.
        for(int curr = n - 1; curr >= 0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {

                // Variable to track the height if we include the current cuboid in the stack.
                int include = 0;

                // Check if the current cuboid can be placed on top of the previous one.
                // If 'prev' is -1, it means there is no previous cuboid, so we can always include 'curr'.
                if(prev == -1 || validationCheck(cuboids[curr], cuboids[prev])) {
                    // Height of the current cuboid.
                    int maxHeight = cuboids[curr][2];

                    // Include the current height and move to the next one.
                    include = maxHeight + nextRow[curr + 1];
                }

                // Variable to track the maximum height excluding the current element.
                // Move to the next element without changing 'prev'
                int exclude = nextRow[prev + 1];

                // Store the maximum computed height for the current position in the current row.
                currRow[prev + 1] = max(include, exclude);
            }

            // Move the current row to next row for the next iteration
            nextRow = currRow;
        }

        // The result for the entire problem is stored in nextRow[0].
        return nextRow[0];
    }

        int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());

        return spaceOptimization(cuboids);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n)
```