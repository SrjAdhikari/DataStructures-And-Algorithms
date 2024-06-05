#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){

    // Outer loop iterates from the second last element to the first element
    for(int i = n - 2; i >= 0; i--){

        // Flag to keep track if any swapping occurred
        bool swapped = false;

        // Inner loop iterates from the first element to the ith element
        for(int j = 0; j <= i; j++){

            // Compare adjacent elements and swap if they are in the wrong order
            if(arr[j] > arr[j + 1]){

                // Swap the elements
                swap(arr[j], arr[j + 1]);

                // Set swapped flag to true
                swapped = true;
            }
        }

        // If no elements were swapped, the array is already sorted, so break out of the loop
        if(!swapped)
            break;
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
    
    bubbleSort(arr, n);

    cout << "Array after sort : " << endl;
    printArray(arr, n);

    return 0;
}

// Time Complexity = O(n^2)
// Space Complexity = O(1)