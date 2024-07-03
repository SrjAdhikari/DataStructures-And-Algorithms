# Question : [Path Sum II - (LeetCode : 113)](https://leetcode.com/problems/path-sum-ii/description/)

Given the `root` of a binary tree and an integer `targetSum`, return all ***root-to-leaf*** *paths where the sum of the node values in the path equals* `targetSum`. *Each path should be returned as a list of the node* ***values***, *not node references*.

A **root-to-leaf** path is a path starting from the root and ending at any leaf node. A **leaf** is a node with no children.


### Example 1

![](https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg)

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
```

### Example 2

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)
```
Input: root = [1,2,3], targetSum = 5
Output: []
```

### Example 3

```
Input: root = [1,2], targetSum = 0
Output: []
```

### Constraints

- The number of nodes in the tree is in the range `[0, 5000]`
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

## Solution

```Cpp

class Solution {
public:
    // Helper function to find all root-to-leaf paths where the sum of node values equals targetSum
    void pathSumHelper(TreeNode* root, int targetSum, vector<int> temp, vector<vector<int>>& ans, int sum) {

        if (!root)                      // Base case: if the current node is NULL, return (no path through NULL)
            return;

        sum += root->val;               // Add the current node's value to the running sum
        temp.push_back(root->val);      // Add the current node's value to the temporary path

        // Check if the current node is a leaf node (no left or right children)
        if (!root->left && !root->right) {
            // If the running sum equals the target sum, add the path to the answer list
            if (sum == targetSum)
                ans.push_back(temp);
            else
                return;
        }

        pathSumHelper(root->left, targetSum, temp, ans, sum);       // Recursively call the function for the left subtree
        pathSumHelper(root->right, targetSum, temp, ans, sum);      // Recursively call the function for the right subtree
    }

    // Main function to find all root-to-leaf paths where the sum of node values equals targetSum
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> temp;                                   // Temporary vector to store the current path
        vector<vector<int>> ans;                            // Vector to store all valid paths
        int sum = 0;                                        // Initialize the running sum to 0
        pathSumHelper(root, targetSum, temp, ans, sum);     // Call the helper function to start the process
        return ans;                                         // Return the list of valid paths
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```