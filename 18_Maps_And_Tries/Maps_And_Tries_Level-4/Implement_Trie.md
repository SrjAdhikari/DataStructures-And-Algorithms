# Question : [Implement Trie (Prefix Tree) - (LeetCode : 208)](https://leetcode.com/problems/implement-trie-prefix-tree/description/)

A trie (pronounced as "try") or **prefix tree** is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

- `Trie()` Initializes the trie object.
- `void insert(String word)` Inserts the string `word` into the trie.
- `boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was inserted before), and `false` otherwise.
- `boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string `word` that has the prefix `prefix`, and `false` otherwise.

### Example

```
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]
Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
```

### Constraints

-   `1 <= word.length, prefix.length <= 2000`
-   `word` and `prefix` consist only of lowercase English letters.
-   At most `3 * 10^4` calls in total will be made to `insert`, `search`, and `startsWith`.


## Solution

```Cpp
// Define the TrieNode class to represent each node in the Trie.
class TrieNode {
public:
    // Each TrieNode has a map to its children where each key is a character and 
    // the value is a pointer to another TrieNode, representing possible continuations of words.
    unordered_map<char, TrieNode*> children;

    // A boolean flag to indicate if the current node marks the end of a word.
    bool isEnd;

    // Constructor to initialize the TrieNode.
    TrieNode() {
        // Set the end-of-word flag to false by default since a new node is not the end of a word initially.
        isEnd = false;
    }
};

// Define the Trie class to implement Trie operations such as insert, search, and startsWith.
class Trie {
public:
    // Root node of the Trie. All words are inserted under this root.
    TrieNode *root;

    // Constructor to initialize the Trie.
    Trie() {
        // Create a root node with no characters, which will act as the starting point.
        root = new TrieNode();
    }
    
    // Method to insert a word into the Trie.
    void insert(string word) {
        // Start from the root node.
        TrieNode *node = root;

        // Traverse each character in the word.
        for (char ch : word) {
            // Check if the current character `ch` already exists as a child of the current node.
            if (node->children.find(ch) == node->children.end()) {
                // If the character does not exist, create a new TrieNode for this character.
                node->children[ch] = new TrieNode();
            }
            // Move the current node to the child node corresponding to `ch`.
            node = node->children[ch];
        }

        // After processing all characters, mark the last node as the end of a word.
        node->isEnd = true;
    }
    
    // Method to search for a word in the Trie.
    // Returns true if the word is found and false otherwise.
    bool search(string word) {
        // Start from the root node.
        TrieNode *node = root;

        // Traverse each character in the word.
        for (char ch : word) {
            // Check if the current character `ch` exists as a child of the current node.
            if (node->children.find(ch) == node->children.end()) {
                // If the character is not found, the word does not exist in the Trie.
                return false;
            }
            // Move to the child node corresponding to `ch`.
            node = node->children[ch];
        }

        // After the loop, check if the last node marks the end of a word in the Trie.
        // If it does, then the word exists; otherwise, it's only a prefix, not a full word.
        return node->isEnd;
    }
    
    // Method to check if there is any word in the Trie that starts with a given prefix.
    // Returns true if such a prefix exists, false otherwise.
    bool startsWith(string prefix) {
        // Start from the root node.
        TrieNode *node = root;

        // Traverse each character in the prefix.
        for (char ch : prefix) {
            // Check if the current character `ch` exists as a child of the current node.
            if (node->children.find(ch) == node->children.end()) {
                // If the character is not found, then no word with this prefix exists in the Trie.
                return false;
            }
            // Move to the child node corresponding to `ch`.
            node = node->children[ch];
        }

        // If we reach here, it means all characters of the prefix were found in sequence,
        // so the prefix exists in the Trie.
        return true;
    }
};
```