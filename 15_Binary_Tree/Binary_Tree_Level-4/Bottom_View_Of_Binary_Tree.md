# Question : [Bottom View of Binary Tree - GFG](https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)

Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

          20
        /    \
       8      22
     /   \      \
    5     3      25
        /   \      
       10    14

For the above tree, the bottom view is 5 10 3 14 25.

If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

           20
        /    \
       8      22
     /   \   /  \
    5     3 4    25
         /   \      
        10    14

For the above tree the output should be 5 10 4 14 25.

**Note**: The **Input/Output** format and **Example** given are used for the system's internal purpose, and should be used by a user for **Expected Output** only. As it is a function problem, hence a user should not read any input from the stdin/console. The task is to complete the function specified, and not to write the full code.

### Example 1
```
Input:
   1
 /  \
3    2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.
```
![](https://contribute.geeksforgeeks.org/wp-content/uploads/BT-1.jpg)
Thus nodes of the binary tree will be
printed as such 3 1 2.

### Example 2
```
Input:
      10
    /    \
  20     30
 /  \
40  60
Output: 40 20 60 30
```
### Your Task:
This is a functional problem, you **don't** need to care about input, just complete the function **bottomView()** which takes the root node of the tree as input and returns an array containing the bottom view of the given tree.

```
Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N).
```

### Constraints
`1 <= Number of nodes <= 10^5`
`1 <= Data of a node <= 10^5`

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

    // Function to return a list of nodes visible from the bottom view
    // from left to right in Binary Tree.
    vector<int> bottomView(Node *root) {
        // Variables to track the leftmost and rightmost positions
        int leftPos = 0, rightPos = 0;

        // Find the range of positions for the bottom view
        findPosition(root, 0, leftPos, rightPos);

        // Initialize the answer vector with the size of the range of positions
        vector<int> ans(rightPos - leftPos + 1);

        // Initialize a visited vector to mark positions that have been filled
        vector<bool> visited(rightPos - leftPos + 1);

        // Queues for BFS traversal
        queue<Node*> q;     // Queue to hold nodes
        queue<int> index;   // Queue to hold corresponding positions

        // Initialize the queues with the root node
        q.push(root);
        index.push(-1 * leftPos);  // Normalize the position to start from 0

        // Perform BFS traversal
        while (!q.empty()) {

            Node* front = q.front();         // Get the front node from the queue
            int pos = index.front();        // Get the corresponding position from the queue
            q.pop();                        // Remove the front node from the queue
            index.pop();                    // Remove the corresponding position from the queue

            // Update the view with the current node's data (always take the latest node at each position -> Overwrite the latest node)
            visited[pos] = true;
            ans[pos] = front->data;

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

        // Return the bottom view of the binary tree
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

    // Helper function to populate the bottom view of the binary tree
    void bottomViewHelper(Node* root, int position, vector<int>& ans, vector<int>& level, int currLevel) {

        // Base case: If the root is null, return
        if (!root)
            return;

        // Update the view if the current level is greater or equal to the recorded level at this position
        // This ensures the bottom-most node is considered
        if (level[position] <= currLevel) {
            ans[position] = root->data;     // Store the node's data in the result
            level[position] = currLevel;    // Update the level for this position
        }

        // Recur for the left subtree with the position decremented by 1 and level incremented by 1
        bottomViewHelper(root->left, position - 1, ans, level, currLevel + 1);

        // Recur for the right subtree with the position incremented by 1 and level incremented by 1
        bottomViewHelper(root->right, position + 1, ans, level, currLevel + 1);
    }

    // Function to return a list of nodes visible from the bottom view 
    // from left to right in Binary Tree.
    vector<int> bottomView(Node *root) {

        // Variables to track the leftmost and rightmost positions
        int leftPos = 0, rightPos = 0;

        // Find the range of positions for the bottom view
        findPosition(root, 0, leftPos, rightPos);

        // Initialize the answer vector with the size of the range of positions
        vector<int> ans(rightPos - leftPos + 1);

        // Initialize a level vector to keep track of the greatest level for each position
        vector<int> level(rightPos - leftPos + 1, INT_MIN);

        // Populate the bottom view using the helper function
        bottomViewHelper(root, -1 * leftPos, ans, level, 0);

        // Return the bottom view of the binary tree
        return ans;
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

            // Update the mapping with the data of the current node at the given horizontal distance (level). If level already exists in mapping, the existing value is overwritten with the data of the current node. This ensures that the node processed last at each horizontal distance (which will be the bottommost node when viewed from the top) is the one stored in the map.
            mapping[level] = front->data;


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