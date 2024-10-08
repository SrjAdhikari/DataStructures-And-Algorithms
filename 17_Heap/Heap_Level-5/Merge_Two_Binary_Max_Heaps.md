# Question : [Merge two binary Max heaps - GFG](https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1)

Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

### Example

```
Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
Explanation :
```
![](https://media.geeksforgeeks.org/wp-content/uploads/Merge_max_heap_1.jpg)
![](https://media.geeksforgeeks.org/wp-content/uploads/Merge_max_heap_2.jpg)
![](https://media.geeksforgeeks.org/wp-content/uploads/Merge_max_heap_3.jpg)


### Your Task
You don't need to read input or print anything. Your task is to complete the function `mergeHeaps()` which takes the array `a[]`, `b[]`, its size `n` and `m`, as inputs and return the merged max heap. Since there can be multiple solutions, therefore, to check for the correctness of your solution, your answer will be checked by the driver code and will return `1` if it is correct, else it returns `0`.

```
Expected Time Complexity: O(n.Logn)
Expected Auxiliary Space: O(n + m)
```

### Constraints

- `1 <= n, m <= 10^5`
- `1 <= a[i], b[i] <= 2*10^5`

## Solution

```Cpp
class Solution {
public:
    // Function to maintain the max-heap property
    void heapify(vector<int>& ans, int index, int size) {
        int largest = index;          // Assume the current node is the largest.
        int left = 2 * index + 1;     // Left child index.
        int right = 2 * index + 2;    // Right child index.

        // Check if the left child exists and is larger than the current node.
        if(left < size && ans[left] > ans[largest])
            // Update largest to be the left child.
            largest = left;

        // Check if the right child exists and is larger than the largest node so far.
        if(right < size && ans[right] > ans[largest])
            largest = right;

        // If the largest is not the current node, swap with the largest child & continue heapifying.
        if(largest != index) {
            swap(ans[largest], ans[index]);

            // Move to the largest child and repeat the process.
            index = largest;

            // Recursively heapify the affected sub-tree.
            heapify(ans, index, size);
        }
    }

    // Function to merge two heaps and return a single valid max-heap
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // Create a new vector to store the merged heaps
        vector<int> ans;
        
        // Copy all elements from the first heap 'a' to the new heap 'ans'
        for (int i = 0; i < n; i++) {
            ans.push_back(a[i]);
        }

        // Copy all elements from the second heap 'b' to the new heap 'ans'
        for (int i = 0; i < m; i++) {
            ans.push_back(b[i]);
        }
        
        // Size of the new merged heap
        int size = ans.size();
        
        // Build the max heap by calling heapify from the last non-leaf node to the root
        // We start from size/2 - 1 because nodes after this index are leaves and already satisfy heap property.
        for(int i = size/2 - 1; i >= 0; i--) {
            // Call heapify
            heapify(ans, i, size);
        }
        
        // Return the final merged max-heap
        return ans; 
    }
};

Time Complexity = O(n + m)
Space Complexity = O(n + m)
```