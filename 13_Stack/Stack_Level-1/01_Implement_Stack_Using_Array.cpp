#include <iostream>
using namespace std;

// Define a class called Stack to represent a stack data structure
class Stack {
    public:
    int *arr;   // Pointer to an integer array that will hold stack elements
    int size;   // Variable to store the maximum size of the stack
    int top;    // Variable to keep track of the topmost element index in the stack

    // Constructor to initialize the stack with a given size
    Stack(int size) {
        arr = new int[size];  // Dynamically allocate memory for the stack array
        this->size = size;    // Set the size of the stack to the provided value
        top = -1;             // Initialize top to -1, indicating an empty stack
    }

    // Function to push a value onto the stack
    void push(int value) {
        // Check if the stack is full
        if (top == size - 1) {
            cout << "Stack is full (stack overflow)" << endl;
            return;  // Exit the function to prevent pushing onto a full stack
        } 
        else {
            top++;               // Increment the top index to point to the next empty position
            arr[top] = value;    // Add the new value to the top of the stack
            cout << "Value " << value << " successfully inserted." << endl;
        }
    }

    // Function to pop the top value from the stack
    void pop() {
        // Check if the stack is empty
        if (top == -1) {
            cout << "Stack is empty (stack underflow)" << endl;
            return;  // Exit the function to prevent popping from an empty stack
        } 
        else {
            cout << "Value " << arr[top] << " successfully removed." << endl;
            top--;  // Decrement the top index to effectively remove the top element
        }
    }

    // Function to get the value at the top of the stack
    int getTop() {
        // Check if the stack is empty
        if (top == -1) {
            cout << "Stack is empty (stack underflow)" << endl;
            return -1;  // Return -1 to indicate that the stack is empty
        } 
        else {
            return arr[top];  // Return the value at the top of the stack
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;  // Return true if the stack is empty, otherwise false
    }

    // Function to get the current number of elements in the stack
    int getSize() {
        return top + 1;  // Return the number of elements in the stack (top index + 1)
    }
};

int main() {
    // Create a stack object with a maximum size of 5
    Stack st(5);

    // Push elements onto the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(5);
    cout << endl;

    // Display the current size and top element of the stack
    cout << "Current size of stack: " << st.getSize() << endl;
    cout << "Current top element: " << st.getTop() << endl;
    cout << endl;

    // Pop the top element from the stack
    st.pop();

    // Display the updated size and top element of the stack
    cout << "Current size of stack: " << st.getSize() << endl;
    cout << "Current top element: " << st.getTop() << endl;
    cout << endl;

    // Check if the stack is empty
    cout << "Is the stack empty: " << st.isEmpty() << endl;

    return 0;
}