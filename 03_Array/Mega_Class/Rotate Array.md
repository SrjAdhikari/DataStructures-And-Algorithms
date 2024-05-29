# Question : [Rotate Array - (LeetCode : 189)](https://leetcode.com/problems/rotate-array/description/)

Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

### Example 1

```plaintext
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

### Example 2

```plaintext
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

### Constraints

`1 <= nums.length <= 10^5`

`-2^31 <= nums[i] <= 2^31 - 1`

`0 <= k <= 10^5`


### Follow up
1. Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.

2. Could you do it in-place with `O(1)` extra space?


## Solution 1

```Cpp
Using Extra Space And Modulus Operator : 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Get the size of the input vector.
        int n = nums.size();
        
        // Create a new vector to store the rotated elements.
        vector<int> ans(n);

        // Iterate through each element of the input vector.
        for(int i = 0; i < n; i++){

            // Calculate the new index for the current element after rotation.
            int index = ((i + k) % n);
            
            // Assign the current element to its new index in the rotated vector.
            ans[index] = nums[i];
        }
        
        // Update the original vector with the rotated elements.
        nums = ans;
    }
};


Time Complexity = O(n)
Space Complexity = O(n)
```

## Solution 2

```Cpp
Using Reverse Method : 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        // Get the size of the input vector.
        int n = nums.size();
        
        // Calculate the effective number of steps to rotate within the range [0, n-1].
        k = k % n;
        
        // Reverse the entire vector.
        reverse(nums.begin(), nums.end());
        
        // Reverse the first 'k' elements.
        reverse(nums.begin(), nums.begin() + k);
        
        // Reverse the remaining elements after 'k'.
        reverse(nums.begin() + k, nums.end());
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```