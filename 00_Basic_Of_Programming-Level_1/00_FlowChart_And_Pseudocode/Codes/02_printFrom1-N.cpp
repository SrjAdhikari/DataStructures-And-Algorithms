#include <iostream>
using namespace std;

// Function to count number from 1 to N.
void countFrom1ToN(int target)
{
    cout << "Number from 1 to " << target << " is : " << endl;

    for (int start = 1; start <= target; start++)
        cout << start << " ";
}

// Function to count number from 1 to N given by user.
void countFromOneToN()
{
    int start, target;

    cout << "Enter the target number: " << endl;
    cin >> target;

    cout << "Number from 1 to " << target << " is : " << endl;

    for (int start = 1; start <= target; start++)
        cout << start << "  ";
}

int main()
{
    countFromOneToN();
    // countFrom1ToN(10);

    return 0;
}