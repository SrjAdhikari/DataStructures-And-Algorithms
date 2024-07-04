#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        // Constructor to initialize the data and children of a node
        Node(int value) {
            data = value;
            left = right = NULL;
        }
};

// Function to perform level order traversal on a binary tree
void levelOrderTraversal(Node* root) {

    if (root == NULL) {     // If the tree is empty, return
        return;
    }

    queue<Node*> q;     // Create a queue to hold nodes at each level
    q.push(root);       // Push the root node into the queue
    q.push(NULL);       // Push a NULL marker to indicate the end of the current level

    // Continue the traversal while there are nodes in the queue
    while (!q.empty()) {

        Node* front = q.front();    // Get the front node from the queue
        q.pop();                    // Remove the front node from the queue

        // If the front node is NULL, it indicates the end of the current level
        if (front == NULL) {
            cout << endl;       // Print a newline to separate levels
            if (!q.empty()) {   // If the queue is not empty, push another NULL marker to indicate the end of the next level
                q.push(NULL);
            }
        } else {
            cout << front->data << " ";     // Print the data of the current node

            if (front->left) {              // If the current node has a left child, push it into the queue
                q.push(front->left);
            }
            
            if (front->right) {             // If the current node has a right child, push it into the queue
                q.push(front->right);
            }
        }
    }
}

// Function to map each node value to its index in the inorder traversal array
void findPosition(int inOrder[], int inOrderStart, int inOrderEnd, map<int, int>& mapping) {
    for (int i = inOrderStart; i <= inOrderEnd; i++) {
        int node = inOrder[i];    // Get the current node value
        mapping[node] = i;        // Store the index of the node in the map
    }
}

// Recursive function to create a binary tree from preorder and inorder traversals
Node* createTree(int preOrder[], int inOrder[], int& preOrderIndex, int inOrderStart, int inOrderEnd, map<int, int>& mapping) {
    
    if (inOrderStart > inOrderEnd)          // Base case: return NULL if no elements to process
        return NULL;

    int node = preOrder[preOrderIndex];    // Get the current node value from preorder traversal
    Node* root = new Node(node);           // Create a new tree node with the current node value
    preOrderIndex++;                       // Increment preOrderIndex to move to the next node in preorder traversal

    int position = mapping[node];          // Find the position of the current node in the inorder traversal

    // Recursively create the left subtree using the left part of inorder traversal
    root->left = createTree(preOrder, inOrder, preOrderIndex, inOrderStart, position - 1, mapping);

    // Recursively create the right subtree using the right part of inorder traversal
    root->right = createTree(preOrder, inOrder, preOrderIndex, position + 1, inOrderEnd, mapping);

    return root;    // Return the root of the newly created subtree
}


int main() {

    int preOrder[] = {2, 8, 10, 6, 4, 12};   // Preorder traversal
    int inOrder[] = {10, 8, 6, 2, 4, 12};    // Inorder traversal
    int size = 6;                            // Number of nodes in the tree

    int inOrderStart = 0;                    // Start index for inorder traversal
    int inOrderEnd = size - 1;               // End index for inorder traversal
    int preOrderStart = 0;                   // Start index for preorder traversal

    map<int, int> mapping;                  // Map to store the position of each node in the inorder traversal

    // Populate the map with node positions from the inorder traversal
    findPosition(inOrder, inOrderStart, inOrderEnd, mapping);

    // Create the binary tree using preorder and inorder traversals
    Node* root = createTree(preOrder, inOrder, preOrderStart, inOrderStart, inOrderEnd, mapping);

    // Print the tree in level order to verify the tree structure
    cout << "Printing Tree : " << endl;
    levelOrderTraversal(root);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N)
//* ********************************************** 