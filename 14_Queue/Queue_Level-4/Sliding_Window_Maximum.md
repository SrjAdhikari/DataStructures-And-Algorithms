# Question : [Sliding Window Maximum - (LeetCode : 239)](https://leetcode.com/problems/sliding-window-maximum/description/)

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return *the max sliding window*.

### Example 1

```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

### Example 2

```
Input: nums = [1], k = 1
Output: [1]
```

### Constraints

-   `1 <= nums.length <= 10^5`
-   `-10^4 <= nums[i] <= 10^4`
-   `1 <= k <= nums.length`


## Solution 1 : Brute Force Solution

```Cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Vector to store the result (maximums of each sliding window)
        vector<int> ans;

        // Get the size of the input array
        int n = nums.size();

        // Iterate over the array, setting the start of the sliding window to `i`
        // The loop runs from 0 to (n - k), i.e., until there is enough space for a window of size k
        for(int i = 0; i <= n - k; i++) {
            // Initialize `maxNum` with a very small value (minimum possible integer)
            int maxNum = INT_MIN;

            // Iterate over the current window of size `k`
            for(int j = i; j < i + k; j++) {
                // For each element in the window, update `maxNum` with the maximum value
                maxNum = max(maxNum, nums[j]);
            }

            // After finding the maximum in the current window, add it to the result vector
            ans.push_back(maxNum);
        }
        
        // Return the result vector containing the maximums for each window
        return ans;
    }
};

Time Complexity = O(N * K)
Space Complexity = O(N)
```

## Solution 2 : Optimized Solution

```Cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Deque to store indices of elements in the current window
        deque<int> dq;
        
        // Result vector to store the maximum of each sliding window
        vector<int> ans;

        // Process the first (k-1) elements (i.e., before the first full window)
        for(int i = 0; i < k - 1; i++) {
            // Remove elements from the back of deque that are smaller than the current element nums[i]
            // We maintain the largest elements at the front of the deque
            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            // Add current element index to the deque
            dq.push_back(i);
        }

        // Process the rest of the elements (including the first full window)
        for(int i = k - 1; i < nums.size(); i++) {
            // Same as above: remove elements smaller than nums[i] from the back of deque
            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            // Add the current element index to the deque
            dq.push_back(i);

            // Remove elements from the front of deque that are out of the current window
            if(dq.front() <= i - k) {
                dq.pop_front();
            }

            // The element at the front of the deque is the maximum for the current window
            ans.push_back(nums[dq.front()]);
        }
        
        // Return the result vector containing the maximum values for all sliding windows
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```