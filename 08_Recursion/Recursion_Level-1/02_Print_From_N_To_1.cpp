#include <iostream>
using namespace std;


//* Recursive function to print numbers from n down to 1.
void printFromNToOne (int n) {
    // Base case: If n is 0, return without doing anything
    if(n == 0)
        return;
    
    // Print the current value of n
    // This ensures that numbers are printed in descending order
    cout << n << "  ";

    // Recursive case: Call the function with n - 1
    // This will continue to call itself until n is 0
    printFromNToOne(n - 1);
}


int main() {
    int num;
    cout << "Enter a number : ";
    cin >> num;
    cout << endl;

    cout << "Printing count from " << num << " to 1 : " << endl;
    printFromNToOne(num);
    cout << endl;

    return 0;
}