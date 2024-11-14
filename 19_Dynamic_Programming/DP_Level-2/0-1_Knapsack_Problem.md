# Question : [0 - 1 Knapsack Problem - GFG](https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1)

You are given the weights and values of items, and you need to put these items in a knapsack of capacity `capacity` to achieve the maximum total value in the knapsack. Each item is available in only one quantity.

In other words, you are given two integer arrays `val[]` and `wt[]`, which represent the values and weights associated with items, respectively. You are also given an integer `capacity`, which represents the knapsack capacity. Your task is to find the maximum sum of values of a subset of val[] such that the sum of the weights of the corresponding subset is less than or equal to `capacity`. You cannot break an item; you must either pick the entire item or leave it (0-1 property).

### Example 1

```
Input: capacity = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
```

### Example 2

```
Input: capacity = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
```

### Example 3

```
Input: capacity = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 6, 3] 
Output: 50
Explanation: Choose the second item (value 40, weight 4) and 
the fourth item (value 50, weight 3) for a total weight of 7, 
which exceeds the capacity. Instead, pick the last item (value 50, weight 3) for a total value of 50.
```

```
Expected Time Complexity: O(n*capacity).
Expected Auxiliary Space: O(n*capacity)
```

### Constraints

`2 ≤ val.size() = wt.size() ≤ 10^3`
`1 ≤ capacity ≤ 10^3`
`1 ≤ val[i], wt[i] ≤ 10^3`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion (int capacity, vector<int> &val, vector<int> &wt, int index) {
        int n = val.size();
        int include = 0;
        
        // Base case: if index reaches the end of the items, no value can be added to knapsack
        if(index >= n)
            return 0;
            
        // Check if the current item can be included in the knapsack (weight is within capacity).
        if(wt[index] <= capacity)
            // Include the current item and add its value, reduce capacity, and move to the next item
            include = val[index] + recursion(capacity - wt[index], val, wt, index + 1);
        
        // Exclude the current item from the knapsack and move to the next item.
        int exclude = 0 + recursion(capacity, val, wt, index + 1);
        
        // Return the maximum value obtained by including or excluding the current item.
        return max(include, exclude);
    }

    int knapSack (int capacity, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        return recursion(capacity, val, wt, 0);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
=> n = number of items
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization (int capacity, vector<int> &val, vector<int> &wt, int index, vector<vector<int>>& dp) {
        int n = val.size();
        int include = 0;
        
        // Base case: if index reaches the end of the items, no value can be added to knapsack
        if(index >= n)
            return 0;
            
        // Check if result for current capacity and index is already computed, if so return its result.
        if(dp[capacity][index] != -1)
            return dp[capacity][index];
            
        // Check if the current item can be included in the knapsack (weight is within capacity).
        if(wt[index] <= capacity)
            // Include the current item and add its value, reduce capacity, and move to the next item
            include = val[index] + memoization(capacity - wt[index], val, wt, index + 1, dp);
        
        // Exclude the current item from the knapsack and move to the next item.
        int exclude = 0 + memoization(capacity, val, wt, index + 1, dp);
        
        // Store the maximum value between including and excluding the item in dp array and return it.
        dp[capacity][index] = max(include, exclude);
        return dp[capacity][index];
    }

    int knapSack (int capacity, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>>dp(capacity+1, vector<int>(n+1, -1));
        return memoization(capacity, val, wt, 0, dp);
    }
};

Time Complexity = O(n * capacity)
Space Complexity = O(n * capacity)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation (int capacity, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>>dp(capacity+1, vector<int>(n+1, -1));
        
        // Initialize the base cases for the first row (capacity = 0).
        for(int row = 0; row <= capacity; row++) {
            dp[row][n] = 0;
        }
        
        // Fill the dp table bottom-up from the last item to the first.
        // Loop through all capacities.
        for(int space = 0; space <= capacity; space++) {
            // Loop through items in reverse order.
            for(int index = n-1; index >= 0; index--) {
                int include = 0;

                // Check if the current item can be included in the knapsack (weight is within capacity).
                if(wt[index] <= space)
                    // Include the current item and add its value, reduce capacity, and move to the next item
                    include = val[index] + dp[space-wt[index]][index+1];
                
                // Exclude the current item from the knapsack and move to the next item.
                int exclude = 0 + dp[space][index+1];
                
                // Store the maximum value obtainable by including or excluding the current item in dp array.
                dp[space][index] = max(include, exclude);
            }
        }
        // Return the maximum value obtainable with full capacity and all items.
        return dp[capacity][0];
    }

    int knapSack (int capacity, vector<int> &val, vector<int> &wt) {
        return tabulation(capacity, val, wt);
    }
};

Time Complexity = O(n * capacity)
Space Complexity = O(n * capacity)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(int capacity, vector<int> &val, vector<int> &wt) {
        int n = val.size();

        // Initialize a 1D dp array to store the results for the current row and the next row
        vector<int>next(capacity+1, 0);
        
        // Iterate over items from the last to the first.
        for(int index = n-1; index >= 0; index--) {
            // Traverse from maximum capacity to 0 to avoid overwriting previous results.
            for(int space = capacity; space >= 0; space--) {
                int include = 0;

                // Check if the current item can be included in the knapsack (weight is within capacity).
                if(wt[index] <= space)
                    // Include the current item and add its value, reduce capacity, and move to the next item
                    include = val[index] + next[space - wt[index]];
                
                // Exclude the current item from the knapsack and move to the next item.
                int exclude = 0 + next[space];
                
                // Store the maximum value obtainable by including or excluding the current item.
                next[space] = max(include, exclude);
            }
        }

        // Return the maximum value obtainable with full capacity and all items.
        return next[capacity];
    }

    int knapSack (int capacity, vector<int> &val, vector<int> &wt) {
        return spaceOptimization(capacity, val, wt);
    }
};

Time Complexity = O(capacity)
Space Complexity = O(capacity)
```
