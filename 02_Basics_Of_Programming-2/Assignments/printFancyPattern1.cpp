#include<iostream>
using namespace std;

void printFancyPattern(int n){

    for(int row = 0; row < n; row++){
        
        // Print left hand side star
        for(int star = 0; star < (2*n - row - 2); star++){
            cout << "* ";
        }

        // Print number and star 
        for(int col = 0; col < (2*row + 1); col++){
            if(col % 2 == 1){
                cout << "* ";
            }
            else{
                cout << row + 1 << " ";
            }
        }

        // Print right hand side star
        for(int star = 0; star < (2*n - row - 2); star++){
            cout << "* ";
        }
        
        cout << endl;
    }
}

int main(){

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    printFancyPattern(row);

    return 0;
}