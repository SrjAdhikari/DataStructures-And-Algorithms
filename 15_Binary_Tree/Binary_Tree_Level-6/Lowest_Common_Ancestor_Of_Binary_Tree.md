# Question : [Lowest Common Ancestor of a Binary Tree - (LeetCode : 236)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/)

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the *definition of LCA on Wikipedia*: “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”


### Example 1

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
```

### Example 2

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
```

### Example 3

```
Input: root = [1,2], p = 1, q = 2
Output: 1
```

### Constraints

- The number of nodes in the tree is in the range `[2, 10^5]`
- `-109 <= Node.val <= 109`
- All `Node.val` are unique.
- `p != q`
- `p` and `q` will exist in the tree.

## Solution

```Cpp

class Solution {
public:
    // Function to find the lowest common ancestor (LCA) of two nodes (p and q) in a binary tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root)                  // Base case: if the current node is NULL, return NULL (no ancestor found in this path)
            return NULL;

        if (root->val == p->val)    // If the current node is equal to node p, return the current node
            return p;

        if (root->val == q->val)    // If the current node is equal to node q, return the current node
            return q;

        // Recursively search for the LCA in the left subtree
        TreeNode* leftSubtree = lowestCommonAncestor(root->left, p, q);

        // Recursively search for the LCA in the right subtree
        TreeNode* rightSubtree = lowestCommonAncestor(root->right, p, q);

        // After recursion, we have the results from the left and right subtrees:
        // leftSubtree: the result of the LCA search in the left subtree
        // rightSubtree: the result of the LCA search in the right subtree

        // If neither the left subtree nor the right subtree contains p or q, return NULL
        if (!leftSubtree && !rightSubtree)
            return NULL;

        // If the left subtree contains p or q and the right subtree does not, return the result from the left subtree
        else if (leftSubtree && !rightSubtree)
            return leftSubtree;

        // If the right subtree contains p or q and the left subtree does not, return the result from the right subtree
        else if (!leftSubtree && rightSubtree)
            return rightSubtree;

        // If both the left and right subtrees contain p or q, the current node is the LCA
        else
            return root;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
