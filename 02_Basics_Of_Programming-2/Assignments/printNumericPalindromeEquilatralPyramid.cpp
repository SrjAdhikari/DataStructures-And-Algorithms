#include<iostream>
using namespace std;

void printNumericPalindromeEquilatralPyramid(int n){
    for(int row = 0; row < n; row++){

        // Print space before numeric
        for(int space = 0; space < n-row-1; space++){
            cout << "  ";
        }

        int num = 1;
        
        // Print left hand side numeric triangle
        for(int col = 0; col < row + 1; col++){
            cout << num << " ";
            num++;
        }

        // Print right hand side numeric triangle till 1
        for(int col = num - 1; col > 1;){
            col--;
            cout << col << " ";
        }
        cout << endl;
    }
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printNumericPalindromeEquilatralPyramid(row);

    return 0;
}