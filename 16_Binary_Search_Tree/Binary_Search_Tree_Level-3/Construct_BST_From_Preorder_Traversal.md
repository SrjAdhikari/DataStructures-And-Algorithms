# Question : [Construct Binary Search Tree from Preorder Traversal - (LeetCode : 1008)](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/)

Given an array of integers preorder, which represents the **preorder traversal** of a BST (i.e., **binary search tree**), construct the tree and return *its root*.

It is **guaranteed** that there is always possible to find a binary search tree with the given requirements for the given test cases.

A **binary search tree** is a binary tree where for every node, any descendant of `Node.left` has a value **s`trictly less than** `Node.val`, and any descendant of `Node.right` has a value **strictly greater than** `Node.val`.

A **preorder traversal** of a binary tree displays the value of the node first, then traverses `Node.left`, then traverses `Node.right`.

### Example 1
![](https://assets.leetcode.com/uploads/2019/03/06/1266.png)

```
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
```

### Example 2

```
Input: preorder = [1,3]
Output: [1,null,3]
```

### Constraints
- ` <= preorder.length <= 100`
- ` <= preorder[i] <= 1000`
- All the values of `preorder` are **unique**.

## Solution

```Cpp
class Solution {
public:
    // Function to construct a Binary Search Tree (BST) from a preorder traversal vector
    TreeNode* binarySearchTree(vector<int>& preorder, int &index, int lower, int upper) {

        // Base case: If the index is out of bounds of the preorder vector
        // or the current element is not within the valid range [lower, upper], return NULL
        if (index == preorder.size() || preorder[index] < lower || preorder[index] > upper) {
            return NULL;
        }

        // Extract the current element from the preorder array to create the root node
        int element = preorder[index];

        // Create a new TreeNode with the extracted element
        TreeNode* root = new TreeNode(element);

        // Move to the next element in the preorder vector for the upcoming recursive calls
        index++;

        // Recursively construct the left subtree with updated upper bound
        // The left subtree must have values less than the current root value
        root->left = binarySearchTree(preorder, index, lower, root->val);

        // Recursively construct the right subtree with updated lower bound
        // The right subtree must have values greater than the current root value
        root->right = binarySearchTree(preorder, index, root->val, upper);

        // Return the constructed subtree rooted at the current node
        return root;
    }

    // Function to initiate the construction of a BST from a preorder traversal vector
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;  // Initialize the index to track the current position in the preorder vector
        
        // Call the recursive function with initial bounds for the entire range of valid values
        return binarySearchTree(preorder, index, INT_MIN, INT_MAX);
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```