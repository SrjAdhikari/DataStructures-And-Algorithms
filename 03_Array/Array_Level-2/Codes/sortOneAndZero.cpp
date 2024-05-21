#include<iostream>
#include<algorithm>
using namespace std;

//* Solve using counting method
void sortZeroOne(int arr[], int size){

    int zeroCount = 0;
    int oneCount = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] == 0)
            zeroCount++;
        else
            oneCount++;
    }

    // Place zeos and ones using fill() function
    // fill(arr, arr + zeroCount, 0);
    // fill(arr + zeroCount, arr + n, 1);

    // Place Zeros
    for(int i = 0; i < zeroCount; i++){
        arr[i] = 0;

    }

    // Place Ones
    for(int i = zeroCount; i < size; i++){
        arr[i] = 1;

    }
}


//* Solve using two pointer approach
void twoPointerApproach(int arr[], int size){

    int start = 0;
    int end = size - 1;

    while(start <= end){
        if(arr[start] == 1 && arr[end] == 0){
            swap(arr[start], arr[end]);
        }
        start++;
        end--;
    
    }
}


int main(){

    int arr[] = {1, 0, 1, 0, 1, 0, 1, 0};
    int size = ;

    //sortZeroOne(arr, size);

    // Sorting array using inbuilt sort() function
    // sort(arr, arr+size);

    twoPointerApproach(arr, size);

    // Printing  array
    cout << "Sorted array is : " << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// Time Complexity = O(n)
// Space Complexity = O(1)