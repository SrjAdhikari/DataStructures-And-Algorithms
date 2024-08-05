#include <iostream>
#include <string>
using namespace std;


// Function to count the number of consonants in a string using recursion
int countConsonants(string str, int index) {
    // Base case: When index is less than 0, it means we've processed all characters, so return 0
    if (index < 0) {
        return 0;
    }

    // Check if the current character is a consonant
    // A consonant is a letter that is not a vowel
    if (str[index] != 'a' && str[index] != 'e' && str[index] != 'i' && str[index] != 'o' && str[index] != 'u') {
        // If it's a consonant, add 1 and recursively count consonants in the substring before the current index
        return 1 + countConsonants(str, index - 1);
    } 
    else {
        // If it's not a consonant, simply recursively count consonants in the substring before the current index
        return countConsonants(str, index - 1);
    }
}


int main() {
    string str;
    cout << "Enter a string  : ";
    cin >> str;

    int index = str.length() - 1;

    int count = countConsonants(str, index);
    cout << "Number of consonants : " << count << endl;

    return 0;
}

//* **********************************************
//* Time Complexity : O(N)
//* Space Complexity : O(N)
//* **********************************************