#include <iostream>
using namespace std;

//* 1. Recursive function to print even numbers from 2 to n.
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


//* 2. Recursive function to print even numbers from n down to 2.
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
    int num;
    cout << "Enter a number : ";
    cin >> num;
    cout << endl;

    // Adjust N to the nearest even number if it's odd
    // Checks if n is odd. If it is, it decrements n by 1 to make it even.
    if(num % 2 == 1)
        num--;

    cout << "Printing even numbers till " << num << " : " << endl;
    printEvenNumToN(num);
    cout << endl;

    cout << "Printing even numbers from " << num << " : " << endl;
    printEvenNumFromN(num);
    cout << endl;

    return 0;
}