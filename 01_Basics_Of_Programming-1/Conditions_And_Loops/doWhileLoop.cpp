#include <iostream>
using namespace std;

int main(){

    int num;
    cout << "Enter a number : " << endl;
    cin >> num;                     //User Input

    int start = 1;                  //Declaring starting number

    do{
       if (start % 2 == 0)          //Condition to check even number
       {
        cout << start << "  ";      //Printing the number, if above "If Condition" become true
       }
       start = start + 1;           //If above "If Condition" become false increasing starting number by 1
       
    } while (start <= num);         //Base Condition

    return 0;
}