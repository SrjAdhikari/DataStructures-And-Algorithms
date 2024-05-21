#include <iostream>
using namespace std;

int printSumOfTriplets(int arr[], int size){

    int sum = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
            sum += arr[i] + arr[j] + arr[k];
            }
        }
    }
    return sum;
}


int main(){
    int array[] = {10, 20, 30, 40, 50};
    int size = 5;

    int total = printSumOfTriplets(array, size);
    cout << "Total sum of triplets is : " << total << endl;
    
    return 0;
}

// Time Complexity = O(n^3)
// Space Complexity = O(1)