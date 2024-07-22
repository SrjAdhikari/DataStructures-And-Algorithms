# Question : [Print BST elements in given range - GFG](https://www.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1)

Given a Binary Search Tree and a range **[low, high]**. Find all the numbers in the BST that lie in the given range.
**Note**: Element greater than or equal to root go to the right side.

### Example 1
```
Input:
       17
     /    \
    4     18
  /   \
 2     9 
l = 4, h = 24
Output: 4 9 17 18 
```

### Example 2
```
Input:
       16
     /    \
    7     20
  /   \
 1    10
l = 13, h = 23
Output: 16 20 
```

### Your Task:
You don't need to read input or print anything. Your task is to complete the function **printNearNodes()** which takes the root Node of the BST and the range elements low and high as inputs and returns an array that contains the BST elements in the given range low to high (inclusive) in **non-decreasing order**.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the BST)
```

### Constraints
`1 ≤ Number of nodes ≤ 10^4`
`1 ≤ l ≤ h ≤ 10^5`

## Solution

```Cpp

class Solution {
public:
    // Function to find elements within a given range in a binary search tree (BST)
    void findElement(Node* root, vector<int>& ans, int low, int high) {
        // Base case: if the current node is null, return
        if(!root)
            return;
        
        // If the current node's value is greater than both low and high,
        // then the target range must lie in the left subtree
        if(root->data > low && root->data > high)
            findElement(root->left, ans, low, high);
            
        // If the current node's value is less than both low and high,
        // then the target range must lie in the right subtree
        else if(root->data < low && root->data < high)
            findElement(root->right, ans, low, high);
        
        // If the current node's value is within the range [low, high],
        // process the left subtree, add the current node's value to the result,
        // and then process the right subtree
        else {
            findElement(root->left, ans, low, high);
            ans.push_back(root->data);
            findElement(root->right, ans, low, high);
        }
    }

    // Wrapper function to initialize the result vector and start the search
    vector<int> printNearNodes(Node *root, int low, int high) {
        // Create an empty vector to store the nodes within the range (low to high).
        vector<int> ans;
        findElement(root, ans, low, high);
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```