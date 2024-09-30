# Heapify / Heapification Template Code

### Heapify In Max-Heap

```Cpp

// Function to heapify an array
void heapify(int arr[], int index, int size) {
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
        heapify(arr, index, size);
    }
}

Time Complexity = O(N)
Space Complexity = O(logN)
```

### Heapify In Min-Heap

```Cpp

// Function to heapify an array
void heapify(int arr[], int index, int size) {
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
        heapify(arr, index, size);
    }
}

Time Complexity = O(N)
Space Complexity = O(logN)
```
