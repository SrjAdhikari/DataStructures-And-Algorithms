# Question : [Same Tree - (LeetCode : 100)](https://leetcode.com/problems/same-tree/description/)

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

### Example 1

![](https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg)

```
Input: p = [1,2,3], q = [1,2,3]
Output: true
```

### Example 2

![](https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg)

```
Input: p = [1,2], q = [1,null,2]
Output: false
```

### Example 3

![](https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg)

```
Input: p = [1,2,1], q = [1,1,2]
Output: false
```

### Constraints

- The number of nodes in the tree is in the range `[0, 100]`<br>
- `-10^4 <= Node.val <= 10^4`

## Solution

```Cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // If both nodes are null, the trees are the same (empty trees).
        if(!p && !q)
            return true;

        // If one of the nodes is null and the other is not, the trees are different.
        if((!p && q) || (!q && p))
            return false;

        // If the values of the current nodes are different, the trees are different.
        if(p->val != q->val)
            return false;

        // Recursively check if the left subtrees and right subtrees are the same.
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
