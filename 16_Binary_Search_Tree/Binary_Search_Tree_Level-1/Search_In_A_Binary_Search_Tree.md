# Question : [Search in a Binary Search Tree - (LeetCode : 700)](https://leetcode.com/problems/search-in-a-binary-search-tree/description/)

You are given the `root` of a binary search tree (BST) and an integer `val`.

Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.

### Example 1
![](https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg)

```
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
```

### Example 2
![](https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg)

```
Input: root = [4,2,7,1,3], val = 5
Output: []
```

### Example 3

```
Input: root = [1]
Output: [1]
```

### Constraints

- The number of nodes in the tree is in the range `[1, 5000]`<br>
- `1 <= Node.val <= 10^7`
- `root` is a binary search tree.
- `1 <= val <= 10^7`

## Solution

```Cpp
class Solution {
public:
    // Function to search for a node with a given value in the BST
    TreeNode* searchBST(TreeNode* root, int val) {
        
        // If the tree is empty or the node is not found, return NULL
        if (!root) {
            return NULL;
        }
        
        // If the target value (val) is equal to the current node's value, return the current node
        if (root->val == val) {
            return root;
        }
        // If the value to be searched is smaller than the current node's value, search in the left subtree
        else if (val < root->val) {
            return searchBST(root->left, val);
        }
        // If the value to be searched is greater than the current node's value, search in the right subtree
        else {
            return searchBST(root->right, val);
        }
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```
