#include <iostream>
using namespace std;

int main(){

    int num;
    
    cout << "Enter a number : " << endl;
    cin >> num;     //User Input

    int sum = 0;    //Initializing sum

    for (int start = 1; start <= num; start++){
        sum = sum + start;     //Calculating sum
    }
    cout << "Sum is : " << sum;     //Printing sum

    // Printing table of 19
    // for(int i = 0; i <= 10; i++){
    //     cout << 19 * i << endl;
    // }

    return 0;
}