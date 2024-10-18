# Question : [Smallest Range Covering Elements from K Lists - (LeetCode : 632)](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/)

You have `k` lists of sorted integers in **non-decreasing order**. Find the **smallest** range that includes at least one number from each of the `k` lists.

We define the range `[a, b]` is smaller than range `[c, d]` if `b - a < d - c` or `a < c` if `b - a == d - c`.

### Example 1

```
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
```

### Example 2

```
Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
```

### Constraints
- `nums.length == k`
- `1 <= k <= 3500`
- `1 <= nums[i].length <= 50`
- `-10^5 <= nums[i][j] <= 10^5`
- `nums[i]` is sorted in **non-decreasing** order.

## Solution

```Cpp
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Create a min-heap (priority queue) to store the smallest elements from each array
        // The priority queue stores pairs of (value, (row, column))
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        int maximum = INT_MIN;      // Track the current maximum element in the range
        int minimum = INT_MAX;      // Track the current minimum element in the range

        // Step 1: Initialize the heap with the first element from each list
        // Also, update the maximum value encountered
        for (int i = 0; i < nums.size(); i++) {
            pq.push(make_pair(nums[i][0], make_pair(i, 0)));    // Insert (value, (row, column))
            maximum = max(maximum, nums[i][0]);                 // Track the maximum value of the first elements
        }

        // Step 2: Set the initial range as the difference between the minimum and maximum
        minimum = pq.top().first;   // The smallest element is at the top of the heap
        vector<int> ans(2);         // To store the result range [min, max]
        ans[0] = minimum;           // Initial minimum
        ans[1] = maximum;           // Initial maximum

        int value, row, col;                // Variables to hold the extracted value and its indices
        pair<int, pair<int, int>> pair;     // Pair to hold the current minimum value and its indices

        // Step 3: Process the elements in the priority queue until we exhaust one of the lists
        // This ensures we are considering elements from each of the lists in the current range
        while (pq.size() == nums.size()) {
            pair = pq.top();    // Get the smallest element from the heap
            pq.pop();           // Remove the smallest element from the heap

            // Store the value, row, and column of the smallest element.
            value = pair.first;
            row = pair.second.first;
            col = pair.second.second;

            // Step 4: If there is a next element in the same row, push it into the heap.
            // This ensures we always have the next smallest element from the matrix.
            if (col + 1 < nums[row].size()) {
                col++;      // Move to the next element in the same row

                // Push next element from the row into the heap
                pq.push(make_pair(nums[row][col], make_pair(row, col)));

                // Update the maximum value (since we are adding new elements to the heap)
                maximum = max(maximum, nums[row][col]);

                // Update the minimum value (which is always the top of the heap)
                minimum = pq.top().first;

                // Step 5: Check if the new range [min, max] is smaller than the previous best range
                if (maximum - minimum < ans[1] - ans[0]) {
                    ans[0] = minimum;   // Update the range's minimum
                    ans[1] = maximum;   // Update the range's maximum
                }
            }
        }

        // Return the smallest range [min, max]
        return ans;
    }
};

Time Complexity = O(N*KlogK)
Space Complexity = O(K)
```