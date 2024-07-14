# Question : [Delete a node from BST - GFG](https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/1)

Given a Binary Search Tree and a node value x. Delete the node with the given value x from the BST. If no node with value x exists, then do not make any change. Return the root of the BST after deleting the node with value x. Do not make any update if there's no node with value x present in the BST.
**Note**: The generated output will be the inorder traversal of the modified tree.

### Example 1
```
Input:
      2
    /   \
   1     3
x = 12
Output: 1 2 3
Explanation: In the given input there is no node with value 12 , so the tree will remain same.
```

### Example 2
```
Input:
            1
             \
              2
                \
                 8 
               /    \
              5      11
            /  \    /  \
           4    7  9   12
x = 9
Output: 1 2 4 5 7 8 11 12
Explanation: In the given input tree after deleting 9 will be
             1
              \
               2
                 \
                  8
                 /  \
                5    11
               /  \   \
              4    7   12 
```

```
Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).
```

### Constraints
`1 <= n <= 10^5`

## Solution

```Cpp
class Solution {
public:
    // Function to find the maximum value node in a subtree
    Node* findMax(Node* root) {
        // Traverse the right subtree as long as there's a right child
        while (root && root->right) {
            root = root->right;  // Move to the right child
        }
        return root;    // Return the rightmost (maximum value) node.
    }

    // Function to delete a node with a given value (X) from a BST
    Node* deleteNode(Node* root, int X) {
        // Base case: If the tree is empty, return NULL.
        if (!root) {
            return NULL;
        }

        // If the target node is found
        if (root->data == X) {
            // Handle cases for deleting the node:

            // Case 1: The node is a leaf (has no children).
            if ((!root->left) && (!root->right)) {
                delete root;    // Deallocate memory for the node -> Delete the node.
                return NULL;    // Return NULL to update the parent pointer
            }
            // Case 2: The node has only a right child.
            else if ((!root->left) && root->right) {
                Node* temp = root->right;   // Store the right child.
                delete root;                // Deallocate memory for the node -> Delete the current node.
                return temp;                // Return the right child to update the parent pointer
            }
            // Case 3: The node has only a left child.
            else if (root->left && (!root->right)) {
                Node* temp = root->left;    // Store the left child.
                delete root;                // Deallocate memory for the node -> Delete the current node.
                return temp;                // Return the right child to update the parent pointer.
            } 
            // Case 4: The node has two children.
            else {
                Node* max = findMax(root->left);                    // Find the maximum value node in the left subtree.
                root->data = max->data;                             // Replace the current node's data with the maximum value from the left subtree.
                root->left = deleteNode(root->left, max->data);     // Delete the maximum value node from the left subtree.
                return root;                                        // Return the updated root.
            }
        }
        // If the target value is smaller, search in the left subtree.
        else if (X < root->data) {
            root->left = deleteNode(root->left, X);
        }
        // If the target value is larger, search in the right subtree.
        else {
            root->right = deleteNode(root->right, X);
        }

        // Return the root node (important for BST structure)
        return root;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```