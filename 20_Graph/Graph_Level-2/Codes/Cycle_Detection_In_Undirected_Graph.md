# Question : [Detect Cycle In An Undirected Graph - GFG](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)

Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

### Example 1

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700219/Web/Other/891791f9-1abb-45b1-80f2-7af46d73dcd2_1685086491.png)

```plaintext
Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1

Explanation: 
1->2->3->4->1 is a cycle.
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700219/Web/Other/d8cbd97e-406e-4f50-a38c-6a58747df876_1685086491.png)

```plaintext
Input: 
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0

Explanation: 
No cycle in the graph.
```

### Your task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

**NOTE**: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

```plaintext
Expected Time Complexity : O(V + E)
Expected Auxiliary Space : O(V)
```

### Constraints
`1 ≤ V, E ≤ 10^5`

## Solution 1

```Cpp
Using DFS Traversal :

class Solution {
public:

    // Helper function to detect a cycle in the graph using DFS
    bool cycleDetect(int srcNode, int parent, vector<int> adj[], vector<bool>& visited) {

        visited[srcNode] = 1; // Mark the source node as visited
        
        // Iterate through all the adjacent nodes of the source node
        for(auto nbrNode : adj[srcNode]) {
            if(parent == nbrNode)
                continue;       // Skip the parent node to avoid false cycle detection
            
            if(visited[nbrNode])
                return 1;       // If the neighbor node is already visited, a cycle is detected
                
            // Recursively call cycleDetect for the neighbor node
            if(cycleDetect(nbrNode, srcNode, adj, visited))
                return 1;       // If a cycle is detected in the recursive call, return true
        }
        return 0;               // No cycle detected
    }

    // Function to check if there is a cycle in the graph
    bool isCycle(int V, vector<int> adj[]) {

        vector<bool> visited(V, 0);     // Create a visited array to keep track of visited nodes
        int parent = -1;                // Initialize the parent node as -1 (no parent)
        
        // Iterate through all the nodes in the graph
        for(int node = 0; node < V; node++) {

            // If the node is not visited and a cycle is detected from that node
            if(!visited[node] && cycleDetect(node, parent, adj, visited)) {
                return 1;               // Return true if a cycle is detected
            }
        }
        return 0;                       // Return false if no cycle is detected
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```

## Solution 2

```Cpp
Using BFS Traversal :

class Solution {
public:

    
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```