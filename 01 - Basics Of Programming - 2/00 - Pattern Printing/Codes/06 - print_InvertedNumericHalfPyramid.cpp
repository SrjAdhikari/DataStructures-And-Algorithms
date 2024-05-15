#include<iostream>
using namespace std;

void printInvertedNumericHalfPyramid(int n){

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n - row; col++) {
            cout << col + 1 << " ";
        }
        cout << endl; 
    }
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printInvertedNumericHalfPyramid(row);

    return 0;
}