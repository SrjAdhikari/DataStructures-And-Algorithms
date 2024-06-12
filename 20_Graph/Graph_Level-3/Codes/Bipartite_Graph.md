# Question : [Bipartite Graph - GFG](https://www.geeksforgeeks.org/problems/bipartite-graph/1)

Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

### Example 1

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700410/Web/Other/cdb283af-c52d-46df-8646-5017b45b5a13_1685086658.png)

```plaintext
Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700410/Web/Other/471d9abf-5d47-48ea-aa35-2dace9f5a2da_1685086659.png)

```plaintext
Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
```

### Your task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of the graph and returns a boolean value true if the graph is bipartite otherwise returns false.


```plaintext
Expected Time Complexity : O(V + E)
Expected Auxiliary Space : O(V)
```

### Constraints
`1 ≤ V, E ≤ 10^5`

## Solution 1

```Cpp
Using BFS Traversal :

class Solution {
public:

    // Function to check if a graph is bipartite
    bool isBipartite(int V, vector<int> adj[]) {

        vector<int> color(V, -1);   // Vector to store the color of each vertex
        queue<int> q;               // Queue for BFS
        
        // Iterate through all vertices to ensure all components are checked
        for (int node = 0; node < V; node++) {
            // If the node is not colored, start a BFS from that node
            if (color[node] == -1) {
                q.push(node);       // Push the starting node to the queue
                color[node] = 0;    // Color the starting node with color 0
                
                // Process the queue -> Perform BFS
                while (!q.empty()) {
                    int frontNode = q.front();      // Get the front node from the queue
                    q.pop();                        // Remove the front node from the queue
                    
                    // Traverse all adjacent nodes of the front node
                    for (auto nbrNode : adj[frontNode]) {
                        // If the neighbor node is not colored
                        if (color[nbrNode] == -1) {
                            color[nbrNode] = (color[frontNode] + 1) % 2;    // Assign an alternate color to the neighbor node (0 or 1)
                            q.push(nbrNode);                                // Push the neighbor node to the queue
                        }
                        // If the neighbor node is colored with the same color as the current node, the graph is not bipartite
                        else {
                            if (color[frontNode] == color[nbrNode])
                                return 0;       // The graph is not bipartite
                        }
                    }
                }
            }
        }
        return 1;   // If no conflicts in coloring are found, the graph is bipartite
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```

## Solution 2

```Cpp
Using DFS Traversal :

class Solution {
public:

    // Helper function to check if a graph is bipartite
    bool checkBipartite(int srcNode, vector<int> adj[], vector<int>& color) {

        // Iterate through all adjacent nodes of srcNode
        for (auto nbrNode : adj[srcNode]) {
            // If the neighbor node is not colored
            if (color[nbrNode] == -1) {
                // Assign the neighbor node the opposite color (0 or 1)
                color[nbrNode] = (color[srcNode] + 1) % 2;
                // Recursively check if the subgraph is bipartite
                if (checkBipartite(nbrNode, adj, color) == 0)
                    return 0;   // If not bipartite, return false
            }
            // If the neighbor node is already colored and has the same color as srcNode
            else {
                if (color[srcNode] == color[nbrNode])
                    return 0; // If not bipartite, return false
            }
        }
        return 1;   // If bipartite, return true
    }

    // Function to check if a graph is bipartite
    bool isBipartite(int V, vector<int> adj[]) {

        vector<int> color(V, -1);   // Vector to store the color of each vertex, initialized to -1
        
        // Iterate through all nodes in the graph -> Handle Disconnected Components Of Graph
        for (int node = 0; node < V; node++) {
            // If the node is not colored
            if (color[node] == -1) {
                color[node] = 0;    // Assign the first color (0) to the node
                // Check if the subgraph is bipartite starting from this node
                if (checkBipartite(node, adj, color) == 0)
                    return 0;   // If not bipartite, return false
            }
        }
        return 1;   // If bipartite, return true
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```