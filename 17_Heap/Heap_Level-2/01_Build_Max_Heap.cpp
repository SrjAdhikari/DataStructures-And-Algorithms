#include <iostream>
using namespace std;

// Function to heapify an array
void heapify(int arr[], int size, int index) {
    int largest = index;          // Assume the current node is the largest.
    int left = 2 * index + 1;     // Left child index.
    int right = 2 * index + 2;    // Right child index.

    // Check if the left child exists and is larger than the current node.
    if(left < size && arr[left] > arr[largest])
        // Update largest to be the left child.
        largest = left;

    // Check if the right child exists and is larger than the largest node so far.
    if(right < size && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the current node, swap with the largest child & continue heapifying.
    if(largest != index) {
        swap(arr[largest], arr[index]);

        // Move to the largest child and repeat the process.
        index = largest;

        // Recursively heapify the affected sub-tree.
        heapify(arr, size, index);
    }
}

// Function to build a Max-Heap from an unsorted array.
void buildMaxHeap(int arr[], int size) {
    // Step-down heapify
    // Start from the last non-leaf node and heapify each node.
    // Non-leaf nodes are located from size/2 - 1 to 0.
    for(int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

void printHeap(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    int size = sizeof(arr) / sizeof(int);

    buildMaxHeap(arr, size);
    printHeap(arr, size);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(logN)
//* ********************************************** 