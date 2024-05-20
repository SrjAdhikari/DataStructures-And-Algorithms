#include <iostream>
using namespace std;

void printFancyPattern(int n)
{

    for (int row = 0; row < n; row++)
    {
        if (row == 0)
        {
            cout << row + 1;
        }
        else if (row == n - 1)
        {
            for (int col = 0; col < n; col++)
            {
                cout << col + 1 << " ";
            }
        }
        else
        {
            for (int col = 0; col < row + 2; col++)
            {
                if (col == 0)
                {
                    cout << col + 1;
                }
                else if (col == (row + 2 - 1))
                {
                    cout << col << " ";
                }
                else
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
}

int main()
{

    int row;

    cout << "Enter the number of row : " << endl;
    cin >> row;

    printFancyPattern(row);

    return 0;
}