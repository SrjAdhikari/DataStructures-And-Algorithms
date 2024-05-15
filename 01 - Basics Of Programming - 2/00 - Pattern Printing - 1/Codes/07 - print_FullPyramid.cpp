#include<iostream>
using namespace std;

void printFullPyramid(int n){

    for (int row = 0; row < n; row++) {
        for (int space = 0; space < (n - row - 1); space++) {
            cout << " ";
        }
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

    printFullPyramid(row);

    return 0;
}