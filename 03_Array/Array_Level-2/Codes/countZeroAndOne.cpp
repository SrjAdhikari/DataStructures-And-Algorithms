#include <iostream>
#include<limits.h>
using namespace std;

void countZeroAndOne(int arr[], int size){

    int zeroCount = 0;
    int oneCount = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] == 0)
            zeroCount++;
        else
            oneCount++;
    }

    cout << "Total no. of zero : " << zeroCount << endl;
    cout << "Total no. of one : " << oneCount << endl;
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
    countZeroAndOne(arr, size);

    return 0;
}

// Time Complexity = O(n)
// Space Complexity = O(1)