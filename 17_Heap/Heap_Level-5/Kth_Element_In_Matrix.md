# Question : [Kth element in Matrix - GFG](https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1)

Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

### Example 1

```
Input:
N = 4
mat[][] =     { {16, 28, 60, 64},
                {22, 41, 63, 91},
                {27, 50, 87, 93},
                {36, 78, 87, 94 } }
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
```

### Example 2

```
Input:
N = 4
mat[][] =     { {10, 20, 30, 40}
                {15, 25, 35, 45}
                {24, 29, 37, 48}
                {32, 33, 39, 50} }
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.
```

### Your Task
You don't need to read input or print anything. Complete the function `kthsmallest()` which takes the mat, N and K as input parameters and returns the kth smallest element in the matrix.

```
Expected Time Complexity: O(K*Log(N))
Expected Auxiliary Space: O(N)
```

### Constraints

- `1 <= N <= 50`
- `1 <= mat[][] <= 10000`
- `1 <= K <= N*N`

## Solution

```Cpp
class Solution {
public:
    // Function to find the k-th smallest element in a sorted matrix
    int kthSmallest(int mat[MAX][MAX], int n, int k) {
        // Vector to store the elements along with their row and column indices
        vector<pair<int, pair<int, int>>> temp;

        // Step 1: Initialize the priority queue with the first element of each row
        for(int i = 0; i < n; i++) {
            // Push (value, (row, column))
            temp.push_back(make_pair(mat[i][0], make_pair(i, 0)));
        }
        
        // Step 2: Create priority queue (min-heap) to store the matrix elements. We use a min-heap so that
        // the smallest element is always at the top. 
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq(temp.begin(), temp.end());
        
        int value, row, col;                // Variables to hold the extracted value and its indices
        pair<int, pair<int, int>> pair;     // Pair to hold the current minimum value and its indices
        
        // Step 3: Iterate 'k' times to find the kth smallest element.
        while(k--) {
            pair = pq.top();    // Get the smallest element from the heap
            pq.pop();           // Remove the smallest element from the heap
            
            // Store the value, row, and column of the smallest element.
            value = pair.first;
            row = pair.second.first;
            col = pair.second.second;
            
            // If there is a next element in the same row, push it into the heap.
            // This ensures we always have the next smallest element from the matrix.
            if(col + 1 < n){
                pq.push(make_pair(mat[row][col+1], make_pair(row, col+1)));
            }
        }
        
        // After 'k' iterations, the value will hold the kth smallest element.
        return value;
    }
};

Time Complexity = O(KlogN)
Space Complexity = O(N)
```