#include<iostream>
using namespace std;

void printSolidHalfDiamond(int n){

    // Upper half
    for(int row = 0; row < n; row++){
        
        for(int col = 0; col < (row + 1); col++){
            cout << "* ";
        }        
        cout << endl;
    }

    // Lower half
    for(int row = 0; row < n; row++){
        
        for(int col = 0; col < (n - row - 1); col++){
            cout << "* ";
        }        
        cout << endl;
    }
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printSolidHalfDiamond(row);

    return 0;
}