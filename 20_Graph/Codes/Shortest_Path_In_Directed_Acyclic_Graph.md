# Question : [Shortest Path In Directed Acyclic Graph - GFG](https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/0)

Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the **shortest** path from **src(0)** vertex to all the vertices and if it is impossible to reach any vertex, then return **-1** for that vertex.

### Example 1
```
Input:
N = 4, M = 2
edge = [[0,1,2],[0,2,1]]
Output:
0 2 1 -1
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->2 with edge weight 1.
There is no way we can reach 3, so it's -1 for 3.
```

### Example 2
```
Input:
N = 6, M = 7
edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
Output:
0 2 3 6 1 5
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
Shortest path from 0 to 4 is 0->4 with edge weight 1.
Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
```

### Your task
You don't need to print or input anything. Complete the function **shortest path()** which takes an integer N as number of vertices, an integer M as number of edges and a 2D Integer array(or vector) edges as the input parameters and returns an **integer array(or vector),** denoting the list of distance from src to all nodes.

```
Expected Time Complexity : O(N + M), where N is the number of nodes and M is the edges
Expected Space Complexity : O(N)
```

### Constraints
`1<=n,m<=100`
`1 <= M <= min((N*(N-1))/2,4000)`
`0 <= edgei,0,edgei,1 < n`
`0 <= edgei,2 <=10^5`

## Solution

```Cpp
Using DFS Traversal + Topological Sort :

class Solution {
public:

    // Function to perform DFS traversal and push nodes to stack in topological order
    void dfsTraversal(int srcNode, vector<pair<int,int>> adj[], stack<int>& s, vector<bool>& visited) {
        visited[srcNode] = true;                            // Mark the current node as visited
        for(auto nbrPair : adj[srcNode]) {                  // Traverse all the adjacent nodes
            int nbrNode = nbrPair.first;                    // Get the neighboring node
            if(!visited[nbrNode])                           // If the neighbor hasn't been visited
                dfsTraversal(nbrNode, adj, s, visited);     // Recursively perform DFS on the neighbor
        }
        s.push(srcNode); // Push the current node to the stack after all its neighbors are processed
    }

    // Function to find the shortest path in a Directed Acyclic Graph (DAG)
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // Create an adjacency list to represent the weighted graph
        vector<pair<int,int>> adj[N];
        for(int i = 0; i < M; i++) {
            int u = edges[i][0];                    // Start vertex of the edge
            int v = edges[i][1];                    // End vertex of the edge
            int weight = edges[i][2];               // Weight of the edge
            adj[u].push_back({v, weight});          // Add the edge to the adjacency list
        }

        // Stack to store the topological order of nodes
        stack<int> s;
        // Vector to keep track of visited nodes
        vector<bool> visited(N, false);

        // Perform DFS from the first node (assuming the graph is connected)
        dfsTraversal(0, adj, s, visited);

        // Initialize distance vector with infinity (INT_MAX)
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;                    // Distance to the source node is 0

        // Process nodes in topological order
        while(!s.empty()) {
            int topNode = s.top();      // Get the top node from the stack
            s.pop();                    // Pop the top node from the stack

            // Update distances for all the neighbors of the current node
            if(dist[topNode] != INT_MAX) {
                for(auto nbrPair : adj[topNode]) {
                    int nbrNode = nbrPair.first;        // Neighboring node
                    int weight = nbrPair.second;        // Weight of the edge to the neighbor
                    // Update the distance if a shorter path is found
                    if(dist[topNode] + weight < dist[nbrNode]) {
                        dist[nbrNode] = dist[topNode] + weight;
                    }
                }
            }
        }

        // Replace distances of unreachable nodes with -1
        for(int i = 0; i < N; i++) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        // Return the distance vector containing shortest path distances from the source node
        return dist;
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V + E)
```