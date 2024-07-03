# Question : [Construct Tree from Inorder & Preorder - GFG](https://www.geeksforgeeks.org/problems/construct-tree-1/1)

Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. 

### Example 1
```
IInput:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
```

### Example 2
```
Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
     /   \
    1     2
  /  \   /
 3    4 5
```
### Your Task:
Your task is to complete the function **buildTree()** which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

```
Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).
```

### Constraints
`1<=Number of Nodes<=1000`

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

    // Recursive function to create the binary tree
    Node* createTree(int inOrder[], int preOrder[], int inOrderStart, int inOrderEnd, int preOrderIndex) {

        // Base case: if the start index is greater than the end index, return NULL
        if (inOrderStart > inOrderEnd)
            return NULL;
        
        int node = preOrder[preOrderIndex];     // Get the current root node value from the preOrder array
        Node* root = new Node(node);            // Create a new node with the root node value

        // Find the position of the root node in the inOrder array
        int rootNodePos = findRootNodePos(inOrder, node, inOrderStart, inOrderEnd);
        
        // Recursively build the left subtree
        // Left subtree is built from inOrderStart to rootNodePos - 1 in inOrder array
        // The next root node in preOrder array is at preOrderIndex + 1
        root->left = createTree(inOrder, preOrder, inOrderStart, rootNodePos - 1, preOrderIndex + 1);
        
        // Recursively build the right subtree
        // Right subtree is built from rootNodePos + 1 to inOrderEnd in inOrder array
        // The next root node in preOrder array is at preOrderIndex + (rootNodePos - inOrderStart) + 1
        root->right = createTree(inOrder, preOrder, rootNodePos + 1, inOrderEnd, preOrderIndex + (rootNodePos - inOrderStart) + 1);

        // Return the constructed root node
        return root;
    }

    // Function to build a binary tree given inOrder and preOrder traversal arrays
    Node* buildTree(int inOrder[], int preOrder[], int n) {

        int inOrderStart = 0;       // Define the start and end indices for the inOrder array
        int inOrderEnd = n - 1;     // The end index is the last index of the inOrder array
        int preOrderIndex = 0;      // The initial root node index in preOrder array is 0
        
        // Call the createTree function to build the tree and return the root node
        return createTree(inOrder, preOrder, inOrderStart, inOrderEnd, preOrderIndex);
    }
};

Time Complexity = O(N^2)
Space Complexity = O(N)
```