# Question : [Kth Smallest Element In Array - GFG](https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1)

Given an array `arr[]` and an integer `k` where k is smaller than the size of the array, the task is to find the `kth smallest` element in the given array.

**Follow up**: Don't solve it using the inbuilt sort function.

### Example 1

```
Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output:  7
Explanation: 3rd smallest element in the given array is 7.
```

### Example 2

```
Input: arr[] = [2, 3, 1, 20, 15], k = 4 
Output: 15
Explanation: 4th smallest element in the given array is 15.
```

```
Expected Time Complexity: O(n+(max_element) )
Expected Auxiliary Space: O(max_element)
```

### Constraints

- `1 <= arr.size <= 10^6`
- `1<= arr[i] <= 10^6`
- `1 <= k <= n`

## Solution

```Cpp
class Solution {
public:
    // Function to find the kth smallest element in the given array 'arr'.
    int kthSmallest(vector<int> &arr, int k) {
        // Create a max-heap (priority queue) to keep track of the k smallest elements.
        priority_queue<int> pq;
        
        // Get the size of the array.
        int size = arr.size();
        
        // Push the first 'k' elements into the max-heap.
        // The heap will hold at most 'k' elements and the largest among them will be at the top.
        for(int i = 0; i < k; i++) {
            pq.push(arr[i]); 
        }
        
        // Traverse through the rest of the array starting from the k-th element.
        for(int i = k; i <= size - 1; i++) {
            // If the current element is smaller than the largest element in the heap (pq.top()).
            // replace the largest element with the current element.
            if(arr[i] < pq.top()) {
                pq.pop();           // Remove the largest element from the heap.
                pq.push(arr[i]);    // Insert the smaller element.
            }
        }
        
        // After processing all elements, the top of the heap will be the kth smallest element.
        return pq.top();
    }
};

Time Complexity = O(Nlog(k))
Space Complexity = O(k)
```