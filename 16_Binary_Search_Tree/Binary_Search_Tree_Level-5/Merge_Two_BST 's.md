# Question : [Merge two BST 's - GFG](https://www.geeksforgeeks.org/problems/merge-two-bst-s/1)

Given two BSTs, return elements of merged BSTs in **sorted** form.

### Example 1
```
Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
```

### Example 2
```
Input:
BST1:
      12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
```

```
Expected Time Complexity: O(m+n)
Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)
```

### Constraints
`1 ≤ Number of Nodes ≤ 10^5`

## Solution

```Cpp

class Solution {
public:
    // Function to perform in-order traversal on a BST and store node values in a vector.
    void inorder(Node* root, vector<int>& ans) {
        // Base case: If the current node is NULL (empty subtree), return.
        if (!root) {
            return;
        }

        // Recursive call: Perform in-order traversal on the left subtree.
        inorder(root->left, ans);

        // Add the current node's data to the result vector.
        ans.push_back(root->data);

        // Recursive call: Perform in-order traversal on the right subtree.
        inorder(root->right, ans);
    }

    // Function to merge two BSTs into a single sorted list.
    vector<int> merge(Node* root1, Node* root2) {
        // Create two temporary vectors `ans1` and `ans2` to store in-order traversals of BSTs.
        vector<int> ans1;
        vector<int> ans2;

        // Perform in-order traversal on `root1` and store values in `ans1`.
        inorder(root1, ans1);

        // Perform in-order traversal on `root2` and store values in `ans2`.
        inorder(root2, ans2);

        // Create the final result vector `ans` to store the merged sorted list.
        vector<int> ans;

        // Initialize two pointers `i` and `j` to iterate through `ans1` and `ans2`.
        int i = 0, j = 0;

        // Merge elements from both vectors while maintaining sorted order.
        while (i < ans1.size() && j < ans2.size()) {
            // If the element in `ans1` is smaller, add it to `ans` and increment `i`.
            if (ans1[i] < ans2[j]) {
                ans.push_back(ans1[i++]);
            } 
            else {
                // If the element in `ans2` is smaller, add it to `ans` and increment `j`.
                ans.push_back(ans2[j++]);
            }
        }

        // Add remaining elements from `ans1` (if any) to `ans` after `ans2` is exhausted.
        while (i < ans1.size()) {
            ans.push_back(ans1[i++]);
        }

        // Add remaining elements from `ans2` (if any) to `ans` after `ans1` is exhausted.
        while (j < ans2.size()) {
            ans.push_back(ans2[j++]);
        }

        // Return the final merged sorted list.
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```