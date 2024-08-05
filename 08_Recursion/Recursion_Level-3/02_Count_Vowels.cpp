#include <iostream>
#include <string>
using namespace std;


// Function to count the number of vowels in a string using recursion
int countVowels(string str, int index) {
    // Base case: When index is less than 0, return 0
    if (index < 0) {
        return 0;
    }

    // Check if the current character is a vowel
    if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u') {
        // If it's a vowel, add 1 and recursively count vowels in the substring before the current index
        return 1 + countVowels(str, index - 1);
    }
    else {
        // If it's not a vowel, simply recursively count vowels in the substring before the current index
        return countVowels(str, index - 1);
    }
}


int main() {
    string str;
    cout << "Enter a string to count vowels : " << endl;
    cin >> str;

    int index = str.length() - 1;

    int count = countVowels(str, index);
    cout << "Number of vowels : " << count << endl;

    return 0;
}

//* **********************************************
//* Time Complexity : O(N)
//* Space Complexity : O(N)
//* **********************************************