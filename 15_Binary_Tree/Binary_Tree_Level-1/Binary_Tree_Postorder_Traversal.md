# Question : [Binary Tree Postorder Traversal - (LeetCode : 145)](https://leetcode.com/problems/binary-tree-postorder-traversal/description/)

Given the `root` of a binary tree, return _the postorder traversal of its nodes' values._

### Example 1

![](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```
Input: root = [1,null,2,3]
Output: [3,2,1]
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

    // Helper function to perform postorder traversal recursively
    void postOrder(TreeNode* root, vector<int>& ans) {

        if(root == NULL)
            return;

        // Traverse left subtree
        postOrder(root->left, ans);

        // Traverse right subtree
        postOrder(root->right, ans);

        // Visit the root node (postorder visit)
        ans.push_back(root->val);
    }

    // Main function to initiate postorder traversal
    vector<int> postorderTraversal(TreeNode* root) {

        // Initialize an empty vector to store traversal result
        vector<int> ans;

        // Call helper function to perform post-order traversal
        postOrder(root, ans);

        // Return the traversal result
        return ans;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
