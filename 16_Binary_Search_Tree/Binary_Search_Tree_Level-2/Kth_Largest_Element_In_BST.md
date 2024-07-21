# Question : [Kth largest element in BST - GFG](https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1)

Given a **Binary Search Tree**. Your task is to complete the function which will return the **Kth largest** element without doing any modification in Binary Search Tree.

### Example 1
```
Input:
      4
    /   \
   2     9
k = 2 
Output: 4
```

### Example 2
```
Input:
       9
        \ 
          10
K = 1
Output: 10
```
### Your task:
You don't need to read input or print anything. Your task is to complete the function **kthLargest()** which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(H) where H is max recursion stack of height H at a given time.
```

### Constraints
`1 <= N <= 10^5`
`1 <= K <= N`

## Solution

```Cpp
class Solution {
public:
    // Helper function to find the k-th largest element in a BST using in-order traversal
    void kLargest(Node* root, int& ans, int& k) {

        if (!root)      // Base case: if the node is NULL, return
            return;
        
        // Traverse the right subtree first (to get larger elements in descending order)
        kLargest(root->right, ans, k);
        
        // Decrement k to keep track of the number of nodes processed
        k--;
        
        // Check if we have reached the k-th largest node
        if (k == 0) {
            ans = root->data;   // Update the result with the current node's value
            return;             // Return since we've found the k-th largest element
        }
        
        // Traverse the left subtree (to continue finding the k-th largest element)
        kLargest(root->left, ans, k);
    }

    // Main function to return the k-th largest element in a BST
    int kthLargest(Node* root, int K) {
        
        int ans = INT_MIN;          // Initialize ans to the minimum possible integer value
        kLargest(root, ans, K);     // Call the helper function to find the k-th largest element
        return ans;                 // Return the k-th largest element
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```