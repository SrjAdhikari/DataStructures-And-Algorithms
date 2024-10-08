# Question : [Is Binary Tree Heap - GFG](https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1)

Given a binary tree. The task is to check whether the given tree follows the **max heap** property or not.
**Note**: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

### Example 1

```
Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.
```

### Example 2

```
Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0
```

### Your Task
You don't need to read input or print anything. Your task is to complete the function `isHeap()` which takes the root of Binary Tree as parameter returns `True` if the given binary tree is a `heap` else returns `False`.

```
Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
```

### Constraints

- `1 ≤ Number of nodes ≤ 100`
- `1 ≤ Data of a node ≤ 1000`

## Solution

```Cpp
class Solution {
public:
    // Function to count the total number of nodes in a binary tree
    int countNode(Node* root) {
        // If the current node is null, return 0 (base case)
        if (!root)
            return 0;

        // Recursively count nodes in the left subtree
        int left = countNode(root->left);

        // Recursively count nodes in the right subtree
        int right = countNode(root->right);

        // Total number of nodes is 1 (for the current node) + nodes in the left subtree + nodes in the right subtree
        return 1 + left + right;
    }

    // Function to check if the binary tree is a Complete Binary Tree (CBT)
    bool isCBT(Node* root, int index, int totalNode) {
        // If the current node is null, return true (base case for CBT)
        if (!root)
            return true;

        // If the index of the current node is greater than or equal to the total number of nodes, it's not a CBT
        if (index >= totalNode)
            return false;

        // Recursively check if the left subtree is a CBT
        bool left = isCBT(root->left, 2 * index + 1, totalNode);

        // Recursively check if the right subtree is a CBT
        bool right = isCBT(root->right, 2 * index + 2, totalNode);

        // Return true if both left and right subtrees are CBT
        return left && right;
    }

    // Function to check if the binary tree follows the Max-Heap property
    bool isMaxHeap(Node* root) {
        // If the current node is null, return true (base case for max-heap)
        if (!root)
            return true;

        // Check the left child if it exists
        if (root->left) {
            // If the current node's value is less than the left child's value, it's not a max-heap
            if (root->data < root->left->data)
                return false;

            // Recursively check the left subtree for the max-heap property
            if (!isMaxHeap(root->left))
                return false;
        }

        // Check the right child if it exists
        if (root->right) {
            // If the current node's value is less than the right child's value, it's not a max-heap
            if (root->data < root->right->data)
                return false;

            // Recursively check the right subtree for the max-heap property
            return isMaxHeap(root->right);
        }

        // If both left and right children (if they exist) satisfy the max-heap property, return true
        return true;
    }

    // Function to check if a binary tree is a heap (both CBT and Max-Heap)
    bool isHeap(struct Node* tree) {
        // Step 1: Count the total number of nodes in the tree
        int nodeCount = countNode(tree);

        // Step 2: Check if the tree is a Complete Binary Tree (CBT)
        bool ans = isCBT(tree, 0, nodeCount);
        
        // If the tree is not a CBT, return false
        if (!ans)
            return false;

        // Step 3: Check if the tree satisfies the Max-Heap property
        return isMaxHeap(tree);
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```