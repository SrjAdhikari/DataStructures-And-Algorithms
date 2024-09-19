# Question : [Minimum Number of K Consecutive Bit Flips - (LeetCode : 995)](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/)

You are given a binary array `nums` and an integer `k`.

A **k-bit flip** is choosing a **subarray** of length `k` from `nums` and simultaneously changing every `0` in the subarray to `1`, and every `1` in the subarray to `0`.

Return *the minimum number of **k-bit flips** required so that there is no `0` in the array*. If it is not possible, return `-1`.

A **subarray** is a **contiguous** part of an array.

### Example 1

```
Input: nums = [0,1,0], k = 1
Output: 2
Explanation: Flip nums[0], then flip nums[2].
```

### Example 2

```
Input: nums = [1,1,0], k = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, 
we cannot make the array become [1,1,1].
```

### Example 3

```
Input: nums = [0,0,0,1,0,1,1,0], k = 3
Output: 3
Explanation: 
Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]
```

### Constraints

-   `1 <= nums.length <= 10^5`
-   `1 <= k <= nums.length`


## Solution 1 : Brute Force Solution

```Cpp
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // Variable to count the total number of flips performed
        int flipCount = 0;

        // Iterate through each element of the array `nums`
        for(int i = 0; i < nums.size(); i++) {
            // If we encounter a 0 at position `i`, we need to flip this bit and the next (k-1) bits
            if(nums[i] == 0) {
                // Check if there are enough elements left to flip k bits
                // If `i + k - 1` exceeds the size of the array, we can't flip all `k` bits,
                // so return -1 as it is impossible to flip.
                if(i + k - 1 >= nums.size()) 
                    return -1;

                // Flip the current bit and the next `k-1` bits
                // We loop over the next `k` elements starting from index `i`
                for(int j = i; j <= i + k - 1; j++) {
                    // Perform a bit flip: If `nums[j]` is 0, it becomes 1, and if it is 1, it becomes 0
                    nums[j] = (nums[j] == 0 ? 1 : 0);
                    // Alternatively, nums[j] = !nums[j]; can also be used to flip the bit
                }
                // After successfully flipping `k` bits, increment the flip count
                flipCount++;
            }
            // If `nums[i]` is already 1, we do nothing and move to the next element
        }

        // Return the total number of flips needed to make all bits in `nums` 1
        return flipCount;
    }
};

Time Complexity = O(N * K)
Space Complexity = O(N)
```

## Solution 2 : Optimized Solution

```Cpp
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // Queue to keep track of the indices where flips start and end
        queue<int> q;

        // Variable to count the number of flips performed
        int flipCount = 0;

        // Size of the input array
        int n = nums.size();

        // Iterate through each bit in the array
        for(int i = 0; i < n; i++) {
            // Remove indices from the queue that are out of the current window of size k
            if(!q.empty() && q.front() < i) {
                q.pop();
            }

            // Check if the current bit is in the state that we need to flip
            // If the number of flips so far is even, `q.size()` should be equal to `nums[i]`
            // If it's odd, `q.size()` should be different from `nums[i]`
            if(q.size() % 2 == nums[i]) {
                // Check if there are enough elements left to flip k bits
                if(i + k - 1 >= n) 
                    return -1;

                // Push the end index of the current flip operation
                // We use `i + k - 1` because the flip will affect elements from index `i` to `i + k - 1`
                q.push(i + k - 1);

                // Increment the flip count
                flipCount++;
            }
        }
        
        // Return the total number of flips performed
        return flipCount;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```