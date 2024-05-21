#include <iostream>
using namespace std;

// Function that print all pair which sum is equal to target
void printAllPairs(int arr[], int size, int target){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(arr[i] + arr[j] == target){
                cout << arr[i] << ", " << arr[j] << endl;
            }
        }
    } 
}


// Function that print only unique pair which sum is equal to target
void printUniquePairs(int arr[], int size, int target){

    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] + arr[j] == target){
                cout << arr[i] << ", " << arr[j] << endl;
            }
        }
    } 
}


int main(){
    int arr[] = {10, 20, 25, 40, 50};
    int size = 5;
    int target = 60;

    cout << "Printing all pairs : " << endl;
    printAllPairs(arr, size, target);
    cout << endl;

    cout << "Printing only unique pairs : " << endl;
    printUniquePairs(arr, size, target);

    return 0;
}

// Time Complexity = O(n^2)
// Space Complexity = O(1)