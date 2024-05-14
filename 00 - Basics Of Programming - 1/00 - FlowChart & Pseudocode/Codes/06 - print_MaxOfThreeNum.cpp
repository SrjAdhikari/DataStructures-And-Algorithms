#include <iostream>
using namespace std;

// Function to check geater number among the 3 numbers.
int findMax(int num1, int num2, int num3)
{
    if (num1 > num2)
    {
        if (num1 > num3)
            return num1;
        else
            return num3;
    }
    else
    {
        if (num2 > num3)
            return num2;
        else
            return num3;
    }
}

void maxOfThreeNumbers()
{
    int num1, num2, num3;
    cout << "Enter first number : ";
    cin >> num1;

    cout << "Enter second number : ";
    cin >> num2;

    cout << "Enter third number : ";
    cin >> num3;

    if (num1 > num2)
    {
        if (num1 > num3)
            cout << "The maximum number among 3 is : " << num1;
        else
            cout << "The maximum number among 3 is : " << num3;
    }
    else
    {
        if (num2 > num3)
            cout << "The maximum number among 3 is : " << num2;
        else
            cout << "The maximum number among 3 is : " << num3;
    }
}

int main()
{
    maxOfThreeNumbers();

    // int a = 10, b = 50, c = 150;
    // cout << "The maximum of " << a << ", " << b << " and " << c << " is : " << findMax(a, b, c);
    
    return 0;
}