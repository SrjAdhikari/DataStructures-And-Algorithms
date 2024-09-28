#include <iostream>
using namespace std;

class MaxHeap {
public:
    int* arr;         // Pointer to an array that represents the heap.
    int size;         // Current size of the heap (number of elements in the heap).
    int capacity;     // Maximum capacity of the heap.

    // Constructor: Initializes the heap with a given capacity.
    Heap (int n) {
        arr = new int[n];  // Dynamically allocate memory for the heap array.
        size = 0;          // Initially, the heap is empty.
        capacity = n;      // Set the maximum capacity for the heap.
    }

    // Function to insert a new value into the heap. 0-index based insertion
    void insertion (int value) {
        // Step 1: Check if the heap is full. If so, print a message and return.
        if(size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }

        // Step 2: Insert the new value at the end of the heap (at index 'size').
        arr[size] = value;  // Place the new value at the end (next available spot).
        int index = size;   // Index of the newly inserted element.
        size++;             // Increase the size of the heap by 1.

        // Step 3: Heapify-up to maintain the max-heap property.
        // Compare the new element with its parent and swap if the new element is larger.
        while(index > 0) {
            // Calculate the parent index of the current node.
            int parentIndex = (index - 1) / 2;

            // If the parent node is smaller than the current node, swap them.
            if(arr[parentIndex] < arr[index]) {
                swap(arr[parentIndex], arr[index]);

                // Move the index to the parent and continue heapifying up.
                index = parentIndex;
            }
            // If the parent node is larger, the max-heap property is satisfied.
            else {
                break;
            }
        }
        cout << arr[index] << " inserted into Heap!" << endl;
    }

    // Function to print all elements of the heap.
    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
};

int main() {
    // Create a heap of capacity 5.
    MaxHeap h(5);

    // Insert values into the heap and print after each series of insertions.
    h.insertion(10);
    h.insertion(20);
    h.insertion(30);
    h.print();

    h.insertion(40);
    h.insertion(50);
    h.print();

    // Try to insert 60 into the heap. This should print "Heap is full!" since the heap capacity is 5.
    h.insertion(60);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(logN)
    //* Space Complexity : O(N)
//* ********************************************** 