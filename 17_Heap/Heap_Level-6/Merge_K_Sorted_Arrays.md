# Question : [Merge k Sorted Arrays - GFG](https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1)

Given `k` sorted arrays arranged in the form of a matrix of size `k * k`. The task is to merge them into one sorted array. Return the merged sorted array ( as a pointer to the merged sorted arrays in `cpp`, as an ArrayList in `java`, and list in `python`).

### Example 1

```
Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation: Above test case has 3 sorted arrays of size 3, 3, 3 
arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. 
The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
```

### Example 2

```
Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4 
arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6], [7, 8, 9, 9 ]]. 
The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].
```

```
Expected Time Complexity: O(k2*Log(k))
Expected Auxiliary Space: O(k2)
```

### Constraints

- `1 <= k <= 100`

## Solution

```Cpp
class Solution {
public:
    // Function to merge k sorted arrays into a single sorted array
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // A temporary vector to store the initial values and their positions (row, column) in each array
        vector<pair<int, pair<int, int>>> temp;
        
        // Step 1: Push the first element of each sorted array into the temp vector
        for (int i = 0; i < K; i++) {
            // Push a pair: (value, (row index, column index))
            temp.push_back(make_pair(arr[i][0], make_pair(i, 0)));
        }
        
        // Step 2: Create a min-heap (priority queue) to store the smallest elements from each array
        // The priority queue stores pairs of (value, (row, column))
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq(temp.begin(), temp.end());

        // Resultant vector to store the final merged array
        vector<int> ans;

        int row, col;                       // Variables to hold the extracted value indices
        pair<int, pair<int, int>> pair;     // Pair to hold the current minimum value and its indices

        // Step 3: Extract the smallest element from the heap, add it to the result array, and insert the next element from the same row (if exists)
        while (!pq.empty()) {
            pair = pq.top();                // Get the smallest element from the heap
            pq.pop();                       // Remove the smallest element from the heap
            
            // Add the smallest value to the merged array
            ans.push_back(pair.first);
            
            // Get the row and column index of the extracted smallest element
            row = pair.second.first;
            col = pair.second.second;
            
            // Step 4: If the next element in the same row exists, push it into the heap
            // This ensures we always have the next smallest element from the matrix.
            if (col + 1 < K) {
                pq.push(make_pair(arr[row][col + 1], make_pair(row, col + 1)));
            }
        }

        // Return the merged array
        return ans;
    }
};

Time Complexity = O(k2*log(k))
Space Complexity = O(k2)
```