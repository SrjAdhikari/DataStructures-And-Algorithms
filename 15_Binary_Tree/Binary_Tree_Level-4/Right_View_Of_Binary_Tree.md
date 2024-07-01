# Question : [Right View of Binary Tree - GFG](https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1)

Given a Binary Tree, find **Right view** of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
        /   \
       2     3
      / \   / \
     4   5 6   7
      \
       8   

### Example 1
```
Input:
   1
 /  \
3    2
Output: 1 2
```

### Example 2
```
Input:
     10
    /  \
   20    30
  / \
 40  60 
Output: 10 30 60
```
### Your Task:
Just complete the **function rightView()** that takes **node** as **parameter** and returns the right view as a list. 

```
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
```

### Constraints
`1 ≤ Number of nodes ≤ 10^5`
`0 ≤ Data of a node ≤ 10^5`

## Solution 1

```Cpp
Using Level Order Travesal : 

class Solution {
public:
    vector<int> rightView(Node *root) {

        queue<Node*> q;         // Queue to perform level order traversal (BFS)
        vector<int> ans;        // Vector to store the right view elements
        if (!root)              // If the root is null, return an empty vector
            return ans;
        
        q.push(root);           // Push the root node in the queue        
        
        // Perform level order traversal until the queue is empty
        while (!q.empty()) {
            
            ans.push_back(q.front()->data);     // Add the first node of each level to the result (right view)
            int n = q.size();                   // Number of nodes at the current level
            
            // Process all nodes at the current level
            while (n--) {
                Node* front = q.front();    // Get the front node from the queue
                q.pop();                    // Remove the front node from the queue
                
                // If the front node has a right child, add it to the queue
                if (front->right)
                    q.push(front->right);

                // If the front node has a left child, add it to the queue
                if (front->left)
                    q.push(front->left);
            }
        }
        
        // Return the right view of the binary tree
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```

## Solution 2

```Cpp
Using Recursion : 

class Solution {
public:
    // Helper function to compute the right view of the binary tree recursively
    void rightViewHelper(Node* root, int level, vector<int>& ans) {

        if (!root)                      // Base case: If the root is null, return
            return;
        
        if (level == ans.size())        // If this is the first node of its level, add it to the result
            ans.push_back(root->data);
        
        // Recursively visit right subtree first, then left subtree
        rightViewHelper(root->right, level + 1, ans);
        rightViewHelper(root->left, level + 1, ans);
    }

    // Function to return a list containing elements of the right view of the binary tree
    vector<int> leftView(Node *root) {
        vector<int> ans;                    // Vector to store the right view elements
        if (!root)                          // If the root is null, return an empty vector
            return ans;
        rightViewHelper(root, 0, ans);       // Initialize the helper function with the root node at level 0
        return ans;                         // Return the right view of the binary tree
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```