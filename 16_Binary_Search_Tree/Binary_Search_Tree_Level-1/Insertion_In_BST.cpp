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

// Function to perform in-order traversal of a binary search tree
void inorderTraversal(Node* root) {
    if (!root) {        // Base case: If the node is NULL, there's nothing to traverse
        return;
    }

    // 1. Recursively traverse the left subtree
    inorderTraversal(root->left);

    // 2. Visit the current node (process the data)
    cout << root->data << " ";

    // 3. Recursively traverse the right subtree
    inorderTraversal(root->right);
}

int main() {
    // Array containing elements to be inserted into the BST
    int array[] = {6, 3, 11, 5, 7, 18, 12, 2};

    // Calculate the size of the array (number of elements)
    int size = sizeof(array) / sizeof(int);

    Node* root = NULL;      // Initialize the root node of the BST as NULL (empty tree initially)

    // Insert each element from the array into the BST
    for (int i = 0; i < size; i++) {
        root = insertion(root, array[i]);   // Call the insertion function to create and insert nodes
    }

    cout << "Inorder Traversal of BST : " << endl;
    inorderTraversal(root);     // Perform in-order traversal on the BST

    return 0;                   // Exit the program successfully
}

//* **********************************************
    //* Time Complexity : O(N) -> In Worst Case
    //* Time Complexity : O(H) -> In Average Case (H : Height of Binary Tree)
    //* Space Complexity : O(N)
//* ********************************************** 

//* **********************************************
    //* Insert element : 5
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
    //* Time Complexity : O(N) -> In Worst Case
//* ********************************************** 