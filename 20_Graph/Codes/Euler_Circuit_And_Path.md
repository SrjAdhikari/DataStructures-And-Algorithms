# Question : [Euler Circuit And Path - GFG](https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1?page=3&difficulty[]=1&category[]=Graph&sortBy=submissions)

**_An Eulerian Path_** is a path in graph that visits every edge exactly once. **_An Eulerian Circuit_** is **_an Eulerian Path_** which starts and ends on the same vertex. Given an **_undirected graph_** with **_V_** nodes, and **_E_** edges, with adjacency list **_adj_**, return 2 if the graph contains an **_eulerian circuit_**, else if the graph contains an **_eulerian path_**, return 1, otherwise, return 0.

### Example 1

```
Input:
```

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700537/Web/Other/c191d733-5295-4e4a-81b7-7a1de77ec269_1685086734.png)

```
Output: 2
Explanation:
Following is an eulerian circuit in the mentioned graph
1 -> 2 -> 0 -> 1
```

### Example 2

```
Input:
```

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700537/Web/Other/c5419f69-5051-4865-aabe-4898ff1c92f3_1685086735.png)

```
Output: 1
Explanation:
Following is an eulerian path in the mentioned graph
1 -> 0 -> 2
```

### Your task

You don't need to read or print anything. Your task is to complete the function **_isEulerCircuilt()_** which takes number of vertices in the graph denoted as **_V_** and an adjacency list of graph denoted as **_adj_** and returns 2 if the graph contains an **_eulerian circuit_**, else if the graph contains an **_eulerian path_**, it returns 1, otherwise, it will return 0.

```plaintext
Expected Time Complexity : O(V + E) where E is the number of edges in graph.
Expected Auxiliary Space : O(V)
```

### Constraints

`1 ≤ V, E ≤ 10^4` <br>
` ≤ adj[i][j] ≤ V-1`

## Solution

```Cpp
Using DFS Traversal :

class Solution {
public:

    // Depth First Search (DFS) function to explore the graph
    // node: current node being visited
    // adj: adjacency list representation of the graph
    // visited: vector to track visited nodes

    void DFS(int node, vector<int> adj[], vector<bool>& visited) {
        // Mark the current node as visited
        visited[node] = 1;

        // Traverse all adjacent nodes (neighbors) of the current node
        for (auto nbrNode : adj[node]) {
            // If the neighbor node has not been visited, recursively visit it (perform DFS on it)
            if (!visited[nbrNode])
                DFS(nbrNode, adj, visited);
        }
    }

    // Function to determine if the graph has an Eulerian Circuit or Path
    // V: number of vertices in the graph
    // adj: adjacency list representation of the graph

    int isEulerCircuit(int V, vector<int> adj[]) {

        // Conditions for Eulerian Circuit:
        // 1. All vertices must have even degree.
        // 2. All non-zero degree vertices must be connected.
        // 3. If Eulerian Circuit is present, return 2.

        // Conditions for Eulerian Path:
        // 1. Exactly zero or two vertices can have odd degree, and the rest must have even degree.
        // 2. All non-zero degree vertices must be connected.
        // 3. If Eulerian Path is present, return 1.

        // Calculate the degree of each vertex
        vector<int> degree(V, 0);
        int oddDegree = 0;              // Store the count of vertices with odd degree

        for (int i = 0; i < V; i++) {
            degree[i] = adj[i].size();  // Degree is the number of edges connected to the vertex
            if (degree[i] & 1)          // Check if the degree is odd
                oddDegree++;
        }

        // If the number of vertices with odd degree is not 2 or 0, it's neither an Eulerian Path nor Circuit
        if (oddDegree != 2 && oddDegree != 0)
            return 0;

        // Vector to keep track of visited vertices
        vector<bool> visited(V, 0);

        // Find a vertex with non-zero degree to start DFS
        // Perform DFS from the first node with a non-zero degree to check connectivity
        for (int i = 0; i < V; i++) {
            if (degree[i] != 0) {
                DFS(i, adj, visited);   // Perform DFS from this vertex
                break;                  // Exit the loop after finding the first non-zero degree vertex
            }
        }

        // Check if all non-zero degree vertices are visited
        for (int i = 0; i < V; i++) {
            if (degree[i] != 0 && !visited[i])
                return 0;               // If any non-zero degree vertex is not visited, return 0
        }

        // If all vertices have even degree, it's an Eulerian Circuit
        if (oddDegree == 0)
            return 2;
        else
            return 1;   // If exactly two vertices have odd degree, it's an Eulerian Path
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```
