#include <iostream>
#include <unordered_map>
using namespace std;

void countFrequency(string str) {
    // Declare an unordered_map to store character frequencies
    unordered_map<char, int> ump;

    // Traverse the string and count the frequency of each character
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        ump[ch]++;      // Increment the frequency of the character
    }

    // Print the frequency of each character
    for(auto pair : ump) {
        cout << "Character: '" << pair.first << "' appears " << pair.second << " times." << endl;
    }
}


int main() {
    string str = "abracadabra";
    countFrequency(str);
    return 0;
}

//* *****************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N)
//* *****************************************