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

// Function to perform level-order traversal of the binary tree
void levelOrderTraversal(Node* root) {

    // Create a queue to manage the nodes during the traversal
    queue<Node*> q;

    // Push the root node into the queue
    q.push(root);

    // Push a NULL marker to indicate the end of the current level
    q.push(NULL);

    // Continue the traversal until there is more than one element in the queue
    while(q.size() > 1) {

        // Get the front node from the queue
        Node* frontNode = q.front();
        q.pop();                // Remove the front node from the queue

        // Check if the front node is NULL, indicating the end of a level
        if(frontNode == NULL) {
            cout << endl;       // Print a newline to separate levels
            q.push(NULL);       // Push a NULL marker to indicate the end of the next level
        } 
        else {
            // Print the data of the current node
            cout << frontNode->data << "  ";

            // If the left child exists, push it into the queue
            if(frontNode->left != NULL)
                q.push(frontNode->left);

            // If the right child exists, push it into the queue
            if(frontNode->right != NULL)
                q.push(frontNode->right);
        }
    }
}

// Function to construct a balanced BST from a given sorted inorder array
Node* bstFromInorder(int inorder[], int start, int end) {
    // Base case: if the start index exceeds the end index, return NULL (empty subtree)
    if (start > end) {
        return NULL;
    }

    int mid = start + (end - start) / 2;    // Find the middle index of the current subarray
    int element = inorder[mid];             // Get the middle element which will be the root of the current subtree
    Node* root = new Node(element);         // Create a new node with the element at the middle index

    // Recursively build the left subtree with elements before the middle index
    root->left = bstFromInorder(inorder, start, mid - 1);

    // Recursively build the right subtree with elements after the middle index
    root->right = bstFromInorder(inorder, mid + 1, end);

    return root;    // Return the root of the constructed BST
}

int main() {

	int inorder[] = {10,20,30,40,50,60,70};
	int size = sizeof(inorder) / sizeof(int);
	int start = 0;
	int end = size - 1;
	Node* root = bstFromInorder(inorder, start, end);

	levelOrderTraversal(root);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N)
//* ********************************************** 