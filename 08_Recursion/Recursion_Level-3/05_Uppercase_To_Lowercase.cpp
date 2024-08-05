#include <iostream>
#include <string>
using namespace std;


// Function to convert all uppercase letters in a string to lowercase using recursion
void upperToLower(string& str, int index) {
    // Base case: When index is less than 0, stop recursion
    if (index < 0) {
        return;
    }

    // Convert the character at the current index from uppercase to lowercase if it's a uppercase letter
    if (str[index] >= 'A' && str[index] <= 'Z') {
        str[index] = 'a' + (str[index] - 'A');
    }

    // Recursive call to process the previous character
    upperToLower(str, index - 1);
}


int main() {
    string str;
    cout << "Enter a string : ";
    cin >> str;

    int index = str.length() - 1;

    cout << "Lowercase is : ";
    upperToLower(str, index);
    cout << str << endl;

    return 0;
}

//* **********************************************
//* Time Complexity : O(N)
//* Space Complexity : O(N)
//* **********************************************