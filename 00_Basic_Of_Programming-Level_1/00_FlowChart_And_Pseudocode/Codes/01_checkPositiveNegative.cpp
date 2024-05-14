#include <iostream>
using namespace std;

// Function to check whether the number given by user is Positive, Negative or Zero.
void checkNumber()
{
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;

    if (num > 0)
        cout << "Number " << num << " is Positive." << endl;
    else if (num < 0)
        cout << "Number " << num << " is Negative." << endl;
    else
        cout << "Number is Zero";
}

// Function to check whether the number is Positive, Negative or Zero.
void checkNumber2(int num)
{

    if (num > 0)
        cout << "Number " << num << " is Positive." << endl;
    else if (num < 0)
        cout << "Number " << num << " is Negative." << endl;
    else
        cout << "Number is Zero." << endl;
}

int main()
{
    checkNumber();
    // checkNumber2(15);

    return 0;
}