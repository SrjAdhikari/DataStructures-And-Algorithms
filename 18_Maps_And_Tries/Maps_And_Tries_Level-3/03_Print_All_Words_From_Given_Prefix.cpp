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
void storeBelowChar(TrieNode* root, vector<string>& ans, string output) {
    // If the current node marks the end of a word, add the current constructed word to the answer list
    if(root->isEnd == true) {
        ans.push_back(output);
    }

    // Traverse all possible children nodes (from 'a' to 'z')
    for(char ch = 'a'; ch <= 'z'; ch++) {
        // Calculate index of the character in children array
        int index = ch - 'a';

        // Access the child node for character ch
        TrieNode* child = root->children[index];

        // If there is a valid child node, append the character to the input and continue the traversal
        if(child != NULL) {
            // Add the character to the current output string
            output.push_back(ch);

            // Recursive call to explore the next level
            storeBelowChar(child, ans, output);

            // Backtrack to explore other branches, removing the last character
            output.pop_back();
        }
    }
}

// Function to find all words that start with a given prefix
void findPrefixString(TrieNode* root, vector<string>& ans, string prefix) {
    // Base case: If the input prefix has been fully traversed, collect all words from this Trie node onward
    if(prefix.length() == 0) {
        // Mark this node as the last character node of the prefix
        TrieNode* lastChar = root;

        // Collect all words below this node
        storeBelowChar(lastChar, ans, prefix);
        return;
    }

    // Get the next character in the input prefix and calculate its corresponding index in the Trie
    char ch = prefix[0];
    int index = ch - 'a';
    TrieNode* child;

    // Check if there is a child for the current character
    if(root->children[index] != NULL) {
        // Move to the child node for the current character
        child = root->children[index];
    }
    // If no child exists for the character, no words with this prefix exist
    else {
        return;
    }

    // Recursive call to continue searching the next character in the prefix
    findPrefixString(child, ans, prefix.substr(1));
}

int main() {
    TrieNode* root = new TrieNode();

    // Insert words into the Trie
    insert(root, "code");
    insert(root, "court");
    insert(root, "course");
    insert(root, "car");
    insert(root, "card");
    insert(root, "cat");
    insert(root, "love");
    insert(root, "loved");
    insert(root, "lovely");

    // Define the prefix to search for and initialize the prefix as input
    string prefix = "co";
    vector<string> words; 

    // Call the function to find all words starting with the given prefix
    findPrefixString(root, words, prefix);

    // Output all collected words with the specified prefix
    for (auto ch : words) {
        cout << prefix + ch << " ";
    }
    cout << endl;

    return 0;
}