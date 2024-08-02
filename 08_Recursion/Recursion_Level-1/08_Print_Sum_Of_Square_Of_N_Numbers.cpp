#include <iostream>
using namespace std;

// Function to calculate the sum of squares from n numbers
int printSquareSum(int n) {
    // Base case: if n is 1, return 1 (square of 1)
    if (n == 1) {
        return 1;
    }
    // Recursive case: return the square of n plus the sum of squares of numbers less than n
    return n * n + printSquareSum(n - 1);
}


int main () {
    int num;
    cout << "Enter a number : ";
    cin >> num;

    int sum = printSquareSum(num);
    cout << "Sum of square of " << num << " natural numbers : " << sum << endl;

    return 0;
}