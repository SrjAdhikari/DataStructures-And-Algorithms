#include <iostream>
#include <queue>
using namespace std;

// Node class to represent each element in the queue
class Node {
    public:
    int data;    // Data stored in the node
    Node* next;  // Pointer to the next node in the queue

    // Constructor to initialize a node with the given value
    Node(int value) {
        data = value;   // Set data
        next = NULL;    // Initially, the next pointer is NULL
    }
};

// Queue class using a linked list
class Queue {
    Node* front;  // Pointer to the front element in the queue
    Node* rear;   // Pointer to the rear element in the queue

    public:
    // Constructor to initialize the queue
    Queue() {
        front = rear = NULL;  // Both front and rear are NULL, indicating the queue is empty
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        // Queue is empty if both front and rear are NULL
        return (front == NULL && rear == NULL);
    }

    // Function to insert an element at the rear of the queue (enqueue operation)
    void push(int data) {
        // If the queue is empty, create a new node and set both front and rear to this node
        if(isEmpty()) {
            cout << "Data " << data << " pushed into the Queue." << endl;
            front = new Node(data);  // Create new node
            rear = front;            // Since it's the only node, front and rear are the same
            return;
        }
        // Otherwise, create a new node and add it to the end of the queue
        else {
            rear->next = new Node(data);  // Link the new node to the rear
            cout << "Data " << data << " pushed into the Queue." << endl;
            rear = rear->next;            // Update rear to point to the new node
        }
    }

    // Function to remove the front element from the queue (dequeue operation)
    void pop() {
        // If the queue is empty, there's nothing to remove
        if(isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        // Otherwise, remove the front node and update the front pointer
        else {
            cout << "Data " << front->data << " popped from the Queue." << endl;
            Node* temp = front;   // Temporary pointer to hold the current front node
            front = front->next;  // Move front to the next node
            delete temp;          // Free the memory of the removed node
        }
    }

    // Function to get the front element without removing it
    int getFront() {
        // If the queue is empty, return -1
        if(isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        // Otherwise, return the data of the front node
        else {
            return front->data;
        }
    }

    // Function to get the rear element without removing it
    int getRear() {
        // If the queue is empty, return -1
        if(isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        // Otherwise, return the data of the rear node
        else {
            return rear->data;
        }
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout << endl;

    cout << "Current front data of Queue: " << q.getFront() << endl;
    cout << "Current rear data of Queue: " << q.getRear() << endl;
    cout << endl;

    q.pop();
    q.push(60);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(1)
    //* Space Complexity : O(N) 
//* ********************************************** 