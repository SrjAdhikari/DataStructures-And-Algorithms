#include<iostream>
using namespace std;

void printZeroOneTriangle(int n){

    for(int row = 0; row < n; row++){
        
        for(int col = 0; col < (row + 1); col++){
            int sum = row + col;
            if(sum % 2 == 0){
                cout << "1 ";
            }
            else{
                cout << "0 ";
            }
        }        
        cout << endl;
    }
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printZeroOneTriangle(row);

    return 0;
}