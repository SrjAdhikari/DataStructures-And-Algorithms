#include <iostream>
using namespace std;


// Function to print digits of a number in the original order using recursion
void printDigit(int num) {
    // Base case: When num is 0, stop recursion
    if (num == 0) {
        return;
    }

    int digit = num % 10;       // Extract the last digit
    printDigit(num / 10);       // Recursive call to process the rest of the number
    cout << digit << "  ";      // Print the last digit after returning from recursive calls
}


// Function to print digits of a number in reverse order using recursion
void printDigitInReverse(int num) {
    // Base case: When num is 0, stop recursion
    if (num == 0) {
        return;
    }

    int digit = num % 10;               // Extract the last digit
    cout << digit << "  ";              // Print the last digit before making the recursive call
    printDigitInReverse(num / 10);      // Recursive call to process the rest of the number
}


int main() {
    int number = 9728;
    cout << "Printing digit of " << number << " : " << endl;
    printDigit(number);
    cout << endl;

    cout << "Printing digit of " << number << " in reverse order :" << endl;
    printDigitInReverse(number);

    return 0;
}