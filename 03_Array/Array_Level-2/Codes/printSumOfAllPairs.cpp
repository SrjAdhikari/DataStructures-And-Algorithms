#include <iostream>
using namespace std;

int printTotalSum(int arr[], int size){

    int sum = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            sum += arr[i] + arr[j];
        }
    }
    return sum;
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

    int total = printTotalSum(arr, size);
    cout << "Total sum of pairs is : " << total << endl;
    
    return 0;
}

// Time Complexity = O(n^2)
// Space Complexity = O(1)