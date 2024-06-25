# Question : [Size of Binary Tree - GFG](https://www.geeksforgeeks.org/problems/size-of-binary-tree/1)

Given a binary tree of size **n**, you have to count the number of nodes in it. For example, the count of nodes in the tree below is 4.

```
      1
     / \
   10   39
  /
 5
```

### Example 1

```
Input:
1 2 3
Output:
3
Explanation:
Given Tree is :
        1
       /  \
      2    3
There are 3 nodes in the tree.
```

### Example 2

```
Input:
10 5 9 N 1 3 6
Output:
6
Explanation:
Given Tree is :
        10
       /  \
      5    9
       \  / \
        1 3  6
There are 6 nodes in the tree.
```

### Your task

You don't need to read input or print anything. Your task is to complete the function **getSize()** which takes the tree head node and returns an integer representing the number of nodes in the tree.

```
Expected Time Complexity : O(n)
Expected Space Compelxity : O(h), where h is the height of the binary tree
```

### Constraints

`1 <= n <= 10^5`<br>
`1 <= values of nodes <= 10^6`

## Solution

````Cpp
Using BFS Traversal + Topological Sort :

## Solution 1

```Cpp

class Solution {
public:
    // Function to calculate the size (number of nodes) of a binary tree
    int getSize(Node* root) {

        if(root == NULL)                            // Base case: If the root is NULL, the size is 0 (empty tree)
            return 0;

        int leftSubtree = getSize(root->left);      // Recursively calculate the size of the left subtree
        int rightSubtree = getSize(root->right);    // Recursively calculate the size of the right subtree

        // Return the size of the tree which is 1 (for the current node)
        // plus the sizes of its left and right subtrees
        return 1 + leftSubtree + rightSubtree;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
````

## Solution 2

```Cpp

class Solution {
public:
    // Helper function to count nodes in the tree recursively
    void countNode(Node* root, int& count) {

        if(root == NULL)                    // Base case: If the root is NULL, return (no nodes to count)
            return;

        count++;                            // Increment the count for the current node
        countNode(root->left, count);       // Recursively count nodes in the left subtree
        countNode(root->right, count);      // Recursively count nodes in the right subtree
    }

    // Function to calculate the size (number of nodes) of a binary tree
    int getSize(Node* root) {

        int count = 0;              // Initialize count to 0
        countNode(root, count);     // Call helper function to count nodes starting from the root
        return count;               // Return the total count of nodes
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
