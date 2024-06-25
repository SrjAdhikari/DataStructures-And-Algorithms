# Question : [Binary Tree Level Order Traversal - (LeetCode : 102)](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)

Given the `root` of a binary tree, return _the level order traversal of its nodes' values_. (i.e., from left to right, level by level).

### Example 1

![](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

### Example 2

```
Input: root = [1]
Output: [[1]]
```

### Example 3

```
Input: root = []
Output: []
```

### Constraints

- The number of nodes in the tree is in the range `[0, 2000]`<br>
- `-100 <= Node.val <= 100`

## Solution

```Cpp

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> q;                         // Queue to hold nodes to be processed
        vector<vector<int>> result;                 // 2D vector to store the final level order traversal

        if (root)                                   // If the root is not NULL,
            q.push(root);                           // push the root node onto the queue

        while (!q.empty()) {                        // Continue while there are nodes to process
            vector<int> order;                      // Vector to store values of nodes at the current level
            int size = q.size();                    // Number of nodes at the current level

            for (int i = 0; i < size; i++) {        // Process each node at the current level
                TreeNode* frontNode = q.front();    // Get the front node in the queue
                q.pop();                            // Remove the front node from the queue
                order.push_back(frontNode->val);    // Add the value of the front node to the order vector

                if (frontNode->left != NULL)        // If the front node has a left child,
                    q.push(frontNode->left);        // push the left child onto the queue

                if (frontNode->right != NULL)       // If the front node has a right child,
                    q.push(frontNode->right);       // push the right child onto the queue
            }
            result.push_back(order);                // Add the current level's values to the result
        }
        return result;                              // Return the final level order traversal
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
