# Question : [Binary Tree Inorder Traversal - (LeetCode : 94)](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)

Given the `root` of a binary tree, return _the inorder traversal of its nodes' values._

### Example 1

![](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```
Input: root = [1,null,2,3]
Output: [1,3,2]
```

### Example 2

```
Input: root = []
Output: []
```

### Example 3

```
Input: root = [1]
Output: [1]
```

### Constraints

- The number of nodes in the tree is in the range `[0, 100]`<br>
- `-100 <= Node.val <= 100`

## Solution

```Cpp
class Solution {
public:
    // Helper function to perform in-order traversal recursively
    void inOrder(TreeNode* root, vector<int>& ans) {

        // Base case: if root is NULL, return to previous call
        if(root == NULL)
            return;

        // Traverse left subtree recursively
        inOrder(root->left, ans);

        // Push current node's value into the vector
        ans.push_back(root->val);

        // Traverse right subtree recursively
        inOrder(root->right, ans);
    }

    // Main function to initiate in-order traversal and return result
    vector<int> inorderTraversal(TreeNode* root) {

        // Initialize an empty vector to store traversal result
        vector<int> ans;

        // Call helper function to perform in-order traversal
        inOrder(root, ans);

        // Return the traversal result
        return ans;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
