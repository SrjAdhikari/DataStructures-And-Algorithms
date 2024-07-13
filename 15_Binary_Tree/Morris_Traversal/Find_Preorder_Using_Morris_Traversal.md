#  Question : Find Pre-order Using Morris Traversal

Given a Binary tree. Find the preorder traversal of the tree **without using recursion**.

### Example 1
```
Input:
           1
         /   \
        2     3
      /  \
     4    5
Output: 1 2 4 5 3
Explanation:
Preorder traversal (Root->Left->Right) of 
the tree is 1 2 4 5 3.
```

### Example 2
```
Input:
            8
          /   \
         1      5
          \    /  \
           7  10   6
            \  /
            10 6
Output: 8 1 7 10 5 10 6 6 
Explanation:
Preorder traversal (Root->Left->Right) 
of the tree is 8 1 7 10 5 10 6 6.
```

### Algorithm
```
1. Check, if left subtree of root node exist or not.
2. If left subtree does not exist :
    a. Print root node.
    b. Go to right subtree.

3. If left subtree exist :
    a. Check, if left subtree of root node traverse or not.
    b. If left subtree of root node not traverse :
        i. Print root node.
        ii. Create the link to the root node.
        iii. Go to left subtree.
    
    c. If left subtree of root node traverse :
        i. Remove the link.
        ii. Go to right subtree.
```

## Solution

```Cpp

class Solution {
public:
    // Function to perform an pre-order traversal of the binary tree
    vector<int> preOrder(Node* root) {

        vector<int> ans; // Initialize an empty vector to store the pre-order traversal results

        // Traverse the tree until the root becomes NULL (indicating no more nodes)
        while (root) {
            if (!root->left) {                  // If the current node has no left child:
                ans.push_back(root->data);      // Add the current node's data to the pre-order list
                root = root->right;             // Move to the right child for further traversal
            } 
            else {
                Node* current = root->left;         // Find the predecessor (pre-order predecessor) of the current node
                while (current->right && current->right != root) {
                    // Traverse down the right subtree of the left child until we reach:
                    // - A node with a NULL right child (predecessor)
                    // - The current node itself (avoiding infinite loops)
                    current = current->right;
                }

                // If the rightmost node's right child is NULL, establish a temporary link back to the current node.
                if (!current->right) {
                    ans.push_back(root->data);      // Pre-order processing: Add the current node's data to the pre-order list
                    current->right = root;          // Create a temporary link between the predecessor's right child and the current node
                    root = root->left;              // Move to the left child for further traversal
                } 
                else {
                    // If the rightmost node's right child points back to the current node,
                    // this means we have completed the traversal of the left subtree.
                    current->right = NULL;          // Remove the temporary link.
                    root = root->right;             // Move to the right child for further traversal
                }
            }
        }
        return ans;         // Return the vector containing the pre-order traversal results
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```