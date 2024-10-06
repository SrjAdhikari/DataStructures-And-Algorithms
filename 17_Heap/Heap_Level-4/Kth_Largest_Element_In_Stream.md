# Question : [Kth largest element in a stream - GFG](https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1)

Given an input stream `arr[]` of `n` integers. Find the `Kth` largest element (not `Kth` largest unique element) after insertion of each element in the stream and if the `Kth` largest element doesn't exist, the answer will be -1 for that insertion.  return a list of size n after all insertions.

### Example 1

```
Input:
k = 4, n = 6
arr[] = {1, 2, 3, 4, 5, 6}
Output:
-1 -1 -1 1 2 3
Explanation:
k = 4
For 1, the 4th largest element doesn't
exist so answer will be -1.
For 2, the 4th largest element doesn't
exist so answer will be -1.
For 3, the 4th largest element doesn't
exist so answer will be -1.
For 4, the 4th largest element is 1.
For 5, the 4th largest element is 2.
for 6, the 4th largest element is 3.
```

### Example 2

```
Input:
k = 1, n = 2
arr[] = {3, 4}
Output:
3 4 
Explanation: 
For the 1st and 2nd element the 1st largest 
element is itself.
```

### Your Task
You don't need to read input or print anything. Your task is to complete the function `kthLargest()` which takes 2 Integers k, and n and also an array arr[] of size n as input. After the insertion of each element find `Kth` largest element in the stream and if the `Kth` element doesn't exist, the answer will be -1 for that insertion.  return a list of size n after all insertions.

```
Expected Time Complexity: O(nlogk)
Expected Auxiliary Space: O(n)
```

### Constraints

- `1 ≤ k ≤ n ≤ 10^5`
- `1 ≤ arr[i] ≤ 10^5`

## Solution

```Cpp
class Solution {
public:
    // Function to return a vector of k-th largest elements in a streaming manner.
    vector<int> kthLargest(int k, int arr[], int n) {
        // Min-heap (priority queue) to store the k largest elements encountered so far.
        priority_queue<int, vector<int>, greater<int>> pq;

        // Vector to store the result, where each index will store the k-th largest element at that step.
        vector<int> ans;
        
        // Traverse the array, processing the first 'k' elements first.
        for (int i = 0; i < k; i++) {
            // Add the current element into the min-heap.
            pq.push(arr[i]);
            
            // If the heap has less than 'k' elements, we can't find the k-th largest element yet.
            if (pq.size() != k)
                ans.push_back(-1);          // Push -1 since there aren't enough elements yet.
            else 
                ans.push_back(pq.top());    // When heap has 'k' elements, the top is the k-th largest.
        }
        
        // Now process the remaining elements from arr[k] to arr[n-1].
        for (int i = k; i < n; i++) {
            // If the current element is larger than the smallest element in the heap (i.e., pq.top()),
            // replace the smallest element with the current element.
            if (arr[i] > pq.top()) {
                pq.pop();          // Remove the smallest element.
                pq.push(arr[i]);   // Insert the new larger element.
            }

            // At each step, the top of the heap will always represent the k-th largest element.
            ans.push_back(pq.top());
        }

        // Return the result vector containing the k-th largest element for each step.
        return ans;
    }
};

Time Complexity = O(Nlog(k))
Space Complexity = O(N)
```