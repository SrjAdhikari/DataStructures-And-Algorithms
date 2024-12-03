# Question : [Longest Arithmetic Subsequence - (LeetCode : 1027)](https://leetcode.com/problems/longest-arithmetic-subsequence/description/)

Given an array `nums` of integers, return _the length of the longest arithmetic subsequence in_ `nums`.

**Note** that:

-   A **subsequence** is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
-   A sequence `seq` is arithmetic if `seq[i + 1] - seq[i]` are all the same value (for `0 <= i < seq.length - 1`).

### Example 1

```
Input: nums = [3,6,9,12]
Output: 4
Explanation:  The whole array is an arithmetic sequence with steps of length = 3.
```

### Example 2

```
Input: nums = [9,4,7,2,10]
Output: 3
Explanation:  The longest arithmetic subsequence is [4,7,10].
```

### Example 3

```
Input: nums = [20,1,15,3,10,5,8]
Output: 4
Explanation:  The longest arithmetic subsequence is [20,15,10,5].
```

### Constraints

-   `2 <= nums.length <= 1000`
-   `0 <= nums[i] <= 500`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(int index, int diff, vector<int>& nums) {
        // Base case: If index goes out of bounds (less than 0), no subsequence exists
        if (index < 0)
            return 0;

        // Initialize the maximum length of the subsequence found so far
        int length = 0;

        // Iterate backward from `index-1` to 0 to check all possible predecessors
        for (int k = index - 1; k >= 0; k--) {
            // If the difference between nums[index] and nums[k] matches `diff`, consider it as part of the subsequence
            if (nums[index] - nums[k] == diff)
                // Recursively compute the length of the subsequence ending at `k`
                length = max(length, 1 + recursion(k, diff, nums));
        }
        // Return the maximum subsequence length found
        return length;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int length = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                // Compute the maximum length for all pairs as starting points
                length = max(length, 2 + recursion(i, nums[j]-nums[i], nums));
            }
        }
        return length;
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(int index, int diff, vector<int>& nums, unordered_map<int, int> dp[]) {
        // Base case: If index goes out of bounds (less than 0), no subsequence exists
        if (index < 0)
            return 0;

        // If the result for this index and diff is already computed, return it
        if (dp[index].count(diff))
            return dp[index][diff];

        // Initialize the maximum length of the subsequence found so far
        int length = 0;

        // Iterate backward from `index-1` to 0 to check all possible predecessors
        for (int k = index - 1; k >= 0; k--) {
            // If the difference between nums[index] and nums[k] matches `diff`, consider it as part of the subsequence
            if (nums[index] - nums[k] == diff)
                // Recursively compute the length of the subsequence ending at `k` with memoization
                length = max(length, 1 + memoization(k, diff, nums, dp));
        }

        // Store the computed result in the dp array and return the value
        return dp[index][diff] = length;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int length = 0;

        unordered_map<int, int>dp[n+1];

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                // Compute the maximum length for all pairs as starting points
                length = max(length, 2 + memoization(i, nums[j]-nums[i], nums, dp));
            }
        }
        return length;
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& nums) {
        int n = nums.size();        // Number of elements in the input array
        int length = 0;             // Variable to track the maximum length of the arithmetic subsequence found

        // If there are fewer than 2 elements, the maximum subsequence length is the size of the array
        if (n <= 2)
            return n;

        // Array of hash maps to store the difference and corresponding length for each index
        unordered_map<int, int> dp[n + 1];

        // Traverse all pairs of elements in the array (i, j), where i < j
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Calculate the difference between the current pair
                int diff = nums[i] - nums[j];

                // Initialize the subsequence length to 1
                int count = 1;

                // If a subsequence with the same difference ending at index `j` exists, extend it
                if (dp[j].count(diff))
                    // Get the length of the subsequence ending at nums[j] with this diff
                    count = dp[j][diff];

                // Update the dp array for index `i` and the current difference
                dp[i][diff] = 1 + count;

                // Update the global maximum subsequence length
                length = max(length, dp[i][diff]);
            }
        }
        // Return the maximum subsequence length
        return length;
    }

    int longestArithSeqLength(vector<int>& nums) {
        return tabulation(nums);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```
