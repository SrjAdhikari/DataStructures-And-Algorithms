#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){

    // Outer loop iterates from the first element to the second-last element
    for(int i = 0; i < n - 1; i++){

        // Assume the minimum element is at the current position i
        int minIndex = i;

        // Inner loop iterates from the element after i to the last element
        for(int j = i + 1; j < n; j++){

            // If a smaller element is found, update minIndex
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the element at position i
        swap(arr[minIndex], arr[i]);
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
    
    selectionSort(arr, n);

    cout << "Array after sort : " << endl;
    printArray(arr, n);

    return 0;
}

// Time Complexity = O(n^2)
// Space Complexity = O(1)