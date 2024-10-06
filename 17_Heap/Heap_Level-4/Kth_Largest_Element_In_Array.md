# Question : [Kth Largest Element in an Array - (LeetCode : 215)](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

Given an integer array `nums` and an integer `k`, return *the `kth` largest element in the array*.
Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.
Can you solve it without sorting?

### Example 1

```
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```

### Example 2

```
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```

### Constraints

-   `1 <= k <= nums.length <= 10^5`
-   `-10^4 <= nums[i] <= 10^4`

## Solution

```Cpp
class Solution {
public:
    // Function to find the k-th largest element in the given array 'nums'.
    int findKthLargest(vector<int>& nums, int k) {
        // Create a min-heap (priority queue) to keep track of the k largest elements.
        // This priority queue stores the smallest element at the top.
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Get the size of the array.
        int size = nums.size();

        // Insert the first 'k' elements into the min-heap.
        // The heap will hold at most 'k' elements and the smallest among them will be at the top.
        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }

        // Traverse through the rest of the array starting from the k-th element.
        for (int i = k; i <= size - 1; i++) {
            // If the current element is larger than the smallest element in the heap (pq.top()).
            // replace the smallest element with the current element.
            if (nums[i] > pq.top()) {
                pq.pop();               // Remove the smallest element from the heap.
                pq.push(nums[i]);       // Insert the current larger element.
            }
        }

        // After processing all elements, the top of the heap will be the kth largest element.
        return pq.top();
    }
};

Time Complexity = O(Nlog(k))
Space Complexity = O(k)
```