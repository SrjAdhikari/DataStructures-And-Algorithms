#include<iostream>
using namespace std;

// Two Pointer Approach
void moveleft(int arr[], int size) {
    int start = 0, end = size - 1;          // Initialize two pointers: start at the beginning and end at the end of the array
    while (start < end) {                   // Continue loop until start is less than end
        if (arr[start] < 0)                 // If the element at start is negative, move to the next element by incrementing start
            start++;

        else if (arr[end] > 0)              // If the element at end is positive, move to the previous element by decrementing end
            end--;

        else                                // If neither condition above is met, swap the elements at start and end, and update pointers
            swap(arr[start], arr[end]);     // Swap elements at start and end
    }
}



int main(){

    int array[] = {1, 2, -3, 4, -5, 6};
    int size = 6;

    // Function Call
    moveleft(array, size);

    // Printing Array Elements
    for(int item : array){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}