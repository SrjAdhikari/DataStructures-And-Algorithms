#include<iostream>
using namespace std;

void printFloydTriangle(int n){

    int num = 1;

    for (int row = 0; row < n; row++) {
        for(int col = 0; col < row + 1; col++){
            cout << num << " ";  
            num++;
        }
        cout << endl; 
    }
}


int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printFloydTriangle(row);

    return 0;
}