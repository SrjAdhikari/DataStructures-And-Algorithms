#include <iostream>
using namespace std;

int main(){

    // Array Initialization
    int array[5];

    // Taking input for array element
    for(int index = 0; index < 5; index++) {
        cout << "Enter the value for box index : " << index << endl;
        cin >> array[index];
    }
    cout << endl;

    // Printing array element
    cout << "Array elements : " << endl;
    for(int i = 0; i < 5; i++){
        cout << array[i] << " ";
    }
    
    return 0;
}