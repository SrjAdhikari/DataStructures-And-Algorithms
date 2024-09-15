#include <iostream>
using namespace std;

class Queue {
    int* arr;           // Array to store queue elements
    int front, rear;    // Indices to track the front and rear of the queue
    int size;           // Maximum size of the queue

public:
    // Constructor to initialize the queue with a given size
    Queue(int n) {
        arr = new int[n];    // Dynamically allocate an array of size n
        front = rear = -1;   // Set front and rear to -1 indicating an empty queue
        size = n;            // Set the size of the queue
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        // The queue is empty if both front and rear are -1
        return (front == -1 && rear == -1);
    }

    // Function to check if the queue is full
    bool isFull() {
        // The queue is full if the next position of rear is the same as front
        // (Circular queue condition)
        return ((rear + 1) % size == front);
    }

    // Function to add an element to the queue
    void push(int data) {
        if (isFull()) {
            // If the queue is full, we cannot insert an element
            cout << "Queue is full." << endl;
            return;
        }
        else if (isEmpty()) {
            // If the queue is empty, set both front and rear to 0 
            // And Insert the element at the first position (index 0)
            cout << "Data " << data << " pushed in Queue." << endl;
            front = rear = 0;
            arr[0] = data;
        }
        // If the queue is not empty, move rear to the next position circularly and insert data
        else {
            // Update rear using modulo operator for circular behavior
            rear = (rear + 1) % size;
            // Insert the data at the new rear position
            arr[rear] = data;
            cout << "Data " << data << " pushed in Queue." << endl;
        }
    }

    // Function to remove the front element from the queue
    void pop() {
        if (isEmpty()) {
            // If the queue is empty, we cannot remove any element
            cout << "Queue is empty." << endl;
            return;
        }
        else if (front == rear) {
            // If there is only one element, remove it and reset front and rear
            cout << "Data " << arr[front] << " popped from Queue." << endl;

            // Reset both front and rear to -1 to indicate the queue is now empty
            front = rear = -1;
        }
        // Otherwise, move the front pointer to the next position circularly
        else {
            cout << "Data " << arr[front] << " popped from Queue." << endl;

            // Update front using modulo operator for circular behavior
            front = (front + 1) % size;
        }
    }

    // Function to get the front element of the queue without removing it
    int getFront() {
        // If the queue is empty, return -1 and indicate it's empty
        if(isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        // Otherwise, return the element at the front of the queue
        else {
            return arr[front];
        }
    }

    // Function to get the rear element of the queue
    int getRear() {
        // If the queue is empty, return -1 and indicate it's empty
        if(isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        // Otherwise, return the element at the rear of the queue
        else {
            return arr[rear];
        }
    }

    // Function to get the current number of elements in the queue
    int getSize() {
        // If the queue is empty, return 0
        if(isEmpty()) {
            cout << "Queue is empty." << endl;
            return 0;
        }
        // If the rear is ahead of the front (normal case)
        else if(rear >= front) {
            return rear - front + 1;
        }
        // If the rear is behind the front (circular case)
        else {
            return (size - front + rear + 1);
        }
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] arr;  // Deallocate the dynamically allocated memory
    }
};

int main() {
    Queue q(5);  // Create a queue with a capacity of 5

    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << endl;

    // Display the current size, front, and rear of the queue
    cout << "Current size of Queue: " << q.getSize() << endl;
    cout << "Current front data of Queue: " << q.getFront() << endl;
    cout << "Current rear data of Queue: " << q.getRear() << endl;
    cout << endl;

    // Perform pop and push operations
    q.pop();
    q.push(50);
    q.push(60);  // This will wrap around in the circular queue
    q.pop();
    cout << endl;

    // Display updated size and front data
    cout << "Current size of Queue: " << q.getSize() << endl;
    cout << "Current front data of Queue: " << q.getFront() << endl;
    cout << endl;

    return 0;
}

//* **********************************************
    //* Time Complexity : O(1)
    //* Space Complexity : O(N) 
//* ********************************************** 