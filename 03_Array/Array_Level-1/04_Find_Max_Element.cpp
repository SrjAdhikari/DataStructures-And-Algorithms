#include <iostream>
#include<limits.h>
using namespace std;

int findMaxNumber(int arr[], int size){

    int maxNum = INT_MIN;

    for(int i = 0; i < size; i++){
        if(arr[i] > maxNum){
            maxNum = arr[i];
        }
        
        // InBuilt function to find maximum between two values.
        // maxNum = max(maxNum, arr[i]);
    }
    return maxNum;
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

    // Function call
    int maxElement = findMaxNumber(arr, size);

    cout << "Max number is : " << maxElement << endl;
    
    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(1) 
//* ********************************************** 