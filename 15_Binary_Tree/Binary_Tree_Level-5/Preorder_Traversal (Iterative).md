# Question : [Preorder traversal (Iterative) - GFG](https://www.geeksforgeeks.org/problems/preorder-traversal-iterative/1)

Given a Binary tree. Find the preorder traversal of the tree **without using recursion**.

### Example 1
```
Input:
           1
         /   \
        2     3
      /  \
     4    5
Output: 1 2 4 5 3
Explanation:
Preorder traversal (Root->Left->Right) of 
the tree is 1 2 4 5 3.
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
Output: 8 1 7 10 5 10 6 6 
Explanation:
Preorder traversal (Root->Left->Right) 
of the tree is 8 1 7 10 5 10 6 6.
```
### Your Task:
You don't need to read input or print anything. Your task is to complete the function preOrder() which takes the root of the tree as input and returns a list containing the preorder traversal of the tree, calculated **without using recursion**.

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
    // Function to perform pre-order traversal of a binary tree iteratively
    vector<int> preOrder(Node* root) {

        // Stack to hold nodes during traversal
        stack<Node*> st;
        
        // Push the root node onto the stack
        st.push(root);
        
        // Vector to store the result of the pre-order traversal
        vector<int> ans;
        
        // Loop until the stack is empty
        while (!st.empty()) {
            
            // Get the top node from the stack
            Node* top = st.top();
            
            // Remove the top node from the stack
            st.pop();
            
            // Add the data of the top node to the result
            ans.push_back(top->data);
            
            // Push the right child of the top node onto the stack (if it exists)
            // We push the right child first so that the left child is processed first
            if (top->right)
                st.push(top->right);
            
            // Push the left child of the top node onto the stack (if it exists)
            if (top->left)
                st.push(top->left);
        }
        
        // Return the result of the pre-order traversal
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```