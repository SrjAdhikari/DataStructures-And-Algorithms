#include<iostream>
using namespace std;

int main (){
    
    char ch;
    
    cout << "Enter the character : " << endl;
    cin >> ch;

    if(ch >= 'A' && ch <= 'Z')
    {
        cout << "Charater is Uppercase." << endl;
    }
    else if(ch >= 'a' && ch <= 'z')
    {
        cout << "Character is Lowecase." << endl;
    }
    else
    {
        cout << "Character is Numeric.";
    }

    return 0;
}