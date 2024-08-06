#include <iostream>
using namespace std;


// Function to perform binary search on a sorted array
bool binarySearch(int arr[], int start, int end, int target) {
    // Base case: When start index is greater than end index, target is not found
    if (start > end) {
        return false;
    }

    // Calculate the middle index
    int mid = start + (end - start) / 2;

    // Check if the middle element is the target
    if (arr[mid] == target) {
        return true;
    }
    // If the target is greater than the middle element, search in the right half
    else if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, end, target);
    }
    // If the target is less than the middle element, search in the left half
    else {
        return binarySearch(arr, start, mid - 1, target);
    }
}


int main() {
    int array[] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(int);
    int start = 0;
    int end = size - 1;
    int target = 40;

    bool isFound = binarySearch(array, start, end, target);
    // if(isFound)
    //     cout << target << " present in array." << endl;
    // else
    //     cout << target << " not present in array." << endl;

    cout << target << (isFound ? " present in array." : " not present in array.") << endl;

    return 0;
}

//* **********************************************
//* Time Complexity : O(log(N))
//* Space Complexity : O(log(N))
//* **********************************************