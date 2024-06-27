# Question : [Check If Two Nodes Are Cousins - GFG](https://www.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1)

Given a binary tree (having **distinct** node values) and two node values. Check whether the two node values are **cousins** of each other or not.

**Note**: Two nodes of a binary tree are **cousins** if they have the same depth with different parents.

### Example 1

```
Input:
      1
    /   \
   2     3
a = 2, b = 3
Output: false
Explanation: Here, nodes 2 and 3 areat the same level but have sameparent nodes.
```

### Example 2

```
Input:
       1
     /   \
    2     3
   /       \
  5         4
a = 5, b = 4
Output: True
Explanation: Here, nodes 5 and 4 areat the same level and have differentparent nodes. Hence, they both are cousins
```

### Your task

You don't need to read input or print anything. Your task is to complete the function **isCousins()** that takes the tree's root node, and two integers 'a' and 'b' as inputs. It returns true if the nodes with given values 'a' and 'b' are Cousins of each other and returns false otherwise.

```
Expected Time Complexity: O(Number of Nodes).
Expected Auxiliary Space: O(Number of Nodes).
```

### Constraints

`1 <= Number of nodes <= 10^5`

## Solution

```Cpp

class Solution {
public:
    // Helper function to check if nodes with values 'a' and 'b' are siblings
    // or direct children of the same parent in the binary tree.
    bool findParent(Node* root, int a, int b) {

        if (!root)      // Base case: if root is null, return false
            return 0;

        // If both left and right children of root exist
        if (root->left && root->right) {
            // Check if the left child is 'a' and the right child is 'b'
            if(root->left->data == a && root->right->data == b)
                return 1;

            // Check if the left child is 'b' and the right child is 'a'
            if(root->left->data == b && root->right->data == a)
                return 1;
        }

        // Recursively search in the left and right subtrees
        return findParent(root->left, a, b) || findParent(root->right, a, b);
    }


    // This function checks if two nodes with values 'a' and 'b' are cousins in a binary tree.
    // Cousins are nodes at the same level but have different parents.
    // It uses a BFS approach to determine the levels of nodes 'a' and 'b', and then verifies
    // if they are at the same level and do not share the same parent.
    bool isCousins(Node *root, int a, int b) {

        // If the tree has no left or right child, return false
        if (!root->left && !root->right)
            return false;

        queue<Node*> q;                     // Queue for level order traversal
        q.push(root);                       // Push the root node to the queue

        int l1 = -1, l2 = -1;               // Initialize levels of nodes 'a' and 'b' to -1
        int level = 0;                      // Current level of the BFS traversal (Level-order Traversal)

        // Perform level order traversal using BFS to find nodes 'a' and 'b' and determine their levels
        while (!q.empty()) {
            int size = q.size();            // Get the number of nodes at the current level

            // Traverse all nodes at the current level
            while (size--) {
                Node* front = q.front();    // Get the front node from the queue
                q.pop();                    // Remove the front node from the queue

                // Check if current node is 'a' or 'b' and update their levels
                if (front->data == a)
                    l1 = level;             // Update level of node 'a'

                if (front->data == b)
                    l2 = level;             // Update level of node 'b'

                // Push left and right children into the queue if they exist
                if (front->left)
                    q.push(front->left);    // Push left child into the queue

                if (front->right)
                    q.push(front->right);   // Push right child into the queue
            }

            // Increment the level after processing all nodes at the current level (Move to the next level)
            level++;

            // If 'a' and 'b' are found at different levels, they can't be cousins
            if (l1 != l2)
                return 0;

            // If both 'a' and 'b' are found, no need to continue further
            if (l1 != -1 && l2 != -1)
                break;                      // Break the loop if both 'a' and 'b' are found at the same level
        }

        // Check if 'a' and 'b' are not siblings (same parent) using findParent function
        // Returns true if they are not siblings (i.e., they are cousins)
        return !findParent(root, a, b);     // Return true if 'a' and 'b' are cousins
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```
