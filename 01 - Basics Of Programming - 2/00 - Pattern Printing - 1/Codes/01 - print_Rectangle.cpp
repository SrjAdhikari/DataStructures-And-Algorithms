#include<iostream>
using namespace std;

void printRectanglePattern(int length, int width){

    for (int row = 0; row < length; row++) {
        for (int col = 0; col < width; col++) {    
            cout << " * "; 
        }
       cout << endl;
    }
}

int main(){

    int row, column;

    cout << "Enter the number of row : " << endl;
    cin >> row; 

    cout << "Enter the number of column : " << endl;
    cin >> column;

    printRectanglePattern(row, column);

    return 0;
}