# Question : [Maximum Path Sum between 2 Special Nodes - GFG](https://www.geeksforgeeks.org/problems/maximum-path-sum/1)

Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one special node to another special node.

**Note**: Here special node is a node which is connected to exactly one different node.

### Example 1
```
Input:      
           3                               
         /   \                          
       4      5                     
     /  \      
   -10   4                          
Output: 16
Explanation:
Maximum Sum lies between special node 4 and 5.
4 + 4 + 3 + 5 = 16.
```

### Example 2
```
Input:    
           -15                               
         /     \                          
        5        6                      
      /  \      / \
    -8    1     3  9
   /  \             \
  2   -3             0
                    / \
                    4 -1
                       /
                      10  
Output:  27
Explanation:
The maximum possible sum from one special node 
to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)
```

### Your Task:  
You dont need to read input or print anything. Complete the function **maxPathSum()** which takes root node as input parameter and returns the maximum sum between 2 special nodes.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
```

### Constraints
`2  ≤  Number of nodes  ≤  10^4`
`-10^3  ≤ Value of each node ≤ 10^3`

## Solution

```Cpp

class Solution {
public:
    // Function to calculate the maximum path sum from a node to any leaf node in the tree
    int pathSum(Node* root, int &sum) {
        if (!root) {
            return 0;   // No contribution to path sum if the node is NULL
        }

        // If the current node is a leaf (no children), its path sum is just its own value
        if (!root->left && !root->right) {
            return root->data;
        }

        // Recursively calculate the maximum path sum starting from the left and right subtrees
        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);

        // Check if both left and right subtrees exist
        if (root->left && root->right) {
            // Update the current maximum path sum (considering both subtrees)
            sum = max(sum, root->data + left + right);
            // Return the maximum path sum found from the current node (including the current node's value)
            // considering either the left or right subtree (whichever has a higher path sum)
            return root->data + max(left, right);
        }

        // If only the left subtree exists, return the path sum including the current node and the left subtree
        if (root->left) {
            return root->data + left;
        }

        // If only the right subtree exists, return the path sum including the current node and the right subtree
        if (root->right) {
            return root->data + right;
        }
    }

    // Function to find the maximum path sum from any node to any leaf node in the entire tree
    int maxPathSum(Node* root) {
    int sum = INT_MIN;                // Initialize to negative infinity to ensure first encountered path sum becomes the initial maximum
    int ans = pathSum(root, sum);     // Recursively calculate the maximum path sum and update the 'sum' reference

    // Edge case: if the root is not a leaf node, that means root node not a special node.
    if (root->left && root->right) {
        return sum;     // Return the overall maximum path sum found during the recursive calls
    }

    // Otherwise, return the maximum of the overall maximum sum and the maximum path sum starting from the root.
    return max(sum, ans);
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```