#include<iostream>
using namespace std;

int main(){

    int rowSize = 3;
    int colSize = 3;

    // Initialize 2D Array
    int array[rowSize][colSize] = { {10, 20, 30}, {40, 50, 60}, {70, 80, 90} };

    cout << "Array Diagonal Element : " << endl;

    // Print array reverse diagonal elements
    for(int row = 0; row < rowSize; row++){
        for(int col = 0; col < colSize; col++){
            if(row + col == colSize - 1){
                cout << array[row][col];
            }
        }
        cout << endl;
    }
    
    return 0;
}

//* *********************************************
    //* Time Complexity = O(rowSize * colSize)
    //* Space Complexity = O(1)
//* *********************************************