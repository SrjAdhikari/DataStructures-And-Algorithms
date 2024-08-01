#include <iostream>
using namespace std;

// Recursive function to print numbers from 1 to n
void printFromOneToN (int n) {
    // Base case: If n is 0, return without doing anything
    if(n == 0)
        return;
    
    // Recursive case: Call the function with n - 1
    // This will keep calling itself until n is 0
    printFromOneToN(n - 1);

    // After the recursive call returns, print the current value of n
    // This ensures that numbers are printed in ascending order
    cout << n << "  ";
}


// Recursive function to print numbers from n down to 1
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


// Recursive function to print even numbers from n down to 2 (inclusive)
void printEvenNumToN(int n) {
    // Base case: If n is 2, print it and return
    if (n == 2) {
        cout << n << "  ";
        return;
    }

    // Recursive case: Call the function with n - 2
    // This will continue to call itself with decreasing even numbers
    printEvenNumToN(n - 2);

    // After the recursive call returns, print the current value of n
    // This ensures that even numbers are printed in ascending order
    cout << n << "  ";
}


// Recursive function to print even numbers from n down to 2 (inclusive)
void printEvenNumFromN(int n) {
    // Base case: If n is 2, print it and return
    if (n == 2) {
        cout << n << "  ";
        return;
    }

    // Print the current value of n
    cout << n << "  ";

    // Recursive case: Call the function with n - 2
    // This will continue to call itself with decreasing even numbers
    printEvenNumFromN(n - 2);
}


int main() {
    int n = 10;

    cout << "Printing count from 1 to N : ";
    printFromOneToN(n);
    cout << endl;

    cout << "Printing count from N to 1 : ";
    printFromNToOne(n);
    cout << endl;

    cout << "Printing even numbers till N : ";
    printEvenNumToN(n);
    cout << endl;

    cout << "Printing even numbers from N : ";
    printEvenNumFromN(n);
    cout << endl;

    return 0;
}