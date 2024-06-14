# Question : [Alien Dictionary - GFG](https://www.geeksforgeeks.org/problems/alien-dictionary/1)

Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
**Note:** Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

### Example 1
```plaintext
Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
```

### Example 2
```plaintext
Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
```

### Your task
You don't need to read or print anything. Your task is to complete the function **findOrder**() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.

```
Expected Time Complexity : O(N * |S| + K) , where |S| denotes maximum length.
Expected Space Compelxity : O(K)
```

### Constraints
`1 ≤ N, M ≤ 300`
`1 ≤ K ≤ 26`
`1 ≤ Length of words ≤ 50`

## Solution

```Cpp
Using BFS Traversal + Topological Sort :

class Solution {
public:

    string findOrder(string dict[], int N, int K) {
        
        // Create adjacency list for the graph and in-degree vector
        vector<int> adj[K];             // To store edges from one character to another
        vector<int> inDegree(K, 0);     // To store the in-degree of each character
        
        for (int i = 0; i < N - 1; i++) {
            // Extract two consecutive words from the dictionary
            string word1 = dict[i];
            string word2 = dict[i + 1];
            
            // Initialize indices to compare characters of word1 and word2
            int index1 = 0;
            int index2 = 0;
            
            // Compare characters of word1 and word2 until we find a mismatch or reach the end of one of the words
            while (index1 < word1.size() && index2 < word2.size() && word1[index1] == word2[index2]) {
                index1++;
                index2++;
            }
            
            // Skip to the next pair if all characters of word1 match word2
            if (index1 == word1.size()) {
                continue;
            }
            

            // Find the first differing character and create a directed edge from word1's character to word2's character
            // 'a' is subtracted to convert character to index (e.g., 'a' -> 0, 'b' -> 1, ..., 'z' -> 25)
            char charFromWord1 = word1[index1];
            char charFromWord2 = word2[index2];
            adj[charFromWord1 - 'a'].push_back(charFromWord2 - 'a');
            
            // Increment the in-degree of word2[k] (since word2 depends on word1 in the dictionary order)
            inDegree[charFromWord2 - 'a']++;
        }
        
        // Initialize a queue to process characters with zero in-degree (no prerequisites)
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Initialize an empty string to store the result (order of characters)
        string ans;
    
        // Process characters in topological order using BFS
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            
            // Convert the integer index back to character ('a' + frontNode)
            char ch = 'a' + frontNode;
            ans += ch;  // Append the character to the result
            
            // Process all adjacent characters (nodes) of the current character
            for (auto nbrNode : adj[frontNode]) {
                // Decrease the in-degree of the adjacent character
                inDegree[nbrNode]--;
                
                // If the in-degree becomes zero, add the character to the queue for processing
                if (inDegree[nbrNode] == 0) {
                    q.push(nbrNode);
                }
            }
        }
        
        // Return the result string containing the topological order of characters
        return ans;
    }
};

Time Complexity : O(N * L + K + P) -> L is the average length of the words.
Space Complexity = O(K + P) -> P is the total number of dependencies.
```