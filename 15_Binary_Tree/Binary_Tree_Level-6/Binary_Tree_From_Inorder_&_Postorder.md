# Question : [Binary Tree from Inorder and Postorder - GFG](https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1)

Given **inorder** and **postorder** traversals of a binary tree(having **n** nodes) in the arrays **in[]** and **post[]** respectively. The task is to construct a **unique** binary tree from these traversals.

Driver code will print the preorder traversal of the constructed tree.

**Note** :- The **inorder** and **postorder** traversals contain ** values, and every value present in the **postorder** traversal is also found in the **inorder** traversal.

### Example 1
```
Input: n = 8, in[] = {4, 8, 2, 5, 1, 6, 3, 7}, post[] = {8, 4, 5, 2, 6, 7, 3, 1}
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and inorder traversal of tree the  resultant binary tree will be
         1
       /   \
      2     3
     /  \  /  \
     4   5 6   7
      \
       8
```

### Example 2
```
Input: n = 5, in[] = {9, 5, 2, 3, 4}, post[] = {5, 9, 3, 4, 2}
Output: 2 9 5 4 3
Explanation: The  resultant binary tree will be
          2
        /   \
       9     4
        \    /
         5  3
```

```
Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).
```

### Constraints
`1 <= n <= 10^3`
`1 <= in[i], post[i] <= 10^6`

## Solution

```Cpp

class Solution {
public:
    // Function to find the position of the root node in the inOrder array
    int findRootNodePos(int inOrder[], int rootNode, int inOrderStart, int inOrderEnd) {

        // Loop through the inOrder array to find the root node position
        for (int i = inOrderStart; i <= inOrderEnd; i++) {
            // If the current element matches the root node, return its position
            if (inOrder[i] == rootNode)
                return i;
        }
        // If the root node is not found, return -1
        return -1;
    }

    // Recursive function to create the binary tree from inOrder and postOrder arrays
    Node* createTree(int inOrder[], int postOrder[], int inOrderStart, int inOrderEnd, int postOrderIndex) {

        // Base case: if the start index is greater than the end index, return NULL
        if (inOrderStart > inOrderEnd)
            return NULL;
        
        int node = postOrder[postOrderIndex];       // Get the current root node value from the postOrder array
        Node* root = new Node(node);                // Create a new node with the root node value

        // Find the position of the root node in the inOrder array
        int rootNodePos = findRootNodePos(inOrder, node, inOrderStart, inOrderEnd);
        
        // Recursively build the right subtree
        // Right subtree is built from rootNodePos + 1 to inOrderEnd in the inOrder array
        // The next root node in the postOrder array is at postOrderIndex - 1
        root->right = createTree(inOrder, postOrder, rootNodePos + 1, inOrderEnd, postOrderIndex - 1);
        
        // Recursively build the left subtree
        // Left subtree is built from inOrderStart to rootNodePos - 1 in the inOrder array
        // The next root node in the postOrder array is at postOrderIndex - (inOrderEnd - rootNodePos) - 1
        root->left = createTree(inOrder, postOrder, inOrderStart, rootNodePos - 1, postOrderIndex - (inOrderEnd - rootNodePos) - 1);

        // Return the constructed root node
        return root;
    }

    // Function to build a binary tree given inOrder and postOrder traversal arrays
    Node* buildTree(int n, int inOrder[], int postOrder[]) {

        int inOrderStart = 0;           // Define the start and end indices for the inOrder array
        int inOrderEnd = n - 1;         // The end index is the last index of the inOrder array
        int postOrderIndex = n - 1;     // The initial root node index in the postOrder array is the last index

        // Call the createTree function to build the tree and return the root node
        return createTree(inOrder, postOrder, inOrderStart, inOrderEnd, postOrderIndex);
    }
};

Time Complexity = O(N^2)
Space Complexity = O(N)
```