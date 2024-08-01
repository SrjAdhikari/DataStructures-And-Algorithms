#include <iostream>
using namespace std;

// Function to calculate 2 raised to the power of n
int findPowerOfTwo(int n) {
    // Base case: If n is 0, return 1
    // This is because 2^0 is 1
    if (n == 0) {
        return 1;
    }

    // Recursive case: Multiply 2 by the result of findPowerOfTwo(n - 1)
    // This calculates 2^n by reducing the power by 1 in each recursive call
    return 2 * findPowerOfTwo(n - 1);
}


// Recursive function to calculate base raised to the power of power (base^power)
int findPower(int base, int power) {
    // Base case: If power is 0, return 1
    // Any number raised to the power of 0 is 1
    if (power == 0) {
        return 1;
    }

    // Recursive case: Multiply base by the result of findPower with power - 1
    // This calculates base^power by reducing the power by 1 in each recursive call
    return base * findPower(base, power - 1);
}


int main() {
    int base, power;
    cout << "Enter a base number : ";
    cin >> base;

    cout << "Enter power of base number: ";
    cin >> power;

    int powerOfTwo = findPowerOfTwo(power);
    cout << "2 to the power " << power << " is : " << powerOfTwo << endl;

    int powerOfAnyNum = findPower(base, power);
    cout << base << " to the power " << power << " is : " << powerOfAnyNum << endl;
    
    return 0;
}