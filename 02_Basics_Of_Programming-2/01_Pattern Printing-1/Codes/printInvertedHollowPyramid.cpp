#include<iostream>
using namespace std;

void printHollowPyramid(int n){

    for (int row = 0; row < n; row++) {

        // Print space before star
        for (int space = 0; space < row; space++) {
            cout << " ";
        }
        for (int star = 0; star < (n - row); star++) {

            // Print star in first and last column of every row.
            if(star == 0 || star == (n - row - 1))
                cout << "* ";

            // Print space between first and last column of every row
            else
                cout << "  ";
        }
        cout << endl; 
    }
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printHollowPyramid(row);

    return 0;
}