#include <iostream>
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

//* ***********************************************
//* Time Complexity : O(L) -> L : Length of the word
//* Space Complexity : O(L)
//* ***********************************************


// Functiion to search for a word in the trie
bool search(TrieNode *root, string word) {
    // Base case: If the word is empty, return whether this node marks the end of a word.
    if(word.length() == 0) {
        return root->isEnd;
    }

    // Process the first character of the current word segment.
    char ch = word[0];

    // Compute the index corresponding to the character (0-25 for 'a' to 'z').
    int index = ch - 'a';

    // Pointer to the child node corresponding to the current character.
    TrieNode *child;

    // If there is no child node for the current character, return false.
    if(root->children[index] == NULL) {
        return false;
    }
    // If the child node exists, set `child` to point to it.
    else {
        child = root->children[index];
    }

    // Move to the next node (the child node corresponding to the current character).
    return search(child, word.substr(1));
}

//* ***********************************************
//* Time Complexity : O(L) -> L : Length of the word
//* Space Complexity : O(L)
//* ***********************************************


// Function to delete a word from the trie
void deleteWord(TrieNode *root, string word) {
    // Base case: If the word is empty, mark the current node as the end of a word.
    if(word.length() == 0) {
        root->isEnd = false;
        return;
    }

    // Process the first character of the current word segment.
    char ch = word[0];

    // Compute the index corresponding to the character (0-25 for 'a' to 'z').
    int index = ch - 'a';

    // Pointer to the child node corresponding to the current character.
    TrieNode *child;

    // If there is no child node for the current character, return.
    if(root->children[index] == NULL) {
        return;
    }
    // If the child node exists, set `child` to point to it.
    else {
        child = root->children[index];
    }

    // Move to the next node (the child node corresponding to the current character).
    deleteWord(child, word.substr(1));
}

//* ***********************************************
//* Time Complexity : O(L) -> L : Length of the word
//* Space Complexity : O(L)
//* ***********************************************

int main() {
    TrieNode *root = new TrieNode();
    insert(root, "cater");
    insert(root, "care");
    insert(root, "com");
    insert(root, "Lover");
    insert(root, "Load");
    insert(root, "cat");
    insert(root, "car");

    // Check if the word "cater" is present in the Trie before deletion
    cout << "Before deletion : " << endl;
    if(search(root, "cater"))
        cout << "cater is present in the trie" << endl;
    else
        cout << "cater is not present in the trie" << endl;

    cout << endl;

    // Delete the word
    deleteWord(root, "cater");

    // Check if the word "cater" is present in the Trie after deletion
    cout << "After deletion : " << endl;
    if(search(root, "cater"))
        cout << "cater is present in the trie" << endl;
    else
        cout << "cater is not present in the trie" << endl;

    return 0;
}