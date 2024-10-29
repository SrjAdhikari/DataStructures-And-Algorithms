#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TrieNode class definition, representing a node in the Trie (prefix tree).
class TrieNode {
public :
    // Array to store pointers to the children nodes (for each alphabet letter).
    TrieNode *children[26];

    // Boolean flag to mark the end of a word.
    bool isEnd;

    // Constructor to initialize the TrieNode.
    TrieNode() {
        // Initialize all child pointers to NULL.
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        // Initialize the end-of-word flag to false.
        isEnd = false;
    }
};

// Function to insert a word into the trie
void insert(TrieNode *root, string word) {
    // cout << "Inserting : " << word << endl;

    // Base case : If the word is empty, mark the current node as the end of a word.
    if(word.length() == 0) {
        root->isEnd = true;
        return;
    }

    // Process the first character of the current word segment.
    char ch = word[0];

    // Compute the index corresponding to the character (0-25 for 'a' to 'z').
    int index = ch - 'a';

    // Pointer to the child node corresponding to the current character.
    TrieNode *child;

    // If there is no child node for the current character, create a new TrieNode.
    if(root->children[index] == NULL) {
        // Create a new node for the character.
        child = new TrieNode();

        // Add the new node as a child of the current node.
        root->children[index] = child;
    }
    // If the child node exists, set `child` to point to it.
    else {
        child = root->children[index];
    }

    // Move to the next node (the child node corresponding to the current character).
    insert(child, word.substr(1));
}

// Function to store string below the last character of the given prefix
void storeBelowChar(TrieNode* root, vector<string>& ans, string& input) {
    // If the current node marks the end of a word, add the current complete word (which is 'input' at this point) to the answer list
    if(root->isEnd == true) {
        ans.push_back(input);
    }

    // Traverse all possible children nodes (from 'a' to 'z')
    for(char ch = 'a'; ch <= 'z'; ch++) {
        // Calculate index of the character in children array
        int index = ch - 'a';

        // Access the child node for character ch
        TrieNode* child = root->children[index];

        // If there is a valid child node, append the character to the input and continue the traversal
        if(child != NULL) {
            // Add the character to the current input string
            input.push_back(ch);

            // Recursive call to explore the next level
            storeBelowChar(child, ans, input);

            // Backtrack to explore other branches, removing the last character
            input.pop_back();
        }
    }
}

// Function to retrieve suggestions based on the input prefix
vector<vector<string>> getSuggestions(TrieNode* root, string input) {
    // Output list to store the suggestions for each prefix of the input
    vector<vector<string>> output;

    // 'prev' points to the root node initially to start the traversal
    TrieNode* prev = root;

    // 'str' will store the current prefix being evaluated
    string str = "";

    // Iterate over each character in the input string
    for(int i = 0; i < input.length(); i++) {
        // Get the current character from the input
        char lastChar = input[i];

        // Calculate the index in the children array for this character
        int index = lastChar - 'a';

        // Access the child node that corresponds to 'lastChar'
        TrieNode* curr = prev->children[index];

        // If there is no valid child node for this character, no further suggestions are possible
        if(curr == NULL) {
            // Exit the loop as there are no more matching prefixes
            break;
        }
        // If there is a valid child node, add the character to the current prefix and explore the next level
        else {
            // Temporary list to hold matching words for the current prefix
            vector<string> temp;

            // Add the character to the current prefix 'str'
            str += lastChar;

            // Use 'storeBelowChar' to find all words starting with this prefix
            storeBelowChar(curr, temp, str);

            // Store the found suggestions in the output
            output.push_back(temp);
        }

        // Move 'prev' to 'curr' to continue traversing the Trie with the next character
        prev = curr;
    }

    // Return the list of suggestions for each prefix of the input
    return output;
}

int main() {
    TrieNode* root = new TrieNode();

    // Insert words into the Trie
    insert(root, "code");
    insert(root, "court");
    insert(root, "course");
    insert(root, "car");
    insert(root, "card");
    insert(root, "load");
    insert(root, "love");
    insert(root, "loved");
    insert(root, "lover");

    // Get suggestions based on the prefix 'loa'
    vector<vector<string>> output = getSuggestions(root, "loa");

    // Display the suggestions for each prefix of the input
    for(int i = 0; i < output.size(); i++) {
        cout << i << " : ";

        // Iterate over each suggested word and print it
        for(auto ch : output[i]) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}
