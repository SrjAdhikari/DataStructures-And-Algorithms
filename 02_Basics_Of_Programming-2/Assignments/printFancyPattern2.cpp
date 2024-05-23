#include<iostream>
using namespace std;

void printFancyPattern(int n){

    // Upper half
    int count = 1;
    for(int row = 0; row < n; row++){
        
        for(int col = 0; col <= row; col++){
            // Print Numbers
            cout << count;
            count++;

            // Condition for print Stars
            if(col < row){
                cout << "*";
            }
        }        
        cout << endl;
    }

    // Lower half

    int start = count - n;
    for(int row = 0; row < n; row++){

        int num = start;
        for(int col = 0; col <= (n - row - 1); col++){
            // Print Numbers
            cout << num;
            num++;

            // Condition for print Stars
            if(col < (n - row - 1)){
                cout << "*";
            }
        }
        start = start - (n - row - 1);
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