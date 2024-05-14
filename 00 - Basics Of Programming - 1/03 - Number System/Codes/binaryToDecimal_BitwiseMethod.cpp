#include<iostream>
#include<cmath>
using namespace std;

int binaryToDecimal(int num){

    int decimalNum = 0;
    int power = 0;

    while (num > 0) {
        if(num % 10 == 1){ // extracting the last digit
            decimalNum += (1 << power) ;
        }
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