#include <iostream>
using namespace std;

int main(){

    int num;

    cout << "Enter a number : " << endl;
    cin >> num;     //User Input

    int start = 1;  //Declaring starting number
    int sum = 0;    //Initializing sum

    while (start <= num)    //Base Condition
    {
        if (start % 2 == 0)     //Condition to check even number
        {
            sum = sum + start;  //Calculating the sum, if above "If Condition" become true
        }
        start = start + 1;  //If above "If Condition" become false increasing starting number by 1
    }
    cout << "Sum of even number is : " << sum ;    //Printing the sum of even number

    /*
    int num;
    cout << "Enter a number : " << endl;
    cin >> num;                     //User Input

    int start = 1;                  //Declaring the starting number

    while (start <= num)            //Base Condition
    {
        cout << start << "  ";      //Printing a number
        start = start + 1;          //Increasing a starting number by 1
    }
    */

    return 0;
}