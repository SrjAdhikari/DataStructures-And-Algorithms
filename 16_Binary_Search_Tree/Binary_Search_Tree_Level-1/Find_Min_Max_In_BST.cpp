#include<iostream>
using namespace std;

class Node {
    public:
    int data;       // Data value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize a node with a given value
    Node(int value) {
        data = value;
        left = right = NULL;    // Initially, both children are set to NULL
    }
};

// Function to insert a new node with the given element into a binary search tree
Node* insertion(Node* root, int element) {
    if (!root) {
        // If the tree is empty, create a new node for the element and return it as the root
        Node* rootNode = new Node(element);
        return rootNode;
    }

    if (element < root->data) {
        // If the element is less than the current node's data, insert it recursively in the left subtree
        root->left = insertion(root->left, element);
    } else {
        // If the element is greater than or equal to the current node's data, insert it recursively in the right subtree
        root->right = insertion(root->right, element);
    }

    // After recursive insertion, return the root of the modified tree
    return root;
}

// Function to find the minimum element in a BST
Node* findMinimum(Node* root) {
    if (!root) {        // Base case: If the node is NULL, no minimum element exists
        return NULL;
    }

    // Traverse the left subtree until a node without a left child is found
    while (root->left) {
        root = root->left;
    }
    
    return root;    // The node without a left child is the minimum element
}

// Function to find the maximum element in a BST
Node* findMaximum(Node* root) {
    if (!root) {    // Base case: If the node is NULL, no maxiimum element exists
        return NULL;
    }

    // Traverse the right subtree until a node without a right child is found
    while (root->right) {
        root = root->right;
    }

    return root;    // The node without a right child is the maximum element
}

int main() {
    // Array containing elements to be inserted into the BST
    int array[] = {6, 3, 11, 5, 7, 18, 12, 2};

    // Calculate the size of the array (number of elements)
    int size = sizeof(array) / sizeof(int);

    Node* root = NULL;      // Initialize the root node of the BST as NULL (empty tree initially)

    // Insert each element from the array into the BST
    for (int i = 0; i < size; i++) {
        root = insertion(root, array[i]);   // Call the insertion function to create and insert nodes in the BST
    }

    // Find the minimum and maximum elements in the BST
    Node* minValue = findMinimum(root);
    Node* maxValue = findMaximum(root);

    cout << "Minimum value in the BST is : " << minValue->data << endl;
    cout << "Maximum value in the BST is : " << maxValue->data << endl;

    return 0;
}

//* **********************************************
    //* Time and space complexity to find min and max elemelt in BST.
    //* Time Complexity : O(N) -> In Worst Case
    //* Time Complexity : O(H) -> In Average Case (H : Height of Binary Tree)
    //* Space Complexity : O(1)
//* ********************************************** 