#include<iostream>
using namespace std;

// Print diagonal sum of 2D array
void printDiagonalSum(int arr [][3], int rowSize, int colSize){

    int sum = 0;
    for(int row = 0; row < rowSize; row++){
        sum += arr[row][row];
        // cout << "Diagonal sum is :  " << sum <<endl;
    }
    cout << "Diagonal sum is :  " << sum <<endl;
}

//* ***************************************
    //* Time Complexity = O(rowSize)
    //* Space Complexity = O(1)
//* ***************************************


// Print reverse diagonal sum of 2D array
void printReverseDiagonalSum(int arr [][3], int rowSize, int colSize){

    int sum = 0;
    for(int row = 0; row < rowSize; row++){
        for(int col = 0; col < colSize; col++){
            if(row + col == colSize - 1){
                sum += arr[row][col];
            }
        }
        // cout << "Reverse diagonal sum is :  " << sum <<endl;
    }
    cout << "Reverse diagonal sum is :  " << sum <<endl;
}

//* *********************************************
    //* Time Complexity = O(rowSize * colSize)
    //* Space Complexity = O(1)
//* *********************************************


int main(){

    int arr[3][3] = { {5, 10, 15}, {10, 25, 20}, {30, 40, 50} };
    int rowSize = 3;
    int colSize = 3;

    printDiagonalSum(arr , rowSize, colSize);
    printReverseDiagonalSum(arr, rowSize, colSize);

    return 0;
}