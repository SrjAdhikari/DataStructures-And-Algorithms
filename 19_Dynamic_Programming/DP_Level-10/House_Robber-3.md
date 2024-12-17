# Question : [House Robber III - (LeetCode : 337)](https://leetcode.com/problems/house-robber-iii/description/)

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called `root`.

Besides the `root`, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if **two directly-linked houses were broken into on the same night**.

Given the `root` of the binary tree, return _the maximum amount of money the thief can rob_ **_without alerting the police_**.

### Example 1

![](https://assets.leetcode.com/uploads/2021/03/10/rob1-tree.jpg)

```
Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
```

### Example 2

![](https://assets.leetcode.com/uploads/2021/03/10/rob2-tree.jpg)

```
Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
```

### Constraints

-   The number of nodes in the tree is in the range `[1, 10^4]`
-   `0 <= Node.val <= 10^4`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(TreeNode* root) {
        // Base case: If the current node is NULL, return 0 as no money can be robbed from it.
        if (!root)
            return 0;

        // Option 1: Rob the current house (root), then recursively rob the houses two levels down (skip immediate children).
        int robHouse = root->val;

        // If the left child exists, rob the grand-children (left's left and right).
        if (root->left)
            // Rob the grandchildren of left child
            robHouse += recursion(root->left->left) + recursion(root->left->right);

        // If the right child exists, rob the grand-children (right's left and right).
        if (root->right)
            // Rob the grandchildren of right child
            robHouse += recursion(root->right->left) + recursion(root->right->right);

        // Option 2: Skip the current house, and recursively rob the left and right subtrees.
        int skipHouse = 0 + recursion(root->left) + recursion(root->right);

        // Return the maximum of robbing or skipping the current house.
        return max(robHouse, skipHouse);
    }

    int rob(TreeNode* root) {
        return recursion(root);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        // Base case: If the current node is NULL, return 0 as no money can be robbed from it.
        if (!root)
            return 0;

        // If the result for this root has already been computed, return it.
        if (dp.count(root))
            return dp[root];

        // Option 1: Rob the current house (root), then recursively rob the houses two levels down (skip immediate children).
        int robHouse = root->val;

        // If the left child exists, rob the grand-children (left's left and right).
        if (root->left)
            // Rob the grandchildren of left child
            robHouse += memoization(root->left->left, dp) + memoization(root->left->right, dp);

        // If the right child exists, rob the grand-children (right's left and right).
        if (root->right)
            // Rob the grandchildren of right child
            robHouse += memoization(root->right->left, dp) + memoization(root->right->right, dp);

        // Option 2: Skip the current house, and recursively rob the left and right subtrees.
        int skipHouse = 0 + memoization(root->left, dp) + memoization(root->right, dp);

        // Store and return the maximum of robbing or skipping the current house.
        return dp[root] = max(robHouse, skipHouse);
    }

    int rob(TreeNode* root) {
        // Memoization approach with a DP map to store results for each node.
        unordered_map<TreeNode*, int> dp;
        return memoization(root, dp);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
