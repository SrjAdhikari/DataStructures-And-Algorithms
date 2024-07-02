# Question : [Postorder traversal (Iterative) - GFG](https://www.geeksforgeeks.org/problems/postorder-traversal-iterative/1)

Given a Binary tree. Find the postorder traversal of the tree **without using recursion**.

### Example 1
```
Input:
           1
         /   \
        2     3
      /  \
     4    5
Output: 4 5 2 3 1
Explanation:
Postorder traversal (Left->Right->Root) of 
the tree is 4 5 2 3 1.
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
Output: 10 7 1 6 10 6 5 8 
Explanation:
Postorder traversal (Left->Right->Root) 
of the tree is 10 7 1 6 10 6 5 8 .
```
### Your Task:
You don't need to read input or print anything. Your task is to complete the function **postOrder()** which takes the root of the tree as input and returns a list containing the postorder traversal of the tree, calculated **without using recursion**.

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
    // Function to perform post-order traversal of a binary tree iteratively
    vector<int> postOrder(Node* root) {

        // Node, Right, Left -> NRL
        // Stack to hold nodes during traversal
        stack<Node*> st;
        
        // Push the root node onto the stack
        st.push(root);
        
        // Vector to store the result of the traversal
        vector<int> ans;
        
        // Loop until the stack is empty
        while (!st.empty()) {
            // Get the top node from the stack
            Node* top = st.top();
            
            // Remove the top node from the stack
            st.pop();
            
            // Add the data of the top node to the result
            ans.push_back(top->data);
            
            // Push the left child of the top node onto the stack (if it exists)
            // We push the left child first so that the right child is processed first
            if (top->left)
                st.push(top->left);
            
            // Push the right child of the top node onto the stack (if it exists)
            if (top->right)
                st.push(top->right);
        }
        
        // Reverse the result to get the post-order traversal (Left, Right, Node -> LRN)
        reverse(ans.begin(), ans.end());
        
        // Return the result of the post-order traversal
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```