#include<iostream>
using namespace std;

void printHollowRectangle(int length, int width){

    for (int row = 0; row < length; row++) {
        for (int col = 0; col < width; col++) {
            if (row == 0 || row == length - 1 || col == 0 || col == width - 1) {
                cout << "* ";
            }
            else {
                    cout << "  ";   // Two spaces to account for the space after "* "
            }
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

    printHollowRectangle(row, column);

    return 0;
}