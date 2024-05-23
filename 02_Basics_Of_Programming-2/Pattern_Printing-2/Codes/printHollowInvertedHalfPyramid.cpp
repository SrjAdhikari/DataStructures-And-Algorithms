#include<iostream>
using namespace std;

void printHollowInvertedHalfPyramid(int n){

    for (int row = 0; row < n; row++) {
        for(int col = 0; col < n - row; col++){
            if (row == 0 || row == n - 1) {
                cout << "* ";
            }
            else {
                if (col == 0 || col == n-row-1) {
                    cout << "* ";
                }
                else {
                    cout << "  ";
                }
            }  
        }
        cout << endl; 
    }
}


int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printHollowInvertedHalfPyramid(row);

    return 0;
}