# Question : Find Preorder Using Morris raversal

Given a Binary tree. Find the postorder traversal of the tree **without using recursion**.

### Example 1
```
Input:
           1
         /   \
        2     3
      /  \
     4    5
Output: 4 5 2 3 1
Explanation:
Postorder traversal (Left->Right->Root) of 
the tree is 4 5 2 3 1.
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
Output: 10 7 1 6 10 6 5 8 
Explanation:
Postorder traversal (Left->Right->Root) 
of the tree is 10 7 1 6 10 6 5 8 .
```

### Algorithm
```
- We will traverse the tree in the "NRL" order.

1. Check, if right subtree of root node exist or not.
2. If right subtree does not exist :
    a. Print root node.
    b. Go to left subtree.

3. If right subtree exist :
    a. Check, if right subtree of root node traverse or not.
    b. If right subtree of root node not traverse :
        i. Print root node.
        ii. Create the link to the root node.
        iii. Go to right subtree.
    
    c. If right subtree of root node traverse :
        i. Remove the link.
        ii. Go to left subtree.
```

## Solution

```Cpp

class Solution {
public:
    // Function to perform a post-order traversal of the binary tree (visit nodes in N R L order)
    vector<int> postOrder(Node* root) {
        // Vector to store the post-order traversal result.
        vector<int> ans;
        
        // Traverse the tree until root becomes NULL, indicating the whole tree has been traversed.
        while(root) {
            // If there is no right child, visit this node, move to the left child, and push the node's data into the array.
            if(!root->right) {
                ans.push_back(root->data);
                root = root->left;
            }
            // If there is a right child:
            else {
                // Find the leftmost node in the right subtree or the postorder successor of the current node.
                Node *current = root->right;
                while(current->left && current->left != root)
                    // Traverse down the right subtree of the left child until we reach:
                    // - A node with a NULL left child
                    // - The current node itself (avoiding infinite loops)
                    current = current->left;
                
                // There are two conditions:
                // First, if the leftmost node's left child is NULL, it means we haven't traversed this part yet.
                if(current->left == NULL) {
                    ans.push_back(root->data);          // Add the current node's data to the ans array.
                    current->left = root;               // Create a temporary link from the leftmost node back to the current node.
                    root = root->right;                 // Move to the right child of the current node.
                } 
                // Second, if we have already traversed this part:
                else {
                    current->left = NULL;               // Remove the temporary link.
                    root = root->left;                  // Move to the left child of the current node.
                }
            }
        }
        
        // The traversal order we obtained is the reverse of post-order (N R L).
        // Reverse the ans array to get the correct post-order (L R N).
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```