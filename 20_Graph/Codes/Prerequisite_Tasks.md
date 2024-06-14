# Question : [Prerequisite Tasks - GFG](https://www.geeksforgeeks.org/problems/prerequisite-tasks/1)

There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

### Example 1
```plaintext
Input: 
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}
Output:
Yes
Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should 
have finished task 1, and to do task 3 you 
should have finished task 2. So it is possible. 
```

### Example 2
```plaintext
Input:
N = 2, P = 2
prerequisites = {{1,0},{0,1}}
Output:
No
Explanation:
To do task 1 you should have completed
task 0, and to do task 0 you should
have finished task 1. So it is impossible.
```

### Your task
You don’t need to read input or print anything. Your task is to complete the function isPossible() which takes the integer N denoting the number of tasks, P denoting the number of prerequisite pairs and prerequisite as input parameters and returns true if it is possible to finish all tasks otherwise returns false. 

```
Expected Time Complexity: O(N + P)
Expected Auxiliary Space: O(N + P)
```

### Constraints
`1 ≤ N ≤ 10^4`
`1 ≤ P ≤ 10^5`

## Solution

```Cpp
Using BFS Traversal + Topological Sort :

class Solution {
public:

    bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {

        // Initialize adjacency list and in-degree vector
        vector<int> adj[N];
        vector<int> inDegree(N, 0);
        
        // Populate the adjacency list and in-degree vector based on prerequisites
        for (int i = 0; i < P; i++) {
            int u = prerequisites[i].second; // Prerequisite task
            int v = prerequisites[i].first;  // Dependent task
            adj[u].push_back(v);             // Add edge from prerequisite to dependent task (add edge u -> v)
            inDegree[v]++;                   // Increment in-degree of the dependent task (task v)
        }
        
        // Initialize a queue to process tasks with no prerequisites
        queue<int> q;
        for (int task = 0; task < N; task++) {
            if (inDegree[task] == 0) {      // If a task has no prerequisites
                q.push(task);               // Add it to the queue
            }
        }
        
        int count = 0; // Counter for the number of tasks processed
        
        // Process the tasks in topological order
        while (!q.empty()) {
            int frontNode = q.front();  // Get the task from the front of the queue
            q.pop();                    // Remove the task from the queue
            count++;                    // Increment the processed task count
            
            // Process all the dependent tasks
            for (auto nbrNode : adj[frontNode]) {
                inDegree[nbrNode]--;                // Decrement the in-degree of the dependent task
                if (inDegree[nbrNode] == 0) {       // If the dependent task has no more prerequisites
                    q.push(nbrNode);                // Add it to the queue
                }
            }
        }
        
        // If all tasks have been processed, return true. Otherwise, return false.
        return count == N;
    }
};

Time Complexity = O(N + P)
Space Complexity = O(N + P)
```