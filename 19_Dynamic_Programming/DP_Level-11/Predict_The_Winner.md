# Question : [Predict the Winner - (LeetCode : 486)](https://leetcode.com/problems/predict-the-winner/description/)

You are given an integer array `nums`. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of `0`. At each turn, the player takes one of the numbers from either end of the array (i.e., `nums[0]` or `nums[nums.length - 1]`) which reduces the size of the array by `1`. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return `true` if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return `true`. You may assume that both players are playing optimally.

### Example 1

```
Input: nums = [1,5,2]
Output: false
Explanation: Initially, player 1 can choose between 1 and 2.
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5.
If player 2 chooses 5, then player 1 will be left with 1 (or 2).
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
Hence, player 1 will never be the winner and you need to return false.
```

### Example 2

```
Input: nums = [1,5,233,7]
Output: true
Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7.
No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12),
so you need to return True representing player1 can win.
```

### Constraints

-   `1 <= nums.length <= 20`
-   `0 <= nums[i] <= 10^7`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& nums, int start, int end) {
        // Base case: If there is only one element left, return it as the score difference
        if(start == end)
            return nums[start];

        // Calculate the score difference if the player picks the number at the start
        int diffByStart = nums[start] - recursion(nums, start + 1, end);

        // Calculate the score difference if the player picks the number at the end
        int diffByEnd = nums[end] - recursion(nums, start, end - 1);

        // Return the maximum score difference the player can achieve
        return max(diffByStart, diffByEnd);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return recursion(nums, 0, n - 1) >= 0;
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        // Base case: If there is only one element left, return it as the score difference
        if(start == end)
            return nums[start];

        // If the result for the current range is already computed, return it
        if(dp[start][end] != -1)
            return dp[start][end];

        // Calculate the score difference if the player picks the number at the start
        int diffByStart = nums[start] - memoization(nums, start + 1, end, dp);

        // Calculate the score difference if the player picks the number at the end
        int diffByEnd = nums[end] - memoization(nums, start, end - 1, dp);

        // Store and return the maximum score difference for the current range
        return dp[start][end] = max(diffByStart, diffByEnd);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return memoization(nums, 0, n - 1, dp) >= 0;
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& nums) {
        int n = nums.size();

        // Initialize a dp table where dp[start][end] stores the maximum score difference for the subarray from start to end
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill the dp table from the end to the start
        for(int start = n - 1; start >= 0; start--) {
            // Iterate from the current start index to the last index
            for(int end = start; end < n; end++) {
                // Base case: when there's only one element, the score difference is just the value of that element
                if(start == end)
                    dp[start][end] = nums[start];
                else {
                    // Calculate the score difference if picking the number at the start
                    int diffByStart = nums[start] - dp[start + 1][end];

                    // Calculate the score difference if picking the number at the end
                    int diffByEnd = nums[end] - dp[start][end - 1];

                    // Store the maximum score difference for the current range
                    dp[start][end] = max(diffByStart, diffByEnd);
                }
            }
        }

        // Return the score difference for the full range [0, n-1]
        return dp[0][n - 1];
    }

    bool predictTheWinner(vector<int>& nums) {
        return tabulation(nums) >= 0;
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```
