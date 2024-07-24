# Question : [Maximum Sum BST in Binary Tree - (LeetCode : 1373)](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/)

Given a **binary tree** `root`, return *the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST)*.

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.


### Example 1
![](https://assets.leetcode.com/uploads/2020/01/30/sample_1_1709.png)

```
Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
```

### Example 2
![](https://assets.leetcode.com/uploads/2020/01/30/sample_2_1709.png)

```
Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
```

### Example 3

```
Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
```

### Constraints

- The number of nodes in the tree is in the range `[1, 4 * 10^4]`.<br>
- `-4 * 10^4 <= Node.val <= 4 * 10^4`

## Solution

```Cpp
Using Morris Traversal :

class NodeInfo {
    public:
    bool isBST;             // Indicates whether the subtree is a BST
    int sum;                // Sum of all node values in the subtree
    int min;                // Minimum value in the subtree
    int max;                // Maximum value in the subtree
    
    NodeInfo() {            // Constructor to initialize NodeInfo for a non-existent node
        isBST = true;       // By default, an empty subtree is considered a BST
        sum = 0;            // Initialize sum to 0 for an empty tree
        min = INT_MAX;      // Minimum value for a non-existent subtree
        max = INT_MIN;      // Maximum value for a non-existent subtree
    }
};

class Solution {
public:
    
    // Helper function to find the maximum sum of BST subtree
    NodeInfo* findMaxSum(Node* root, int& sum) {
        // Base case: if the node is null, return an empty NodeInfo object with default values
        if(!root) {
            NodeInfo* node = new NodeInfo();
            return node;
        }
        
        // Recursively find the maximum sum in the left and right subtrees
        NodeInfo* leftSubtree = findMaxSum(root->left, sum);
        NodeInfo* rightSubtree = findMaxSum(root->right, sum);
        
        // Check if both subtrees are BSTs and their values are within valid range
        // for the current node to be the root of a BST
        if(leftSubtree->isBST && rightSubtree->isBST && leftSubtree->max < root->val && rightSubtree->min > root->val) {   // Current subtree is a BST
            NodeInfo* head = new NodeInfo();
            head->sum += leftSubtree->sum + rightSubtree->sum + root->val;      // Update sum of the current BST
            head->min = min(root->val, leftSubtree->min);                       // Update minimum value in the current BST
            head->max = max(root->val, rightSubtree->max);                      // Update maximum value in the current BST
            sum = max(sum, head->sum);                                          // Update maximum BST sum found so far
            return head;                                                        // Return the head for the current subtree
        } 
        // Current subtree is not a BST
        else {
            leftSubtree->isBST = false;     // Mark the subtree as not a BST
            return leftSubtree;             // Return the left subtree info (could also return rightSubtree)
        }
    }
    
    // Main function to return the maximum sum of all BST subtrees in the tree
    int maxSumBST(Node *root) {
        int sum = 0;
        findMaxSum(root, sum);      // Find the maximum sum BST subtree
        return totalSize;           // Return the maximum sum of BST subtrees
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```