# Question : [Left View of Binary Tree - GFG](https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1)

Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function **leftView()**, which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

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
Output: 1 3
```

### Example 2
Input:
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190221103723/leftview.jpg)
Output: 10 20 40

```
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
```

### Constraints
`0 <= Number of nodes <= 100`
`0 <= Data of a node <= 1000`

## Solution 1

```Cpp
Using Level Order Travesal : 

class Solution {
public:
    vector<int> leftView(Node *root) {

        queue<Node*> q;         // Queue to perform level order traversal (BFS)
        vector<int> ans;        // Vector to store the left view elements
        if (!root)              // If the root is null, return an empty vector
            return ans;
        
        q.push(root);           // Push the root node in the queue        
        
        // Perform level order traversal until the queue is empty
        while (!q.empty()) {
            
            ans.push_back(q.front()->data);     // Add the first node of each level to the result (left view)
            int n = q.size();                   // Number of nodes at the current level
            
            // Process all nodes at the current level
            while (n--) {
                Node* front = q.front();    // Get the front node from the queue
                q.pop();                    // Remove the front node from the queue
                
                // If the front node has a left child, add it to the queue
                if (front->left)
                    q.push(front->left);
                
                // If the front node has a right child, add it to the queue
                if (front->right)
                    q.push(front->right);
            }
        }
        
        // Return the left view of the binary tree
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
    // Helper function to compute the left view of the binary tree recursively
    void leftViewHelper(Node* root, int level, vector<int>& ans) {
        // Base case: If the root is null, return
        if (!root)
            return;
        
        // If this is the first node of its level, add it to the result
        if (level == ans.size())
            ans.push_back(root->data);
        
        // Recursively visit left subtree first, then right subtree
        leftViewHelper(root->left, level + 1, ans);
        leftViewHelper(root->right, level + 1, ans);
    }

    // Function to return a list containing elements of the left view of the binary tree
    vector<int> leftView(Node *root) {
        vector<int> ans;                    // Vector to store the left view elements
        if (!root)                          // If the root is null, return an empty vector
            return ans;
        leftViewHelper(root, 0, ans);       // Initialize the helper function with the root node at level 0
        return ans;                         // Return the left view of the binary tree
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```