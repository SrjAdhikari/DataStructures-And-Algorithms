#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node {
    public:
        int data;
        Node* left, *right;

        Node(int value) {
            data  = value;
            left = right = NULL;
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

void topView(Node* root) {
    // Check if the root is NULL, if so, there is nothing to do
    if(root == NULL) 
        return;

    // Declare a map to store the first node's data at each horizontal distance
    map<int, int> mapping;
    
    // Declare a queue to perform level order traversal. Each element in the queue
    // is a pair where the first element is the node and the second element is its 
    // horizontal distance from the root
    queue<pair<Node*, int>> q;
    
    // Push the root node with a horizontal distance of 0 into the queue
    q.push({root, 0});

    // Continue level order traversal until the queue is empty
    while(!q.empty()) {
        // Get the front element of the queue and pop it
        pair<Node*, int> pair = q.front();
        q.pop();

        // Get the node and its horizontal distance from the pair
        Node* front = pair.first;
        int level = pair.second;

        // If this horizontal distance is not already in the map, add it with
        // the current node's data (this ensures only the topmost node at this
        // horizontal distance is recorded)
        if(mapping.find(level) == mapping.end())
            mapping[level] = front->data;

        // If the left child exists, push it into the queue with a horizontal 
        // distance decreased by 1
        if(front->left)
            q.push({front->left, level - 1});

        // If the right child exists, push it into the queue with a horizontal 
        // distance increased by 1
        if(front->right)
            q.push({front->right, level + 1});
    }

    // Print the top view of the binary tree
    cout << "Top view of binary tree : " << endl;
    
    // Iterate through the map and print the node's data in the top view order
    for(auto node : mapping) {
        cout << node.second << " ";
    }
    
    // Print a newline at the end
    cout << endl;
}

int main() {
    cout << "Enter the root node : ";

    Node* root = createBinaryTree();
    topView(root);

    return 0;
}