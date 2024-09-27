#include<iostream>
using namespace std;

void printInvertedFullPyramid(int n){

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

    printInvertedFullPyramid(row);

    return 0;
}