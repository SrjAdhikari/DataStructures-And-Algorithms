#include<iostream>
using namespace std;

// Print row wise sum of 2D array
void printRowWiseSum(int arr [][3], int rowSize, int colSize){

    for(int row = 0; row < rowSize; row++){
        int sum = 0;
        for(int col = 0; col < colSize; col++){
            sum += arr[row][col];
        }
        cout << "Row " << row << " sum is : " << sum <<endl;
    }
}

//* *********************************************
    //* Time Complexity = O(rowSize * colSize)
    //* Space Complexity = O(1)
//* *********************************************




// Print column wise sum of 2D array
void printColumnWiseSum(int arr [][3], int rowSize, int colSize){

    for(int col = 0; col < colSize; col++){
        int sum = 0;
        for(int row = 0; row < rowSize; row++){
            sum += arr[row][col];
        }
        cout << "Column " << col << " sum is : " << sum <<endl;
    }
}

//* *********************************************
    //* Time Complexity = O(rowSize * colSize)
    //* Space Complexity = O(1)
//* *********************************************


int main(){

    int arr[3][3] = { {10, 20, 5}, {2, 4, 6}, {10, 15, 10} };
    int rowSize = 3;
    int colSize = 3;

    printRowWiseSum(arr , rowSize, colSize);
    cout << endl;
    printColumnWiseSum(arr, rowSize, colSize);

    return 0;
}