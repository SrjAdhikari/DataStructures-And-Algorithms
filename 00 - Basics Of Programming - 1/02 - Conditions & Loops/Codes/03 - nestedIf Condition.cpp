#include<iostream>
using namespace std;

int main(){
    int num = 15;

    if (num >= 0) {
        if (num % 2 == 0) {
            cout << "The number is positive and even." << endl;
        } else {
            cout << "The number is positive and odd." << endl;
        }
    } else {
        cout << "The number is negative." << endl;
    }

    return 0;
}