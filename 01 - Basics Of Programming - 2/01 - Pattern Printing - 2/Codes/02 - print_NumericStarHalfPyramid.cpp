#include<iostream>
using namespace std;

void printNumericStarHalfPyramid1(int n){

    for (int row = 0; row < n; row++) {
        for(int col = 0; col < 2*row + 1; col++){
            if (col % 2 == 1) {
                cout << "*";
            }
            else {
                cout << row + 1;
            }  
        }
        cout << endl; 
    }
}

void printNumericStarHalfPyramid2(int n){

    for (int row = 0; row < n; row++) {
        for(int col = 0; col < row + 1; col++){
            if (col == row + 1 - 1) {
                cout << row + 1;
            }
            else {
                cout << row + 1 << "*";
            }  
        }
        cout << endl; 
    }
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    // printNumericStarHalfPyramid1(row);
    printNumericStarHalfPyramid2(row);

    return 0;
}