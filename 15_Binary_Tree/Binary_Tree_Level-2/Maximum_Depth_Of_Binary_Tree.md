# Question : [Maximum Depth of Binary Tree - (LeetCode : 104)](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/)

Given the `root` of a binary tree, return _its maximum depth._

A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.

### Example 1

![](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: 3
```

### Example 2

```
Input: root = [1,null,2]
Output: 2
```

### Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`<br>
- `-100 <= Node.val <= 100`

## Solution 1

```Cpp
Using Recursion (Pre-Order Traversal) :

class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Base case: If the tree is empty (root is NULL), return 0 as the maximum depth.
        if (root == NULL)
            return 0;

        // Recursively calculate the depth of the left subtree.
        int leftDepth = maxDepth(root->left);

        // Recursively calculate the depth of the right subtree.
        int rightDepth = maxDepth(root->right);

        // The maximum depth of the current tree is 1 (for the root node) plus
        // the greater of the maximum depths of the left and right subtrees.
        return 1 + max(leftDepth, rightDepth);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

## Solution 2

```Cpp
Using Level-Order Traversal :

class Solution {
public:
    int maxDepth(TreeNode* root) {

        // If the tree is empty, return 0 as the maximum depth.
        if (root == NULL) {
            return 0;
        }

        // Initialize a queue to help with level order traversal.
        queue<TreeNode*> q;

        // Push the root node into the queue to start the traversal.
        q.push(root);

        // Initialize depth to keep track of the number of levels.
        int depth = 0;

        // Continue the traversal until the queue is empty.
        while (!q.empty()) {

            // Get the number of nodes at the current level.
            int levelSize = q.size();

            // Process each node at the current level.
            for (int i = 0; i < levelSize; ++i) {
                // Get the front node from the queue.
                TreeNode* node = q.front();
                // Remove the front node from the queue.
                q.pop();

                // If the node has a left child, push it into the queue for the next level.
                if (node->left != NULL) {
                    q.push(node->left);
                }
                // If the node has a right child, push it into the queue for the next level.
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            // Increment the depth after processing all nodes at the current level.
            depth++;
        }

        // Return the maximum depth of the binary tree.
        return depth;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
