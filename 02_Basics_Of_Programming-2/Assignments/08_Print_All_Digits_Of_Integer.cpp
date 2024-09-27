#include <iostream>
using namespace std;

void printDigitsOfInteger(int n)
{
    while (n)
    {
        int digit = n % 10;
        cout << "Digit : " << digit << endl;
        n /= 10;
    }
}

int main()
{
    int num;

    cout << "Enter the number : " << endl;
    cin >> num;

    printDigitsOfInteger(num);

    return 0;
}