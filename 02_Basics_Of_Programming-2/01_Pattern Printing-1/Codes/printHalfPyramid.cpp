#include<iostream>
using namespace std;

void printHalfPyramid(int n){

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < row + 1; col++) {
            cout << "* ";
        }
        cout << endl; 
    }
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printHalfPyramid(row);

    return 0;
}