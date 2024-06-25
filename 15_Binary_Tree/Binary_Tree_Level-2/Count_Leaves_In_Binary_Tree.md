# Question : [Count Leaves in Binary Tree - GFG](https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1)

Given a Binary Tree of size **N**, You have to count leaves in it. For example, there are two leaves in following tree

```
      1
     / \
   10   39
  /
 5
```

### Example 1

```
Input:
Given Tree is
               4
              / \
             8  10
            /  /  \
           7  5    1
          /
         3
Output:
3
Explanation:
Three leaves are 3 , 5 and 1.
```

### Your task

You don't have to take input. Complete the function **countLeaves()** that takes **root** node of the given tree as parameter and **returns** the count of leaves in tree. The **printing** is done by the **driver** code.

```
Expected Time Complexity : O(n)
Expected Space Compelxity : O(h), where h is the height of the binary tree
```

### Constraints

`1 <= N <= 10^4`

## Solution 1

```Cpp

class Solution {
public:
    // Function to count the number of leaf nodes in a binary tree
    int countLeaves(Node* root) {

        // Base case: if the tree is empty, there are no leaves
        if(root == NULL)
            return 0;

        // If the current node is a leaf node (no children), return 1
        if(root->left == NULL && root->right == NULL)
            return 1;

        // Recursively count the leaves in the left and right subtrees
        int left = countLeaves(root->left);
        int right = countLeaves(root->right);

        // Return the total number of leaves in both subtrees
        return left + right;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

## Solution 2

```Cpp

class Solution {
public:
    // Helper function to count the number of leaf nodes in a binary tree
    void leavesCount(Node* root, int& count) {

        if(root == NULL)                    // Base case: if the tree is empty, return
            return;

        // If the current node is a leaf node (no children), increment the count and return
        if(root->left == NULL && root->right == NULL) {
            count++;
            return;
        }

        leavesCount(root->left, count);       // Recursively count leaves in the left subtree
        leavesCount(root->right, count);      // Recursively count leaves in the right subtree
    }

    // Function to count the number of leaf nodes in a binary tree
    int countLeaves(Node* root) {
        int count = 0;                  // Initialize the count of leaf nodes to 0
        leavesCount(root, count);       // Call the helper function to count leaves
        return count;                   // Return the final count of leaf nodes
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
