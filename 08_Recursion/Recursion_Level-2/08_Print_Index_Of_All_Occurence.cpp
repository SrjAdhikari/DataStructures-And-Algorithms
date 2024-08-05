#include <iostream>
using namespace std;


// Function to print the indices of occurrences of a target value in an array using recursion (forward approach)
void printOccurence(int arr[], int size, int index, int target) {
    // Base case: When index is out of bounds, stop recursion
    if (index >= size) {
        return;
    }

    // Print the current index if the current element matches the target
    if (arr[index] == target) {
        cout << index << " ";
    }

    // Recursive call to process the next element
    printOccurence(arr, size, index + 1, target);
}


// Function to print the indices of occurrences of a target value in an array using recursion (backward approach)
void printAllOccurence(int arr[], int index, int target) {
    // Base case: When index is less than 0, stop recursion
    if (index < 0) {
        return;
    }

    // Print the current index if the current element matches the target
    if (arr[index] == target) {
        cout << index << " ";
    }

    // Recursive call to process the previous element
    printAllOccurence(arr, index - 1, target);
}


int main() {
    int array[] = {1, 4, 9, 1, 6, 1, 25, 1, 20};
    int size = sizeof(array) / sizeof(int);
    int target = 1;
    int firstIndex = 0;
    int lastIndex = size - 1;

    cout << "Printing all occurence of" << target << " from 0 index : " << endl;
    printOccurence(array, size, firstIndex, target);
    cout << endl;

    cout << "Printing all occurence of" << target << " from last index : " << endl;
    printAllOccurence(array, lastIndex, target);

    return 0;
}

//* **********************************************
//* Time Complexity : O(N)
//* Space Complexity : O(N)
//* **********************************************