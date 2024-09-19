#include <iostream>
using namespace std;

// Node class represents an element in the doubly linked list used for the deque
class Node {
public:
    int data;          // Value of the node
    Node* next;        // Pointer to the next node
    Node* prev;        // Pointer to the previous node

    // Constructor to initialize a node with a given value
    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};

// Deque class represents a double-ended queue implemented using a doubly linked list
class Deque {
    Node* front;       // Pointer to the front node of the deque
    Node* rear;        // Pointer to the rear node of the deque

    public:
    // Constructor initializes an empty deque
    Deque() {
        front = rear = NULL;
    }

    // Method to insert an element at the front of the deque
    void push_front(int value) {
        // Check if the deque is empty
        if (front == NULL && rear == NULL) {
            front = new Node(value);        // Create a new node with the given value
            rear = front;                   // Both front and rear point to the new node
            cout << "Data " << value << " pushed in front of deque." << endl;
        } 
        // Deque is not empty, so we need to insert at the front
        else {
            Node* temp = new Node(value);   // Create a new node
            temp->next = front;             // Set new node's next to current front node
            front->prev = temp;             // Update the current front node's prev to new node
            front = temp;                   // Update front to point to the new node
            cout << "Data " << value << " pushed in front of deque." << endl;
        }
    }

    // Method to insert an element at the rear of the deque
    void push_back(int value) {
        // Check if the deque is empty
        if (front == NULL && rear == NULL) {
            rear = new Node(value);         // Create a new node with the given value
            front = rear;                   // Both front and rear point to the new node
            cout << "Data " << value << " pushed in back of deque." << endl;
        } 
        // Deque is not empty, so we need to insert at the rear
        else {
            Node* temp = new Node(value);   // Create a new node
            temp->prev = rear;              // Set new node's prev to the current rear node
            rear->next = temp;              // Update the current rear node's next to the new node
            rear = temp;                    // Update rear to point to the new node
            cout << "Data " << value << " pushed in back of deque" << endl;
        }
    }

    // Method to remove an element from the front of the deque
    void pop_front() {
        // Check if the deque is empty
        if (front == NULL && rear == NULL) {
            cout << "Deque is empty!" << endl;
            return;
        } 
        // Deque is not empty, so we need to remove from the front
        else {
            Node* temp = front;             // Node to be removed
            cout << "Data " << temp->data << " popped from front of deque" << endl;
            front = front->next;            // Move front to the next node
            delete temp;                    // Delete the old front node

            // If there are still elements left in the deque
            if (front)
                front->prev = NULL;         // Set the new front node's prev to NULL
            else
                rear = NULL;                // If deque is now empty, set rear to NULL as well
        }
    }

    // Method to remove an element from the rear of the deque
    void pop_back() {
        // Check if the deque is empty
        if (front == NULL && rear == NULL) {
            cout << "Deque is empty!" << endl;
            return;
        } 
        // Deque is not empty, so we need to remove from the rear
        else {
            Node* temp = rear;              // Node to be removed
            cout << "Data " << temp->data << " popped from back of deque" << endl;
            rear = rear->prev;              // Move rear to the previous node
            delete temp;                    // Delete the old rear node

            // If there are still elements left in the deque
            if (rear)
                rear->next = NULL;          // Set the new rear node's next to NULL
            else
                front = NULL;               // If deque is now empty, set front to NULL as well
        }
    }

    // Method to get the data from the front of the deque
    int getFront() {
        // Check if the deque is empty
        if (front == NULL && rear == NULL) {
            return -1;                      // Return -1 to indicate that the deque is empty
        } else {
            return front->data;             // Return the data from the front node
        }
    }

    // Method to get the data from the rear of the deque
    int getBack() {
        // Check if the deque is empty
        if (front == NULL && rear == NULL) {
            return -1;                      // Return -1 to indicate that the deque is empty
        } else {
            return rear->data;              // Return the data from the rear node
        }
    }
};


int main() {
    Deque dq;
    dq.push_back(5);
    dq.push_front(8);
    cout << "Front element of dqueue: " << dq.getFront() << endl;
    cout << "Rear element of dqueue: " << dq.getBack() << endl;
    cout << endl;

    dq.pop_back();
    cout << "Rear element of dqueue: " << dq.getBack() << endl;
    cout << endl;

    dq.pop_back();
    dq.pop_back();

    return 0;
}

//* **********************************************
    //* Time Complexity : O(1)
    //* Space Complexity : O(N) 
//* **********************************************