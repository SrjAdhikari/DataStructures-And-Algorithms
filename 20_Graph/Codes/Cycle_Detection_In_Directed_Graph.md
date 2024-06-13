# Question : [Detect Cycle In A Directed Graph - GFG](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

### Example 1

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700218/Web/Other/9a013355-2510-4ab0-b554-1a2b9f6cb44f_1685086462.png)

```plaintext
Output: 1
Explanation: 3 -> 3 is a cycle
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700218/Web/Other/b1096e14-7c18-47d8-a4e9-8dd42b2e466f_1685086462.png)

```plaintext
Output: 0
Explanation: no cycle in the graph
```

### Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list adj as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
In the adjacency list adj, element adj[i][j] represents an edge from i to j.

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

    // Helper function to detect a cycle in a directed graph using DFS
    bool detectCycle(int srcNode, vector<int> adj[], vector<bool>& pathTrack, vector<bool>& visited) {
        visited[srcNode] = 1;       // Mark the current node as visited
        pathTrack[srcNode] = 1;     // Mark the current node as part of the current path
        
        // Traverse all the adjacent nodes of the current node
        for (auto nbrNode : adj[srcNode]) {
            // If the neighbor node is part of the current path and already visited, a cycle is detected
            if (pathTrack[nbrNode] && visited[nbrNode])
                return 1;
            
            // If the neighbor node is not visited, recursively call detectCycle
            if (!visited[nbrNode] && detectCycle(nbrNode, adj, pathTrack, visited))
                return 1;
        }
        
        pathTrack[srcNode] = 0;     // Remove the current node from the current path
        
        return 0;                   // No cycle detected
    }

    // Function to detect a cycle in a directed graph
    bool isCyclic(int V, vector<int> adj[]) {

        vector<bool> pathTrack(V, 0);       // Vector to track the nodes in the current path
        vector<bool> visited(V, 0);         // Vector to track the visited nodes
        
        // Iterate through all the nodes in the graph -> Handle Disconnected Components Of Graph
        for (int node = 0; node < V; node++) {
            // If the node is not visited and a cycle is detected from that node, return true
            if (!visited[node] && detectCycle(node, adj, pathTrack, visited))
                return 1;
        }
        return 0;                           // Return false if no cycle is detected
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

    // Function to detect a cycle in a directed graph using Kahn's algorithm (BFS)
    bool isCyclic(int V, vector<int> adj[]) {

        vector<int> inDegree(V, 0);     // Vector to store the in-degree of each vertex
        queue<int> q;                   // Queue to manage vertices with in-degree 0
        vector<int> ans;                // Vector to store the topological order of vertices
        
        // Calculate the in-degree of each vertex
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                inDegree[adj[i][j]]++;  // Increment the in-degree of the adjacent vertices
            }
        }
        
        // Add all vertices with in-degree 0 to the queue
        for (int node = 0; node < V; node++) {
            if (inDegree[node] == 0)
                q.push(node);
        }
        
        // Process the vertices in the queue
        while (!q.empty()) {
            int frontNode = q.front();      // Get the front node from the queue
            q.pop();                        // Remove the front node from the queue
            ans.push_back(frontNode);       // Add the front node to the topological order
            
            // Decrease the in-degree of adjacent vertices
            for (auto nbrNode : adj[frontNode]) {
                inDegree[nbrNode]--;        // Decrease the in-degree of the neighbor node
                if (inDegree[nbrNode] == 0)
                    q.push(nbrNode);        // If in-degree becomes 0, add the node to the queue
            }
        }
        
        // If the size of ans is not equal to V, a cycle exists
        return ans.size() != V;
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```