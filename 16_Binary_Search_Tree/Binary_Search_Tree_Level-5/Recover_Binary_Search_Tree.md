# Question : [Convert Sorted List to Binary Search Tree - (LeetCode : 99)](https://leetcode.com/problems/recover-binary-search-tree/description/)

You are given the `root` of a binary search tree (BST), where the values of **exactly** two nodes of the tree were swapped by mistake. *Recover the tree without changing its structure*.


### Example 1
![](https://assets.leetcode.com/uploads/2020/10/28/recover1.jpg)

```
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
```

### Example 2
![](https://assets.leetcode.com/uploads/2020/10/28/recover2.jpg)

```
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
```

### Constraints

- The number of nodes in the tree is in the range `[2, 1000]`.<br>
- `-2^31 <= Node.val <= 2^31 - 1`

## Solution

```Cpp
Using Morris Traversal :

class Solution {
public:
    // Function to recover a Binary Search Tree (BST) with two swapped nodes using Morris In-order Traversal.
    void recoverTree(TreeNode* root) {

        TreeNode* current = NULL;                   // Pointer to keep track of the current node in the traversal
        TreeNode* first = NULL, *second = NULL;     // Pointers to store the nodes that are swapped
        TreeNode* last = NULL, *present = NULL;     // Pointers to keep track of the last and current nodes in the inorder traversal

        // Traverse the tree using a modified in-order traversal approach.
        while (root) {
            // Case 1: When left subtree does not exist (handle right child directly).
            if (!root->left) {
                // Update pointers for potential swap detection.
                last = present;
                present = root;

                // Check for violation (larger value encountered after a smaller one).
                if (last && last->val > present->val) {
                    // If first violation, set first node.
                    if (!first) {
                        first = last;
                    }
                    // Set second node for the violation.
                    second = present;
                }

                // Move to the right child.
                root = root->right;

            } 
            // Case 2: when the left child exists
            else {
                // // Find the inorder predecessor of the current node in left subtree.
                current = root->left;

                // Find the predecessor (rightmost node) in the left subtree.
                while (current->right && current->right != root) {
                    current = current->right;
                }

                // Case 3: when the left subtree not traversed yet (establish temporary link).
                if (!current->right) {
                    current->right = root;      // Temporary link to the current node
                    root = root->left;          // Move to the left child

                }
                // Case 4: when the left subtree already traversed (remove link, check violation).
                else {
                    current->right = NULL;      // Remove the temporary link

                    // Update pointers for potential swap detection.
                    last = present;
                    present = root;

                    // Check for violation (larger value encountered after a smaller one).
                    if (last && last->val > present->val) {
                        // If first violation, set first node.
                        if (!first) {
                            first = last;
                        }
                        // Set second node for the violation.
                        second = present;
                    }

                    // Move to the right child.
                    root = root->right;
                }
            }
        }

        // Swap the values of the two nodes that were swapped by mistake
        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```