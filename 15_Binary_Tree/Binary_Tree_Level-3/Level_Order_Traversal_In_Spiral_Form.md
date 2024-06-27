# Question : [Level Order Traversal In Spiral Form - GFG](https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1)

Given a binary tree and the task is to find the spiral order traversal of the tree.

**Spiral order Traversal mean**: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right.

For below tree, function should return 1, 2, 3, 4, 5, 6, 7.

![](https://contribute.geeksforgeeks.org/wp-content/uploads/level.jpg)

### Example 1

```
Input:
      1
    /   \
   3     2
Output:1 3 2
```

### Example 2

```
Input:
           10
         /    \
        20     30
      /   \
    40     60
Output: 10 20 30 60 40
```

### Your task

The task is to complete the function **findSpiral()** which takes **ot** node as input parameter and returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.

```
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
```

### Constraints

`1 <= Number of nodes <= 10^5`<br>
`0 <= Data of a node <= 10^5`

## Solution

```Cpp

class Solution {
public:
    //Function to return a list containing the level order traversal in spiral form.
    vector<int> findSpiral(Node *root) {

        // Two stacks to alternate levels in spiral order
        stack<Node*> s1;        // Stack for odd levels (root, right, left -> Right To Left)
        stack<Node*> s2;        // Stack for even levels (root, left, right -> Left To Right)

        s1.push(root);          // Start with the root in s1
        vector<int> ans;        // Vector to store the spiral order

        // Process until both stacks are empty
        while (!s1.empty() || !s2.empty()) {

            if (!s1.empty()) {
                // Process nodes in s1 (odd levels)
                while (!s1.empty()) {
                    Node* front = s1.top();         // Get the top node
                    s1.pop();                       // Pop the top node
                    ans.push_back(front->data);     // Push its data to result vector

                    // Push right child first and then left child to s2
                    if (front->right)
                        s2.push(front->right);

                    if (front->left)
                        s2.push(front->left);
                }
            }
            else {
                // Process nodes in s2 (even levels)
                while (!s2.empty()) {

                    Node* front = s2.top();         // Get the top node
                    s2.pop();                       // Pop the top node
                    ans.push_back(front->data);     // Push its data to result vector

                    // Push left child first and then right child to s1
                    if (front->left)
                        s1.push(front->left);

                    if (front->right)
                        s1.push(front->right);
                }
            }
        }

        return ans;     // Return the final spiral order vector
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```
