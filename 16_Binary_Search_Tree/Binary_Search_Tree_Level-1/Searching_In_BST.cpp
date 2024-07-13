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

// Function to search for a target value in a binary search tree
bool searching(Node* root, int target) {
    if (!root) {        // Base case: If the node is NULL, the target is not found
        return false;
    }

    if (root->data == target) {
        return true;    // Target found! Return true
    }

    if (target < root->data) {
        // Search recursively in the left subtree (target might be smaller)
        return searching(root->left, target);
    } 
    else {
        // Search recursively in the right subtree (target might be larger)
        return searching(root->right, target);
    }
}


int main() {
    // Array containing elements to be inserted into the BST
    int array[] = {6, 3, 11, 5, 7, 18, 12, 2};

    // Calculate the size of the array (number of elements)
    int size = sizeof(array) / sizeof(int);

    int target = 50;        // Target value to search for in the BST
    Node* root = NULL;      // Initialize the root node of the BST as NULL (empty tree initially)

    // Insert each element from the array into the BST
    for (int i = 0; i < size; i++) {
        root = insertion(root, array[i]);   // Call the insertion function to create and insert nodes in the BST
    }

    // Search for the target value in the BST
    bool found = searching(root, target);

    // Print message based on search result
    if (found) {
        cout << "Target " << target << " Found!" << endl;
    } 
    else {
    cout << "Target " << target << " Not Found." << endl;
    }

    // Exit the program successfully
    return 0;
}

//* **********************************************
    //* Time Complexity : O(N) -> In Worst Case
    //* Time Complexity : O(H) -> In Average Case (H : Height of Binary Tree)
    //* Space Complexity : O(N)
//* ********************************************** 

//* **********************************************
    //* Search element : 6
    /* 
        1
         \
          2
           \
            3
             \
              4
               \
                5
    */
    //* Traverse all node to search 6.
    //* Time Complexity : O(N) -> In Worst Case
//* ********************************************** 