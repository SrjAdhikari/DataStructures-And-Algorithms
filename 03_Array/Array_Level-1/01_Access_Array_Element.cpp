#include <iostream>
using namespace std;

int main(){

    // Array Initialization
    int array[5] = {10, 20, 30, 40, 50};

    // Normal approach for accessing array elements
    cout << "Array elements : " << endl;
    cout << array[0] << " " << array[1] << " " << array[2] << " " << array[3] << " " << array[4] << endl;
    cout << endl;

    // Looping for accessing array elements
    cout << "Array elements : " << endl;
    for(int index = 0; index < 5; index++){
        cout << array[index] << " ";
    }
    cout << endl;

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(1) 
//* ********************************************** 