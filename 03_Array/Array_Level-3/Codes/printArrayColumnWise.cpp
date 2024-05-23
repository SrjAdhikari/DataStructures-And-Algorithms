#include<iostream>
using namespace std;

int main(){

    // Initialize 2D Array
    int array[4][3] = { {10, 20, 30}, {40, 50, 60}, {70, 80, 90}, {75, 85, 95} };

    // Access / Print Array Elements
    cout << "Array Element : " << endl;
    for(int col = 0; col < 4; col++){
        for(int row = 0; row < 3; row++){
            cout << array[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}

//* *********************************************
    //* Time Complexity = O(row * col)
    //* Space Complexity = O(1)
//* *********************************************