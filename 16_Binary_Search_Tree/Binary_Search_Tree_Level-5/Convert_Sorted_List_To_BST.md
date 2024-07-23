# Question : [Convert Sorted List to Binary Search Tree - (LeetCode : 109)](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/)

Given the head of a singly linked list where elements are sorted in **ascending order**, *convert it to a 
height-balanced binary search tree*.


### Example 1
![](https://assets.leetcode.com/uploads/2020/08/17/linked.jpg)

```
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], 
which represents the shown height balanced BST.
```

### Example 2

```
Input: head = []
Output: []
```

### Constraints

- The number of nodes in `head` is in the range `[0, 2 * 10^4]`.<br>
- `-10^5 <= Node.val <= 10^5`

## Solution

```Cpp
class Solution {
public:
    // Function to construct a Binary Search Tree (BST) from a sorted vector of integers.
    TreeNode* buildBST(vector<int>& tree, int start, int end) {
        // Base case: If the start index is greater than the end index, the subtree is empty.
        // Return NULL to indicate an empty subtree.
        if (start > end) {
            return NULL;
        }

        // Find the middle index. We use (end - start) to avoid integer overflow in case
        // of very large `start` and `end` values.
        int mid = start + (end - start) / 2;

        // Create a new TreeNode object with the value at the middle index of the vector.
        TreeNode* root = new TreeNode(tree[mid]);

        // Recursively build the left subtree using elements from `start` to `mid - 1`.
        root->left = buildBST(tree, start, mid - 1);

        // Recursively build the right subtree using elements from `mid + 1` to `end`.
        root->right = buildBST(tree, mid + 1, end);

        // Return the root node of the constructed BST.
        return root;
    }

    // Function to convert a sorted linked list to a BST.
    TreeNode* sortedListToBST(ListNode* head) {
        // Create an empty vector `tree` to store the values from the linked list.
        vector<int> tree;

        // Traverse the linked list and add each node's value to the vector.
        while (head) {
            tree.push_back(head->val);
            head = head->next;
        }

        // Set the start and end indices for the vector (assuming 0-based indexing).
        int start = 0;
        int end = tree.size() - 1;

        // Call the `buildBST` function to construct the BST from the vector.
        return buildBST(tree, start, end);
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```