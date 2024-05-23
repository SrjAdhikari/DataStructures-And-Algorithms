#include<iostream>
#include<vector>
using namespace std;

// Find the difference between the sum of element at even indices to the sum of element at odd indices.

void findSumDifference(vector<int>arr){

    int size = arr.size();
    int sumDiff = 0;

    for(int i = 0; i < size; i++){
        if((i & 1) == 0 ){
            sumDiff += arr[i];
        }
        else{
            sumDiff -= arr[i];
        }
    }
    cout << "Difference is : " << sumDiff << endl;
}

//* *********************************************
    //* Time Complexity = O(size)
    //* Space Complexity = O(1)
//* *********************************************


int main(){

    vector<int> array = {1, 2, 10, 5, 11, 20};
    findSumDifference(array);

    return 0;
}