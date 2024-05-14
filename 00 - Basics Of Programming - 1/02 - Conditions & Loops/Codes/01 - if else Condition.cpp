#include<iostream>
using namespace std;

int main() {

    int num;

    cout << "Enter the value of num :" << endl;
    cin >> num;

    if (num > 0)
    {
        cout << "Num is positive";
    }
    else{
        cout << "Num is negative";
    }

    return 0;
}