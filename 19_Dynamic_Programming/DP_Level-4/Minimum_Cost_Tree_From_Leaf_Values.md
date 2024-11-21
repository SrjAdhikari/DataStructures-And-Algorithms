# Question : [Minimum Cost Tree From Leaf Values - (LeetCode : 1130)](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/)

Given an array `arr` of positive integers, consider all binary trees such that:

- Each node has either `0` or `2` children;
- The values of `arr` correspond to the values of each **leaf** in an in-order traversal of the tree.
- The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.

Among all possible binary trees considered, return *the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a **32-bit** integer*.

A node is a **leaf** if and only if it has zero children.

### Example 1

![](https://assets.leetcode.com/uploads/2021/08/10/tree1.jpg)

```
Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
```

### Example 2

![](https://assets.leetcode.com/uploads/2021/08/10/tree2.jpg)

```
Input: arr = [4,11]
Output: 44
```

### Constraints

-   `2 <= arr.length <= 40`
-   `1 <= arr[i] <= 15`
-   It is guaranteed that the answer fits into a **32-bit** signed integer (i.e., it is less than 2^31).

### Recursive Approach

```Cpp

class Solution {
public:
    int recursion(int start, int end, map<pair<int, int>, int>& maxValue, vector<int>& arr) {
        // Base case: If the range is invalid or contains only one element, no cost is required
        if (start >= end)
            return 0;

        // Variable to store the minimum cost for this range
        int minCost = INT_MAX;

        // Iterate through all possible partitions of the range [start, end]
        for (int i = start; i < end; i++) {
            // Calculate the cost for the current partition:
            // 1. Cost of multiplying the maximum values in the left and right partitions
            // 2. Add the cost of recursively solving the left and right partitions
            minCost = min(minCost, 
                        (maxValue[{start, i}] * maxValue[{i + 1, end}]) + 
                        recursion(start, i, maxValue, arr) + 
                        recursion(i + 1, end, maxValue, arr));
        }

        // Return the minimum cost for this range
        return minCost;
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxValue;      // Map to store maximum values for all subarrays
        int start = 0;                          // Starting index of the range
        int end = arr.size() - 1;               // Ending index of the range

        // Precompute maximum values for all subarrays [i, j]
        for (int i = 0; i < arr.size(); i++) {
            // The max value for a single element subarray is the element itself
            maxValue[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++) {
                // Maximum value of subarray [i, j] is the maximum of the current element and the previous maximum
                maxValue[{i, j}] = max(arr[j], maxValue[{i, j - 1}]);
            }
        }

        return recursion(start, end, maxValue, arr);
    }
};

Time Complexity = O(2^N)
Space Complexity = O(N)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(int start, int end, map<pair<int, int>, int>& maxValue, vector<int>& arr, vector<vector<int>>& dp) {
        // Base case: If the range is invalid or contains only one element, no cost is required
        if (start >= end)
            return 0;

        // If the result for the range [start, end] is already computed, return it
        if (dp[start][end] != -1)
            return dp[start][end];

        // Variable to store the minimum cost for this range
        int minCost = INT_MAX;

        // Iterate through all possible partitions of the range [start, end]
        for (int i = start; i < end; i++) {
            // Calculate the cost for the current partition
            minCost = min(minCost, 
                        (maxValue[{start, i}] * maxValue[{i + 1, end}]) + 
                        memoization(start, i, maxValue, arr, dp) + 
                        memoization(i + 1, end, maxValue, arr, dp));
        }

        // Store the result in the DP array and return it
        return dp[start][end] = minCost;
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxValue;      // Map to store maximum values for all subarrays
        int start = 0;                          // Starting index of the range
        int end = arr.size() - 1;               // Ending index of the range

        // Precompute maximum values for all subarrays [i, j]
        for (int i = 0; i < arr.size(); i++) {
            // The max value for a single element subarray is the element itself
            maxValue[{i, i}] = arr[i]；
            for (int j = i + 1; j < arr.size(); j++) {
                // Maximum value of subarray [i, j] is the maximum of the current element and the previous maximum
                maxValue[{i, j}] = max(arr[j], maxValue[{i, j - 1}]);
            }
        }

        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return memoization(start, end, maxValue, arr, dp);
    }
};

Time Complexity = O(N^3)
Space Complexity = O(N^2)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& arr, map<pair<int, int>, int>& maxValue) {
        int n = arr.size();

        // Create a DP table to store the minimum cost for ranges [start, end]
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

        // Fill the DP table for all ranges from smaller lengths to larger lengths
        for (int start = n; start >= 0; start--) {
            for (int end = 0; end <= n - 1; end++) {
                // Skip invalid ranges
                if (start >= end)
                    continue;

                // Variable to store the minimum cost for this range
                int minCost = INT_MAX;

                // Explore all possible partitions of the range [start, end]
                for (int i = start; i < end; i++) {
                    // Calculate the cost for the current partition
                    minCost = min(minCost, 
                                (maxValue[{start, i}] * maxValue[{i + 1, end}]) + 
                                dp[start][i] + dp[i + 1][end]);
                }

                // Store the result in the DP table
                dp[start][end] = minCost;
            }
        }

        // Return the result for the entire array range [0, n-1]
        return dp[0][n - 1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxValue;      // Map to store maximum values for all subarrays
        int start = 0;                          // Starting index of the range
        int end = arr.size() - 1;               // Ending index of the range

        // Precompute maximum values for all subarrays [i, j]
        for (int i = 0; i < arr.size(); i++) {
            // The max value for a single element subarray is the element itself
            maxValue[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++) {
                // Maximum value of subarray [i, j] is the maximum of the current element and the previous maximum
                maxValue[{i, j}] = max(arr[j], maxValue[{i, j - 1}]);
            }
        }

        return tabulation(arr, maxValue);
    }
};

Time Complexity = O(N^3)
Space Complexity = O(N^2)
```