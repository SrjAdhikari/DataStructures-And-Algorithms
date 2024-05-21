#include <iostream>
using namespace std;

// Function that print pair which sum is equal to target
void checkTwoSumUsingArray(int arr[], int size, int target, int ans[]){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(arr[i] + arr[j] == target){
                ans[0] = arr[i];
                ans[1] = arr[j];
                return;
            }
        }
    } 
}


int main(){
    int arr[] = {10, 20, 25, 40, 50};
    int size = 5;
    int target = 70;
    int ans[2] = {-1, -1};

    checkTwoSumUsingArray(arr, size, target, ans);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}

// Time Complexity = O(n^2)
// Space Complexity = O(1)