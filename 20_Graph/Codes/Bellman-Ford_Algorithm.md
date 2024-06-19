# Question : [Distance From The Source (Bellman-Ford Algorithm) - GFG](https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1)

Given a weighted and directed graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S. If a vertices can't be reach from the S then mark the distance as 10^8. Note: If the Graph contains a negative cycle then return an array consisting of only -1.

### Example 1
![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/706218/Web/Other/c8d8b64c-f87e-4b44-ad81-5069e9698985_1685087173.png)
```
Input :
E = [[0,1,9]]
S = 0
Output :
0 9
Explanation :
Shortest distance of all nodes from
source is printed.
```

### Example 2
![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/706218/Web/Other/46db67e8-b4da-46d6-a9ab-604249bea60a_1685087173.png)
```
Input :
E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]
S = 2
Output :
1 6 0
Explanation :
For nodes 2 to 0, we can follow the path-
2-0. This has a distance of 1.
For nodes 2 to 1, we cam follow the path-
2-0-1, which has a distance of 1+5 = 6,
```

### Your task
You don't need to read input or print anything. Your task is to complete the function ***bellman_ford( )*** which takes a number of vertices ***V*** and an ***E***-sized list of lists of three integers where the three integers are ***u,v,*** and ***w;*** denoting there's an edge from ***u to v***, which has a weight of ***w*** and source node ***S*** as input parameters and returns a list of integers where the ith integer denotes the distance of an ith node from the source node.

If some node isn't possible to visit, then its distance should be 100000000(1e8). Also, If the Graph contains a negative cycle then return an array consisting of a single -1.

```
Expected Time Complexity : O(V*E).
Expected Auxiliary Space : O(V).
```

### Constraints
`1 ≤ V ≤ 500`
`1 ≤ E ≤ V*(V-1)`
`-1000 ≤ adj[i][j] ≤ 1000`
`0 ≤ S < V`

## Solution

```Cpp
class Solution {
public:

    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {

        // Initialize the distance vector with a large value (1e8)
        vector<int> distance(V, 1e8);   // 1e8 = 10^8, representing infinity
        distance[S] = 0;                // Distance to the source vertex is 0

        // Relax edges up to V-1 times
        for(int i = 0; i < V; i++) {

            bool flag = false;          // Flag to check if any distance was updated

            // Iterate through all edges
            for(auto& edge : edges) {
                int u = edge[0];            // Start vertex of the edge
                int v = edge[1];            // End vertex of the edge
                int weight = edge[2];       // Weight of the edge

                // If the distance to u is not infinity and distance to v can be minimized
                if(distance[u] != 1e8 && distance[u] + weight < distance[v]) {
                    flag = true;                            // Set flag to true as we have updated a distance
                    distance[v] = distance[u] + weight;     // Update distance to v
                }
            }

            // If no distance was updated in this iteration, break the loop
            if(flag == false)
                return distance;            // Return the distance array as it won't change further
        }

        // Check for negative weight cycles -> One more time relaxation
        for(int i = 0; i < V; i++) {
            for(auto& edge : edges) {
                int u = edge[0];            // Start vertex of the edge
                int v = edge[1];            // End vertex of the edge
                int weight = edge[2];       // Weight of the edge

                // If a shorter path is found, it indicates a negative weight cycle
                if(distance[u] != 1e8 && distance[u] + weight < distance[v]) {
                    vector<int> ans;            // Vector to store the result
                    ans.push_back(-1);          // Push -1 indicating negative weight cycle
                    return ans;                 // Return the result
                }
            }
        }

        return distance;                        // Return the final distance array
    }
};

Time Complexity = O(V * E)
Space Complexity = O(E)
```