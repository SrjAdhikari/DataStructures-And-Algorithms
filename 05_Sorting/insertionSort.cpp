#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    
    // Outer loop iterates from the second element to the last element
    for(int i = 1; i < n; i++){

        // Inner loop iterates backwards from the current element to the start of the array
        for(int j = i; j > 0; j--){
            
            // Compare the current element with the previous one
            if(arr[j] < arr[j - 1])
                // If the current element is smaller, swap them
                swap(arr[j], arr[j - 1]);
            else
                // If the current element is not smaller, break out of the inner loop
                break;
        }
    }
}


void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}


int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;

    cout << "Array before sort : " << endl;
    printArray(arr, n);
    cout << endl;
    
    insertionSort(arr, n);

    cout << "Array after sort : " << endl;
    printArray(arr, n);

    return 0;
}

// Time Complexity = O(n^2)
// Space Complexity = O(1)