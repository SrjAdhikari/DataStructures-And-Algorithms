#include<iostream>
using namespace std;

// Function to find the last occurrence of a target element in a sorted array
// arr[]: the array in which to search
// size: the number of elements in the array
// target: the element to search for

int findLastOccurrence(int arr[], int size, int target) {
    int start = 0;                 // Initialize start index
    int end = size - 1;            // Initialize end index
    int lastOccurrence = -1;       // Initialize the result variable

    // Loop until the search space is exhausted
    while (start <= end) {

        // Calculate the mid element index
        int mid = start + (end - start) / 2;  

        // Check if the target is present at mid
        if (arr[mid] == target) {
            lastOccurrence = mid;   // Update the last occurrence index
            start = mid + 1;        // Continue to search in the right half
        }
        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            start = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            end = mid - 1;
        }
    }
    // Return the last occurrence index, or -1 if not found
    return lastOccurrence;
}

// Time Complexity = O(logn)
// Space Complexity = O(1)


int main(){
    int arr[] = {10, 20, 30, 30, 30, 40, 50};
    int size = sizeof(arr) / sizeof(int);
    int target = 30;

    int lastOccur = findLastOccurrence(arr, size, target);
    cout << "First Occurrence of " << target << " is : " << lastOccur << endl;

    return 0;
}