#include <iostream>
using namespace std;

// Function to check if a triangle is valid or not.
bool checkValidTriangle()
{
    int side1, side2, side3;
    cout << "Enter first value : ";
    cin >> side1;

    cout << "Enter second value : ";
    cin >> side2;

    cout << "Enter third value : ";
    cin >> side3;

    if ((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1))
        return true;
    else
        return false;
}

int main()
{
    // Calling the function and displaying the result of it.
    bool isValid = checkValidTriangle();
    if (isValid == true)
        cout << "It's a Valid Triangle." << endl;
    else
        cout << "It's Not a Valid Triangle." << endl;

    return 0;
}