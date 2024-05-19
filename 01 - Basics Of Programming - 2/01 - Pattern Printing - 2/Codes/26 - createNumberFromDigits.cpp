#include<iostream>
using namespace std;

int createNumberFromDigits(int n){

    int num = 0;

    for(int i = 0; i < n; i++){

        // Taking user input for digits
        cout << "Enter Digits : " << endl;
        int digit;
        cin >> digit;

        // Creating number from digits enter by user
        num = num * 10 + digit;
        cout << "Number created so far : " << num << endl;
        cout << endl;
    }
    return num;
}


int main(){

    int num;

    cout << "Enter the number : " << endl;
    cin >> num; 

    int number = createNumberFromDigits(num);
    cout << "Created number by digits is : " << number << endl;

    return 0;
}