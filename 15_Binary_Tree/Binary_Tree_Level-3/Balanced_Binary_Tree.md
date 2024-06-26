# Question : [Balanced Binary Tree - (LeetCode : 110)](https://leetcode.com/problems/balanced-binary-tree/description/)

Given a binary tree, determine if it is **height-balanced**.

Height-balanced : A **_height-balanced_** binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

### Example 1

![](https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: true
```

### Example 2

![](https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg)

```
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
```

### Example 3

```
Input: root = []
Output: true
```

### Constraints

- The number of nodes in the tree is in the range `[0, 5000]`<br>
- `-10^4 <= Node.val <= 10^4`

## Solution 1

```Cpp
class Solution {
public:
    // Function to calculate the height of the tree and check balance.
    int height(TreeNode* root, bool& valid) {

        // Base case: if the root is null, height is 0.
        if (!root)
            return 0;

        // Recursively calculate heights of left and right subtrees.
        int leftSubtree = height(root->left, valid);
        int rightSubtree = height(root->right, valid);

        // Check if the absolute difference between heights of left and right subtrees
        // is greater than 1. If yes, mark the tree as unbalanced.
        if (abs(leftSubtree - rightSubtree) > 1)
            valid = false;      // Update valid to false if tree is unbalanced.

        // Return height of current subtree (1 + maximum of left and right subtree heights).
        return 1 + max(leftSubtree, rightSubtree);
    }

    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(TreeNode *root) {
        bool valid = true;      // Initially assume tree is balanced.
        height(root, valid);    // Call height function to calculate heights and check balance.
        return valid;           // Return the validity status of the tree (balanced or not).
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

## Solution 2

```Cpp
Optimize Solution :

class Solution {
public:
    // Function to calculate the height of the tree and check balance
    int height(Node* root, bool& valid) {

        // If the node is null, return height as 0
        if(!root)
            return 0;

        // Calculate height of left subtree recursively
        int leftSubtree = height(root->left, valid);

        // If the left subtree is balanced, proceed to check right subtree
        if(valid) {
            // Calculate height of right subtree recursively
            int rightSubtree = height(root->right, valid);

            // Check if the difference in height between left and right subtrees is greater than 1
            if(abs(leftSubtree - rightSubtree) > 1)
                valid = false;      // Tree is not balanced

            // Return height of the current subtree
            return 1 + max(leftSubtree, rightSubtree);
        }

        // If subtree is unbalanced, return -1 to propagate the unbalanced state
        return -1;
    }

    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root) {
        bool valid = true;      // Initialize validity flag
        height(root, valid);    // Call height function to check balance and update valid flag
        return valid;           // Return final validity of the tree
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
