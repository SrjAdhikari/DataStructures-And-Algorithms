//* **********************************************************************
    // Given a sorted array arr[] of size N, some elements of array are moved to either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1] i.e. arr[i] can only be swapped with either arr[i+1] or arr[i-1]. The task is to search for an element in this array.

    // Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
    // Output: 2
    // Explanation: Output is index of 40 in given array i.e. 2

    // Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 90
    // Output: -1
    // Explanation: -1 is returned to indicate the element is not present
//* **********************************************************************

#include<iostream>
using namespace std;

int searchTarget(int arr[], int n, int target) {

    // Initialize the start and end pointers for the search
    int start = 0;
    int end = n - 1;

    // Perform binary search
    while (start <= end) {
        // Calculate the mid index to avoid potential overflow
        int mid = start + (end - start) / 2;

        // Check if the mid element is the target
        if (arr[mid] == target)
            return mid;

        // Check if the element just before mid is the target
        if (mid > start && arr[mid - 1] == target)
            return mid - 1;

        // Check if the element just after mid is the target
        if (mid < end && arr[mid + 1] == target)
            return mid + 1;

        // If the target is greater than the mid element, move start to mid + 2
        if (arr[mid] < target)
            start = mid + 2;

        // If the target is less than the mid element, move end to mid - 2
        else
            end = mid - 2;
    }

    // If the target is not found, return -1
    return -1;
}


int main(){

    int arr[] = {10, 3, 40, 20, 50, 80, 70};
    int size = 7;
    int target = 20;

    int targetIndex = searchTarget(arr, size, target);
    cout << "Tartget found at Index: " << targetIndex << endl;
    
    return 0;
}

// Time Complexity = O(logn)
// Space Complexity = O(1)