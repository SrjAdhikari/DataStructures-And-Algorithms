# Question : [Flatten binary tree to linked list - GFG](https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1)

Given the root of a binary tree, flatten the tree into a "lLinked list":

- The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
- The "linked list" should be in the same order as a pre-order traversal of the binary tree.

### Example 1
```
Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 
Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.
```

### Example 2
```
Input :
        1
       / \
      3   4
         /
        2
         \
          5 
Output : 
1 3 4 2 5  
Explanation : 
After flattening, the tree looks 
like this 
     1
      \
       3
        \
         4
          \
           2
            \ 
             5 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 3 4 2 5.
```
### Your Task:
You don't have to read input or print anything. Your task is to complete the function flatten() which takes the root of the tree and flattens the tree into a linked list without using any auxiliary space.
Note: The driver code prints the in-order traversal of the flattened binary tree.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1).
```

### Constraints
`1 <= N <= 10^5`


## Solution

```Cpp

class Solution {
public:
    // Function to flatten a binary tree into a linked list in-place
    void flatten(Node* root) {
        // Traverse the tree until the current node becomes NULL (indicating no more nodes)
        while (root) {
            if (!root->left) {          // If the current node has no left child:
                root = root->right;     // Simply move to the right child for further processing
            } 
            else {                      // If the current node has a left child:
            // Find the rightmost node in the left subtree
            Node* current = root->left;
            while (current->right) {
                current = current->right;
            }

            // Flatten the left subtree:
            current->right = root->right;       // - Link the left subtree rightmost child to the original right child of root node.
            root->right = root->left;           // - Make the left child the new right child of root.
            root->left = NULL;                  // - Set the left child of root to NULL (it has been moved to the right.)

            root = root->right;                 // Move to the new right child (flattened left subtree) for further processing
            }
        }
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```