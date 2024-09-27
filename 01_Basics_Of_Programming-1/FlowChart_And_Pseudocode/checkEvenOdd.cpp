#include <iostream>
using namespace std;

// Function to check whether the number is even or odd.
void checkEvenOdd(int n)
{
    if (n % 2 == 0)
        cout << "The number " << n << " is Even." << endl;
    else
        cout << "The number " << n << " is Odd." << endl;
}

// Function to check whether the number provided by the user is even or odd.
void checkEvenOddFromUserInput()
{
    int num;
    cout << "Enter a number: " << endl;
    cin >> num;

    if (num % 2 == 0)
    {
        cout << "The number " << num << " is Even." << endl;
    }
    else
    {
        cout << "The number " << num << " is Odd." << endl;
    }
}

int main()
{
    // checkEvenOdd(15);
    checkEvenOddFromUserInput();

    return 0;
}