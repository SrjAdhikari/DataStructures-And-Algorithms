#include <iostream>
using namespace std;

// TrieNode class definition, representing a node in the Trie (prefix tree).
class TrieNode {
public:
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

// Trie class definition, representing the Trie (prefix tree) structure.
class Trie {
public :
    // Root node of the Trie.
    TrieNode *root;

    // Constructor to initialize the Trie.
    Trie() {
        // Create the root node for the Trie.
        root = new TrieNode();
    }


    // Function to insert a word into the trie
    void insert(string word) {
        // Start from the root of the Trie.
        TrieNode *node = root;

        // Iterate over each character in the word
        for(char ch : word) {
            // Compute the index corresponding to the character (0-25 for 'a' to 'z').
            int index = ch - 'a';

            // If there is no child node for the current character, create a new TrieNode.
            if(node->children[index] == NULL)
                // Create a new node for the character.
                node->children[index] = new TrieNode();

            // Move to the next node (the child node corresponding to the current character).
            node = node->children[index];
        }

        // After inserting all characters, mark the end of the word.
        node->isEnd = true;
    }

    //* ***********************************************
    //* Time Complexity : O(L) -> L : Length of the word
    //* Space Complexity : O(1)
    //* ***********************************************


    // Function to search a word in the trie
    bool search(string word) {
        // Start from the root of the Trie
        TrieNode *node = root;

        // Iterate over each character in the word
        for(char ch : word) {
            // Compute the index corresponding to the character (0-25 for 'a' to 'z').
            int index = ch - 'a';

            // If there is no child node exists for the current character, return false.
            if(node->children[index] == NULL)
                return false;

            // Move to the next node (the child node corresponding to the current character).
            node = node->children[index];
        }

        // After the loop, check if this node marks the end of a word in the Trie
        // Return true if it's the end of a word, false otherwise
        return node->isEnd;
    }

    //* ***********************************************
    //* Time Complexity : O(L) -> L : Length of the word
    //* Space Complexity : O(1)
    //* ***********************************************


    // Function to delete a word from the Trie (marks its end as false)
    void deleteWord(string word) {
        // Start from the root of the Trie
        TrieNode *node = root;

        // Iterate over each character in the word
        for(char ch : word) {
            // Compute the index corresponding to the character (0-25 for 'a' to 'z').
            int index = ch - 'a';

            // If the corresponding child node is NULL, the word does not exist in the Trie, so return.
            if(node->children[index] == NULL)
                return;

            // Move to the next node (the child node corresponding to the current character).
            node = node->children[index];
        }

        // After traversing all characters, mark the end of the word as false.
        // This will ensure that this word is no longer present in the Trie by unmarking its end.
        node->isEnd = false;
    }
    
    //* ***********************************************
    //* Time Complexity : O(L) -> L : Length of the word
    //* Space Complexity : O(1)
    //* ***********************************************
};

int main() {
    Trie *tree = new Trie();

    tree->insert("apple");
    tree->insert("appex");
    tree->insert("load");
    tree->insert("love");
    tree->insert("lov");
    tree->insert("loving");

    if(tree->search("apple")) {
        cout << "apple is present in the trie" << endl;
    }    
    else {
        cout << "apple is not present in the trie" << endl;
    }

    tree->deleteWord("loving");

    if(tree->search("loving")) {
        cout << "loving is present in the trie" << endl;
    }
    else {
        cout << "loving is not present in the trie" << endl;
    }

    return 0;
}