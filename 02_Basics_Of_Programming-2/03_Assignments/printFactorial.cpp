#include <iostream>
using namespace std;

// Function to print factorial of a number given by user.
void printFactorial()
{
    int num, factorial = 1;
    cout << "Enter the number you want to calculate factorial : ";
    cin >> num;

    // The loop starts from 1 because the factorial of any number is always greater than zero and it includes that number itself in its calculation. So we start counting from 1.

    // Iterate from 1 to the given number and multiply the result with every integer in this range.
    
    for (int start = 1; start <= num; start++)
    {
        factorial *= start;
    }
    cout << "The factorial of " << num << " is : " << factorial << endl;
}

int main()
{
    printFactorial();
    return 0;
}