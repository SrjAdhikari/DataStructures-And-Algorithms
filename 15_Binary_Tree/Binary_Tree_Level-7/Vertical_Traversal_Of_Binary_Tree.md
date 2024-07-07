# Question : [Vertical Traversal of Binary Tree - GFG](https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1)

Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in **level order** traversal of the tree.

### Example 1
```
Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9
```
Explanation:
![](https://media.geeksforgeeks.org/img-practice/ScreenShot2021-05-28at3-1622541589.png)

### Example 2
```
Input:
      1
    /   \
   2     3
 /  \     \
4    5     6
Output: 4 2 1 5 3 6
```
### Your Task:
You don't need to read input or print anything. Your task is to complete the function **verticalOrder()** which takes the root node as input parameter and returns an array containing the vertical order traversal of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.

```
Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N).
```

### Constraints
`1 <= Number of nodes <= 3*10^4`

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

    vector<int> verticalOrder(Node *root) {
        // Initialize variables to track the leftmost and rightmost positions
        int leftPos = 0, rightPos = 0; 
        
        // Find the horizontal positions of the leftmost (`leftPos`) and rightmost (`rightPos`) nodes
        findPosition(root, 0, leftPos, rightPos);    
        
        // Initialize vectors to store nodes at positive and negative horizontal positions
        // positive[i] will store nodes at horizontal position i (from 0 to rightPos)
        vector<vector<int>> positive(rightPos + 1);             
        // negative[i] will store nodes at horizontal position -i (from 0 to abs(leftPos))
        vector<vector<int>> negative(abs(leftPos) + 1);     
        
        // Queue to perform level order traversal of the tree
        queue<Node*> q; 
        q.push(root);
        
        // Queue to track horizontal positions corresponding to nodes in the tree
        queue<int> index; 
        index.push(0);
        
        // Perform level order traversal
        while(!q.empty()) {
            // Get the front node from the queue
            Node* front = q.front();
            q.pop();
            
            // Get the horizontal position of the node
            int position = index.front();
            index.pop();
            
            // Store the node's data in the appropriate vector based on its horizontal position
            if(position >= 0)
                positive[position].push_back(front->data);
            else
                negative[abs(position)].push_back(front->data);
                
            // Enqueue left child with its updated horizontal position
            if(front->left){
                q.push(front->left);
                index.push(position - 1);
            }
            
            // Enqueue right child with its updated horizontal position
            if(front->right){
                q.push(front->right);
                index.push(position + 1);
            }
        }
        
        // Merge data from negative and positive vectors into a single result vector (`ans`)
        vector<int> ans;
        
        // Append data from negative positions in reverse order (bottom-up)
        for(int i = negative.size() - 1; i > 0; i--){
            for(int j = 0; j < negative[i].size(); j++){
                ans.push_back(negative[i][j]);
            }
        }
        
        // Append data from positive positions in order (top-down)
        for(int i = 0; i < positive.size(); i++){
            for(int j = 0; j < positive[i].size(); j++){
                ans.push_back(positive[i][j]);
            }
        }
            
        // Return the final vertical order traversal of the binary tree
        return ans;                                            
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```

## Solution 2

```Cpp
Using Level Order Travesal & Map: 

class Solution {
public:
    vector<int> verticalOrder(Node *root) {
        vector<int> ans;  // This will store the final result of nodes in vertical order
        
        if (!root)
            return ans;  // Return an empty vector when root is NULL
        
        // This map is used to store nodes grouped by their vertical levels. Each key (int) represents a vertical level, and the corresponding value (vector<int>) is a vector that stores node values at that level.
        map<int, vector<int>> verticalMap;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});  // Push the root node with its level (0) into the queue
        
        // BFS traversal to populate the verticalMap
        while (!q.empty()) {
            pair<Node*, int> current = q.front();
            q.pop();
            
            Node* node = current.first;  // Get the node
            int level = current.second;  // Get the level
            
            // Store the node's data in the corresponding level vector
            verticalMap[level].push_back(node->data);
            
            // Process left child (level - 1) if it exists
            if (node->left)
                q.push({node->left, level - 1});
            
            // Process right child (level + 1) if it exists
            if (node->right)
                q.push({node->right, level + 1});
        }
        
        // Now, verticalMap contains nodes grouped by their vertical levels
        // Traverse the map and collect nodes in vertical order
        for (auto& node : verticalMap) {
            for (int value : node.second) {
                ans.push_back(value);  // Collect nodes' data in the result vector
            }
        }
        return ans;  // Return the final vertical order traversal
    }
};

Time Complexity = O(NlogN)
Space Complexity = O(N)
```