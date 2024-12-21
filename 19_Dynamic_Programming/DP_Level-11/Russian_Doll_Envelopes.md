# Question : [Russian Doll Envelopes - (LeetCode : 354)](https://leetcode.com/problems/russian-doll-envelopes/description/)

You are given a 2D array of integers `envelopes` where `envelopes[i] = [wi, hi]` represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return _the maximum number of envelopes you can Russian doll (i.e., put one inside the other)._

**Note:** You cannot rotate an envelope.

### Example 1

```
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
```

### Example 2

```
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
```

### Constraints

-   `1 <= envelopes.length <= 10^5`
-   `envelopes[i].length == 2`
-   `1 <= wi, hi <= 10^5`

### Recursive Approach

```Cpp
class Solution {
public:
    // Function to check if the current envelope can fit inside the previous envelope
    int validationCheck(vector<int>& curr, vector<int>& prev) {
        // Returns true if the cuboid 'curr' can be placed on top of 'prev'.
        // This ensures that the width, and height of 'prev' are all
        // less than to the corresponding dimensions of 'curr'.
        return (prev[0] < curr[0] && prev[1] < curr[1]);
    }

    int recursion(vector<vector<int>>& envelopes, int curr, int prev) {
        // Base case: If we have processed all envelopes, return 0 (no envelopes left to add).
        if (curr >= envelopes.size())
            return 0;

        // Variable to store the result if the current envelope is included
        int include = INT_MIN;

        // Check if the current envelopes can be placed on top of the previous one.
        // If 'prev' is -1, it means there is no previous envelopes, so we can always include 'curr'.
        if (prev == -1 || validationCheck(envelopes[curr], envelopes[prev]))
            // Include the current envelopes and move to the next element (curr+1) and (prev = curr).
            include = 1 + recursion(envelopes, curr + 1, curr);

        // Exclude current envelope and move to the next element without changing 'prev'
        int exclude = recursion(envelopes, curr + 1, prev);

        // Return the maximum of including or excluding the current envelope
        return max(include, exclude);
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort envelopes by width and height in ascending order
        // Sort envelopes in increasing order by width.
        // if width(curr) == width(prev) then, sort in heightwise decreasing
        sort(envelopes.begin(), envelopes.end());

        return recursion(envelopes, 0, -1);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    // Function to check if the current envelope can fit inside the previous envelope
    int validationCheck(vector<int>& curr, vector<int>& prev) {
        // Returns true if the cuboid 'curr' can be placed on top of 'prev'.
        // This ensures that the width, and height of 'prev' are all
        // less than to the corresponding dimensions of 'curr'.
        return (prev[0] < curr[0] && prev[1] < curr[1]);
    }

    int memoization(vector<vector<int>>& envelopes, int curr, int prev, vector<vector<int>>& dp) {
        // Base case: If we have processed all envelopes, return 0 (no envelopes left to add).
        if (curr >= envelopes.size())
            return 0;

        // Check if the result for this (curr, prev) pair is already computed, if yes, return it.
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        // Variable to store the result if the current envelope is included
        int include = INT_MIN;

        // Check if the current envelopes can be placed on top of the previous one.
        // If 'prev' is -1, it means there is no previous envelopes, so we can always include 'curr'.
        if (prev == -1 || validationCheck(envelopes[curr], envelopes[prev]))
            // Include the current envelopes and move to the next element (curr+1) and (prev = curr).
            include = 1 + memoization(envelopes, curr + 1, curr, dp);

        // Exclude current envelope and move to the next element without changing 'prev'
        int exclude = memoization(envelopes, curr + 1, prev, dp);

        // Store the result for this (curr, prev) pair in the DP array and return it.
        return dp[curr][prev + 1] = max(include, exclude);
    }


    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort envelopes first by width and height (in increasing order)
        sort(envelopes.begin(), envelopes.end());

        int n = envelopes.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        return memoization(envelopes, 0, -1, dp);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```

### Binary Search Approach

```Cpp
class Solution {
public:
    // Comparator function for sorting envelopes
    static bool comp(vector<int>& curr, vector<int>& prev) {
        // If widths are equal, sort by height in descending order
        if (curr[0] == prev[0])
            return curr[1] > prev[1];

        // Otherwise, sort by width in ascending order
        return curr[0] < prev[0];
    }

    int binarySearch(vector<int>& nums) {
        // Sort envelopes first by width in increasing order,
        // and if the widths are equal, by height in decreasing order
        sort(arr.begin(), arr.end(), comp);

        // If no envelopes exist, return 0
        if (arr.size() == 0)
            return 0;

        // Vector to store the heights of the nested envelopes
        vector<int> result;

        // Add the height of the first envelope
        result.push_back(arr[0][1]);

        // Iterate through the sorted envelopes from the second element.
        for(int i = 1; i < nums.size(); i++) {
            // If the current envelope's height is greater than the last height in result, we can add it
            if (arr[i][1] > result.back()) {
                // Add it to the result
                result.push_back(arr[i][1]);
            }
            // Otherwise, find the position where the current height should be placed to maintain increasing order
            else {
                // find the correct position to replace it using binary search.
                int index = lower_bound(result.begin(), result.end(), arr[i][1]) - result.begin();

                // Replace the height at the found position
                result[index] = arr[i][1]
            }
        }

        // Return the size of the array, which represents the maximum number of nested envelopes.
        return result.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort envelopes first by width and height (in increasing order)
        sort(envelopes.begin(), envelopes.end());

        return binarySearch(envelopes);
    }
};

Time Complexity = O(nlogn)
Space Complexity = O(n)
```
