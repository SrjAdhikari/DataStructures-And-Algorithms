#include <iostream>
#include <queue>
using namespace std;

class Queue {
    int* arr;         // Dynamic array to store queue elements
    int front, rear;  // Indices to track the front and rear of the queue
    int size;         // Maximum size of the queue

public:
    // Constructor to initialize the queue with a fixed size
    Queue(int n) {
        arr = new int[n];  // Allocate memory for the queue
        front = rear = -1; // Initially, both front and rear are set to -1 (queue is empty)
        size = n;          // Set the size of the queue
    }

    // Check if the queue is empty
    bool isEmpty() {
        // If both front and rear are -1, the queue is empty
        if(front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    // Check if the queue is full
    bool isFull() {
        // If the rear is at the last index, the queue is full
        if(rear == size - 1)
            return true;
        else
            return false;
    }

    // Function to push an element into the queue
    void push(int data) {
        // If the queue is full, display a message and return
        if(isFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        // If the queue is empty, insert the first element
        else if(isEmpty()) {
            cout << "Data " << data << " pushed in Queue." << endl;
            front = rear = 0; // Set both front and rear to 0 (first position)
            arr[0] = data;    // Insert the data at the 0th index
        }
        // Otherwise, insert the element at the rear and increment the rear
        else {
            rear++;
            arr[rear] = data;
            cout << "Data " << data << " pushed in Queue." << endl;
        }
    }

    // Function to pop an element from the queue
    void pop() {
        // If the queue is empty, display a message and return
        if(isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        // If there is only one element, reset the queue after popping
        else if(front == rear) {
            cout << "Data " << arr[front] << " popped from Queue." << endl;
            front = rear = -1;  // Reset the queue
        }
        // Otherwise, pop the front element and increment the front
        else {
            cout << "Data " << arr[front] << " popped from Queue." << endl;
            front++;
        }
    }

    // Function to get the front element of the queue
    int getFront() {
        // If the queue is empty, display a message
        if(isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;  // Return -1 to indicate empty queue
        }
        // Otherwise, return the front element
        else {
            return arr[front];
        }
    }

    // Function to get the rear element of the queue
    int getRear() {
        // If the queue is empty, display a message
        if(isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;  // Return -1 to indicate empty queue
        }
        // Otherwise, return the rear element
        else {
            return arr[rear];
        }
    }

    // Function to get the current size of the queue
    int getSize() {
        // If the queue is empty, return size 0
        if(isEmpty()) {
            cout << "Queue is empty." << endl;
            return 0;
        }
        // Otherwise, return the number of elements (rear - front + 1)
        else {
            return rear - front + 1;
        }
    }
};

int main() {
    // Create a queue of size 5
    Queue q(5);
    
    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout << endl;

    // Display the current size, front, and rear element
    cout << "Current size of Queue: " << q.getSize() << endl;
    cout << "Current front data of Queue: " << q.getFront() << endl;
    cout << "Current rear data of Queue: " << q.getRear() << endl;
    cout << endl;

    // Pop elements from the queue
    q.pop();
    q.pop();

    // Display the updated size and front element after popping
    cout << "Current size of Queue: " << q.getSize() << endl;
    cout << "Current front data of Queue: " << q.getFront() << endl;
    cout << endl;

    return 0;
}

//* **********************************************
    //* Time Complexity : O(1)
    //* Space Complexity : O(N) 
//* ********************************************** 