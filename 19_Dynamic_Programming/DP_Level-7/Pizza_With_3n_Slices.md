# Question : [Pizza With 3n Slices - (LeetCode : 1388)](https://leetcode.com/problems/pizza-with-3n-slices/description/)

There is a pizza with `3n` slices of varying size, you and your friends will take slices of pizza as follows:

-   You will pick **any** pizza slice.
-   Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
-   Your friend Bob will pick the next slice in the clockwise direction of your pick.
-   Repeat until there are no more slices of pizzas.

Given an integer array `slices` that represent the sizes of the pizza slices in a clockwise direction, return _the maximum possible sum of slice sizes that you can pick_.

### Example 1

![](https://assets.leetcode.com/uploads/2020/02/18/sample_3_1723.png)

```
Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively.
Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
```

### Example 2

![](https://assets.leetcode.com/uploads/2020/02/18/sample_4_1723.png)

```
Input: slices = [8,9,8,6,1,1]
Output: 16
Explanation: Pick pizza slice of size 8 in each turn.
If you pick slice with size 9 your partners will pick slices of size 8.
```

### Constraints

-   `3 * n == slices.length`
-   `1 <= slices.length <= 500`
-   `1 <= slices[i] <= 1000`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(vector<int>& slices, int start, int end, int n) {
        // Base case: if no more slices can be picked (n == 0) or if start index exceeds end index
        if(n == 0 || start > end)
            return 0;

        // Option 1: Include the current slice (start), and move 2 positions forward (since adjacent slices can't be chosen)
        int include = slices[start] + recursion(slices, start + 2, end, n - 1);

        // Option 2: Exclude the current slice (start), and move 1 position forward
        int exclude = 0 + recursion(slices, start + 1, end, n);

        // Return the maximum of including or excluding the slice
        return max(include, exclude);
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();

        int includeFirst = recursion(slices, 0, n-2, n/3);
        int excludeFirst = recursion(slices, 1, n-1, n/3);

        return max(includeFirst, excludeFirst);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(vector<int>& slices, int start, int end, int n, vector<vector<int>>& dp) {
        // Base case: if no more slices can be picked (n == 0) or if start index exceeds end index
        if(n == 0 || start > end)
            return 0;

        // If the result for this state has already been computed, return it from the dp array
        if(dp[start][n] != -1)
            return dp[start][n];

        // Option 1: Include the current slice (start), and move 2 positions forward (since adjacent slices can't be chosen)
        int include = slices[start] + memoization(slices, start + 2, end, n - 1, dp);

        // Option 2: Exclude the current slice (start), and move 1 position forward
        int exclude = 0 + memoization(slices, start + 1, end, n, dp);

        // Store the result in the dp array and return it
        return dp[start][n] = max(include, exclude);
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();

        vector<vector<int>>dp1(n, vector<int>(n, -1));
        vector<vector<int>>dp2(n, vector<int>(n, -1));

        int includeFirst = memoization(slices, 0, n-2, n/3, dp1);
        int excludeFirst = memoization(slices, 1, n-1, n/3, dp2);

        return max(includeFirst, excludeFirst);
    }
};

Time Complexity = O(n * m)
Space Complexity = O(n * m)
=> 'n' is the number of slices and 'm' is the number of slice selections (n / 3).
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(vector<int>& slices) {
        int size = slices.size();

        // dp1 will store the results for the first possible choice (0th slice included)
        // dp2 will store the results for the second possible choice (1st slice included)
        vector<vector<int>> dp1(size + 2, vector<int>(size + 2, 0));
        vector<vector<int>> dp2(size + 2, vector<int>(size + 2, 0));

       // Filling dp1 for the case where the first slice is included
        for(int start = size - 2; start >= 0; start--) {
            for(int n = 1; n <= size / 3; n++) {
                // Option 1: Include the current slice (start) and move 2 positions forward
                int include = slices[start] + dp1[start + 2][n - 1];

                // Option 2: Exclude the current slice (start) and move 1 position forward
                int exclude = 0 + dp1[start + 1][n];

                // Store the maximum of including or excluding the slice in dp1
                dp1[start][n] = max(include, exclude);
            }
        }
        // Max value when including the first slice
        int includeFirst = dp1[0][size / 3];

        // Filling dp2 for the case where the first slice is excluded
        for(int start = size - 1; start >= 1; start--) {
            for(int n = 1; n <= size / 3; n++) {
                // Option 1: Include the current slice (start) and move 2 positions forward
                int include = slices[start] + dp2[start + 2][n - 1];

                // Option 2: Exclude the current slice (start) and move 1 position forward
                int exclude = 0 + dp2[start + 1][n];

                // Store the maximum of including or excluding the slice in dp2
                dp2[start][n] = max(include, exclude);
            }
        }
        // Max value when excluding the first slice
        int excludeFirst = dp2[1][size / 3];

        // Return the maximum of the two scenarios: including the first slice or excluding the first slice
        return max(includeFirst, excludeFirst);
    }

    int maxSizeSlices(vector<int>& slices) {
        return tabulation(slices);
    }
};

Time Complexity = O(n * m)
Space Complexity = O(n * m)
=> 'n' is the number of slices and 'm' is the number of slice selections (n / 3).
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(vector<int>& slices) {
        int size = slices.size();

        // Arrays to store the DP results, prev1, curr1, next1 for dp1 calculations (includeFirst)
        vector<int> prev1(size + 2, 0), curr1(size + 2, 0), next1(size + 2, 0);

        // Arrays to store the DP results, prev2, curr2, next2 for dp2 calculations (excludeFirst)
        vector<int> prev2(size + 2, 0), curr2(size + 2, 0), next2(size + 2, 0);

        // First pass: Filling prev1, curr1, and next1 for the case where the first slice is included
        for(int start = size - 2; start >= 0; start--) {
            for(int n = 1; n <= size / 3; n++) {
                // Option 1: Include the current slice (start) and move 2 positions forward
                int include = slices[start] + next1[n - 1];

                // Option 2: Exclude the current slice (start) and move 1 position forward
                int exclude = 0 + curr1[n];

                // Store the maximum of including or excluding the slice in prev1
                prev1[n] = max(include, exclude);
            }
            // Update the next, curr, and prev arrays for the next iteration
            next1 = curr1;
            curr1 = prev1;
        }
        // Max value when including the first slice
        int includeFirst = curr1[size / 3];

        // Second pass: Filling prev2, curr2, and next2 for the case where the first slice is excluded
        for(int start = size - 1; start >= 1; start--) {
            for(int n = 1; n <= size / 3; n++) {
                // Option 1: Include the current slice (start) and move 2 positions forward
                int include = slices[start] + next2[n - 1];

                // Option 2: Exclude the current slice (start) and move 1 position forward
                int exclude = 0 + curr2[n];

                // Store the maximum of including or excluding the slice in prev2
                prev2[n] = max(include, exclude);
            }
            // Update the next, curr, and prev arrays for the next iteration
            next2 = curr2;
            curr2 = prev2;
        }
        // Max value when excluding the first slice
        int excludeFirst = curr2[size / 3];

        // Return the maximum of the two scenarios: including the first slice or excluding the first slice
        return max(includeFirst, excludeFirst);
    }

    int maxSizeSlices(vector<int>& slices) {
        return spaceOptimization(slices);
    }
};

Time Complexity = O(n * m)
Space Complexity = O(m)
```
