#include<iostream>
using namespace std;

void printFancyPattern(int n){

    // Upper Half
    for(int row = 0; row < n; row++){
        for(int col = 0; col < (2*row+1); col++){
            if(col % 2 == 1){
                cout << "* ";
            }
            else{
                cout << row + 1 << " ";
            }
        }
        cout << endl;
    }

    // Lower Half
    for(int row = 0; row < n; row++){
        for(int col = 0; col < (2*n - 2*row - 1); col++){
            if(col % 2 == 1){
                cout << "* ";
            }
            else{
                cout << n - row << " ";
            }
        }
        cout << endl;
    }
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printFancyPattern(row);

    return 0;
}