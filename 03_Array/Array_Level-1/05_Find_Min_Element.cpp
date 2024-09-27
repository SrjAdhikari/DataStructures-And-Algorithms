#include <iostream>
#include<limits.h>
using namespace std;

int findMinNumber(int arr[], int size){

    int minNum = INT_MAX;

    for(int i = 0; i < size; i++){
        if(arr[i] < minNum){
            minNum = arr[i];
        }

        // InBuilt function to find minimum between two values.
        // minNum = min(minNum, arr[i]);
    }
    return minNum;
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
    int minElement = findMinNumber(arr, size);

    cout << "Min number is : " << minElement << endl;
    
    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(1) 
//* ********************************************** 