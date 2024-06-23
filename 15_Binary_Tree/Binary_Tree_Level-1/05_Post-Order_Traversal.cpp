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
    cin >> data;

    // Base case: if the input data is -1, return NULL indicating no node
    if (data == -1) return NULL;

    // Create the current node with the input data
    Node* root = new Node(data);

    // Recursively create the left subtree
    cout << "Enter the left child of " << root->data << " : ";
    root->left = createBinaryTree();

    // Recursively create the right subtree
    cout << "Enter the right child of " << root->data << " : ";
    root->right = createBinaryTree();

    return root;    // Return the created node
}

// Function to perform pre-order traversal of the binary tree
void postOrderTraversal(Node* root) {

    // Base case : if the current node is NULL, return
    if(root == NULL) return;

    // Recursively traverse the left subtree
    postOrderTraversal(root->left);

    // Recursively traverse the right subtree
    postOrderTraversal(root->right);

    // Visit the root node: print its data
    cout << root->data << "  ";
}

int main() {
    cout << "Enter the root node : ";

    // Create the binary tree starting from the root node
    Node* root = createBinaryTree();

// Print the Post-order Traversal
    cout << "Post Order Traversal is : " << endl;
    postOrderTraversal(root);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) -> In Worst Case
    //* Space Complexity : O(H) -> In Average Case
    //* H : Height of Binary Tree
//* ********************************************** 