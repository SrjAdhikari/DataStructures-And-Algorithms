# Question : [Check whether BST contains Dead End - GFG](https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1)

Given a Binary Search Tree that contains **unique positive integer values greater than 0**. The task is to complete the function **isDeadEnd** which returns **true** if the BST contains a **dead end** else returns **false**. Here **Dead End** means a **leaf** node, at which no other node can be inserted.

### Example 1
```
Input :   
               8
             /   \ 
            5     9
          /  \     
         2    7 
        /
       1     
          
Output : 
Yes
Explanation : 
Node 1 is a Dead End in the given BST.
```

### Example 2
```
Input :     
            　8
            /   \ 
           7     10
         /      /   \
        2      9     13
Output : 
Yes
Explanation : 
Node 9 is a Dead End in the given BST.
```

### Your Task:
You don't have to input or print anything. Complete the function **isDeadEnd()** which takes **BST** as input and returns a boolean value.

```
Expected Time Complexity: O(N), where N is the number of nodes in the BST.
Expected Auxiliary Space: O(N)
```

### Constraints
`1 <= N <= 1001`
`1 <= Value of Nodes <= 10001`

## Solution

```Cpp

class Solution {
public:
    // Helper function to determine if there's a dead node in the BST
    bool isDeadNode(Node* root, int lower, int upper) {
        // Base case: If the current node is NULL, it's not a leaf node and cannot be a dead end.
        if(!root)
            return 0;
            
        // Check if the current node is a leaf node (no children).
        if(!root->left && !root->right) {
            // If the node is a leaf and it cannot have any new nodes added as children
            // due to the lower and upper constraints, it's a dead node
            if(root->data - lower == 1 && upper - root->data == 1)
                return 1;   // Return true if it's a dead node
            else
                return 0;   // Return false otherwise
        }
        
        // Recursively check the left subtree for dead ends, passing the current node's data as the new upper bound.
        bool left = isDeadNode(root->left, lower, root->data);

        // Recursively check the right subtree for dead ends, passing the current node's data as the new lower bound.
        bool right = isDeadNode(root->right, root->data, upper);
        
        // Return true if either the left or right subtree has a dead end (indicated by `left` or `right` being true).
        return left || right;
    }

    // Function to determine if the BST contains a dead end
    bool isDeadEnd(Node *root) {
        // Call the helper function `isDeadNode` with appropriate parameters for the entire tree:
        // - root: The root node of the tree
        // - lower: 0 (assuming the tree can have elements less than 0)
        // - upper: INT_MAX (to accommodate any valid values in the tree)
        // If `isDeadNode` returns true, it means a dead end exists in the tree.
        return isDeadNode(root, 0, INT_MAX);
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```