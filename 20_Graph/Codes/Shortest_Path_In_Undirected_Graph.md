# Question : [Shortest Path In Undirected Graph - GFG](https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1)

You are given an **Undirected Graph** having **unit weight** of the edges, find the shortest path from **src** to all the vertex and if it is **unreachable** to reach any vertex, then return **-1** for that vertex.

### Example 1
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/711976/Web/Other/blobid1_1712813311.png)
```
Input:
n = 9, m= 10
edges=[[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4
```

### Example 2
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/711976/Web/Other/blobid3_1712814761.png)
```
Input:
n = 4, m= 4
edges=[[0,0],[1,1],[1,3],[3,0]] 
src=3
Output:
1 1 -1 0
```

### Your task
You don't need to print or input anything. Complete the function **shortest path()** which takes a 2d vector or array of **edges** representing the edges of an undirected graph with unit weight, an integer n as the number of nodes, an integer **m** as a number of edges and an integer **src** as the input parameters and returns an integer array or vector, denoting **the vector of distance from src to all nodes.**

```
Expected Time Complexity : O(N + E), where N is the number of nodes and E is the edges
Expected Space Complexity : O(N)
```

### Constraints
`1<=n,m<=10000`
`0<=edges[i][j]<=n-1`

## Solution

```Cpp
Using BFS Traversal :

class Solution {
public:

    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        // Create an adjacency list to represent the graph
        vector<int> adj[N];

        // Iterate over all edges to populate the adjacency list
        for(int i = 0; i < M; i++) {
            int u = edges[i][0];    // Start vertex of the edge
            int v = edges[i][1];    // End vertex of the edge
            adj[u].push_back(v);    // Add v to the list of adjacent vertices of u
            adj[v].push_back(u);    // Since the graph is undirected, add u to the list of adjacent vertices of v
        }

        // Initialize the distance vector with -1, indicating that initially, all nodes are unreachable
        vector<int> dist(N, -1);
        
        // Initialize the visited vector to keep track of visited nodes
        vector<bool> visited(N, false);
        
        // Create a queue for BFS (Breadth-First Search)
        queue<int> q;
        
        // Start BFS from the source node
        q.push(src);                // Enqueue the source node
        dist[src] = 0;              // Distance to the source node is 0
        visited[src] = true;        // Mark the source node as visited

        // Perform BFS
        while(!q.empty()) {
            int frontNode = q.front();      // Get the front node from the queue
            q.pop();                        // Dequeue the front node

            // Iterate over all the neighbors of the current node
            for(auto nbrNode : adj[frontNode]) {
                if(visited[nbrNode])        // If the neighbor has already been visited, skip it
                    continue;
                else {
                    // If the neighbor hasn't been visited:
                    visited[nbrNode] = true;                    // Mark it as visited
                    q.push(nbrNode);                            // Enqueue the neighbor
                    dist[nbrNode] = dist[frontNode] + 1;        // Update the distance to this neighbor
                }
            }
        }

        // Return the distance vector containing shortest paths from the source to all nodes
        return dist;
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V + E)
```