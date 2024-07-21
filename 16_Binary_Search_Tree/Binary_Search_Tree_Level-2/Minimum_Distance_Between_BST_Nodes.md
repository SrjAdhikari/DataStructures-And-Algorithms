# Question : [Minimum Distance Between BST Nodes - (LeetCode : 783)](https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/)

Given the `root` of a Binary Search Tree (BST), return *the minimum difference between the values of any two different nodes in the tree.*

### Example 1
![](https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg)

```
Input: root = [4,2,6,1,3]
Output: 1
```

### Example 2
![](https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg)

```
Input: root = [1,0,48,null,null,12,49]
Output: 1
```

### Constraints

- The number of nodes in the tree is in the range `[2, 100]`
- `0 <= Node.val <= 10^5`

## Solution

```Cpp
class Solution {
public:
    // Function to find the minimum distance between two nodes in a Binary Search Tree (BST)
    void minDistance(TreeNode* root, int &prev, int &ans) {

    // Base case: If the current node is null, return
    if (!root) {
        return;
    }

    // Recursively find the minimum distance in the left subtree
    minDistance(root->left, prev, ans);

    // If a previous node has already been visited (not INT_MIN), update the minimum difference -> Handle edge case for Integer Overflow
    // if the current node's value minus the previous node's value is smaller than the current minimum
    if (prev != INT_MIN) {
        ans = min(ans, root->val - prev);
    }

    // Update the previous node's value with the current node's value for future comparisons
    prev = root->val;

    // Recursively find the minimum distance in the right subtree
    minDistance(root->right, prev, ans);
    }

    // Function to find the minimum difference between any two nodes in a BST
    int minDiffInBST(TreeNode* root) {
    int prev = INT_MIN; // Initialize previous node value to negative infinity
    int ans = INT_MAX;  // Initialize minimum difference to positive infinity

    // Call the helper function to find the minimum distance
    minDistance(root, prev, ans);

    // Return the minimum difference found
    return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```
