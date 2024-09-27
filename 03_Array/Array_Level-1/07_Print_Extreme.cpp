#include <iostream>
using namespace std;

void printExtreme(int arr[], int size){

    // Two Pointer Approach
    int start = 0;
    int end = size - 1;

    while(start <= end){
        if(start == end){
            cout << arr[start] << " ";
        }
        else{
            cout << arr[start] << " ";
            cout << arr[end] << " ";
        }

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

    cout << "Extreme print is : " << endl;
    printExtreme(arr, size);        // Function call
    
    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(1) 
//* ********************************************** 