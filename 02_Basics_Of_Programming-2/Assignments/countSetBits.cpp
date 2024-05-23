#include<iostream>
using namespace std;

// Normal Method (Divide Method)
int countSetBitsDivideMethod(int n){

    int count = 0;

    while(n > 0){
        int bit = n % 2;
        if(bit == 1){
            count++;
        }
        n = n / 2;
    }
    return count;
}


// Bitwise Method
int countSetBitsBitwiseMethod(int n){

    int count = 0;

    while(n > 0){
        int bit = n & 1;
        if(bit == 1){
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main(){

    int num;

    cout << "Enter the number : " << endl;
    cin >> num; 

    // int bitCount = countSetBitsDivideMethod(num);
    // cout << "Count of bits is : " << bitCount << endl;

    int countBits = countSetBitsBitwiseMethod(num);
    cout << "Count of bits is : " << countBits << endl;

    return 0;
}