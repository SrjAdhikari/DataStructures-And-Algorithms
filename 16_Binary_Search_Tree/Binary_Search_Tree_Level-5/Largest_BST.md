# Question : [Largest BST - GFG](https://www.geeksforgeeks.org/problems/largest-bst/1)

Given a binary tree. Find the **size** of its largest subtree which is a Binary Search Tree.
**Note**: Here Size equals the number of nodes in the subtree.

### Example 1
```
Input:   1
        /  \
        4   4              
       / \ 
      6   8
Output: 1 
Explanation: There's no sub-tree with size greater than 1 which forms a BST. 
All the leaf Nodes are the BSTs with size equal to 1.
```

### Example 2
```
Input:    6
        /   \
      6      2              
       \    / \
        2  1   3
Output: 3
Explanation: The following sub-tree is a BST of size 3: 
       2
     /   \
    1     3
```

```
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(Height of BST)
```

### Constraints
`1 ≤ Number of nodes ≤ 10^5`
`1 ≤ Data of a node ≤ 10^6`

## Solution 1

```Cpp

class NodeInfo {
    public:
    bool isBST;         // Indicates whether the current subtree is a BST
    int size;           // Size of the current subtree
    int min, max;       // Minimum and maximum values in the current subtree

    // Constructor to initialize a NodeInfo object with a single node's data
    NodeInfo(int data) {
        isBST = 1;
        size = 1;
        min = max = data;
    }
};


class Solution {
    public:

    // Function to find the largest BST in the given binary tree
    NodeInfo* findLargestBST(Node* root, int& totalSize) {

        // Base case: If the node is a leaf node
        if (!root->left && !root->right) {
            NodeInfo* leafNode = new NodeInfo(root->data);
            totalSize = max(totalSize, 1);      // Update the total size with the current node
            return leafNode;
        }

        // Case: If only the right child exists
        else if (!root->left && root->right) {
            NodeInfo* head = findLargestBST(root->right, totalSize);

            // Check if the right subtree is a BST and its minimum value is greater than current node's data
            if (head->isBST && head->min > root->data) {
                head->size++;                               // Increment the size of the subtree
                head->min = root->data;                     // Update the minimum value
                totalSize = max(totalSize, head->size);     // Update the total size
                return head;
            } 
            // Right subtree is not a BST, mark it not a BST and return
            else {
                head->isBST = 0;
                return head;
            }
        } 
        // Case: If only the left child exists
        else if (root->left && !root->right) {
            NodeInfo* head = findLargestBST(root->left, totalSize);

            // Check if the left subtree is a BST and its maximum value is less than current node's data
            if (head->isBST && head->max < root->data) {
                head->size++;                               // Increment the size of the subtree
                head->max = root->data;                     // Update the maximum value
                totalSize = max(totalSize, head->size);     // Update the total size
                return head;
            }
            // Left subtree is not a BST, mark it not a BST and return
            else {
                head->isBST = 0;
                return head;
            }
        }

        // Case: If both children exist, recursively find largest BST in subtrees
        else {
            NodeInfo* leftSubtree = findLargestBST(root->left, totalSize);
            NodeInfo* rightSubtree = findLargestBST(root->right, totalSize);

            // Check if both subtrees are BSTs and their values are within valid range for current node to be root of a BST
            if (leftSubtree->isBST && rightSubtree->isBST && leftSubtree->max < root->data && rightSubtree->min > root->data) {
                NodeInfo* head = new NodeInfo(root->data);
                head->size += leftSubtree->size + rightSubtree->size;       // Sum sizes of both subtrees
                head->min = leftSubtree->min;                               // Update minimum value
                head->max = rightSubtree->max;                              // Update maximum value
                totalSize = max(totalSize, head->size);                     // Update the total size
                return head;
            } 
            // If not a BST, mark left subtree is not a BST and return
            else {
                leftSubtree->isBST = 0;     // Mark the subtree as not a BST
                return leftSubtree;         // Return the left subtree info (could also return rightSubtree)
            }
        }
    }

    int largestBst(Node *root) {
        int totalSize = 0;
        findLargestBST(root, totalSize);
        return totalSize;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```

## Solution 2

```Cpp

class NodeInfo {
    public:
    bool isBST;             // Indicates whether the subtree is a BST
    int size;               // Size of the subtree
    int min;                // Minimum value in the subtree
    int max;                // Maximum value in the subtree
    
    NodeInfo() {            // Constructor to initialize NodeInfo for a non-existent node
        isBST = true;       // By default, an empty subtree is considered a BST
        size = 0;           // Size is 0 for non-existent nodes
        min = INT_MAX;      // Minimum value for a non-existent subtree
        max = INT_MIN;      // Maximum value for a non-existent subtree
    }
};

class Solution {
public:
    
    // Helper function to find the largest BST in the binary tree
    NodeInfo* findLargestBST(Node* root, int& totalSize) {
        // Base case: if the node is null, return an empty NodeInfo object with default values
        if(!root) {
            NodeInfo* node = new NodeInfo();
            return node;
        }
        
        // Recursively find the largest BST in the left and right subtrees
        NodeInfo* leftSubtree = findLargestBST(root->left, totalSize);
        NodeInfo* rightSubtree = findLargestBST(root->right, totalSize);
        
        // Check if both subtrees are BSTs and their values are within valid range
        // for the current node to be the root of a BST
        if(leftSubtree->isBST && rightSubtree->isBST && leftSubtree->max < root->data && rightSubtree->min > root->data) {   // Current subtree is a BST
            NodeInfo* head = new NodeInfo();
            head->size = 1 + leftSubtree->size + rightSubtree->size;    // Size of the current BST
            head->min = min(root->data, leftSubtree->min);              // Minimum value in the current BST
            head->max = max(root->data, rightSubtree->max);             // Maximum value in the current BST
            totalSize = max(totalSize, head->size);                     // Update the largest BST size found so far
            return head;                                                // Return the NodeInfo for the current subtree
        } 
        // Current subtree is not a BST
        else {
            leftSubtree->isBST = false;     // Mark the subtree as not a BST
            return leftSubtree;             // Return the left subtree info (could also return rightSubtree)
        }
    }
    
    int largestBst(Node *root) {
        int totalSize = 0;
        findLargestBST(root, totalSize);
        return totalSize;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```