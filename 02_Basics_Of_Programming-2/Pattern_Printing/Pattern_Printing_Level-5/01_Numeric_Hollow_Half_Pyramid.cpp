#include<iostream>
using namespace std;

void printNumericHollowHalfPyramid(int n){

    for(int row = 0; row < n; row++){
        for(int col = 0; col <= row; col++){
            if(col == 0 || col == row || row == n - 1){
                cout << col + 1;
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printNumericHollowHalfPyramid(row);

    return 0;
}