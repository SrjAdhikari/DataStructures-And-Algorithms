# Question : [Array to BST - GFG](https://www.geeksforgeeks.org/problems/array-to-bst4443/1)

Given a sorted array. Convert it into a Height balanced Binary Search Tree (BST). Find the preorder traversal of height balanced BST. If there exist many such balanced BST consider the tree whose preorder is lexicographically smallest.
Height balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

### Example 1
```
Input: nums = {1, 2, 3, 4}
Output: {2, 1, 3, 4}
Explanation: 
The preorder traversal of the following 
BST formed is {2, 1, 3, 4}:
           2
         /   \
        1     3
               \
                4
```

### Example 2
```
Input: nums = {1,2,3,4,5,6,7}
Ouput: {4,2,1,3,6,5,7}
Explanation: 
The preorder traversal of the following
BST formed is {4,2,1,3,6,5,7} :
        4
       / \
      2   6
     / \  / \
    1   3 5  7
```
### Your task:
You don't need to read or print anything. Your task is to complete the function **sortedArrayToBST()** which takes the sorted array **nums** as input paramater and returns the preorder traversal of height balanced BST. If there exist many such balanced BST consider the tree whose preorder is lexicographically smallest.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
```

### Constraints
`1 ≤ |nums| ≤ 10^4`
`-10^4 ≤ nums[i] ≤ 10^4`

## Solution

```Cpp
class Solution {
public:
    // Helper function to convert a sorted array to a BST in an in-order traversal manner
    void arrayToBST(vector<int>& nums, int start, int end, vector<int>& ans) {

        // Base case: if start index exceeds end index, return
        if (start > end) return;

        // Find the middle index of the sub-array. This middle element will become the root node of the BST for this sub-array.
        int mid = start + (end - start) / 2;

        // Add the middle element (root node) to the `ans` vector. Since we're doing
        // an in-order traversal, this ensures the left subtree elements are added
        // before the root and the right subtree elements are added after the root.
        ans.push_back(nums[mid]);

        // Recursively build the left subtree with elements before the middle
        arrayToBST(nums, start, mid - 1, ans);

        // Recursively build the right subtree with elements after the middle
        arrayToBST(nums, mid + 1, end, ans);
    }

    // Function to convert a sorted array to an in-order traversal of a BST
    vector<int> sortedArrayToBST(vector<int>& nums) {

        vector<int> ans;  // Initialize an empty vector to store the BST elements

        // Set the start and end indices for the entire sorted array (`nums`)
        int start = 0;
        int end = nums.size() - 1;

        // Call the helper function to fill the result vector with the in-order traversal of the BST
        arrayToBST(nums, start, end, ans);

        return ans;     // Return the vector containing the in-order traversal of the BST
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```