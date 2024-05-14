#include<iostream>
#include<cmath>
using namespace std;

int decimalToBinary(int num){

    int binaryNum = 0;
    int power = 0;

    while (num > 0) {
        int bit = (num & 1);  // Calculate last digit or remainder of a number
        binaryNum += bit * pow(10, power);
        num = num >> 1;   // Remove last digit from number
        power++;
    }
    return binaryNum;
}

int main() {

    int num;

    cout << "Enter a number : " << endl;
    cin >> num;

    int binaryNum = decimalToBinary(num);
    cout << "Binary representation of " << num << " is : " << binaryNum << endl;
    
    return 0;
}