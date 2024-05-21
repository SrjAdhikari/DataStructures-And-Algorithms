#include <iostream>
using namespace std;

void printAllPairs(int arr[], int size){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
        }
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

    cout << "All pairs are : " << endl;
    printAllPairs(arr, size);        // Function call
    
    return 0;
}

// Time Complexity = O(n^2)
// Space Complexity = O(1)