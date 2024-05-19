#include<iostream>
using namespace std;

nt main() {

    int num1, num2;
    
    cout << "Enter the value of num1 : " << endl;
    cin >> num1;

    cout << "Enter the value of num2 : " << endl;
    cin >> num2;

    if(num1 > num2){
        cout << "Num1 is greater";
    }
    if (num1 < num2)
    {
        cout << "Num2 is greater";
    }

    return 0;
}