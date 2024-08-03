#include <iostream>
using namespace std;

//* 1. Function to calculate the sum of elements in an array using recursion
int calculateSum(int arr[], int size, int index) {
    // Base case: When index is equal to or greater than size, return 0
    if (index >= size) {
        return 0;
    }

    // Recursive case: Add the current element to the sum of the remaining elements
    return arr[index] + calculateSum(arr, size, index + 1);
}

//* 2. Function to calculate the sum of elements in an array using recursion (alternative approach)
int calculateSum2(int arr[], int index) {
    // Base case: When index is less than 0, return 0
    if (index < 0) {
        return 0;
    }
    
    // Recursive case: Add the current element to the sum of the preceding elements
    return arr[index] + calculateSum2(arr, index - 1);
}


int main() {
    int array[] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(int);
    int firstIndex = 0;
    int lastIndex = size - 1;

    int arraySum = calculateSum(array, size, firstIndex);
    cout << "Calculate sum of array from 0 index : " << arraySum << endl;

    int totalSum = calculateSum2(array, lastIndex);
    cout << "Calculate sum of array from last index : " << totalSum << endl;

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) 
//* ********************************************** 