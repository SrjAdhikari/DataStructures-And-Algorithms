#include <iostream>
using namespace std;

int printSquareSum (int n) {
    if(n == 1) {
        return 1;
    }
    return n * n + printSquareSum(n - 1);
}


int main () {
    int num;
    cout << "Enter a number : ";
    cin >> num;

    int sum = printSquareSum(num);
    cout << "Sum of square of " << num << " natural numbers : " << sum << endl;

    return 0;
}