#include<iostream>
#include<cmath>
using namespace std;

int binaryToDecimal(int num){

    int decimalNum = 0;
    int power = 0;

    while (num != 0) {
        int bit = (num % 10);  // Calculate last digit or remainder of a number
        decimalNum += bit * pow(2, power);
        num = num / 10;   // Remove last digit from number
        power++;
    }
    return decimalNum;
}


int main() {

    int num;

    cout << "Enter a number : " << endl;
    cin >> num;

    int decimalNum = binaryToDecimal(num);
    cout << "Decimal representation of " << num << " is : " << decimalNum << endl;
    
    return 0;
}