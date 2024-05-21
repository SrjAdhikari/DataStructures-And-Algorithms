#include <iostream>
using namespace std;

// Function that only check if pair exist or not
bool checkTwoSum(int arr[], int size, int target){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(arr[i] + arr[j] == target)
                return true;
        }
    }
    return false;
}


int main(){
    int arr[] = {10, 15, 20, 25, 40, 50};
    int size = 6;
    int target = 30;

    bool isFound = checkTwoSum(arr, size, target);
    if(isFound)
        cout << "Pair found" << endl;
    else
        cout << "Pair not found" << endl;

    return 0;
}

// Time Complexity = O(n^2)
// Space Complexity = O(1)