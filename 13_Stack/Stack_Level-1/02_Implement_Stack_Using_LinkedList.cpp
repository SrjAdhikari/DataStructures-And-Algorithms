#include <iostream>
using namespace std;

// Node class to represent each element in the stack
class Node {
    public:
    int data;     // Data stored in the node
    Node* next;   // Pointer to the next node in the stack

    // Constructor to initialize the node with a value
    Node(int value) {
        data = value;     // Set the data to the given value
        next = NULL;      // Initialize next pointer to NULL
    }
};

// Stack class to represent the stack data structure using linked lists
class Stack {
    public:
    Node* top;   // Pointer to the top node of the stack
    int size;    // Number of elements in the stack

    // Constructor to initialize the stack
    Stack() {
        top = NULL;  // Initially, the stack is empty, so top is NULL
        size = 0;    // Set the initial size of the stack to 0
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* temp = new Node(value);  // Create a new node with the given value

        // Check if memory allocation for the new node failed (unlikely in C++)
        if(temp == NULL) {
            cout << "Stack is full (stack overflow)" << endl;
            return;  // Exit the function if memory allocation fails
        } 
        else {
            temp->next = top;  // Link the new node to the current top node
            top = temp;        // Update top to the new node
            size++;            // Increment the size of the stack
            cout << "Value " << value << " successfully inserted." << endl;
        }
    }

    // Function to pop the top element from the stack
    void pop() {
        // Check if the stack is empty
        if(top == NULL) {
            cout << "Stack is empty (stack underflow)" << endl;
            return;  // Exit the function if the stack is empty
        } 
        else {
            Node* temp = top;  // Store the current top node in a temporary variable
            cout << "Value " << top->data << " successfully removed." << endl;
            top = top->next;  // Move the top pointer to the next node in the stack
            delete temp;      // Delete the old top node to free memory
            size--;           // Decrement the size of the stack
        }
    }

    // Function to get the value of the top element without removing it
    int getTop() {
        // Check if the stack is empty
        if(top == NULL) {
            cout << "Stack is empty (stack underflow)" << endl;
            return -1;  // Return -1 to indicate the stack is empty
        } 
        else {
            return top->data;  // Return the value of the top element
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == NULL;  // Return true if the top is NULL, indicating the stack is empty
    }

    // Function to get the current size of the stack
    int getSize() {
        return size;  // Return the number of elements in the stack
    }
};

int main() {
    // Create a stack object 'st'
    Stack st;
    
    // Push elements onto the stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout << endl;
    
    // Display the current size and top element of the stack
    cout << "Current size of stack: " << st.getSize() << endl;
    cout << "Current top element: " << st.getTop() << endl;
    cout << endl;

    // Pop the top element from the stack
    st.pop();

    cout << "Current size of stack: " << st.getSize() << endl;
    cout << "Current top element: " << st.getTop() << endl;
    cout << endl;

    // Check if the stack is empty
    cout << "Is the stack empty: " << st.isEmpty() << endl;

    return 0;
}