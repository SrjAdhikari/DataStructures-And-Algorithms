# Question : [Tree Boundary Traversal - GFG](https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1)

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

1. **Left boundary nodes**: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
2. **Leaf nodes**: All the leaf nodes except for the ones that are part of left or right boundary.
3. **Reverse right boundary nodes**: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.

**Note**: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

### Example 1
```
nput:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3
```
Explanation:
![](https://media.geeksforgeeks.org/wp-content/uploads/20211103204119/graph4-300x300.png)

### Example 2
```
Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8
```
Explanation:
![](https://media.geeksforgeeks.org/wp-content/uploads/20211103204646/graph1-300x300.png)

### Your Task:
This is a function problem. You don't have to take input. Just complete the **function boundary()** that takes the root node as input and returns an array containing the boundary values in anti-clockwise.

```
Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).
```

### Constraints
`1 <= Number of nodes<= 10^5`
`1 <= Data of a node<= 105`

## Solution

```Cpp
Using Pre-order Travesal : 

class Solution {
public:
    // Function to print the left boundary nodes of the binary tree (excluding leaves)
    void printLeftBoundary(Node* root, vector<int>& ans) {
        if (!root) {
            // Base case: Empty subtree, nothing to print
            return;
        }

        // If the current node has no left child but has a right child,
        // it's not part of the left boundary, so skip it
        if (!root->left && !root->right) {
            return;
        }

        // Add the current node's data to the boundary list
        ans.push_back(root->data);

        // If the current node has a left child, recursively print the left boundary of the left subtree
        if (root->left) {
            printLeftBoundary(root->left, ans);
        } else {
            // If there's no left child, print the right boundary (excluding leaves) to reach the leftmost node
            printLeftBoundary(root->right, ans);
        }
    }

    // Function to print the leaf nodes of the binary tree
    void printLeafBoundary(Node* root, vector<int>& ans) {
        if (!root) {
            // Base case: Empty subtree, nothing to print
            return;
        }

        // If the current node is a leaf (no children), add its data to the boundary list
        if (!root->left && !root->right) {
            ans.push_back(root->data);
        }

        // Recursively print leaf nodes in both the left and right subtrees
        printLeafBoundary(root->left, ans);
        printLeafBoundary(root->right, ans);
    }

    // Function to print the right boundary nodes of the binary tree (excluding leaves, in reverse order)
    void printRightBoundary(Node* root, vector<int>& ans) {
        if (!root) {
            // Base case: Empty subtree, nothing to print
            return;
        }

        // If the current node has no right child but has a left child,
        // it's not part of the right boundary, so skip it
        if (!root->left && !root->right) {
            return;
        }

        // If the current node has a right child, recursively print the right boundary of the right subtree (in reverse)
        if (root->right) {
            printRightBoundary(root->right, ans);
        } else {
            // If there's no right child, print the left boundary (excluding leaves) to reach the rightmost node (in reverse)
            printLeftBoundary(root->right, ans); // Note: Use left subtree here (in reverse order)
        }

        // Add the current node's data to the boundary list (in reverse order)
        ans.push_back(root->data);
    }

    // Function to find the boundary nodes (left, leaf, and right) of the binary tree
    vector<int> boundary(Node *root) {
        vector<int> ans;

        if (!root) {
            // Base case: Empty tree, no boundary
            return ans;
        }

        // Add the root node's data to the boundary list
        ans.push_back(root->data);

        // Print the left boundary nodes (excluding leaves)
        printLeftBoundary(root->left, ans);

        // Include leaf nodes if the tree has at least one child (left or right)
        if (root->left || root->right) {
            printLeafBoundary(root, ans);
        }

        // Print the right boundary nodes (excluding leaves, in reverse order)
        printRightBoundary(root->right, ans);

        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```