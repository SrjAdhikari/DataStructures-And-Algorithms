// Take N number form user and multiply them.

#include <iostream>
using namespace std;

// Function to display the product of all numbers entered by the user.
void multiplyNumbers()
{
    int num1, num2, product = 1;

    cout << "Enter the number of elements you want to multiply: ";
    cin >> num1;

    for (int iterator = num1; iterator >= 1; iterator--)
    {
        cout << "Enter numbers to multiply : ";
        cin >> num2;

        cout << "The product of " << product << " and " << num2 << " is : ";
        product *= num2;

        cout << product << endl;
        cout << endl;
    }

    cout << "Product of all entered integers is : " << product;
}

int main()
{
    multiplyNumbers();
    return 0;
}