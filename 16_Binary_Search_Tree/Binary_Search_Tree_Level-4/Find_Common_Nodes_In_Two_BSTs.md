# Question : [Find Common Nodes in two BSTs - GFG](https://www.geeksforgeeks.org/problems/print-common-nodes-in-bst/1)

Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

**Note**: Return the common nodes in **sorted** order.

### Example 1
```
Input:
BST1:
                  5
               /     \
             1        10
           /   \      /
          0     4    7
                      \
                       9
BST2:
                10 
              /    \
             7     20
           /   \ 
          4     9
Output: 4 7 9 10
```

### Example 2
```
Input:
BST1:
    　　　　　 10
    　　　　　/  \
   　　　　　2   11
  　　　　　/  \
 　　　　　1   3
BST2:
       　　　　2
     　　　　/  \
    　　　　1    3
Output: 1 2 3
```

### Your Task:
You don't need to read input or print anything. Your task is to complete the function **findCommon()** that takes roots of the two BSTs as input parameters and returns a list of integers containing the common nodes in sorted order. 

```
Expected Time Complexity: O(N1 + N2) where N1 and N2 are the sizes of the 2 BSTs.
Expected Auxiliary Space: O(H1 + H2) where H1 and H2 are the heights of the 2 BSTs.
```

### Constraints
`1 <= Number of Nodes <= 10^5`
`1 <= Node data <= 10^9`

## Solution

```Cpp

class Solution {
public:
    vector<int> findCommon(Node *root1, Node *root2) {
        // Create an empty vector to store the common elements found in both trees.
        vector<int> ans;

        // Initialize two stacks `s1` and `s2` to store nodes from the respective trees
        // during the iterative in-order traversal process.
        stack<Node*> s1, s2;

        // Push all elements from the leftmost path of `root1` onto `s1`.
        while (root1) {
            s1.push(root1);
            root1 = root1->left;
        }

        // Push all elements from the leftmost path of `root2` onto `s2`.
        while (root2) {
            s2.push(root2);
            root2 = root2->left;
        }

        // Process elements from both stacks until either stack becomes empty.
        while (!s1.empty() && !s2.empty()) {

            // If the top elements of both stacks have the same data, it's a common element.
            // Add it to the answer vector and move on to the right subtrees of both nodes.
            if (s1.top()->data == s2.top()->data) {
                ans.push_back(s1.top()->data);
                root1 = s1.top()->right;
                s1.pop();
                root2 = s2.top()->right;
                s2.pop();
            } 
            // If the top element of `s1` has a greater value than the top element of `s2`,
            // it means there can't be any further common elements in that subtree of `s2`.
            // Pop the top element from `s2` and continue pushing elements from its leftmost path.
            else if (s1.top()->data > s2.top()->data) {
                root2 = s2.top()->right;
                s2.pop();
            } 
            // Similarly, if the top element of `s2` has a greater value,
            // pop the top element from `s1` and continue pushing elements from its leftmost path.
            else {
                root1 = s1.top()->right;
                s1.pop();
            }

            // After processing the top elements, 
            // Traverse (Push) the leftmost path of the right subtree of the node just processed from s1
            while (root1) {
                s1.push(root1);
                root1 = root1->left;
            }

            // Traverse (push) the leftmost path of the right subtree of the node just processed from s2
            while (root2) {
                s2.push(root2);
                root2 = root2->left;
            }
        }

        // Return the vector containing the common elements found in both trees.
        return ans;
    }
};

Time Complexity = O(N + M)  // where N1 and N2 are the number of nodes in root1 and root2, respectively. 
Space Complexity = O(N + M)
```