#include <iostream>
using namespace std;

//* 1. Function to print elements of an array from the beginning to the end using recursion
void printArray(int arr[], int size, int index) {
    // Base case: When index is equal to or greater than size, stop recursion
    if (index >= size) {
        return;
    }

    // Print the current element
    cout << arr[index] << "  ";

    // Recursively call printArray for the next index
    printArray(arr, size, index + 1);
}

//* 2. Function to print elements of an array from the end to the beginning using recursion
void printArray2(int arr[], int index) {
    // Base case: When index is negative, stop recursion
    if (index < 0) {
        return;
    }

    // Recursively call printArray2 for the previous index
    printArray2(arr, index - 1);

    // Print the current element (after recursive call, thus in reverse order)
    cout << arr[index] << "  ";
}


int main() {
    int array[] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(int);
    int firstIndex = 0;
    int lastIndex = size - 1;

    cout << "Printing array from 0 index : " << endl;
    printArray(array, size, firstIndex);
    cout << endl;

    cout << "Printing array from last index : " << endl;
    printArray2(array, lastIndex);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) 
//* ********************************************** 