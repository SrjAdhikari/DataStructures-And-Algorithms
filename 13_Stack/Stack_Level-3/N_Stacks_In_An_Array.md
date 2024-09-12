## Solution 1

```Cpp
#include <iostream>
#include <stack>
using namespace std;

// Class to represent a node in a linked list for each stack
class Node {
public:
    int index;          // Index in the array where the element is stored
    Node* next;         // Pointer to the next node in the linked list (for stack tracking)

    // Constructor to initialize a node with a given index
    Node(int x) {
        index = x;
        next = NULL;    // Initialize the next pointer as NULL
    }
};

// Class to represent N stacks using a single array
class NStack {
public:
    int* arr;           // Array to store elements for all stacks
    Node** top;         // Array of Node pointers to  keep track of the top elements of each stack
    stack<int> st;      // Stack to keep track of free indices in the array

    // Constructor to initialize the NStack with 'n' stacks and 'size' total capacity
    NStack(int n, int size) {
        arr = new int[size];  // Allocate memory for the array to hold stack elements
        top = new Node*[n];   // Allocate memory for the array of top pointers (one for each stack)
        
        // Initialize all stack tops to NULL (empty stacks)
        for (int i = 0; i < n; i++) {
            top[i] = NULL;
        }

        // Initialize the free index stack with all available indices
        for (int i = 0; i < size; i++) {
            st.push(i);  // Push all indices (0 to size-1) onto the stack to indicate free slots
        }
    }

    // Function to push an element 'x' onto stack 'm'
    bool push(int x, int m) {
        // Check if there's space available in the array
        if (st.empty())
            return 0;       // Return false if no space is available
        
        // Get the top free index from the stack and Store the element 'x' at this free index in the array
        arr[st.top()] = x;

        // Create a new node with the index of the inserted element
        Node* temp = new Node(st.top());
        
        // Set the new node's next pointer to the current top of stack 'm'
        temp->next = top[m - 1];

        // Update the top of the stack 'm' to be the new node
        top[m - 1] = temp;
        
        // Remove the used index from the stack
        st.pop();

        // Return true indicating the push operation was successful
        return 1;
    }

    // Function to pop an element from stack 'm'
    int pop(int m) {
        // Check if stack 'm' is empty
        if (top[m - 1] == NULL)
            return -1;  // Return -1 if the stack 'm' is empty
        
        // Get the index of the top element of stack 'm'
        int element = arr[top[m - 1]->index];  // Retrieve the element from the array
        
        // Push the now free index back onto the free index stack
        st.push(top[m - 1]->index);
        
        // Update the top of the stack to the next element in the list
        top[m - 1] = top[m - 1]->next;
        
        return element;  // Return the popped element
    }
};

Time Complexity = O(1)
Space Complexity = O(n + size)
```

## Solution 2

```Cpp
#include <iostream>
#include <stack>
using namespace std;

class NStack {
public:
    int* arr;       // Array to store the actual elements of all stacks
    int* top;       // Array to store the top index for each stack
    int* next;      // Array to store the next available index or the next element for each stack
    int n, size;    // Number of stacks (n) and size of the array (size)
    int freeSpot;   // Keeps track of the next free index in the array

    // Constructor to initialize data structures for 'n' stacks with a total capacity of 'size'
    NStack(int n, int size) {
        this->n = n;              // Number of stacks
        this->size = size;        // Total size of the array
        arr = new int[size];      // Array to store elements
        top = new int[n];         // Array to store top indices for each stack
        next = new int[size];     // Array to manage the next free index
        freeSpot = 0;             // The initial free spot is at index 0

        // Initialize all stacks as empty, indicated by top[i] = -1 for each stack
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize the 'next' array where each index points to the next available free index
        for (int i = 0; i < size; i++) {
            next[i] = i + 1;        // Each index points to the next
        }
        next[size - 1] = -1;        // The last index points to -1, indicating no more free spots
    }

    // Function to push an element 'x' into the m-th stack (1-based index)
    bool push(int x, int m) {
        // If there's no free spot available, return false (stack overflow)
        if (freeSpot == -1)
            return false;

        int index = freeSpot;         // Get the current free spot
        freeSpot = next[index];       // Update freeSpot to the next available index
        arr[index] = x;               // Place the element in the array at the free index

        next[index] = top[m - 1];     // Link the current index with the previous top of the m-th stack
        top[m - 1] = index;           // Update the top of the m-th stack to the current index

        return true;                  // Successfully pushed the element
    }

    // Function to pop an element from the m-th stack (1-based index)
    int pop(int m) {
        // If the stack is empty, return -1 (stack underflow)
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];         // Get the index of the top element of the m-th stack
        top[m - 1] = next[index];       // Update the top to the next element in the stack

        int poppedElement = arr[index]; // Get the popped element from the array
        next[index] = freeSpot;         // Link the freed spot back to the free list
        freeSpot = index;               // Update the free spot to the index of the popped element

        return poppedElement;           // Return the popped element
    }

    // Destructor to free allocated memory
    ~NStack() {
        delete[] arr;   // Free the array that stores elements
        delete[] top;   // Free the array that stores top indices for each stack
        delete[] next;  // Free the array that manages next available indices
    }
};

Time Complexity = O(1)
Space Complexity = O(n + size)
```