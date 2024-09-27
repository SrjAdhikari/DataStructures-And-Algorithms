#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int target){
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return true;
        }
    }
    return false;
}


int main(){

    int arr[100];
    int size;

    cout << "Enter the number of elements" << endl;
    cin >> size;
    cout << endl;

    // User input for array elements
    for(int i=0; i< size; i++) {
        cout << "Enter the input value for index: " << i << endl;
        cin >> arr[i];
    }
    cout << endl;

    // User input for target
    int target;
    cout << "Enter the value of target" << endl;
    cin >> target;
    cout << endl;

    // Function call
    bool isFound = linearSearch(arr, size, target);

    if(isFound)
        cout << "Target found." << endl;
    else
        cout << "Target not found." << endl;
    
    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(1) 
//* ********************************************** 