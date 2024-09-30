#include <iostream>
using namespace std;

// Function to heapify an array
void heapify(int arr[], int size, int index) {
    int smallest = index;          // Assume the current node is the smallest.
    int left = 2 * index + 1;     // Left child index.
    int right = 2 * index + 2;    // Right child index.

    // Check if the left child exists and is smaller than the current node.
    if(left < size && arr[left] < arr[smallest])
        // Update smallest to be the left child.
        smallest = left;

    // Check if the right child exists and is smaller than the smallest node so far
    if(right < size && arr[right] < arr[smallest])
        // Update smallest to be the right child.
        smallest = right;

    // If the smallest is not the current node, swap with the smallest child & continue heapifying.
    if(smallest != index) {
        swap(arr[smallest], arr[index]);

        // Move to the smallest child and repeat the process.
        index = smallest;

        // Recursively heapify the affected sub-tree.
        heapify(arr, size, index);
    }
}

// Function to build a Max-Heap from an unsorted array.
void buildMinHeap(int arr[], int size) {
    // Step-down heapify
    // Start from the last non-leaf node and heapify each node.
    // Non-leaf nodes are located from size/2 - 1 to 0.
    for(int i = size / 2 - 1;i >= 0; i--) {
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

    buildMinHeap(arr, size);
    printHeap(arr, size);

    return 0;
}