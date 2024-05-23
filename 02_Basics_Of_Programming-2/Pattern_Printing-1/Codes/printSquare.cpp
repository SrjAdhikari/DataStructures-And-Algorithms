#include<iostream>
using namespace std;

void printSquarePattern(int size){

    for (int row = 0; row < size; row++)        //Outer loop for row
    {
        for (int col = 0; col < size; col++)    //Inner loop for column & to print star in every row
        {
                cout << " * ";                  //Printing star 
        }
        cout << endl;                           //New line after printing star in single row
    }
}

int main(){

    int size;                                   //Size of square
    cout << "Enter the size of square : " << endl;
    cin >> size;                                //User Input

    printSquarePattern(size);

    return 0;
}