#include <iostream>
using namespace std;


// Function to check if an array is sorted in non-decreasing order using recursion
bool isSorted(int arr[], int size, int index) {
    // Base case: If index is the last element, the array is sorted
    if (index >= size) {
        return true;
    }

    // Check if the current element is less than the previous element
    if (arr[index] < arr[index - 1]) {
        return false;
    }

    // Recursive case: Check the rest of the array from the next index
    return isSorted(arr, size, index + 1);
}


int main() {
    int array[] = {10, 30, 50, 70, 90, 100};
    int size = sizeof(array) / sizeof(int);
    int index = 1;

    bool sorted = isSorted(array, size, index);
    cout << (sorted ? "Array is sorted" : "Array is not sorted") << endl;

    return 0;
}

//* **********************************************
//* Time Complexity : O(N)
//* Space Complexity : O(N)
//* **********************************************