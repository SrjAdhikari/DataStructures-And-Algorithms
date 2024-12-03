# Question : [Reducing Dishes - (LeetCode : 1402)](https://leetcode.com/problems/reducing-dishes/description/)

A chef has collected data on the `satisfaction` level of his `n` dishes. Chef can cook any dish in 1 unit of time.

**Like-time coefficient** of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. `time[i] * satisfaction[i]`.

Return the maximum sum of **like-time coefficient** that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in **any** order and the chef can discard some dishes to get this maximum value.

### Example 1

```
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
```

### Example 2

```
Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
```

### Example 3

```
Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
```

### Constraints

-   `n == satisfaction.length`
-   `1 <= n <= 500`
-   `-1000 <= satisfaction[i] <= 1000`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& satisfaction, int index, int time) {
        // Get the size of the satisfaction array
        int n = satisfaction.size();

        // Base case: If index is out of bounds (i.e., all dishes are considered), return 0
        if(index >= n)
            return 0;

        // Calculate the satisfaction for the current dish based on its time of preparation (time + 1) as we start from time = 0
        int likeTimeCoeff = satisfaction[index] * (time + 1);

        // Include the current dish: Add the time coefficient and recursively move to the next dish with incremented time
        int include = likeTimeCoeff + recursion(satisfaction, index + 1, time + 1);

        // Exclude the current dish: Skip this dish and recursively move to the next one with the same time
        int exclude = 0 + recursion(satisfaction, index + 1, time);

        // Return the maximum of including or excluding the current dish
        return max(include, exclude);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        // Sort the satisfaction array in non-decreasing order to maximize the total satisfaction
        sort(satisfaction.begin(), satisfaction.end());
        return recursion(satisfaction, 0, 0);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& satisfaction, int index, int time, vector<vector<int>>& dp) {
        // Get the size of the satisfaction array
        int n = satisfaction.size();

        // Base case: If index is out of bounds (i.e., all dishes are considered), return 0
        if(index >= n)
            return 0;

        // Check if the result for this state has already been computed, if yes return it.
        if(dp[index][time] != -1)
            return dp[index][time];

        // Calculate the satisfaction for the current dish based on its time of preparation (time + 1) as we start from time = 0
        int likeTimeCoeff = satisfaction[index] * (time + 1);

        // Include the current dish: Add the time coefficient and recursively move to the next dish with incremented time
        int include = likeTimeCoeff + memoization(satisfaction, index + 1, time + 1, dp);

        // Exclude the current dish: Skip this dish and recursively move to the next one with the same time
        int exclude = 0 + memoization(satisfaction, index + 1, time, dp);

        // Store the result in the dp table and return the maximum value
        return dp[index][time] = max(include, exclude);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        // Sort the satisfaction array in non-decreasing order to maximize the total satisfaction
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return memoization(satisfaction, 0, 0, dp);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& satisfaction) {
        // Get the size of the satisfaction array
        int n = satisfaction.size();

        // DP table to store the maximum satisfaction for each index and time
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Iterate backward through all dishes from n-1 to 0
        for(int index = n - 1; index >= 0; index--) {
            // For each dish, iterate backward through time (from n-1 to 0)
            for(int time = n - 1; time >= 0; time--) {
                // Calculate the satisfaction for the current dish based on its time of preparation (time + 1)
                int likeTimeCoeff = satisfaction[index] * (time + 1);

                // Include the current dish: Add the time coefficient and take the result for the next dish with incremented time
                int include = likeTimeCoeff + dp[index + 1][time + 1];

                // Exclude the current dish: Skip this dish and take the result for the next dish with the same time
                int exclude = 0 + dp[index + 1][time];

                // Store the maximum of including or excluding the current dish
                dp[index][time] = max(include, exclude);
            }
        }

        // Return the maximum satisfaction achievable from index 0 and time 0
        return dp[0][0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        // Sort the satisfaction array in non-decreasing order to maximize the total satisfaction
        sort(satisfaction.begin(), satisfaction.end());
        return tabulation(satisfaction);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(vector<int>& satisfaction) {
        int n = satisfaction.size();    // Get the size of the satisfaction array
        vector<int> curr(n + 1, 0);     // Current row of the DP table
        vector<int> next(n + 1, 0);     // Next row of the DP table

        // Iterate backward through all dishes from n-1 to 0
        for(int index = n - 1; index >= 0; index--) {
            // For each dish, iterate backward through time (from n-1 to 0)
            for(int time = n - 1; time >= 0; time--) {
                // Calculate the satisfaction for the current dish based on its time of preparation (time + 1)
                int likeTimeCoeff = satisfaction[index] * (time + 1);

                // Include the current dish: Add the time coefficient and take the result for the next dish with incremented time
                int include = likeTimeCoeff + next[time + 1];

                // Exclude the current dish: Skip this dish and take the result for the next dish with the same time
                int exclude = 0 + next[time];

                // Store the maximum of including or excluding the current dish
                curr[time] = max(include, exclude);
            }
            // Move the current row to the next row for the next iteration
            next = curr;
        }

        // Return the maximum satisfaction achievable from index 0 and time 0
        return next[0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        // Sort the satisfaction array in non-decreasing order to maximize the total satisfaction
        sort(satisfaction.begin(), satisfaction.end());
        return spaceOptimization(satisfaction);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n)
```
