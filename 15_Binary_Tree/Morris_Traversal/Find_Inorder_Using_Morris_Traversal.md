# Question : Find In-order Using Morris Traversal

Given a Binary tree. Find the in-order traversal of the tree **without using recursion**.

### Example 1
```
Input:
           1
         /   \
        2     3
      /  \
     4    5
Output: 4 2 5 1 3
Explanation:
In-order traversal (Left->Root->Right) of 
the tree is 4 2 5 1 3.
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
Output: 1 7 10 8 6 10 5 6
Explanation:
In-order traversal (Left->Root->Right) 
of the tree is 1 7 10 8 6 10 5 6.
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
        i. Create the link to the root node.
        ii. Go to left subtree.
    
    c. If left subtree of root node traverse :
        i. Remove the link.
        ii. Print root node.
        iii. Go to right subtree.
```

## Solution

```Cpp

class Solution {
public:
    // Function to perform an in-order traversal of the binary tree
    vector<int> inOrder(Node* root) {

        vector<int> ans; // Initialize an empty vector to store the in-order traversal results

        // Traverse the tree until the root becomes NULL (indicating no more nodes)
        while (root) {
            if (!root->left) {                  // If the current node has no left child:
                ans.push_back(root->data);      // Add the current node's data to the in-order list
                root = root->right;             // Move to the right child for further traversal
            } 
            else {
                Node* current = root->left;         // Find the predecessor (in-order predecessor) of the current node
                while (current->right && current->right != root) {
                    // Traverse down the right subtree of the left child until we reach:
                    // - A node with a NULL right child (predecessor)
                    // - The current node itself (avoiding infinite loops)
                    current = current->right;
                }

                // If the rightmost node's right child is NULL, establish a temporary link back to the current node.
                if (!current->right) {
                    current->right = root;      // Create a temporary link between the predecessor's right child and the current node
                    root = root->left;          // Move to the left child for further traversal
                } 
                else {
                    // If the rightmost node's right child points back to the current node,
                    // this means we have completed the traversal of the left subtree.
                    current->right = NULL;          // Remove the temporary link.
                    ans.push_back(root->data);      // Add the current node's data to the in-order list (processed)
                    root = root->right;             // Move to the right child for further traversal
                }
            }
        }
        return ans;         // Return the vector containing the in-order traversal results
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```