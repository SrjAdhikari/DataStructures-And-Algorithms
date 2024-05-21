#include <iostream>
using namespace std;

// Function that print pair which sum is equal to target
pair<int, int> isPairExist(int arr[], int size, int target){

    // Create a pair of int, int, store the pair which sum is equal to target
    // Assuming (-1,-1) as no answer found
    pair<int, int> ans = make_pair(-1, -1);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(arr[i] + arr[j] == target){
                // Found pair that sums is equal to target
                ans.first = arr[i];
                ans.second = arr[j];
            }
        }
    }

    return ans;
}

int main(){
    int arr[] = {10, 15, 20, 25, 40, 50};
    int size = 6;
    int target = 30;

    pair<int,int> ans = isPairExist(arr, size, target);
    if(ans.first == -1 && ans.second == -1) 
        cout << "Pair not found" << endl;
    else 
        cout << "Pair Found : " << ans.first << ", " << ans.second << endl;

    return 0;
}

// Time Complexity = O(n^2)
// Space Complexity = O(1)