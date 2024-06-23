//* Print all the levels of nodes in a single line.

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

// Function to perform level-order traversal of the binary tree
void levelOrderTraversal(Node* root) {

    // Queue to facilitate level-order traversal
    queue<Node*> q;

    // Push the root node to the queue
    q.push(root);

    // Continue until the queue is empty
    while(!q.empty()) {

        // Get the front element of the queue
        Node* frontNode = q.front();

        // Remove the front element from the queue
        q.pop();

        // Print the data of the current node
        cout << frontNode->data << "  ";

        // If the left child exists, push it to the queue
        if(frontNode->left != NULL)
            q.push(frontNode->left);

        // If the right child exists, push it to the queue
        if(frontNode->right != NULL)
            q.push(frontNode->right);
    }
}

int main() {

    cout << "Enter the root node : ";

    // Create the binary tree starting from the root node
    Node* root = createBinaryTree();

    // Print the Level-order Traversal
    cout << "Level Order Traversal is : " << endl;
    levelOrderTraversal(root);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) -> In Worst Case
    //* Space Complexity : O(H) -> In Average Case
    //* H : Height of Binary Tree
//* ********************************************** 