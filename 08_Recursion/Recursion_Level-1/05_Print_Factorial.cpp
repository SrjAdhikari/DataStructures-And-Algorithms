#include <iostream>
using namespace std;

// Recursive function to calculate the factorial of a given number n
int findFactorial(int n) {
    // Base case: If n is 0 or 1, return 1
    // Factorial of 0 is 1 (by definition), and factorial of 1 is also 1
    if (n == 0 || n == 1)
        return 1;
    
    // Recursive case: Calculate the factorial of n
    // The factorial of n is n multiplied by the factorial of (n - 1)
    return n * findFactorial(n - 1);
}


int main() {
    int num;
    cout << "Enter a number : ";
    cin >> num;

    // Check if the input number is negative
    if(num < 0) {
        cout << "Invalid input. Can't calculate factorial of negative number!" << endl;
        return 0;   // Exit the program
    }

    // Calculate the factorial of the non-negative number
    int factorial = findFactorial(num);
    cout << "Factorial of " << num << " is : " << factorial << endl;

    return 0;
}