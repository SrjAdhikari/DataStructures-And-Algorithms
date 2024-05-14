
#include <iostream>
using namespace std;

void printEvenNumbers()
{
    int targetNum;

    cout << "Enter the taget number : " << endl;
    cin >> targetNum;

    // Check and print the even from 1 to targetNum.
    cout << "Even numbers between 1 and " << targetNum << " are : " << endl;
    for (int iterator = 1; iterator < targetNum; iterator++)
    {
        if (iterator % 2 == 0)
        {
            cout << iterator << " ";
        }
    }
}

void printEvenNumbers2()
{
    int targetNum;

    cout << "Enter the taget number : " << endl;
    cin >> targetNum;

    // Check and print the even from 1 to targetNum.
    cout << "Even numbers between 1 and " << targetNum << " are : " << endl;
    for (int iterator = 2; iterator < targetNum; iterator = iterator + 2)
    {
        cout << iterator << " ";
    }
}

void aBC(int &num)
{
    num++;
    cout << num + 5;
}
int main()
{
    // printEvenNumbers();
    printEvenNumbers2();

    return 0;
}