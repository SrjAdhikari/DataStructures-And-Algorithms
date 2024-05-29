#include<iostream>
#include<vector>
using namespace std;

/*
    i/p => matrix = 1  2  3  4
                    5  6  7  8
                    9 10 11 12

    o/p => 1 5 9 10 6 2 3 7 11 12 8 4
*/

void waveMatrix(vector<vector<int> > mat) {

    // Get the number of rows and columns in the matrix
    int row = mat.size();
    int column = mat[0].size();

    // Loop through each column
    for(int col = 0; col < column; col++) {
        // Check if the column index is even
        if((col & 1) == 0) {
            // For even columns, print top to bottom
            for(int i = 0; i < row; i++) {
                cout << mat[i][col] << " ";
            }
        }
        else {
            // For odd columns, print bottom to top
            for(int i = row - 1; i >= 0; i--) {
                cout << mat[i][col] << " ";
            }
        }
    }
}



int main(){

    vector<vector<int> >matrix = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    waveMatrix(matrix);

    return 0;
}

//* *******************************************
//* Time Complexity = O(row * col)
//* Space Complexity = O(1)
//* *******************************************