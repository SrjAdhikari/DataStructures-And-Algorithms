# Question : [Minimum Cost For Tickets - (LeetCode : 983)](https://leetcode.com/problems/minimum-cost-for-tickets/description/)

You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array `days`. Each day is an integer from `1` to `365`.

Train tickets are sold in **three different ways**:

- a **1-day** pass is sold for `costs[0]` dollars,
- a **7-day** pass is sold for `costs[1]` dollars, and
- a **30-day** pass is sold for `costs[2]` dollars.

The passes allow that many days of consecutive travel.

- For example, if we get a **7-day** pass on day `2`, then we can travel for `7` days: `2`, `3`, `4`, `5`, `6`, `7`, and `8`.

Return *the minimum number of dollars you need to travel every day in the given list of days*.

### Example 1

```
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
```

### Example 2

```
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.
```

### Constraints

- `1 <= days.length <= 365`
- `1 <= days[i] <= 365`
- `days` is in strictly increasing order.
- `costs.length == 3`
- `1 <= costs[i] <= 1000`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& days, vector<int>& costs, int index) {
        // Base case: If we have processed all days, no cost is required.
        if (index >= days.size())
            return 0;

        // Option 1: Buy a 1-day pass, add the cost of the 1-day pass and move to the next day.
        int cost1 = costs[0] + recursion(days, costs, index + 1);

        // Option 2: Buy a 7-day pass
        int i = index;                      // Pointer to find the first day not covered by the 7-day pass
        int passEndDay = days[index] + 7;   // End day of the 7-day pass

        // Find the first day not covered by the 7-day pass
        while (i < days.size() && days[i] < passEndDay) {
            i++;    // Skip all days covered by the 7-day pass.
        }

        // Add the 7-day pass cost and move to the next uncovered day.
        int cost2 = costs[1] + recursion(days, costs, i);

        // Option 3: Buy a 30-day pass
        i = index;                          // Reset pointer to find the first day not covered by the 30-day pass
        passEndDay = days[index] + 30;       // End day of the 30-day pass

        // Find the first day not covered by the 30-day pass
        while (i < days.size() && days[i] < passEndDay) {
            i++;    // Skip all days covered by the 30-day pass.
        }

        // Add the 30-day pass cost and move to the next uncovered day.
        int cost3 = costs[2] + recursion(days, costs, i);

        // Return the minimum cost from all three options (1-day, 7-day, 30-day pass).
        return min(cost1, min(cost2, cost3));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return recursion(days, costs, 0);
    }
};

Time Complexity = O(3^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& days, vector<int>& costs, int index, vector<int>& dp) {
        // Base case: If we have processed all days, no cost is required.
        if (index >= days.size())
            return 0;

        // Check if the result for the current day is already computed, if yes return it.
        if (dp[index] != -1)
            return dp[index];

        // Option 1: Buy a 1-day pass, add the cost of the 1-day pass and move to the next day.
        int cost1 = costs[0] + memoization(days, costs, index + 1, dp);

        // Option 2: Buy a 7-day pass
        int i = index;                      // Pointer to find the first day not covered by the 7-day pass
        int passEndDay = days[index] + 7;   // End day of the 7-day pass

        // Find the first day not covered by the 7-day pass
        while (i < days.size() && days[i] < passEndDay) {
            i++;    // Skip all days covered by the 7-day pass.
        }

        // Add the 7-day pass cost and move to the next uncovered day.
        int cost2 = costs[1] + memoization(days, costs, i);

        // Option 3: Buy a 30-day pass
        i = index;                          // Reset pointer to find the first day not covered by the 30-day pass
        passEndDay = days[index] + 30;       // End day of the 30-day pass

        // Find the first day not covered by the 30-day pass
        while (i < days.size() && days[i] < passEndDay) {
            i++;    // Skip all days covered by the 30-day pass.
        }

        // Add the 30-day pass cost and move to the next uncovered day.
        int cost3 = costs[2] + memoization(days, costs, i);

        // Store the minimum cost in the dp array and return it.
        return dp[index] = min(cost1, min(cost2, cost3));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, -1);
        return memoization(days, costs, 0, dp);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        // Initialize a dp array to store the minimum cost from each day to the end.
        // Set all costs to a large value initially
        vector<int> dp(n + 1, INT_MAX);

        // Base case: No cost required beyond the last travel day
        dp[n] = 0;

        // Process days from the last day to the first day.
        for (int index = n - 1; index >= 0; index--) {
            // Option 1: Buy a 1-day pass. Move to the next day (index + 1).
            int cost1 = costs[0] + dp[index + 1];

            // Option 2: Buy a 7-day pass. Find the first day not covered by this pass.
            int i = index;
            int passEndDay = days[index] + 7;

            // Find the first day not covered by the 7-day pass
            while (i < days.size() && days[i] < passEndDay) {
                i++;
            }

            // Add the 7-day pass cost and move to the next uncovered day.
            int cost2 = costs[1] + dp[i];

            // Option 3: Buy a 30-day pass. Find the first day not covered by this pass.
            i = index;
            passEndDay = days[index] + 30;

            // Find the first day not covered by the 30-day pass
            while (i < days.size() && days[i] < passEndDay) {
                i++;
            }

            // Add the 30-day pass cost and move to the next uncovered day.
            int cost3 = costs[2] + dp[i];

            // Store the minimum cost for the current day in the dp array.
            dp[index] = min(cost1, min(cost2, cost3));
        }

        // Return the minimum cost for traveling starting from the first day.
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return tabulation(days, costs);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(vector<int>& days, vector<int>& costs) {
        int ans = 0;                    // This will store the minimum cost of travel passes so far.
        queue<pair<int, int>> month;    // Tracks the earliest day a 30-day pass covers
        queue<pair<int, int>> week;     // Tracks the earliest day a 7-day pass covers

        // Iterate through each day in the travel days array.
        for (int day : days) {
            // Remove expired entries for the 30-day pass
            while (!month.empty() && month.front().first + 30 <= day) {
                month.pop();
            }

            // Remove expired entries for the 7-day pass
            while (!week.empty() && week.front().first + 7 <= day) {
                week.pop();
            }

            // Add a new 7-day pass for the current day.
            week.push({day, ans + costs[1]});

            // Add a new 30-day pass for the current day
            month.push({day, ans + costs[2]});

            // Update the answer to the minimum of 1-day, 7-day, and 30-day pass costs
            ans = min(ans + costs[0], min(week.front().second, month.front().second));
        }

        // Return the minimum cost for all travel days.
        return ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return spaceOptimization(days, costs);
    }
};

Time Complexity = O(n)
Space Complexity = O(k)
=> 'k' is the number of travel days.
```