#include <iostream>
#include<limits.h>
using namespace std;

void reverseArray(int arr[], int size){

    // Two Pointer Approach
    int start = 0;
    int end = size - 1;

    while(start <= end){

        // InBuilt function to swap two elements.
        swap(arr[start], arr[end]);

        // Update start and end
        start++;
        end--;
    }
}


int main(){

    int arr[100];
    int size;

    cout << "Enter the number of elements" << endl;
    cin >> size;
    cout << endl;

    // User input for array elements
    for(int i=0; i< size; i++) {
        cout << "Enter the input value for index : " << i << endl;
        cin >> arr[i];
    }
    cout << endl;

    reverseArray(arr, size);        // Function call

    cout << "Reverse array is : " << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(1) 
//* ********************************************** 