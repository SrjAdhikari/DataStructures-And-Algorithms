#include <iostream>
using namespace std;

// Function to print even numbers in an array using recursion (forward approach)
void printEvenNum(int arr[], int size, int index) {
    // Base case: When index is out of bounds, stop recursion
    if (index >= size) {
        return;
    }

    // Check if the current element is even and print it
    if (arr[index] % 2 == 0) {
        cout << arr[index] << "  ";
    }

    // Recursive call to process the next index
    printEvenNum(arr, size, index + 1);
}


// Function to print even numbers in an array using recursion (backward approach)
void printEvenNumber(int arr[], int index) {
    // Base case: When index is less than or equal to 0, stop recursion
    if (index < 0) {
        return;
    }

    // Check if the current element is even and print it
    if (arr[index] % 2 == 0) {
        cout << arr[index] << "  ";
    }

    // Recursive call to process the previous index
    printEvenNumber(arr, index - 1);
}


int main() {
    int array[] = {1, 4, 9, 10, 6, 14, 25, 21, 20};
    int size = sizeof(array) / sizeof(int);
    int firstIndex = 0;
    int lastIndex = size - 1;

    cout << "Printing even elemet from 0 index : " << endl;
    printEvenNum(array, size, firstIndex);
    cout << endl;

    cout << "Printing even elemet from last index : " << endl;
    printEvenNumber(array, lastIndex);

    return 0;
}

//* **********************************************
//* Time Complexity : O(N)
//* Space Complexity : O(N)
//* **********************************************