# Question : [BST to max heap - GFG](https://www.geeksforgeeks.org/problems/bst-to-max-heap/1)

Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

### Example

```
Input :
                 4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output : 1 2 3 4 5 6 7 
Exaplanation :
               7
             /   \
            3     6
          /  \   /  \
         1    2 4    5
The given BST has been transformed into a
Max Heap and it's postorder traversal is
1 2 3 4 5 6 7.

```

### Your Task
You don't need to read input or print anything. Your task is to complete the function convertToMaxHeapUtil() which takes the root of the tree as input and converts the BST to max heap.
Note : The driver code prints the postorder traversal of the converted BST.

```
Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
```

### Constraints

- `1 ≤ n ≤ 10^5`

## Solution

```Cpp
class Solution {
public:
    // Helper function to perform Inorder Traversal of the binary tree
    void inorderTraversal(Node* root, vector<int>& inorder) {
        // Base case: If the node is null, return
        if (!root)
            return;
        
        // Recursively traverse the left subtree
        inorderTraversal(root->left, inorder);

        // Add the current node's data to the inorder traversal list
        inorder.push_back(root->data);

        // Recursively traverse the right subtree
        inorderTraversal(root->right, inorder);
    }

    // Helper function to perform Postorder Traversal of the binary tree
    void postorderTraversal(Node* root, vector<int>& inorder, int& index) {
        // Base case: If the node is null, return
        if (!root)
            return;
        
        // Recursively traverse the left subtree
        postorderTraversal(root->left, inorder, index);

        // Recursively traverse the right subtree
        postorderTraversal(root->right, inorder, index);

        // Set the current node's data to the value from the inorder traversal list
        root->data = inorder[index];
        
        // Move to the next element in the inorder traversal list
        index++;
    }

    // Function to convert a binary tree to a max heap by utilizing inorder and postorder traversals
    void convertToMaxHeapUtil(Node* root) {
        // Step 1: Perform Inorder Traversal of the tree and store the node values
        vector<int> inorder;
        inorderTraversal(root, inorder);

        // Step 2: Perform Postorder Traversal and update node values in the tree based on inorder traversal
        int index = 0;
        postorderTraversal(root, inorder, index);
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```