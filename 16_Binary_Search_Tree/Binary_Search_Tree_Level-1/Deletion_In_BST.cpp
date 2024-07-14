#include<iostream>
#include<queue>
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

// Function to perform level-order traversal of a BST
void levelorderTraversal(Node* root) {
    // If the tree is empty (root is NULL), simply return
    if (!root)
        return;
    
    queue<Node*> q;     // Create a queue to store nodes for level order traversal
    q.push(root);       // Enqueue the root node
    q.push(NULL);       // Use NULL as a marker to indicate the end of the current level

    // Continue the traversal until the queue is empty
    while (!q.empty()) {
        Node* front = q.front();    // Get the front node from the queue
        q.pop();                    // Remove the front node from the queue

        // If the front node is NULL, it indicates the end of the current level
        if (front == NULL) {
            cout << endl;           // Print a newline to separate levels
            // If the queue is not empty, enqueue NULL to mark the end of the next level
            if (!q.empty())
                q.push(NULL);
        }
        else {
            cout << front->data << "  ";    // Print the data of the current node
            if (front->left)                // If the left child exists, enqueue it
                q.push(front->left);

            if (front->right)               // If the right child exists, enqueue it
                q.push(front->right);
        }
    }
}

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

// Function to delete a node with a given target value from a binary search tree
Node* deletion(Node* root, int target) {
    if (!root)          // If the tree is empty, return NULL
        return NULL;

    // If the target node is found
    if (root->data == target) {

        // Case 1: The node is a leaf (has no children)
        if ((!root->left) && (!root->right)) {
            delete root;    // Delete the node
            return NULL;    // Return NULL to update the parent pointer
        }
        // Case 2: The node has only a left child
        else if (root->left && !root->right) {
            Node* temp = root->left;    // Store the left child
            delete root;                // Delete the current node
            return temp;                // Return the left child to update the parent pointer
        }
        // Case 3: The node has only a right child
        else if (root->right && !root->left) {
            Node* temp = root->right;   // Store the right child
            delete root;                // Delete the current node
            return temp;                // Return the right child to update the parent pointer
        }
        // Case 4: The node has two children
        else {
            Node* max = findMaximum(root->left);            // Find the maximum value node in the left subtree
            root->data = max->data;                         // Replace the current node's data with the maximum value from the left subtree
            root->left = deletion(root->left, max->data);   // Delete the maximum value node from the left subtree
            return root;                                    // Return the updated root
        }
    }
    // Target value is smaller: Search in the left subtree
    else if (root->data > target) {
        root->left = deletion(root->left, target);
    }
    // Target value is larger: Search in the right subtree
    else {
        root->right = deletion(root->right, target);
    }

    return root;  // Return the root after deletion
}

int main() {
    // Array containing elements to be inserted into the BST
    int array[] = {61, 50, 90, 10, 55, 75, 5, 35, 20, 15};
    int size = sizeof(array) / sizeof(array[0]);  // Calculate array size

    // Initialize the root node of the BST as NULL (empty tree initially)
    Node* root = NULL;

    // Insert each element from the array into the BST
    for (int i = 0; i < size; i++) {
        root = insertion(root, array[i]);  // Call the insertion function
    }

    // Print the BST before deletion
    cout << "BST before deletion: " << endl;
    levelorderTraversal(root);  // Call function to print level-order traversal

    int target;     // Target value for deletion and user input loop
    cout << "Enter the element you want to delete (enter -1 to quit): " << endl;
    cin >> target;

    // Continue deletion until the user enters -1
    while(target != -1) {
        // Delete the target element from the BST
        root = deletion(root, target);

        // Print the BST after deletion
        cout << "BST after deletion: " << endl;
        levelorderTraversal(root);  // Call function to print level-order traversal

        // Prompt the user to enter the next element they want to delete
        cout << "Enter the element you want to delete (enter -1 to quit): " << endl;
        cin >> target;
    }

    return 0;
}

//* **********************************************
    //* Time and space complexity of deletion in BST.
    //* Time Complexity : O(N) -> In Worst Case
    //* Time Complexity : O(H) -> In Average Case (H : Height of Binary Tree)
    //* Space Complexity : O(N)
//* ********************************************** 