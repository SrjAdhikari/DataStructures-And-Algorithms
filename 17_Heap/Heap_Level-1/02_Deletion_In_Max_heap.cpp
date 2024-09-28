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

    // Function to delete the root element (maximum element in max-heap).
    void deletion() {
        // If the heap is empty, print a message and return.
        if(size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }

        // Print the value that is being deleted (the root of the heap).
        cout << arr[0] << " is deleted from Heap!" << endl;

        // Replace the root with the last element in the heap.
        arr[0] = arr[size - 1];

        // Decrease the size of the heap since we've removed an element.
        size--;

        // Now, perform heapify-down operation starting from the root to maintain heap property.
        int index = 0;

        // Perform the heapify operation: Compare the node with its children and swap if necessary.
        while(index < size) {
            int largest = index;          // Assume the current node is the largest.
            int left = 2 * index + 1;     // Left child index.
            int right = 2 * index + 2;    // Right child index.

            // Check if the left child exists and is larger than the current node.
            if(left < size && arr[left] > arr[largest])
                largest = left;           // Update largest to be the left child.

            // Check if the right child exists and is larger than the largest node so far.
            if(right < size && arr[right] > arr[largest])
                largest = right;          // Update largest to be the right child.

            // If the largest is not the current node, swap with the largest child.
            if(largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;          // Move to the largest child and repeat the process.
            }
            // If no swaps are needed, the heap property is restored, and we can stop.
            else {
                break;
            }
        }
    }

    // Function to print the elements of the heap.
    void print() {
        // Loop through the heap array and print each element.
        for(int i = 0; i < size; i++) { 
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

//* **********************************************
    //* Time Complexity : O(logN)
    //* Space Complexity : O(N)
//* ********************************************** 