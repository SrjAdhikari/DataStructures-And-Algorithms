#include<iostream>
using namespace std;

bool linearSearch(int arr[3][3], int rowSize, int colSize, int target){

    for(int row = 0; row < rowSize; row++){
        for(int col = 0; col < colSize; col++){
            if(arr[row][col] == target)
                return true;
        }
    }
    return false;
}

//* *********************************************
    //* Time Complexity = O(rowSize * colSize)
    //* Space Complexity = O(1)
//* *********************************************


int main(){

    int array[3][3] = { {10, 20, 30}, {40, 50, 60}, {70, 80, 90} };
    int rowSize = 3;
    int colSize = 3;
    int target = 50;

    bool isFound = linearSearch(array, rowSize, colSize, target);

    if(isFound)
        cout << "Target present";
    else
        cout << "Target not present";
    
    return 0;
}