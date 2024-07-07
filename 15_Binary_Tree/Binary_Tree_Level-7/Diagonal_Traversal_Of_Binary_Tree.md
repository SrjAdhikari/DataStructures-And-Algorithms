# Question : [Diagonal Traversal of Binary Tree - GFG](https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1)

Given a Binary Tree, print the **diagonal traversal** of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

### Example 1
```
Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4
```
Explanation:
![](https://contribute.geeksforgeeks.org/wp-content/uploads/diagonal.jpg)
Diagonal Traversal of binary tree : 
 8 10 14 3 6 7 13 1 4

### Your Task:
You don't need to read input or print anything. The task is to complete the function **diagonal()** that takes the root node as input argumets and returns the diagonal traversal of the given tree.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).
```

### Constraints
`1 <= Number of nodes<= 10^5`
`1 <= Data of a node<= 105`

## Solution 1

```Cpp
Using Pre-order Travesal : 

class Solution {
public:
    // Function to find the maximum leftmost position (depth) in the binary tree
    void findPosition(Node* root, int position, int& left) {
    if (!root) {
        // Base case: Empty subtree, nothing to explore further
        return;
    }

    // Update left with the maximum between current position and current left
    left = max(position, left);

    // Explore left subtree with increased depth (go down)
    findPosition(root->left, position + 1, left);

    // Explore right subtree with the same depth (go right) - doesn't affect leftmost position
    findPosition(root->right, position, left);
    }

    // Function to recursively traverse the tree and populate a 2D vector with diagonal elements
    void findDiagonal(Node* root, int pos, vector<vector<int>>& ans) {
        if (!root) {
            // Base case: Empty subtree, nothing to explore further
            return;
        }
        
        // Add current node's data to the corresponding depth (row) in the diagonal vector
        ans[pos].push_back(root->data);

        // Explore left subtree with increased depth (go down)
        findDiagonal(root->left, pos + 1, ans);

        // Explore right subtree with the same depth (go right) - to fill elements on the same diagonal level
        findDiagonal(root->right, pos, ans);
    }

    // Main function to find diagonal elements of the binary tree
    vector<int> diagonal(Node *root) {

        int leftPos = 0;    // Initialize to store the maximum leftmost position
        int position = 0;   // Starting depth

        // Find the maximum leftmost position in the tree
        findPosition(root, position, leftPos);

        // Create a 2D vector to store diagonal elements (size based on leftmost position)
        vector<vector<int>> ans(leftPos + 1);

        // Populate the 2D vector with diagonal elements using recursive traversal
        findDiagonal(root, position, ans);

        // Temporary vector to combine diagonal elements into a single-dimensional format
        vector<int> temp;

        // Combine diagonal elements from the 2D vector into a single vector
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
            temp.push_back(ans[i][j]);
            }
        }

        // Return the final vector containing all diagonal elements
        return temp;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```

## Solution 2

```Cpp
Using Level Order Travesal: 

class Solution {
public:
    // This function takes a pointer to a binary tree node (`root`) as input
    // and returns a vector containing the diagonal elements of the tree.
    vector<int> diagonal(Node *root) {

        vector<int> ans;  // Initialize an empty vector `ans` to store the diagonal elements

        if (!root) {
            // If the root node is NULL (empty tree), the diagonal is empty, so return the empty vector
            return ans;
        }

        queue<Node*> q;         // Create a queue to perform a level-order traversal
        q.push(root);           // Push the root node into the queue

        while (!q.empty()) {    // Loop continues as long as there are nodes remaining in the queue

            Node* front = q.front();  // Get the first node in the queue (current level)
            q.pop();                  // Remove the front node from the queue

            while (front != NULL) {             // Process the current node and its right children (diagonal elements)

                ans.push_back(front->data);     // Add the current node's data to the result vector

                if (front->left) {
                    // If the current node has a left child,
                    // it doesn't belong to the diagonal but needs to be processed later
                    // so push it back into the queue for level-order traversal
                    q.push(front->left);
                }

                front = front->right;  // Move to the next node in the current level (go right)
            }
        }
        return ans;  // Return the vector containing the diagonal elements
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```