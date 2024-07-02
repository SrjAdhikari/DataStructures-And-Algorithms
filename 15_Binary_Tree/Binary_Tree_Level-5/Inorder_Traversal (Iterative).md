# Question : [Inorder Traversal (Iterative) - GFG](https://www.geeksforgeeks.org/problems/inorder-traversal-iterative/1)

Given a Binary tree. Find the inorder traversal of the tree **without using recursion**.

### Example 1
```
Input:
           1
         /   \
        2     3
      /  \
     4    5
Output: 4 2 5 1 3
Explanation:
Inorder traversal (Left->Root->Right) of 
the tree is 4 2 5 1 3.
```

### Example 2
```
Input:
            8
          /   \
         1      5
          \    /  \
           7  10   6
            \  /
            10 6
Output: 1 7 10 8 6 10 5 6
Explanation:
Inorder traversal (Left->Root->Right) 
of the tree is 1 7 10 8 6 10 5 6.
```
### Your Task:
You don't need to read input or print anything. Your task is to complete the function **inOrder()** which takes the root of the tree as input and returns a list containing the postorder traversal of the tree, calculated **without using recursion**.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).
```

### Constraints
`1 <= Number of nodes <= 10^5`
`1 <= Data of a node <= 10^5`

## Solution

```Cpp

class Solution {
public:
    // Function to perform in-order traversal of a binary tree iteratively
    vector<int> inOrder(Node* root) {

        // Stack to hold nodes during traversal
        stack<Node*> st;

        // Stack to keep track of whether nodes have been visited
        stack<bool> visited;
        
        // Push the root node onto the stack along with its visited flag (false initially)
        st.push(root);
        visited.push(0);    // 0 indicates node has not been visited
        
        // Vector to store the result of the traversal
        vector<int> ans;
        
        // Loop until the stack is empty
        while (!st.empty()) {

            // Get the top node from the stack
            Node* top = st.top();
            st.pop();
            
            // Get the visited flag for the top node
            bool flag = visited.top();
            visited.pop();
            
            // If the node has not been visited yet
            if (!flag) {
                // Check if there is a right child, push it onto the stack with visited flag false
                if (top->right) {
                    st.push(top->right);
                    visited.push(0);
                }
                
                // Push the current node back onto the stack with visited flag true
                st.push(top);
                visited.push(1);
                
                // Check if there is a left child, push it onto the stack with visited flag false
                if (top->left) {
                    st.push(top->left);
                    visited.push(0);
                }
            } else {
                // If the node has been visited (flag is true), add its data to the result vector
                ans.push_back(top->data);
            }
        }
        
        // Return the result of the in-order traversal
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```