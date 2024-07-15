# Question : [Validate Binary Search Tree - (LeetCode : 98)](https://leetcode.com/problems/validate-binary-search-tree/description/)

Given the `root` of a binary tree, *determine if it is a valid binary search tree (BST).*

A **valid BST** is defined as follows:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

### Example 1
![](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)

```
Input: root = [2,1,3]
Output: true
```

### Example 2
![](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)

```
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 
but its right child's value is 4.
```

### Constraints

- The number of nodes in the tree is in the range `[1, 10^4]`<br>
- `-2^31 <= Node.val <= 2^31 - 1`

## Solution 1

```Cpp
class Solution {
public:
    // Function to perform in-order traversal of a BST and store the values in a vector
    void inorderTraversal(TreeNode* root, vector<int>& ans) {
        // Base case: If the current node is NULL No processing needed for an empty subtree
        if (!root) {
            return;
        }

        inorderTraversal(root->left, ans);      // Recursive call: Traverse the left subtree in-order
        ans.push_back(root->val);               // Visit the current node: Add its value to the result vector
        inorderTraversal(root->right, ans);     // Recursive call: Traverse the right subtree in-order
    }

    // Function to check if a binary tree is a valid BST
    bool isValidBST(TreeNode* root) {

        vector<int> inorderValues;                  // Create an empty vector to store the in-order traversal results
        inorderTraversal(root, inorderValues);      // Perform in-order traversal and store values in the vector

        // Check if the in-order traversal results are strictly increasing
        for (int i = 1; i < inorderValues.size(); i++) {
            // If the current value is not strictly greater than the previous value, the tree is not a valid BST
            if (inorderValues[i] <= inorderValues[i - 1]) {
                return false;
            }
        }

        // If all values in the in-order traversal are strictly increasing, the tree is a valid BST
        return true;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```

## Solution 2

```Cpp
class Solution {
public:
    // Function to check if a node's value satisfies the BST property within given bounds
    bool isBST(TreeNode* root, long long int lowerBound, long long int upperBound) {
        // Base case: If the node is NULL, return true
        if (!root) {
            return true;        // Empty subtree is considered valid BST (base case)
        }

        // Check if the current node's value falls within the allowed range for its position in the BST
        bool condition1 = root->val > lowerBound;   // Value must be greater than the lower bound
        bool condition2 = root->val < upperBound;   // Value must be less than the upper bound

        // Recursively check the left subtree using the current node's value as the new upper bound
        bool left = isBST(root->left, lowerBound, root->val);

        // Recursively check the right subtree using the current node's value as the new lower bound
        bool right = isBST(root->right, root->val, upperBound);

        // Return true only if all conditions are met:
        // - Current node's value is within bounds
        // - Left and right subtrees are also valid BSTs
        return condition1 && condition2 && left && right;
    }

    // Function to check if a binary tree is a valid BST
    bool isValidBST(TreeNode* root) {
        // Set the initial lower and upper bounds for the entire tree (considering integer limits)
        long long int lowerBound = LLONG_MIN;     // Minimum possible value for a long long int
        long long int upperBound = LLONG_MAX;     // Maximum possible value for a long long int

        // Call the helper function to start the BST validation process from the root
        return isBST(root, lowerBound, upperBound);
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```
