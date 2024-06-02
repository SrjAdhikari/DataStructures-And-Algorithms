# Binary Search Template Code

```Cpp

// Function to perform binary search on a sorted array
// arr[]: the array in which to search
// size: the number of elements in the array
// target: the element to search for

int binarySearch(int arr[], int size, int target) {

    int start = 0;       // Initialize start index
    int end = size - 1;  // Initialize end index

    // Loop until the search space is exhausted
    while (start <= end) {

        // Calculate the mid element index to avoid overflow
        int mid = start + (end - start) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid;  // Target found, return the index
        }

        // If target is greater, ignore the left half & search in right half
        else if (arr[mid] < target) {
            start = mid + 1;
        }

        // If target is smaller, ignore the right half & search in left half
        else {
            end = mid - 1;
        }
    }

    // Target is not present in the array
    return -1;
}

Time Complexity = O(logn)
Space Complexity = O(1)
```