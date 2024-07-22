# Question : [Lowest Common Ancestor of a Binary Search Tree - (LeetCode : 235)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

### Example 1
![](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
```

### Example 2
![](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, 
since a node can be a descendant of itself according to the LCA definition.
```

### Example 3

```
Input: root = [2,1], p = 2, q = 1
Output: 2
```

### Constraints

- The number of nodes in the tree is in the range `[2, 10^5]`<br>
- `-109 <= Node.val <= 109`
- All `Node.val` are **unique**.
- `p != q`
- `p` and `q` will exist in the BST.

## Solution

```Cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If the root is NULL, there's no common ancestor, so return NULL.
        if (!root) {
            return NULL;
        }

        // Utilize the property of BST:
        // - If both p->val and q->val are less than root->val, then the LCA must be
        //   in the left subtree because all elements in the left subtree are smaller
        //   than the root. Recursively search the left subtree.
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // - If both p->val and q->val are greater than root->val, then the LCA must be
        //   in the right subtree because all elements in the right subtree are larger
        //   than the root. Recursively search the right subtree.
        else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // - Otherwise, the current root is the LCA because it's the first node
        //   whose value is between p->val and q->val. Return the root.
        else {
            return root;
        }
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```