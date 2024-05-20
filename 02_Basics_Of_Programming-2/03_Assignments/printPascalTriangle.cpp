#include<iostream>
using namespace std;

void printPascalTriangle(int n){

    for(int row = 1; row <= n; row++){
        
        int count = 1;
        for(int col = 1; col <= row; col++){
            cout << count << " ";

            // Binomial coefficient formula for pascal triangle
            count = count * (row - col) / col;
        }
        cout << endl;
    }           
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printPascalTriangle(row);

    return 0;
}