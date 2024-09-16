#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to find the first non-repeating character in the stream of characters
string nonRepeatingChar(string str) {
    string output = "";              // This will store the result with non-repeating characters (or '#')
    vector<int> freq(26, 0);         // Frequency array to count occurrences of each character (only lowercase letters)
    queue<char> q;                   // Queue to maintain the order of characters for checking their repeat status

    // Loop through each character in the input string
    for (int i = 0; i < str.size(); i++) {
        freq[str[i] - 'a']++;        // Increment the frequency count of the current character
        q.push(str[i]);              // Push the current character into the queue for tracking

        // Check the front of the queue to find the first non-repeating character
        while (!q.empty()) {
            // If the front of the queue has been repeated (frequency > 1), remove it from the queue
            if (freq[q.front() - 'a'] > 1) {
                q.pop();             // This character is repeated, so we discard it from the queue
            } 
            else {
                // If the front character is non-repeating, add it to the result
                output += q.front();
                break;               // Stop the loop as we found the first non-repeating character
            }
        }

        // If the queue is empty, it means all characters seen so far are repeating, so add '#'
        if (q.empty())
            output += '#';
    }

    // Return the final output string containing non-repeating characters at each point
    return output; 
}

int main() {
    string str = "aabbcc";                // Input string to test the function
    string ans = nonRepeatingChar(str);   // Call the function and store the result
    cout << ans << endl;                  // Output the result

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) 
//* **********************************************