#include<iostream>
using namespace std;

int findPivotIndex(int arr[], int n) {

    // Initialize the start and end pointers to the beginning and end of the array, respectively
    int start = 0;
    int end = n - 1;

    // Perform a binary search to find the pivot element
    while (start <= end) {

        // Calculate the mid index to avoid potential overflow
        int mid = start + (end - start) / 2;

        // Single Element -> Corner Case        if (start == end) 
            return start;

        // Check if mid element is less than the previous element
        if (arr[mid] < arr[mid - 1]) {
            // If true, mid-1 is the pivot
            return mid - 1;
        }
        // Check if mid element is greater than the next element
        else if (arr[mid] > arr[mid + 1]) {
            // If true, mid is the pivot
            return mid;
        }
        // If the start element is greater than mid element, pivot must be in the left part
        else if (arr[start] > arr[mid]) {
            end = mid - 1;
        }
        // Otherwise, pivot must be in the right part
        else {
            start = mid + 1;
        }
    }
    // If no pivot is found, return -1
    return -1;
}

// Time Complexity = O(logn)
// Space Complexity = O(1)


int main(){
    int arr[] = {12, 14, 16, 2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(int);

    int pivotIndex = findPivotIndex(arr, size);
    cout << "Pivot element index is : " << pivotIndex << endl;

    return 0;
}