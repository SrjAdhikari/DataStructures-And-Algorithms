# Question : [Minimum Depth of Binary Tree - (LeetCode : 111)](https://leetcode.com/problems/minimum-depth-of-binary-tree/description/)

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

**Note :** A leaf is a node with no children.

### Example 1

![](https://assets.leetcode.com/uploads/2020/10/12/ex_depth.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: 2
```

### Example 2

```
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
```

### Constraints

- The number of nodes in the tree is in the range `[0, 10^5]`<br>
- `-1000 <= Node.val <= 1000`

## Solution

```Cpp
Using Recursion (Pre-Order Traversal) :

class Solution {
public:
    int minDepth(TreeNode* root) {

        if (root == NULL) return 0;         // Base case: if the tree is empty, return 0

        // Recursively find the minimum depth of the left and right subtrees
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        if (leftDepth == 0) return 1 + rightDepth;      // If left subtree is empty, return depth of right subtree + 1
        if (rightDepth == 0) return 1 + leftDepth;      // If right subtree is empty, return depth of left subtree + 1

        // If both subtrees are non-empty, return the minimum depth of the two subtrees + 1
        return 1 + min(leftDepth, rightDepth);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
