#include<iostream>
using namespace std;

void printDiamond(int totalRow){
    
    int n = totalRow / 2;

    // Upper Half -> Full Pyramid Code
    for (int row = 0; row < n; row++) {
        for (int space = 0; space < (n - row - 1); space++) {
            cout << " ";
        }
        for (int star = 0; star < (row + 1); star++) {
            cout << "* ";
        }
        cout << endl; 
    }

    // Lower Half -> Inverted Full Pyramid Code
    for (int row = 0; row < n; row++) {
        for (int space = 0; space < row; space++) {
            cout << " ";
        }
        for (int star = 0; star < (n - row); star++) {
            cout << "* ";
        }
        cout << endl; 
    }
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printDiamond(row);

    return 0;
}