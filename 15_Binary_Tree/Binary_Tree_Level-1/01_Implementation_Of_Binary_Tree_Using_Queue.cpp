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

int main() {
    
    int root;       // Variable to store the value of the root node
    cout << "Enter the root node: ";
    cin >> root;    // Input the root node value from the user

    int leftChild, rightChild;      // Variables to store the values of left and right children
    queue<Node*> q;                 // Queue to facilitate level-order insertion of nodes

    // Create the root node with the given value and push it to the queue
    Node* rootNode = new Node(root);
    q.push(rootNode);

    // Perform level-order insertion of nodes until the queue is empty
    while (!q.empty()) {

        // Get the front node from the queue
        Node* frontNode = q.front();
        q.pop();        // Remove the front node from the queue

        // Input the left child value
        cout << "Enter the left child of " << frontNode->data << ": ";
        cin >> leftChild;

        // If leftChild is not -1, create a new node and attach it as the left child
        if (leftChild != -1) {
            frontNode->left = new Node(leftChild);
            q.push(frontNode->left);    // Push the new node to the queue for further processing
        }

        // Input the right child value
        cout << "Enter the right child of " << frontNode->data << ": ";
        cin >> rightChild;

        // If rightChild is not -1, create a new node and attach it as the right child
        if (rightChild != -1) {
            frontNode->right = new Node(rightChild);
            q.push(frontNode->right);   // Push the new node to the queue for further processing
        }
    }
    
    return 0;
}
