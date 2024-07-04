#include<iostream>
#include<queue>
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

// Function to find the position of the root node in the inorder traversal array
int findPosition(int inOrder[], int rootNode, int inOrderStart, int inOrderEnd) {
    // Iterate through the inorder array from inOrderStart to inOrderEnd
    for (int i = inOrderStart; i <= inOrderEnd; i++) {
        // If the current element matches the rootNode, return its index
        if (inOrder[i] == rootNode) {
            return i;
        }
    }
    // If the rootNode is not found, return -1
    return -1;
}

// Recursive function to create a binary tree from preorder and inorder traversals
Node* createTree(int preOrder[], int inOrder[], int& preOrderIndex, int inOrderStart, int inOrderEnd, int size) {
    
    // Base case: if preOrderIndex is out of bounds or inOrderStart is greater than inOrderEnd
    if (preOrderIndex >= size || inOrderStart > inOrderEnd)
        return NULL;

    int node = preOrder[preOrderIndex];     // Get the current node value from preorder traversal using preOrderIndex
    Node* root = new Node(node);            // Create a new tree node with the current node value
    preOrderIndex++;                        // Increment preOrderIndex to move to the next node in preorder traversal

    // Find the position of the current node in the inorder traversal
    int position = findPosition(inOrder, node, inOrderStart, inOrderEnd);

    // Recursively create the left subtree using the left part of inorder traversal
    root->left = createTree(preOrder, inOrder, preOrderIndex, inOrderStart, position - 1, size);

    // Recursively create the right subtree using the right part of inorder traversal
    root->right = createTree(preOrder, inOrder, preOrderIndex, position + 1, inOrderEnd, size);

    return root;    // Return the root of the newly created subtree
}

int main() {
    int preOrder[] = {2, 8, 10, 6, 4, 12};
    int inOrder[] = {10, 8, 6, 2, 4, 12};
    int size = 6;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;
    int preOrderStart = 0;

    Node* root = createTree(preOrder, inOrder, preOrderStart, inOrderStart, inOrderEnd, size);

    cout << "Printing Tree : " << endl;
    levelOrderTraversal(root);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N^2)
    //* Space Complexity : O(N)
//* ********************************************** 