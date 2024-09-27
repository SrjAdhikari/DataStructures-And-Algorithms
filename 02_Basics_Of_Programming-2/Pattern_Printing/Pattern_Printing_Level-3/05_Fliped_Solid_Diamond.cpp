#include<iostream>
using namespace std;

void printFlipedSolidDiamond(int n){

    // Upper Half
    for (int row = 0; row < n; row++) {

        // Print Inverted Half Pyramid
        for (int star = 0; star < (n - row); star++) {
            cout << "* ";
        }

        // Print Full Pyramid of space
        for (int space = 0; space < (2*row+1); space++) {
            cout << "  ";
        }

        // Print Inverted Half Pyramid
        for (int star = 0; star < (n - row); star++) {
            cout << "* ";
        }
        cout << endl; 
    }

    // Lower Half
    for (int row = 0; row < n; row++) {

        // Print Half Pyramid
        for (int star = 0; star < (row + 1); star++) {
            cout << "* ";
        }

        // Print Full Pyramid of space
        for (int space = 0; space < (2*n - 2*row - 1); space++) {
            cout << "  ";
        }

        // Print Half Pyramid
        for (int star = 0; star < (row + 1); star++) {
            cout << "* ";
        }
        cout << endl; 
    }
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printFlipedSolidDiamond(row);

    return 0;
}