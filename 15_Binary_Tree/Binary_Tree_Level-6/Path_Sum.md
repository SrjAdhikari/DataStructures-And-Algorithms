# Question : [Path Sum - (LeetCode : 112)](https://leetcode.com/problems/path-sum/description/)

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

A **leaf** is a node with no children.


### Example 1

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg)

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
```

### Example 2

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)
```
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
```

### Example 3

```
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
```

### Constraints

- The number of nodes in the tree is in the range `[0, 5000]`
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

## Solution

```Cpp

class Solution {
public:
    // Helper function to determine if there is a root-to-leaf path with the given sum
    bool pathSumHelper(TreeNode* root, int targetSum, int sum) {

        if (!root)              // Base case: if the current node is NULL, return false
            return false;

        sum += root->val;       // Add the current node's value to the running sum

        // Check if the current node is a leaf node (no left or right children)
        if (!root->left && !root->right) {
            // If the running sum equals the target sum, return true
            if (sum == targetSum)
                return true;
            else
                // If the sum is not equal to the target sum, return false
                return false;
        }

        // Recursively check the left subtree for the path sum
        bool leftSubtreeSum = pathSumHelper(root->left, targetSum, sum);

        // Recursively check the right subtree for the path sum
        bool rightSubtreeSum = pathSumHelper(root->right, targetSum, sum);

        // Return true if either the left or right subtree has a path with the required sum
        return leftSubtreeSum || rightSubtreeSum;
    }

    // Main function to determine if there is a root-to-leaf path with the given sum
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Initialize the running sum as 0 and call the helper function
        int sum = 0;
        return pathSumHelper(root, targetSum, sum);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```