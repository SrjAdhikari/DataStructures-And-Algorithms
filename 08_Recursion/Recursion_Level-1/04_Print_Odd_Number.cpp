#include <iostream>
using namespace std;

//* 1. Function to print all odd numbers from 1 up to n in reverse order
void printOddNumToN(int n) {
    // Base case: If n is less than 1, return as there are no valid numbers to print
    if (n < 1) {
        return;
    }
    
    // Recursive case: Call the function with n - 2
    // This will continue to call itself with decreasing odd numbers
    printOddNumToN(n - 2);

    // After the recursive call returns, print the current value of n
    // This ensures that odd numbers are printed in ascending order
    cout << n << "  ";
}

//* 2. Function to print all odd numbers from n down to 1
void printOddNumFromN(int n) {
    // Base case: If n is less than 1, return as there are no valid numbers to print
    if (n < 1) {
        return;
    }
    
    // Print the current odd number n
    cout << n << "  ";
    
    // Recursive case: Call the function with n - 2
    // This will continue to call itself with decreasing odd numbers
    printOddNumFromN(n - 2);
}



int main() {
    int num;
    cout << "Enter a number : ";
    cin >> num;
    cout << endl;

    // Adjust N to the nearest odd number if it's even
    // Checks if n is even. If it is, it decrements n by 1 to make it odd.
    if(num % 2 == 0)
        num--;

    cout << "Printing odd numbers till " << num << " : " << endl;
    printOddNumToN(num);
    cout << endl;

    cout << "Printing even numbers from " << num << " : " << endl;
    printOddNumFromN(num);
    cout << endl;

    return 0;
}