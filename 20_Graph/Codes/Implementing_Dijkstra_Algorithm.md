# Question : [Implementing Dijkstra Algorithm - GFG](https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1)

Given a weighted, undirected and connected graph of ***V*** vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the ***first*** integer of each list ***j*** denotes there is ***edge*** between i and j , second integers corresponds to the ***weight*** of that  edge . You are given the source vertex ***Src*** and You to Find the shortest distance of all the vertex's from the source vertex ***Src***. You have to return a list of integers denoting shortest distance between ***each node*** and Source vertex ***Src***.

***Note :*** The Graph doesn't contain any negative weight cycle.

### Example 1

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700334/Web/Other/6a77963c-f9a6-4cf4-953c-19a2759a52a3_1685086564.png)

```plaintext
Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
Explanation:
The source vertex is 0. Hence, the shortest 
distance of node 0 is 0 and the shortest 
distance from node 1 is 9.
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700334/Web/Other/8c9ee3a2-a7d3-4028-ae22-a22ddb6ab7a3_1685086565.png)

```plaintext
Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .
```

### Your task :
You don't need to read input or print anything. Your task is to complete the function ***dijkstra()***  which takes the number of vertices V and an adjacency list adj as input parameters and Source vertex Src returns a list of integers, where ith integer denotes the shortest distance of the ith node from the Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and the second integer w denotes that the weight between edge i and j is w.

```plaintext
Expected Time Complexity : O(V^2)
Expected Auxiliary Space : O(V^2)
```

### Constraints
`1 ≤ V ≤ 1000`
`1 ≤ adj.size() ≤ [ (V*(V - 1)) / 2 ]`
`0 ≤ Src < V`

## Solution 1

```Cpp
class Solution {
public:

    vector<int> dijkstra(int V, vector<vector<int>> adj[], int src) {

        // Initialize a visited vector to keep track of visited nodes
        vector<bool> visited(V, false);

        // Initialize a distance vector to store the shortest distance from the source to each node
        vector<int> dist(V, INT_MAX);

        // Distance to the source node is 0
        dist[src] = 0;

        // Number of vertices in the graph
        int count = V;

        // Loop to find the shortest path for all nodes
        while (count--) {
            int node = -1;              // Initialize the current node to an invalid value
            int value = INT_MAX;        // Initialize the smallest distance to infinity

            // Find the unvisited node with the smallest distance
            for (int i = 0; i < V; i++) {
                if (!visited[i] && dist[i] < value) {
                    node = i;           // Update the current node
                    value = dist[i];    // Update the smallest distance
                }
            }

            // Mark the selected node as visited
            visited[node] = true;

            // Iterate through all neighbors of the selected node
            for (auto nbr : adj[node]) {
                int nbrNode = nbr[0];   // Neighbor node
                int weight = nbr[1];    // Weight of the edge to the neighbor node

                // If the neighbor node is not visited and a shorter path is found
                if (!visited[nbrNode] && dist[node] + weight < dist[nbrNode]) {
                    dist[nbrNode] = dist[node] + weight;    // Update the distance to the neighbor node
                }
            }
        }

        // Return the distance vector containing the shortest paths from the source to all nodes
        return dist;
    }
};

Time Complexity = O(V^2)
Space Complexity = O(V)
```

## Solution 2

```Cpp
Optimise Approach (using Min Heap) :

class Solution {
public:

    vector<int> dijkstra(int V, vector<vector<int>> adj[], int src) {

        // Initialize a visited vector to keep track of visited nodes
        vector<bool> visited(V, false);

        // Initialize a distance vector to store the shortest distance from the source to each node
        vector<int> dist(V, INT_MAX);

        // Distance to the source node is 0
        dist[src] = 0;

        // Priority queue to select the node with the smallest distance
        // The priority queue stores pairs of (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        // Main loop to process all nodes in the priority queue
        while (!pq.empty()) {
            int node = pq.top().second;     // Get the node with the smallest distance
            int weight = pq.top().first;    // Get the distance of this node from the source
            pq.pop();                       // Remove the node from the queue

            // If the node has already been visited, skip it
            if (visited[node])
                continue;

            // Mark the current node as visited
            visited[node] = true;

            // Iterate through all neighbors of the current node
            for (auto nbr : adj[node]) {
                int nbrNode = nbr[0];       // Neighbor node
                int edgeWeight = nbr[1];    // Weight of the edge to the neighbor node

                // If the neighbor node is not visited and a shorter path is found
                if (!visited[nbrNode] && dist[node] + edgeWeight < dist[nbrNode]) {
                    dist[nbrNode] = dist[node] + edgeWeight;    // Update the distance to the neighbor node
                    pq.push({dist[nbrNode], nbrNode});          // Push the updated distance and node to the priority queue
                }
            }
        }

        // Return the distance vector containing the shortest paths from the source to all nodes
        return dist;
    }
};

Time Complexity = O(ElogV)
Space Complexity = O(V + E)
```