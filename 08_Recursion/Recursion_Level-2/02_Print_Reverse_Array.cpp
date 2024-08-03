#include <iostream>
using namespace std;

//* 1. Function to print elements of an array in reverse order using recursion
void printReverse(int arr[], int size, int index) {
    // Base case: When index is equal to or greater than size, stop recursion
    if (index >= size) {
        return;
    }

    // Recursive call to process the next element
    printReverse(arr, size, index + 1);

    // Print the current element after the recursive call
    cout << arr[index] << "  ";
}

//* 2. Function to print elements of an array in reverse order using recursion with different logic
void printReverse2(int arr[], int index) {
    // Base case: When index is negative, stop recursion
    if (index < 0) {
        return;
    }

    // Print the current element before the recursive call
    cout << arr[index] << "  ";
    
    // Recursive call to process the previous element
    printReverse2(arr, index - 1);
}


int main() {
    int array[] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(int);
    int firstIndex = 0;
    int lastIndex = size - 1;

    cout << "Printing reverse array from 0 index : " << endl;
    printReverse(array, size, firstIndex);
    cout << endl;

    cout << "Printing reverse array from last index : " << endl;
    printReverse2(array, lastIndex);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) 
//* ********************************************** 