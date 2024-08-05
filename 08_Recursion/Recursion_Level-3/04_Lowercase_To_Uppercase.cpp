#include <iostream>
#include <string>
using namespace std;


// Function to convert all lowercase letters to uppercase in a string using recursion
void lowerToUpper(string& str, int index) {
    // Base case: When index is less than 0, stop recursion
    if (index < 0) {
        return;
    }

    // Convert the character at the current index from lowercase to uppercase if it's a lowercase letter
    if (str[index] >= 'a' && str[index] <= 'z') {
        str[index] = 'A' + str[index] - 'a';
    }

    // Recursive call to process the next character in the string
    lowerToUpper(str, index - 1);
}


int main() {
    string str;
    cout << "Enter a string : ";
    cin >> str;

    int index = str.length() - 1;

    cout << "Uppercase is : ";
    lowerToUpper(str, index);
    cout << str << endl;

    return 0;
}

//* Lowercase to Uppercase Conversion: Converts a lowercase letter to uppercase by using the formula 'A' + str[index] - 'a'. This works because the ASCII values of uppercase and lowercase letters differ by a fixed amount (i.e., A is 65 and a is 97, with a difference of 32). For example, 'a' becomes 'A' by subtracting the difference ('a' - 'A').

//* **********************************************
//* Time Complexity : O(N)
//* Space Complexity : O(N)
//* **********************************************