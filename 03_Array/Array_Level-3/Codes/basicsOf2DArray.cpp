#include<iostream>
using namespace std;

int main(){

    // Initialize 2D Array
    int array[4][3] = {
                        {10, 20, 30},
                        {40, 50, 60},
                        {70, 80, 90},
                        {75, 85, 95}
                    };

    // Access / Print Array Elements
    cout << "Array Element : " << endl;
    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 3; col++){
            cout << array[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;


    // Declare 2D Array
    int arr[3][3];

    // Taking user input for array element
    cout << "Enter numbers : " << endl;
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            cin >> arr[row][col];
        }
        cout << endl;
    }

    // Access each location of array element
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            cout << "Element at [" << row << "][" << col << "] : " << arr[row][col] << endl;
        }
        cout << endl;
    }

    return 0;
}