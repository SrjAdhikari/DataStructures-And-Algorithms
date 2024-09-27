#include<iostream>
using namespace std;

void printNumericHalfPyramid(int n){

    for (int row = 0; row < n; row++) {
        for(int col = 0; col < row + 1; col++){
            cout << row + 1 << " ";  
        }
        cout << endl; 
    }
}


int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printNumericHalfPyramid(row);

    return 0;
}