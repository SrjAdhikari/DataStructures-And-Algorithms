#include<iostream>
using namespace std;

void printFancyPattern(int n){

    for(int row = 0; row < n; row++){
        char ch;
        // Print Triangle of character
        for(int col = 0; col < row + 1; col++){
            int num = col + 1;
            ch = num + 'A' -1;
            cout << ch << " ";
        }

        // Print character till 'A'
        for(char alpha = ch; alpha > 'A';){
            alpha -= 1;
            cout << alpha << " ";
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