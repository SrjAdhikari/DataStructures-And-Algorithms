#include <iostream>
using namespace std;

//* 1. Recursive function to print numbers from 1 to n.
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


//* 2. Recursive function to print numbers from 1 to n.
void printFromOneTo_2(int n, int num) {
    // Base case: If the current number n is equal to the target number num, print n and return
    if (n == num) {
        cout << n << "  ";
        return;
    }
    
    // Print the current number
    cout << n << "  ";
    
    // Recursive case: Call the function with the next number (n + 1)
    // This continues until n equals num
    printFromOneTo_2(n + 1, num);
}


int main() {
    int num;
    cout << "Enter a number : ";
    cin >> num;
    cout << endl;

    cout << "Printing count from 1 to " << num << " : " << endl;
    printFromOneToN(num);
    cout << endl;

    cout << "Printing count from 1 to "  << num << " by other method : " << endl;
    printFromOneTo_2(1, num);
    cout << endl;

    return 0;
}