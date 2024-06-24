# Question : [Binary Tree Preorder Traversal - (LeetCode : 144)](https://leetcode.com/problems/binary-tree-preorder-traversal/description/)

Given the `root` of a binary tree, return _return the preorder traversal of its nodes' values._

### Example 1

![](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```
Input: root = [1,null,2,3]
Output: [1,2,3]
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
    // Helper function to perform pre-order traversal recursively
    void preOrder(TreeNode* root, vector<int>& ans) {

        // Base case: if root is NULL, return to previous call
        if(root == NULL)
            return;

        // Push current node's value into the vector
        ans.push_back(root->val);

        // Traverse left subtree recursively
        preOrder(root->left, ans);

        // Traverse right subtree recursively
        preOrder(root->right, ans);
    }

    // Main function to initiate pre-order traversal and return result
    vector<int> preorderTraversal(TreeNode* root) {

        // Initialize an empty vector to store traversal result
        vector<int> ans;

        // Call helper function to perform pre-order traversal
        preOrder(root, ans);

        // Return the traversal result
        return ans;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
