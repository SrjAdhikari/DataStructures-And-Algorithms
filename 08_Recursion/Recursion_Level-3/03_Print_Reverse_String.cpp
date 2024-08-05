#include <iostream>
#include <string>
using namespace std;


// Function to reverse a string using recursion
void reverseString(string& str, int start, int end) {
    // Base case: When start index is greater than or equal to end index, stop recursion
    if (start >= end) {
        return;
    }

    // Swap the characters at the start and end indices
    char ch = str[start];
    str[start] = str[end];
    str[end] = ch;

    // Alternatively, you could use the std::swap function:
    // swap(str[start], str[end]);

    // Recursive call to reverse the substring excluding the swapped characters
    reverseString(str, start + 1, end - 1);
}


int main() {
    string str;
    cout << "Enter a string to reverse : ";
    cin >> str;

    int start = 0;
    int end = str.length() - 1;

    cout << "Reverse string is : ";
    reverseString(str, start, end);
    cout << str << endl;

    return 0;
}

//* **********************************************
//* Time Complexity : O(N)
//* Space Complexity : O(N)
//* **********************************************