#include <iostream>
#include <queue>
using namespace std;

// Definition of the Node class for the binary tree
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

// Function to create a binary tree recursively
Node* createBinaryTree() {
    
    int data;
    cin >> data;    // Input the data for the current node

    // Base case: if the input data is -1, return NULL indicating no node
    if (data == -1)
        return NULL;

    // Create the current node with the input data
    Node* root = new Node(data);

    // Recursively create the left subtree
    cout << "Enter the left child of " << root->data << " : ";
    root->left = createBinaryTree();

    // Recursively create the right subtree
    cout << "Enter the right child of " << root->data << " : ";
    root->right = createBinaryTree();

    // Return the created node
    return root;
}

int main() {
    cout << "Enter the root node : ";

    // Create the binary tree starting from the root node
    Node* root = createBinaryTree();

    // Print the root node's data
    cout << " Root node is: " << root->data << endl;

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) -> In Worst Case
    //* Space Complexity : O(H) -> In Average Case
    //* H : Height of Binary Tree
//* ********************************************** 