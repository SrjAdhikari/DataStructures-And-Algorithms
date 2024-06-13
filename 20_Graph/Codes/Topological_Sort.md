# Question : [Topological Sort - GFG](https://www.geeksforgeeks.org/problems/topological-sort/1)

Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.

**In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.**

### Example 1

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700255/Web/Other/24aa5d54-bc1f-489c-bd2d-ad02ddccdf31_1684492511.png)

```plaintext
Output :
1

Explanation :
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700255/Web/Other/c35bb1d1-130c-49aa-a17e-118181d7bdcd_1684492512.png)

```plaintext
Output :
1

Explanation :
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.
```

### Your task:
You don't need to read input or print anything. Your task is to complete the function **topoSort()**  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

```plaintext
Expected Time Complexity : O(V + E)
Expected Auxiliary Space : O(V)
```

### Constraints
`2 ≤ V ≤ 10^4`

`1 ≤ E ≤ (N*(N-1))/2`

## Solution 1

```Cpp
Using DFS Traversal :

class Solution {
public:

    // Helper function to perform DFS and push nodes to stack in topological order
    void topoSortDFS(int srcNode, vector<int> adj[], vector<bool>& visited, stack<int>& s) {

        visited[srcNode] = 1; // Mark the current node as visited
        
        // Traverse all the adjacent nodes of the current node
        for (auto nbrNode : adj[srcNode]) {
            if (!visited[nbrNode])
                topoSortDFS(nbrNode, adj, visited, s);      // Recursively call DFS for the neighbor node
        }
        s.push(srcNode);        // Push the current node onto the stack after visiting all its neighbors
    }

    // Function to return a list containing vertices in Topological order
    vector<int> topoSort(int V, vector<int> adj[]) {

        vector<bool> visited(V, 0);         // Create a visited array to keep track of visited nodes
        stack<int> s;                       // Stack to store the topological order of nodes
        
        // Perform DFS for each node to find the topological order
        for (int node = 0; node < V; node++) {
            if (!visited[node])
                topoSortDFS(node, adj, visited, s);
        }
        
        vector<int> ans;        // Vector to store the topological order
        
        // Pop elements from the stack to get the topological order
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;         // Return the topological order
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```

## Solution 2

```Cpp
Using BFS Traversal -> Kahn's Algorithm : 

class Solution {
public:

    // Function to return a list containing vertices in Topological order using Kahn's algorithm (BFS)
    vector<int> topoSort(int V, vector<int> adj[]) {

        vector<int> ans;                    // Vector to store the topological order
        vector<int> inDegree(V, 0);         // Vector to store the in-degree of each vertex
        queue<int> q;                       // Queue to manage the vertices with in-degree 0
        
        // Calculate the in-degree of each vertex
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                inDegree[adj[i][j]]++;      // Increment the in-degree of adjacent vertices
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
        
        return ans;                         // Return the topological order
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```