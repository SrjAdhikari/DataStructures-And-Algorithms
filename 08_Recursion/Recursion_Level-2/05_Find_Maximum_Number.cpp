#include <iostream>
#include <algorithm>
using namespace std;

// Function to find the maximum element in an array using recursion (forward approach)
int findMaximum(int arr[], int size, int index) {
    // Base case: When index is the last element, return that element
    if (index == size - 1) {
        return arr[index];
    }

    // Recursive case: Find the maximum of the current element and the result of the recursive call for the next index
    return max(arr[index], findMaximum(arr, size, index + 1));
}

// Function to find the maximum element in an array using recursion (backward approach)
int findMaximum2(int arr[], int index) {
    // Base case: When index is 0, return that element
    if (index == 0) {
        return arr[index];
    }

    // Recursive case: Find the maximum of the current element and the result of the recursive call for the previous index
    return max(arr[index], findMaximum2(arr, index - 1));
}


int main() {
    int array[] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(int);
    int firstIndex = 0;
    int lastIndex = size - 1;

    int maxNumber = findMaximum(array, size, firstIndex);
    cout << "Maximum number from 0 index : " << maxNumber << endl;

    int maxElement = findMaximum2(array, lastIndex);
    cout << "Maximum number from last index : " << maxElement << endl;

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) 
//* ********************************************** 