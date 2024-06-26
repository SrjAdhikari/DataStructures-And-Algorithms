# Question : [Symmetric Tree - (LeetCode : 101)](https://leetcode.com/problems/symmetric-tree/description/)

Given the `root` of a binary tree, _check whether it is a mirror of itself_ (i.e., symmetric around its center).

### Example 1

![](https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg)

```
Input: root = [1,2,2,3,4,4,3]
Output: true
```

### Example 2

![](https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg)

```
Input: root = [1,2,2,null,3,null,3]
Output: false
```

### Constraints

- The number of nodes in the tree is in the range `[1, 1000]`<br>
- `-100 <= Node.val <= 100`

## Solution 1

```Cpp
class Solution {
public:
    // Helper function to check if two subtrees are symmetric
    bool isSymetricTree(TreeNode* p, TreeNode* q) {

        // If both nodes are null, the subtrees are symmetric
        if (!p && !q)
            return true;

        // If one node is null and the other is not, the subtrees are not symmetric
        if (!p || !q)
            return false;

        // If the values of the nodes are not equal, the subtrees are not symmetric
        if (p->val != q->val)
            return false;

        // Recursively check if the left subtree of p is symmetric with the right subtree of q
        // and if the right subtree of p is symmetric with the left subtree of q
        return isSymetricTree(p->left, q->right) && isSymetricTree(p->right, q->left);
    }

    // Function to check if a binary tree is symmetric
    bool isSymmetric(TreeNode* root) {

        // If the root is null, the tree is symmetric
        if (!root)
            return true;

        // Check if the left and right subtrees of the root are symmetric
        return isSymetricTree(root->left, root->right);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

## Solution 2

```Cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        // If the tree is empty, it is symmetric
        if (!root)
            return true;

        // Initialize a queue to hold pairs of nodes
        queue<TreeNode*> q;

        // Push the left and right children of the root in Queue
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {

            // Pop two nodes to compare
            TreeNode* leftNode = q.front(); q.pop();
            TreeNode* rightNode = q.front(); q.pop();

            // If both nodes are null, continue to the next pair
            if (!leftNode && !rightNode)
                continue;

            // If one node is null and the other is not, the tree is not symmetric
            if (!leftNode || !rightNode)
                return false;

            // If the values of the nodes do not match, the tree is not symmetric
            if (leftNode->val != rightNode->val)
                return false;

            // Push the children of the nodes in the correct order for comparison
            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
        }

        // If all pairs of nodes matched, the tree is symmetric
        return true;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
