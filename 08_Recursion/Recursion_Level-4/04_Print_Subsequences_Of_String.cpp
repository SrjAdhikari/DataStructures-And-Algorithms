#include <iostream>
#include <vector>
#include <String>
using namespace std;

// Function to print all subsequences of a given string
void printSubsequences(string str, int index, string output, vector<string>& ans) {
    // Base case: If we've considered all characters in the string
    if (index == str.length()) {
        // Add the current subsequence to the answer list
        ans.push_back(output);  
        return;   
    }

    // Recursive call without including the current character in the subsequence
    printSubsequences(str, index + 1, output, ans);

    // Include the current character in the subsequence
    output.push_back(str[index]);

    // Recursive call including the current character in the subsequence
    printSubsequences(str, index + 1, output, ans);
}

int main() {
    string str = "abc";
    int index = 0;
    string output = "";
    vector<string> ans;

    printSubsequences(str, index, output, ans);

    cout << "Subsequences of string : " << endl;
    for(string s : ans){
        cout << s << " " << endl;
    }

    return 0;
}

//* **********************************************
//* Time Complexity : O(2^n)
//* Space Complexity : O(n * 2^n)
//* **********************************************