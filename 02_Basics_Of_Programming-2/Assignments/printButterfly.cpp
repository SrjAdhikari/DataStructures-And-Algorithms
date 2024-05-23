#include<iostream>
using namespace std;

void printButterfly(int n){

    // Upper half
    for(int row = 0; row < n; row++){
        
        // Print left hand side half pyramid
        for(int star = 0; star < (row + 1); star++){
            cout << "* ";
        } 

        // Print space
        for(int space = 0; space < (2*n - 2*row - 2); space++){
            cout << "  ";
        }  

        // Print right hand side half pyramid
        for(int star = 0; star < (row + 1); star++){
            cout << "* ";
        }        
        cout << endl;
    }

    // Lower half
    for(int row = 0; row < n; row++){
        
        // Print left hand side half pyramid
        for(int star = 0; star < (n - row); star++){
            cout << "* ";
        } 

        // Print space
        for(int space = 0; space < (2*row); space++){
            cout << "  ";
        }  

        // Print right hand side half pyramid
        for(int star = 0; star < (n - row); star++){
            cout << "* ";
        }        
        cout << endl;
    }
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printButterfly(row);

    return 0;
}