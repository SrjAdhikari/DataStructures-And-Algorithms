#include<iostream>
using namespace std;

int findMissingElement(int arr[], int size) {
    int start = 0;                 // Initialize start index
    int end = size - 1;            // Initialize end index
    int missingNum = -1;           // Initialize missing number to -1

    while (start <= end) {

        // Calculate the mid index to avoid overflow
        int mid = start + (end - start) / 2; 

        // Calculate the difference between the element at mid and the mid index
        int diff = arr[mid] - mid;

        // If the difference is 1, the missing number is not in the left half
        if (diff == 1) {
            start = mid + 1;       // Move to the right half
        } 
        // If the difference is not 1, the missing number is in the left half
        else {
            missingNum = mid;      // Update the missing number
            start = mid + 1;       // Continue to search in the right half
        }
    }

    // Check if the missing number was not updated and handle the edge case
    if (missingNum + 1 == 0) {
        return size + 1;  // Return size + 1 if the missing number is not found within the range
    }

    // Return the missing number, which is the last updated mid index + 1
    return missingNum + 1;
}

// Time Complexity = O(logn)
// Space Complexity = O(1)


int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = 8;

    int missingElement = findMissingElement(arr, size);
    cout << "Missing Number is : " << missingElement << endl;

    return 0;
}