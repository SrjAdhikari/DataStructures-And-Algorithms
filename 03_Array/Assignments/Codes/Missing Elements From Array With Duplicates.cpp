#include<iostream>
#include<vector>
using namespace std;

/*
    i/p => array = {1, 3, 5, 3, 4}
    o/p => 2
*/


//* ********************* Visited Method *********************
    void findMissingElementVisitedMethod(int arr[], int size) {

    // Mark visited elements by making the value at the corresponding index negative
    for(int i = 0; i < size; i++) {

        // Get the absolute value of the current element
        int index = abs(arr[i]);

        // If the element at the index position (index-1) is positive, make it negative to mark it visited
        if(arr[index - 1] > 0)
            arr[index - 1] *= -1;
    }

    // Find the first positive element which indicates the missing number
    for(int i = 0; i < size; i++) {

        // If the element is positive, the corresponding index+1 is the missing number
        if(arr[i] > 0)
            cout << "Missing Element is : " << i + 1 << endl;
    }
}

    //* *******************************************
    //* Time Complexity = O(n)
    //* Space Complexity = O(1)
    //* *******************************************
//* **********************************************************


//* ********************* Swapping Method *********************
    void findMissingElementSwappingMethod(int arr[], int size) {
    int i = 0;

    // Place each element at its correct position
    while(i < size) {
        int index = arr[i] - 1;     // Calculate the correct index for arr[i]

        // If the element is not in its correct position, swap it with the element at its correct position
        if(arr[i] != arr[index]) {
            swap(arr[i], arr[index]);
        }
        else {
            i++;    // Move to the next element if the current element is already in its correct position
        }
    }

    // Second pass: Identify the missing element
    for(int i = 0; i < size; i++) {

        // If the element at index i is not equal to i + 1, then i + 1 is the missing element
        if(arr[i] != i + 1) {
            cout << "Missing Element is : " << i + 1 << endl;
        }
    }
}

    //* *******************************************
    //* Time Complexity = O(n)
    //* Space Complexity = O(1)
    //* *******************************************
//* **********************************************************



int main(){
    int array[] = {1, 3, 5, 3, 4};
    int size = sizeof(array) / sizeof(int);

    // findMissingElementVisitedMethod(array, size);
    findMissingElementSwappingMethod(array, size);

    return 0;
}