#include <iostream>
using namespace std;

// Function to search for an element in an array using recursion (forward approach)
bool searchElement(int arr[], int size, int index, int target) {
    // Base case: If index is out of bounds, return false (element not found)
    if (index >= size) {
        return false;
    }

    // If the current element matches the target, return true
    if (arr[index] == target) {
        return true;
    }

    // Recursive case: Search in the remaining part of the array
    return searchElement(arr, size, index + 1, target);
}


// Function to search for an element in an array using recursion (backward approach)
bool searchElement(int arr[], int index, int target) {
    // Base case: If index is negative, return false (element not found)
    if (index < 0) {
        return false;
    }

    // If the current element matches the target, return true
    if (arr[index] == target) {
        return true;
    }
    
    // Recursive case: Search in the preceding part of the array
    return searchElement(arr, index - 1, target);
}



int main() {
    int array[] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(int);
    int firstIndex = 0;
    int target = 30;
    int lastIndex = size - 1;


    cout << "Searching elemet from 0 index : " << endl;
    bool isFound = searchElement(array, size, firstIndex, target);
    if (isFound)
        cout << "Target " << target << " is found." << endl;
    else
        cout << "Target " << target << " is not found." << endl;


    cout << "Searching elemet from last index : " << endl;
    bool isPresent = searchElement(array, lastIndex, target);
    if (isPresent)
        cout << "Target " << target << " is found." << endl;
    else
        cout << "Target " << target << " is not found." << endl;

    return 0;
}

//* **********************************************
//* Time Complexity : O(N)
//* Space Complexity : O(N)
//* **********************************************