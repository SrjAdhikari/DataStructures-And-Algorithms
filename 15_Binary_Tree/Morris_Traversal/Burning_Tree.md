# Question : [Burning Tree - GFG](https://www.geeksforgeeks.org/problems/burning-tree/1)

Given a binary tree and a **node data** called **target**. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
**Note**: The tree contains unique values.

### Example 1
```
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
```

### Example 2
```
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5
```

```
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of tree)
```

### Constraints
`1 <= n <= 10^4`

## Solution

```Cpp

class Solution {
public:

    // Positive number indicate the Height of tree.
    // Negative number indicate the time to burn the tree.

    // Function to calculate the minimum time required to burn a target node in a binary tree
    int burnTree(Node* root, int &time, int target) {
        if (!root)                      // If the current node is NULL, it doesn't contribute to burning time
            return 0;

        if (root->data == target)       // If the current node is the target, immediate burning occurs (no time required)
            return -1;

        // Recursively call burnTree on the left and right subtrees to find the target and calculate burning times
        int left = burnTree(root->left, time, target);
        int right = burnTree(root->right, time, target);

        // Burning from the left subtree
        if (left < 0) {
            time = max(time, abs(left) + right);    // Update time with the maximum of current time and combined burning time from left and right subtrees
            return left - 1;                        // Return burning time from current node to target in left subtree
        }

        // Burning from the right subtree (similar logic as left)
        if (right < 0) {
            time = max(time, left + abs(right));    // Update time with the maximum of current time and combined burning time from right and left subtrees
            return right - 1;                       // Return burning time from current node to target in the right subtree
        }

        // If neither subtree has the target, calculate burning time from the current node
        return 1 + max(left, right);                // 1 for burning the current node, + max burning time from left or right subtree
    }

    // Function to find the node in the tree with the data value matching the target (Node where the fire starts)
    void findBurnNode(Node* root, int target, Node* &burnNode) {
        if (!root)                      // If the current node is NULL, no further search is needed
            return;

        if (root->data == target) {     // If the current node's data matches the target
            burnNode = root;            // Set burnNode to the found target node
            return;                     // Stop further search
        }

        // Recursively search for the target in the left and right subtrees
        findBurnNode(root->left, target, burnNode);
        findBurnNode(root->right, target, burnNode);
    }

    // Function to calculate the height of the binary tree below the node where the fire starts
    int burnNodeHeight(Node* root) {
        if (!root)      // If the current node is NULL, it's an empty tree with height 0
            return 0;

        // Recursively find the heights of the left and right subtrees
        int left = burnNodeHeight(root->left);
        int right = burnNodeHeight(root->right);

        // Return the height of the tree rooted at the current node (1 for current node + max height of left or right subtree)
        return 1 + max(left, right);
    }

    // Function to calculate the minimum time required to burn the target node in the tree
    int minTime(Node* root, int target) {
        int time = 0;   // Initialize burning time to 0

        // Call burnTree to calculate the maximum burning time encountered during recursion
        burnTree(root, time, target);

        Node* burnNode = NULL;                      // Initialize a pointer to store the target node
        findBurnNode(root, target, burnNode);       // Find the target node

        // If no target node is found, return -1 (error handling)
        if (!burnNode)
            return -1;

        // Calculate the height of the subtree rooted at the target node
        int height = burnNodeHeight(burnNode) - 1;  // Subtract 1 to exclude the target node itself

        // Return the maximum of the burning time and the height of the target node's subtree
        return max(time, height);
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```