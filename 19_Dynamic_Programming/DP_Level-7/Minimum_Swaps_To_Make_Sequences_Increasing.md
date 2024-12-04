# Question : [Minimum Swaps To Make Sequences Increasing - (LeetCode : 801)](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/)

You are given two integer arrays of the same length `nums1` and `nums2`. In one operation, you are allowed to swap `nums1[i]` with `nums2[i]`.

-   For example, if `nums1 = [1,2,3,8]`, and `nums2 = [5,6,7,4]`, you can swap the element at `i = 3` to obtain `nums1 = [1,2,3,4]` and `nums2 = [5,6,7,8]`.

Return _the minimum number of needed operations to make `nums1` and `nums2`_ **_strictly increasing_**. The test cases are generated so that the given input always makes it possible.

An array `arr` is **strictly increasing** if and only if `arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1]`.

### Example 1

```
Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
Output: 1
Explanation:
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.
```

### Example 2

```
Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
Output: 1
```

### Constraints

-   `2 <= nums1.length <= 10^5`
-   `nums2.length == nums1.length`
-   `0 <= nums1[i], nums2[i] <= 2 * 10^5`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& nums1, vector<int>& nums2, int index, bool swapped) {
        int n = nums1.size();

        // Base case: If we have reached the end of the arrays, return 0 because no more swaps are needed
        if(index >= n)
            return 0;

        // Initialize minimum swap to a large value
        int minSwap = INT_MAX;

        int nums1Prev = nums1[index-1];         // previous value in nums1
        int nums2Prev = nums2[index-1];         // previous value in nums2

        // Swap the previous values if the swapped flag is true
        if(swapped)
            swap(nums1Prev, nums2Prev);

        // No swap: If nums1[index] and nums2[index] are greater than their previous counterparts, no swap needed
        if(nums1[index] > nums1Prev && nums2[index] > nums2Prev)
            // Proceed recursively without swapping
            minSwap = recursion(nums1, nums2, index+1, 0);

        // Swap: If nums1[index] and nums2[index] are greater after swapping the previous elements, perform swap
        if(nums1[index] > nums2Prev && nums2[index] > nums1Prev)
            // Perform swap recursively
            minSwap = min(minSwap, 1 + recursion(nums1, nums2, index+1, 1));

        // Return the minimum number of swaps needed.
        return minSwap;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);        // Insert a dummy element at the beginning of nums1.
        nums2.insert(nums2.begin(), -1);        // Insert a dummy element at the beginning of nums2.

        bool swapped = 0;

        return recursion(nums1, nums2, 1, swapped);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>>& dp) {
        int n = nums1.size();

        // Base case: If we have reached the end of the arrays, return 0 because no more swaps are needed
        if(index >= n)
            return 0;

        // If the result is already computed for this state, return it
        if(dp[index][swapped] != -1)
            return dp[index][swapped];

        // Initialize minimum swap to a large value
        int minSwap = INT_MAX;

        int nums1Prev = nums1[index-1];         // previous value in nums1
        int nums2Prev = nums2[index-1];         // previous value in nums2

        // Swap the previous values if the swapped flag is true
        // If we have swapped at the previous index, we swap the previous values
        if(swapped)
            swap(nums1Prev, nums2Prev);

        // Case 1: No Swap
        if(nums1[index] > nums1Prev && nums2[index] > nums2Prev)
            minSwap = memoization(nums1, nums2, index+1, 0, dp);

        // Case 2: Swap
        if(nums1[index] > nums2Prev && nums2[index] > nums1Prev)
            minSwap = min(minSwap, 1 + memoization(nums1, nums2, index+1, 1, dp));

        // Store the result in dp and return
        return dp[index][swapped] = minSwap;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);        // Insert a dummy element at the beginning of nums1.
        nums2.insert(nums2.begin(), -1);        // Insert a dummy element at the beginning of nums2.

        bool swapped = 0;

        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));

        return memoization(nums1, nums2, 1, swapped, dp);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        // Initialize dp table with size n+1 for indices and two states (swapped or not)
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        // Traverse the indices from end to start
        for(int index = n-1; index >= 1; index--) {
            // Traverse both swap and no-swap states
            for(int swapped = 1; swapped >= 0; swapped--) {

                int minSwap = INT_MAX;
                int nums1Prev = nums1[index-1];     // previous value in nums1
                int nums2Prev = nums2[index-1];     // previous value in nums2

                // If swapped flag is true, swap the previous elements.
                if(swapped)
                    swap(nums1Prev, nums2Prev);

                // Case 1: No Swap
                if(nums1[index] > nums1Prev && nums2[index] > nums2Prev)
                    minSwap = dp[index+1][0];

                // Case 2: Swap
                if(nums1[index] > nums2Prev && nums2[index] > nums1Prev)
                    minSwap = min(minSwap, 1 + dp[index+1][1]);

                // Store the result in dp
                dp[index][swapped] = minSwap;
            }
        }
        // Return the result for the first index with no swap (since we added a dummy element at the beginning)
        return dp[1][0];
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);        // Insert a dummy element at the beginning of nums1.
        nums2.insert(nums2.begin(), -1);        // Insert a dummy element at the beginning of nums2.

        bool swapped = 0;

        return tabulation(nums1, nums2);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        // Initialize the swap and noSwap variables for the previous state
        int swap = 0;
        int noSwap = 0;

        // Variables to store the current values for swap and noSwap
        int currSwap = 0;
        int currNoSwap = 0;

        // Traverse the indices from end to start
        for(int index = n-1; index >= 1; index--) {
            // Traverse both swap and no-swap states
            for(int swapped = 1; swapped >= 0; swapped--) {

                int minSwap = INT_MAX;
                int nums1Prev = nums1[index-1];     // previous value in nums1
                int nums2Prev = nums2[index-1];     // previous value in nums2

                // If swapped flag is true, swap the previous elements.
                if(swapped) {
                    int temp = nums1Prev;
                    nums1Prev = nums2Prev;
                    nums2Prev = temp;
                }

                // Case 1: No Swap
                if(nums1[index] > nums1Prev && nums2[index] > nums2Prev)
                    minSwap = noSwap;

                // Case 2: Swap
                if(nums1[index] > nums2Prev && nums2[index] > nums1Prev)
                    minSwap = min(minSwap, 1 + swap);

                // Update the current swap or noSwap variables.
                if(swapped)
                    currSwap = minSwap;
                else
                    currNoSwap = minSwap;
            }
            swap = currSwap;        // Update swap for the next iteration.
            noSwap = currNoSwap;    // Update noSwap for the next iteration.
        }
        // Return the minimum number of swaps needed
        return min(swap, noSwap);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);        // Insert a dummy element at the beginning of nums1.
        nums2.insert(nums2.begin(), -1);        // Insert a dummy element at the beginning of nums2.

        bool swapped = 0;

        return spaceOptimization(nums1, nums2);
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
