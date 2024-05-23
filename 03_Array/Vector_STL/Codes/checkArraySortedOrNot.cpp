#include<iostream>
#include<vector>
using namespace std;

bool checkSortedOrNot(vector<int>arr){
    int size = arr.size();

    for(int i = 0; i < size - 1; i++){
        if(arr[i] > arr[i +1]){
            return false;
        }
    }
    return true;
}

//* *********************************************
    //* Time Complexity = O(size)
    //* Space Complexity = O(1)
//* *********************************************


int main(){
    vector<int> array = {10, 20, 30, 40, 50};

    bool isSorted =  checkSortedOrNot(array);
    if(isSorted)
        cout << "Array is sorted." << endl;
    else
        cout << "Array is not sorted." << endl;

    return 0;
}