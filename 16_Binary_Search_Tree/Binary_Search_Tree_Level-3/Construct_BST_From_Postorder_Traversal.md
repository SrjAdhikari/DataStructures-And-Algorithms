# Question : [Construct BST from Postorder - GFG](https://www.geeksforgeeks.org/problems/construct-bst-from-post-order/1)

Given postorder traversal of a Binary Search Tree, you need to construct a BST from postorder traversal. The output will be inorder traversal of the constructed BST.

### Example 1
```
Input:
6
1 7 5 50 40 10

Output:
1 5 7 10 40 50

Explanation:
Testcase 1: The BST for the given post order traversal is:
```
![](https://www.cdn.geeksforgeeks.org/wp-content/uploads/BST.jpg)

### Your Task:
The task is to complete the function **constructTree()** which takes an array post[], size as as the argument and returns the root of BST.

```
Expected Time Complexity: O(No. of  nodes in BST)
Expected Auxiliary Space: O(No. of  nodes in BST)
```

### Constraints
`1 <= T <= 100`
`1 <= N <= 200`

## Solution

```Cpp
class Solution {
public:
    // Function to construct a Binary Search Tree (BST) from a postorder traversal array
    Node* binarySearchTree(int post[], int &index, int lower, int upper) {

        // Base case: If the index is out of bounds of the postorder array
        // or the current element is not within the valid range [lower, upper], return NULL
        if (index < 0 || post[index] < lower || post[index] > upper) {
            return NULL;
        }

        // Extract the current element from the preorder array to create the root node
        int element = post[index];

        // Create a new TreeNode with the extracted element
        Node* root = new Node(element);

        // Move to the previous element in the postorder array for the upcoming recursive calls
        index--;

        // Recursively construct the right subtree with updated lower bound
        // The right subtree must have values greater than the current root value
        root->right = binarySearchTree(post, index, root->data, upper);

        // Recursively construct the left subtree with updated upper bound
        // The left subtree must have values less than the current root value
        root->left = binarySearchTree(post, index, lower, root->data);

        // Return the constructed subtree rooted at the current node
        return root;
    }

    // Function to initiate the construction of a BST from a postorder traversal array
    Node* constructTree(int post[], int size) {
        int index = size - 1;   // Initialize the index to the last element of the postorder array
        
        // Call the recursive function with initial bounds for the entire range of valid values
        return binarySearchTree(post, index, INT_MIN, INT_MAX);
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```