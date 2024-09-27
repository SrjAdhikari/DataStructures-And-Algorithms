#include<iostream>
using namespace std;

int findUniqueElement(int arr[], int size){

    int uniqueNum = 0;

    for(int i = 0; i < size; i++){
        uniqueNum ^= arr[i];
    }
    return uniqueNum;
}


int main(){

    int arr[] = {4, 1, 2, 1, 2};
    int size = 5;

    int ans  = findUniqueElement(arr,size);
    cout << "Unique number is : " << ans << endl;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(1) 
//* ********************************************** 