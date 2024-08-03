#include <iostream>
#include <algorithm>
using namespace std;

//* 1. Function to find the minimum element in an array using recursion
int findMinimum(int arr[], int size, int index) {
    // Base case: When index is the last element, return the element itself
    if (index == size - 1) {
        return arr[index];
    }

    // Recursive case: Compare the current element with the minimum of the rest of the array
    return min(arr[index], findMinimum(arr, size, index + 1));
}

//* 2. Function to find the minimum element in an array using recursion (alternative approach)
int findMinimum2(int arr[], int index) {
    // Base case: When index is 0, return the first element
    if (index == 0) {
        return arr[index];
    }
    
    // Recursive case: Compare the current element with the minimum of the previous elements
    return min(arr[index], findMinimum2(arr, index - 1));
}


int main() {
    int array[] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(int);
    int firstIndex = 0;
    int lastIndex = size - 1;

    int minNumber = findMinimum(array, size, firstIndex);
    cout << "Minimum number from 0 index : " << minNumber << endl;

    int minElement = findMinimum2(array, lastIndex);
    cout << "Minimum number from last index : " << minElement << endl;

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) 
//* ********************************************** 