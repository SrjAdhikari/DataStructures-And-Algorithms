#include <iostream>
#include <string>
using namespace std;


// Function to check if a string is a palindrome using recursion
bool checkPalindrome(string str, int start, int end) {
    // Base case: When start index is greater than or equal to end index, the string is a palindrome
    if (start >= end) {
        return true;
    }

    // If characters at the start and end indices are not equal, the string is not a palindrome
    if (str[start] != str[end]) {
        return false;
    }

    // Recursive case: Check the substring from start+1 to end-1
    return checkPalindrome(str, start + 1, end - 1);
}


int main() {
    string str;
    cout << "Enter a string to check palindrome : " << endl;
    cin >> str;

    int start = 0;
    int end = str.length() - 1;

    bool isPalindrome = checkPalindrome(str, start, end);
    if(isPalindrome) {
        cout << str << " is a palindrome.";
    }
    else {
        cout << str << " is not a palindrome.";
    }

    return 0;
}

//* **********************************************
//* Time Complexity : O(N)
//* Space Complexity : O(N)
//* **********************************************