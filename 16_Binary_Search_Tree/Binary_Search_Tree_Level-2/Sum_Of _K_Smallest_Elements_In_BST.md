# Question : [Sum of k smallest elements in BST - GFG](https://www.geeksforgeeks.org/problems/sum-of-k-smallest-elements-in-bst3029/1)

Given a Binary Search Tree. Find sum of all elements smaller than and equal to Kth smallest element.

### Example 1
```
Input: 
          20
        /    \
       8     22
     /    \
    4     12
         /    \
        10    14   , K=3

Output: 22
Explanation:
Sum of 3 smallest elements are: 
4 + 8 + 10 = 22
```

### Example 2
```
Input:
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8 , K=2

Output: 9
Explanation:
The sum of two smallest elements 
is 4+5=9.
```
### Your task:
You don't need to read input or print anything. Your task is to complete the function **sum()** which takes the **root node** and an **integer K** as input parameters and returns the sum of all elements smaller than and equal to kth smallest element.
```
Expected Time Complexity: O(K)
Expected Auxiliary Space: O(1)
```

### Constraints
`1 <= Number of nodes in BST <= 100`
`1 <= K <= N`

## Solution

```Cpp
class Solution {
public:
    // Function to calculate the sum of nodes in a binary tree where the sum of their depths is equal to the target value 'k'
    void kSum(Node* root, int &sum, int &k) {

        if (!root)                  // If the current node is null, return (base case)
            return;

        kSum(root->left, sum, k);   // Recursively calculate the sum for the left subtree
        
        k--;                        // Decrement the target 'k' by 1, we are processing one more node

        // If 'k' is still non-negative, meaning we're within the desired depth range,
        // include the current node's data in the sum
        if (k >= 0) {
            sum += root->data;
        } else {
            // If k is negative, we've already processed k nodes, so return to stop further processing.
            return;
        }

        kSum(root->right, sum, k);  // Recursively calculate the sum for the right subtree
    }

    // Function to calculate the sum of nodes in a binary tree with a specific depth sum
    int sum(Node* root, int k) {

        int sum = 0;            // Initialize the sum to 0
        kSum(root, sum, k);     // Call the recursive helper function 'kSum' to calculate the actual sum
        return sum;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```