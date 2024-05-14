#include <iostream>
using namespace std;

// Function to count number from N to 1.
void countFromNTo1(int target)
{
    cout << "Number from " << target << " to 1 is : " << endl;

    for (int start = target; start >= 1; start--)
        cout << start << " ";
}

// Function to count number from N given by user to 1
void countFromNToOne()
{
    int target;

    cout << "Enter the target number: " << endl;
    cin >> target;

    cout << "Number from " << target << " to 1 is : " << endl;

    for (int start = target; start >= 1; start--)
        cout << start << " ";
}

int main()
{
    countFromNToOne();
    // Calling function with argument 15, so it will print numbers from 15 to 1
    // countFromNTo1(15); 
    
    return 0;
}