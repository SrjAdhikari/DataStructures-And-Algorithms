#include <iostream>
using namespace std;

// Function to check whether a number is prime or not.
bool isPrime(int num)
{
    for (int start = 2; start <= num / 2; start++)
    {
        if (num % start == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int num;
    cout << "Enter a number : ";
    cin >> num;

    bool result = isPrime(num);
    if (result == true)
        cout << num << " is a Prime Number.";
    else
        cout << num << " is not a Prime Number.";

    return 0;
}