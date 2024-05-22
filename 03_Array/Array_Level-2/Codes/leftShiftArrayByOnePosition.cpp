#include<iostream>
using namespace std;

void shiftArray(int arr[], int size) {
    // Store first element
    int temp = arr[0];

    // Loop to right shift remaining element
    for(int i = 0; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }

    // Place the last element at the starting of the array
    arr[size - 1] = temp;
}


int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    shiftArray(arr, size);
    
    // Print Array
    cout << "Shifted Array : " << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}