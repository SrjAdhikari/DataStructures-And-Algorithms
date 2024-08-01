#include <iostream>
using namespace std;

// Recursive function to find the sum of the first n natural numbers
int findSum(int n) {
    // Base case: If n is 1, return 1
    // The sum of the first 1 natural number is 1
    if (n == 1) {
        return 1;
    }
    
    // Recursive case: Calculate the sum of n natural numbers
    // Sum of n natural numbers is n plus the sum of the first (n - 1) natural numbers
    return n + findSum(n - 1);
}


int main() {
    int num;
    cout << "Enter a number : ";
    cin >> num;

    int sum = findSum(num);
    cout << "Sum of " << num << " natural numbers is : " << sum << endl;

    return 0;
}

//* **********************************************
    //* Example:
    
    //* For n = 5
    //* findSum(5) returns 5 + findSum(4)
    //* findSum(4) returns 4 + findSum(3)
    //* findSum(3) returns 3 + findSum(2)
    //* findSum(2) returns 2 + findSum(1)
    //* findSum(1) returns 1
    //* Thus, findSum(5) ultimately returns 5 + 4 + 3 + 2 + 1 = 15.
//* **********************************************