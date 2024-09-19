#include <iostream>
using namespace std;

class Deque {
    int size;         // Capacity of the deque
    int front;        // Index of the front element in the deque
    int rear;         // Index of the rear element in the deque
    int* arr;         // Pointer to the array storing deque elements

    public:
    // Constructor to initialize the deque with a given capacity
    Deque(int n) {
        size = n;                  // Set the maximum number of elements the deque can hold
        arr = new int[n];          // Allocate memory for the array to hold deque elements
        front = rear = -1;         // Initialize front and rear to -1 indicating an empty deque
    }

    // Method to check if the deque is empty
    bool isEmpty() {
        // Deque is empty if both front and rear are -1
        return (front == -1 && rear == -1); 
    }
    // Method to check if the deque is full
    bool isFull() {
        // The deque is full if the next position of rear (in a circular manner) is equal to front
        return ((rear + 1) % size == front); 
    }

    // Method to insert an element at the front of the deque
    void push_front(int value) {
        // If the deque is empty, insert the first element at position 0
        if(isEmpty()) {
            front = rear = 0;       // Set both front and rear to 0
            arr[0] = value;         // Insert the value at the front
            cout << value << " pushed in front of deque." << endl;
            return;
        }
        // If the deque is full, cannot add more elements
        else if(isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        else {
            // Move the front index to the previous position in a circular manner
            front = (front - 1 + size) % size;
            arr[front] = value;     // Insert the value at the new front index
            cout << value << " pushed in front of deque." << endl;
            return;
        }
    }

    // Method to insert an element at the rear of the deque
    void push_back(int value) {
        // If the deque is empty, insert the first element at position 0
        if(isEmpty()) {
            front = rear = 0;       // Set both front and rear to 0
            arr[0] = value;         // Insert the value at the rear
            cout << value << " pushed in back of deque." << endl;
            return;
        }
        // If the deque is full, cannot add more elements
        else if(isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        else {
            // Move the rear index to the next position in a circular manner
            rear = (rear + 1) % size;
            arr[rear] = value;      // Insert the value at the new rear index
            cout << value << " pushed in back of deque." << endl;
            return;
        }
    }

    // Method to remove an element from the front of the deque
    void pop_front() {
        // If the deque is empty, cannot remove elements
        if(isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        else {
            cout << arr[front] << " popped from front of deque." << endl;
            // If there is only one element in the deque
            if (front == rear) {
                // Set both front and rear to -1 indicating an empty deque
                front = rear = -1; 
            } 
            else {
                // Move the front index to the next position in a circular manner
                front = (front + 1) % size;
            }
        }
    }

    // Method to remove an element from the rear of the deque
    void pop_back() {
        // If the deque is empty, cannot remove elements
        if(isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        else {
            cout << arr[rear] << " popped from back of deque." << endl;
            // If there is only one element in the deque
            if (front == rear) {
                // Set both front and rear to -1 indicating an empty deque
                front = rear = -1; 
            } 
            else {
                // Move the rear index to the previous position in a circular manner
                rear = (rear - 1 + size) % size;
            }
        }
    }

    // Method to get the data from the front of the deque
    int getFront() {
        if (isEmpty()) {
            return -1;          // Return -1 to indicate that the deque is empty
        } else {
            return arr[front];  // Return the data at the front index
        }
    }

    // Method to get the data from the rear of the deque
    int getBack() {
        if (isEmpty()) {
            return -1;          // Return -1 to indicate that the deque is empty
        } else {
            return arr[rear];   // Return the data at the rear index
        }
    }
};


int main() {
    Deque dq(5);
    dq.push_back(10);
    dq.push_back(20);
    cout << endl;

    dq.push_front(15);
    dq.push_front(25);
    cout << endl;

    cout << "Front element of dqueue: " << dq.getFront() << endl;
    cout << "Rear element of dqueue: " << dq.getBack() << endl;
    cout << endl;

    dq.push_front(30);
    cout << endl;

    dq.pop_back();
    dq.pop_back();
    dq.pop_front();
    cout << endl;

    cout << "Front element of dqueue: " << dq.getFront() << endl;
    cout << "Rear element of dqueue: " << dq.getBack() << endl;
    cout << endl;

    return 0;
}

//* **********************************************
    //* Time Complexity : O(1)
    //* Space Complexity : O(N) 
//* **********************************************