# Question : [Count Non-Leaf Nodes in Tree - GFG](https://www.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/1)

Given a Binary Tree of size **N**, your task is to complete the function **ountNonLeafNodes()**, that should return the count of all the non-leaf nodes of the given binary tree.\*\*

### Example

**Input :**

![](https://contribute.geeksforgeeks.org/wp-content/uploads/tree121.gif)

```
Output:
2
Explanation:
Nodes 1 and 2 are the only non leaf nodes.
```

### Your task

You don't need to take input or print anything. Your task is to **complete** the function **countNonLeafNodes()** that takes **oot** as input and returns the number of non leaf nodes in the tree.

```
Expected Time Complexity : O(N).
Expected Auxiliary Space : O(Height of the Tree).
```

### Constraints

`1 ≤ Number of nodes ≤ 10^5`

## Solution 1

```Cpp

class Solution {
public:
    // Function to count the number of non-leaf nodes in a binary tree
    int countNonLeafNodes(Node* root) {

        if (root == NULL)                                   // Base case: if the current node is NULL, return 0 (no nodes to count)
            return 0;

        if (root->left == NULL && root->right == NULL)      // Base case: if the current node is a leaf node (no children), return 0
            return 0;

        int left = countNonLeafNodes(root->left);           // Recursively count non-leaf nodes in the left subtree
        int right = countNonLeafNodes(root->right);         // Recursively count non-leaf nodes in the right subtree

        // Return the sum of non-leaf nodes in the left and right subtrees plus one for the current non-leaf node
        return left + right + 1;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

## Solution 2

```Cpp

class Solution {
public:
    // Helper function to count the number of non-leaf nodes in a binary tree
    // This function uses a reference to an integer count to keep track of the number of non-leaf nodes
    void countNonLeaf(Node* root, int& count) {

        if (root == NULL)                                   // Base case: if the current node is NULL, return (do nothing)
            return;

        if (root->left == NULL && root->right == NULL)      // Base case: if the current node is a leaf node (no children), return (do nothing)
            return;

        count++;                                // Increment the count as the current node is a non-leaf node
        countNonLeaf(root->left, count);        // Recursively count non-leaf nodes in the left subtree
        countNonLeaf(root->right, count);       // Recursively count non-leaf nodes in the right subtree
    }

    // Main function to count the number of non-leaf nodes in a binary tree
    int countNonLeafNodes(Node* root) {

        int count = 0;                      // Initialize the count to 0
        countNonLeaf(root, count);          // Call the helper function to count non-leaf nodes starting from the root
        return count;                       // Return the final count of non-leaf nodes
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
