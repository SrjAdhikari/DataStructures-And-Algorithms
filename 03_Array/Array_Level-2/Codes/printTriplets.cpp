#include <iostream>
using namespace std;

// Function that track the count of triplets and print all triplets.
void printTriplets(int arr[], int size){

    int count = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                cout << "(" << arr[i] << ", " << arr[j] << ", " << arr[k] << ")" << endl;
                count++;
            }
        }
    }
    cout << "Total triplets are : " << count << endl;
}


int main(){

    int arr[] = {10, 20, 25};
    int size = 3;

    cout << "Triplets are : " << endl;
    printTriplets(arr, size);        // Function call
    
    return 0;
}

// Time Complexity = O(n^3)
// Space Complexity = O(1)