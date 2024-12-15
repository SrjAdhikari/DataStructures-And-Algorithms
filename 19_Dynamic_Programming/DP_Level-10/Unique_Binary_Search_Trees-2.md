# Question : [Unique Binary Search Trees II - (LeetCode : 95)](https://leetcode.com/problems/unique-binary-search-trees-ii/description/)

Given an integer `n`, return _all the structurally unique **BST**'s (binary search trees), which has exactly `n` nodes of unique values from `1` to `n`_. Return the answer in **any order**.

### Example 1

![](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

```
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
```

### Example 2

```
Input: n = 1
Output: [[1]]
```

### Constraints

-   `1 <= n <= 8`

### Recursive Approach

```Cpp
class Solution {
public:
    vector<TreeNode*> recursion(int start, int end) {
        // Base case: If `start` exceeds `end`, return a vector containing `NULL` (no tree possible).
        if (start > end)
            return {NULL};

        // Base case: If `start` equals `end`, there's only one possible tree with a single node (start).
        if (start == end)
            return {new TreeNode(start)};

        // Vector to store all possible trees for the current range.
        vector<TreeNode*> result;

        // Iterate over all numbers from `start` to `end`, treating each as the root of the tree.
        for (int i = start; i <= end; i++) {
            // Recursively generate all possible left subtrees using values from `start` to `i-1`.
            vector<TreeNode*> leftSubTree = recursion(start, i - 1);

            // Recursively generate all possible right subtrees using values from `i+1` to `end`.
            vector<TreeNode*> rightSubTree = recursion(i + 1, end);

            // Combine each left subtree with each right subtree, with `i` as thecurrent root.
            for (int j = 0; j < leftSubTree.size(); j++) {
                for (int k = 0; k < rightSubTree.size(); k++) {
                    TreeNode* root = new TreeNode(i);       // Create a new root node with value `i`.
                    root->left = leftSubTree[j];            // Attach the current left subtree.
                    root->right = rightSubTree[k];          // Attach the current right subtree.

                    // Add the current tree (root with its subtrees) to the result list.
                    result.push_back(root);
                }
            }
        }

        // Return the list of all unique trees that can be formed with values from `start` to `end`.
        return result;
    }

     vector<TreeNode*> generateTrees(int n) {
        // Edge case: If `n` is 0, return an empty vector (no BSTs possible).
        if (n == 0)
            return {};

        // Call the recursive helper function for the full range [1, n].
        return recursion(1, n);
    }
};

Time Complexity = O(C(n))
Space Complexity = O(n)
=> 'C(n)' is the nth Catalan number.
```
