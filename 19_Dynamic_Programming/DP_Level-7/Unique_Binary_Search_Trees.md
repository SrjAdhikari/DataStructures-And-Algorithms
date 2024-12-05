# Question : [Unique Binary Search Trees - (LeetCode : 96)](https://leetcode.com/problems/unique-binary-search-trees/description/)

Given an integer `n`, return _the number of structurally unique **BST**'s (binary search trees) which has exactly `n` nodes of unique values from `1` to `n`_.

### Example 1

![](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

```
Input: n = 3
Output: 5
```

### Example 2

```
Input: n = 1
Output: 1
```

### Constraints

-   `1 <= n <= 19`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(int n) {
        // Base case: if there are 0 or 1 nodes, there's only 1 BST possible
        if (n <= 1)
            return 1;

        int uniqueBST = 0;

        // Loop through each number as a potential root node
        for (int i = 1; i <= n; i++) {
            // Calculate the number of unique BSTs formed by left and right subtrees
            // Left subtree has (i-1) nodes, right subtree has (n-i) nodes
            uniqueBST += recursion(i - 1) * recursion(n - i);
        }

        // Return total count of unique BSTs for `n`
        return uniqueBST;
    }

    int numTrees(int n) {
        return recursion(n);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(int n, vector<int>& dp) {
        // Base case: if there are 0 or 1 nodes, there's only 1 BST possible
        if (n <= 1)
            return 1;

        // If the result for 'n' is already computed, return it
        if (dp[n] != -1)
            return dp[n];

        int uniqueBST = 0;

        // Loop through each number as a potential root node
        for (int i = 1; i <= n; i++) {
            // Calculate the number of unique BSTs formed by left and right subtrees
            // Left subtree has (i-1) nodes, right subtree has (n-i) nodes
            uniqueBST += memoization(i - 1, dp) * memoization(n - i, dp);
        }

        // Store the computed result in dp array and return it
        return dp[n] = uniqueBST;
    }

    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return memoization(n, dp);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(int n) {
        // DP array to store the count of unique BSTs
        vector<int> dp(n + 1, 0);

        // Base cases: 1 unique BST for 0 or 1 nodes
        dp[0] = dp[1] = 1;

        // Loop over each number of nodes from 2 to n
        for (int node = 2; node <= n; node++) {
            int uniqueBST = 0;

            // For each potential root node, calculate left and right subtree combinations
            for (int i = 1; i <= node; i++) {
                uniqueBST += dp[i - 1] * dp[node - i];
            }

            // Store the result for 'node' in dp array
            dp[node] = uniqueBST;
        }

        // Return the number of unique BSTs for 'n' nodes
        return dp[n];
    }

    int numTrees(int n) {
        return tabulation(n);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(int n) {
        // Base case: If there are 0 nodes, there's only 1 BST
        if (n == 0) return 1;

        long long int uniqueBST = 1;

        // Use the Catalan number formula to compute the result
        for (int i = 1; i <= n; i++) {
            // Catalan formula: Cn = Cn-1 * (2 * (2n - 1)) / (n + 1)
            uniqueBST = uniqueBST * (2 * (2 * i - 1)) / (i + 1);
        }

        // Return the result for `n`
        return uniqueBST;
    }

    int numTrees(int n) {
        return spaceOptimization(n);
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
