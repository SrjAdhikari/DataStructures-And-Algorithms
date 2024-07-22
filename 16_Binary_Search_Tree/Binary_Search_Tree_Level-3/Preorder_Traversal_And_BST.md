# Question : [Preorder Traversal and BST - GFG](https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1)

Given an array **arr[]** of size **N** consisting of **distinct** integers, write a program that returns **1** if given array can represent preorder traversal of a possible BST, else returns **0**.

### Example 1
```
Input:
N = 3
arr = {2, 4, 3}
Output: 1
Explaination: Given arr[] can represent
preorder traversal of following BST:
               2
                \
                 4
                /
               3
```

### Example 2
```
Input:
N = 3
Arr = {2, 4, 1}
Output: 0
Explaination: Given arr[] cannot represent
preorder traversal of a BST.
```

### Your Task:
You don't need to read input or print anything. Your task is to complete the function **canRepresentBST()** which takes the array **arr[]** and its size **N** as input parameters and returns **1** if given array can represent preorder traversal of a BST, else returns **0**.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
```

### Constraints
`1 ≤ N ≤ 10^5`
`0 ≤ arr[i] ≤ 10^5`

## Solution 1

```Cpp
Using Recursive Approach :

class Solution {
public:
    // Function to check if a given array can represent a Binary Search Tree (BST)
    void binarySearchTree(int arr[], int& index, int lower, int upper, int N) {

    // Base case:
    // 1. Check if the index has reached the end of the array (N).
    // 2. Check if the current element (at `arr[index]`) violates the BST property
    //    for this subtree (i.e., it's less than `lower` or greater than `upper`).
    // If either condition is true, the array cannot represent a valid BST.
    if (index == N || arr[index] < lower || arr[index] > upper) {
        return;
    }

    // Extract the current element from the array and move to the next index
    int element = arr[index];
    index++;

    // Recursively construct the left subtree. Since elements in the left subtree
    // should be smaller than the root, use `element` as the upper bound.
    binarySearchTree(arr, index, lower, element, N);

    // Recursively construct the right subtree. Since elements in the right subtree
    // should be greater than the root, use `upper` as the upper bound.
    binarySearchTree(arr, index, element, upper, N);
    }

    int canRepresentBST(int arr[], int N) {

        if (N == 0) {       // Base case: Empty array cannot represent a BST
            return 0;
        }
        int index = 0;

        // Call the helper function to traverse the array and validate the BST structure
        binarySearchTree(arr, index, INT_MIN, INT_MAX, N);

        // Return 1 if all elements in the array were processed successfully
        // (i.e., the index reached the end of the array `N`) indicating a valid BST.
        return index == N;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```

## Solution 2

```Cpp
Using Iterative Approach :

class Solution {
public:
    // Function to check if a given array can represent a Binary Search Tree (BST)
    int canRepresentBST(int arr[], int N) {

        // Initialize two stacks:
        // - 'lower': Stores the minimum allowed value for a node in the current subtree
        // - 'upper': Stores the maximum allowed value for a node in the current subtree
        stack<int> lower, upper;
        lower.push(INT_MIN);    // Initialize the lower bound with the minimum possible value
        upper.push(INT_MAX);    // Initialize the upper bound with the maximum possible value

        int lowerBound, upperBound;     // Variables to store the current lower and upper bounds

        // Iterate through the elements in the array
        for (int i = 0; i < N; i++) {

            // If the current element (arr[i]) is less than the minimum allowed value
            // for the current subtree (lower.top()), it violates the BST property, so
            // return 0 (not a BST).
            if (arr[i] < lower.top()) {
            return 0;
            }

            // Adjust the bounds if the current element is greater than the top of the upper stack
            while (arr[i] > upper.top()) {
                lower.pop();
                upper.pop();
            }

            // After popping elements, obtain the new minimum and maximum allowed values
            // for the subtree where the current element can potentially be placed.
            int lowerBound = lower.top();
            lower.pop();
            int upperBound = upper.top();
            upper.pop();

            // Update the stacks with the new bounds for the left and right subtrees
            lower.push(arr[i]);         // Push the current element as the new lower bound
            upper.push(upperBound);     // Maintain the current upper bound for the right subtree

            lower.push(lowerBound);     // Maintain the current lower bound for the left subtree
            upper.push(arr[i]);         // Push the current element as the new upper bound for the left subtree
        }

        // If all elements are processed without violating the BST properties, return 1
        return 1;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```