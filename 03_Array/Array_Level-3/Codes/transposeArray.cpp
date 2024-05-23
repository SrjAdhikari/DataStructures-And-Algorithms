#include<iostream>
using namespace std;

// Method : 1
void transposeArray(int arr[][3], int rowSize, int colSize){

    for(int row = 0; row < rowSize; row++){
        for(int col = row + 1; col < colSize; col++){
            swap(arr[row][col], arr[col][row]);
        }
    }
}

//* *********************************************
    //* Time Complexity = O(rowSize * colSize)
    //* Space Complexity = O(1)
//* *********************************************


// Method : 2
void transposeArray(int arr[][3], int rowSize, int colSize){

    for(int row = 0; row < rowSize; row++){
        for(int col = 0; col <= row; col++){
            swap(arr[row][col], arr[col][row]);
        }
    }
}

//* *********************************************
    //* Time Complexity = O(rowSize * colSize)
    //* Space Complexity = O(1)
//* *********************************************


int main(){
    int arr[3][3] = { {2, 4, 6}, {8, 3, 5}, {7, 9, 1} };
    int rowSize = 3;
    int colSize = 3;

    cout << "Before Transpose : " << endl;

    // Print Array
    for(int row = 0; row < rowSize; row++){
        for(int col = 0; col < colSize; col++){
            cout << arr[row][col] << "  ";
        }
        cout << endl;
    }
    cout << endl;

    transposeArray(arr, rowSize, colSize);

    cout << "After Transpose : " << endl;

    // Print Array
    for(int row = 0; row < rowSize; row++){
        for(int col = 0; col < colSize; col++){
            cout << arr[row][col] << "  ";
        }
        cout << endl;
    }
}