# Question : [Kth Smallest Element in a BST - (LeetCode : 230)](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/)

Given the `root` of *a binary search* tree, and an integer `k`, return the `kth` *smallest value (**1-indexed**) of all the values of the nodes in the tree.*

### Example 1
![](https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg)

```
Input: root = [3,1,4,null,2], k = 1
Output: 1
```

### Example 2
![](https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg)

```
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
```

### Constraints
- The number of nodes in the tree is `n`.
- `1 <= k <= n <= 10^4`
- `0 <= Node.val <= 10^4`

## Solution

```Cpp
class Solution {
public:
    // Helper function to find the k-th smallest element in a BST using in-order traversal
    void kthSmallElement(TreeNode* root, int& ans, int& k) {

        // Base case: if the node is NULL, return
        if (!root)
            return;
        
        // Recursively traverse the left subtree (to process smaller elements first)
        kthSmallElement(root->left, ans, k);
        
        // Decrement the target 'k' by 1. This represents how many more elements we
        // need to find to reach the kth smallest.
        k--;

        // If 'k' has become 0, it means we've found the kth smallest element 
        // We store the current node's value in the 'ans' reference variable and return to stop further processing.
        if (k == 0) {
            ans = root->val;    // Update ans with the current node's value if k is zero
            return;             // Return since we've found the k-th smallest element
        }
        
        // If 'k' is still positive, we need to continue searching in the right subtree
        // to continue finding the k-th smallest element
        kthSmallElement(root->right, ans, k);
    }

    // Main function to return the k-th smallest element in a BST
    int kthSmallest(TreeNode* root, int k) {
        int ans = INT_MAX;                  // Initialize ans to the maximum possible integer value
        kthSmallElement(root, ans, k);      // Call the helper function to find the k-th smallest element
        return ans;                         // Return the k-th smallest element
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```