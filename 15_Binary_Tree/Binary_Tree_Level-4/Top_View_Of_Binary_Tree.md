# Question : [Top View of Binary Tree - GFG](https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1)

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

          1
        /   \
       2     3
      / \   / \
     4   5 6   7 
 
Top view will be: 4 2 1 3 7

**Note**: Return nodes from **leftmost** node to **rightmost** node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

### Example 1
```
Input:
   1
 /  \
2    3
Output: 2 1 3
```

### Example 2
```
Input:
      10
    /    \
  20     30
 /  \   /  \
40  60 90  100
Output: 40 20 10 30 100
```
### Your Task:
Since this is a function problem. You don't have to take input. Just complete the function **topView()** that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

```
Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N).
```

### Constraints
`1 ≤ N ≤ 10^5`
`1 ≤ Node Data ≤ 10^5`

## Solution 1

```Cpp
Using Level Order Travesal : 

class Solution {
public:
    void findPosition(Node* root, int position, int& leftPos, int& rightPos) {

        // Base case: If the root is null, return
        if (!root)
            return;

        // Update the leftmost and rightmost positions
        leftPos = min(position, leftPos);       // Update leftPos if the current position is smaller
        rightPos = max(position, rightPos);     // Update rightPos if the current position is larger

        // Recur for the left subtree with the position decremented by 1
        findPosition(root->left, position - 1, leftPos, rightPos);

        // Recur for the right subtree with the position incremented by 1
        findPosition(root->right, position + 1, leftPos, rightPos);
    }

    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        
        // Variables to track the leftmost and rightmost positions
        int leftPos = 0, rightPos = 0;

        // Find the range of positions for the top view
        findPosition(root, 0, leftPos, rightPos);

        // Initialize the answer vector with the size of the range of positions
        vector<int> ans(rightPos - leftPos + 1);

        // Initialize a visited vector to mark positions that have been filled
        vector<bool> visited(rightPos - leftPos + 1, 0);

        // Queues for BFS traversal
        queue<Node*> q;         // Queue to hold nodes
        queue<int> index;       // Queue to hold corresponding positions

        // Initialize the queues with the root node and its position
        q.push(root);
        index.push(-1 * leftPos);   // Normalize the position to start from 0

        // Perform BFS traversal
        while (!q.empty()) {
            // Get the front node and its position
            Node* front = q.front();
            q.pop();

            int pos = index.front();
            index.pop();

            // If the position has not been visited, add the node to the result
            if (!visited[pos]) {
                visited[pos] = 1;
                ans[pos] = front->data;  // Store the node's data in the result
            }

            // If the front node has a left child, add it to the queue
            if (front->left) {
                q.push(front->left);
                index.push(pos - 1);  // Decrement position for left child
            }

            // If the front node has a right child, add it to the queue
            if (front->right) {
                q.push(front->right);
                index.push(pos + 1);  // Increment position for right child
            }
        }

        // Return the top view of the binary tree
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
    // Helper function to find the leftmost and rightmost positions in the tree
    void findPosition(Node* root, int position, int& leftPos, int& rightPos) {

        // Base case: If the root is null, return
        if (!root)
            return;

        // Update the leftmost and rightmost positions
        leftPos = min(position, leftPos);       // Update leftPos if the current position is smaller
        rightPos = max(position, rightPos);     // Update rightPos if the current position is larger

        // Recur for the left subtree with the position decremented by 1
        findPosition(root->left, position - 1, leftPos, rightPos);

        // Recur for the right subtree with the position incremented by 1
        findPosition(root->right, position + 1, leftPos, rightPos);
    }

    // Helper function to populate the top view of the binary tree
    void topViewHelper(Node* root, int position, vector<int>& ans, vector<int>& level, int currLevel) {

        // Base case: If the root is null, return
        if (!root)
            return;

        // If the current level is less than the recorded level at this position, update the view
        if (level[position] > currLevel) {
            ans[position] = root->data;         // Store the node's data in the result
            level[position] = currLevel;        // Update the level for this position
        }

        // Recur for the left subtree with the position decremented by 1 and level incremented by 1
        topViewHelper(root->left, position - 1, ans, level, currLevel + 1);

        // Recur for the right subtree with the position incremented by 1 and level incremented by 1
        topViewHelper(root->right, position + 1, ans, level, currLevel + 1);
    }

    // Function to return a list of nodes visible from the top view 
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {

        int leftPos = 0, rightPos = 0;                          // Variables to track the leftmost and rightmost positions
        findPosition(root, 0, leftPos, rightPos);               // Find the range of positions for the top view
        vector<int> ans(rightPos - leftPos + 1);                // Initialize the answer vector with the size of the range of positions
        vector<int> level(rightPos - leftPos + 1, INT_MAX);     // Initialize a level vector to keep track of the smallest level for each position
        topViewHelper(root, -1 * leftPos, ans, level, 0);       // Populate the top view using the helper function
        return ans;                                             // Return the top view of the binary tree
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```

## Solution 3

```Cpp
Using Level Order Travesal & Map: 

class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> ans;

        // Check if the root is null, if yes, return an empty vector
        if (root == NULL) 
            return ans;

        // Declare a map to store the first node's data at each horizontal distance
        map<int, int> mapping;

        // Declare a queue to perform level order traversal. Each element in the queue
        // is a pair where the first element is the node and the second element is its 
        // horizontal distance from the root
        queue<pair<Node*, int>> q;

        // Push the root node with a horizontal distance of 0 into the queue
        q.push({root, 0});

        // Continue level order traversal until the queue is empty
        while (!q.empty()) {
            // Get the front element of the queue and pop it
            pair<Node*, int> pair = q.front();
            q.pop();

            // Get the node and its horizontal distance from the pair
            Node* front = pair.first;
            int level = pair.second;

            // If this horizontal distance is not already in the map, add it with
            // the current node's data (this ensures only the topmost node at this
            // horizontal distance is recorded)
            if (mapping.find(level) == mapping.end()) {
                mapping[level] = front->data;
            }

            // If the left child exists, push it into the queue with a horizontal 
            // distance decreased by 1
            if (front->left)
                q.push({front->left, level - 1});

            // If the right child exists, push it into the queue with a horizontal 
            // distance increased by 1
            if (front->right)
                q.push({front->right, level + 1});
        }

        // Fill the ans vector with the top view nodes in the correct order
        for (auto node : mapping) {
            ans.push_back(node.second);
        }

        return ans;
    }
};

Time Complexity = O(NlogN)
Space Complexity = O(N)
```