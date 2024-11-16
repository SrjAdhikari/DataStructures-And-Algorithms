# Question : [Longest Repeating Subsequence - GFG](https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1)

Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

### Example 1

```
Input:
str = "axxzxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 

subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
```

### Example 2

```
Input:
str = "axxxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x x y 
0 1 2 3 4

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 

subsequence B
x x
0 1  <-- index of subsequence B
------
2 3  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
```

### Your Task

You don't need to read or print anything. Your task is to complete the `LongestRepeatingSubsequence()` which takes str as input parameter and returns the length of the longest repeating subsequnece.

```
Expected Time Complexity: O(n^2)
Expected Space Complexity: O(n^2)
```

### Constraints

`1 <= |str| <= 10^3`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(int i, int j, string& s) {
        // Base case: if we reach the end of either string, return 0 (no valid subsequence possible)
        if(i >= s.size() || j >= s.size())
            return 0;
        
        // Variable to store the length of the longest repeating subsequence
        int length = 0;

        // If the indices are the same
        if(i == j) 
            // 1. Move i forward, 2. Move j forward, and take the maximum result
            length = 0 + max(recursion(i+1, j, s), recursion(i, j+1, s));

        // If characters at current indices of both strings match
        else if(s[i] == s[j]) 
            // Include this character in the LRS and move both i and j forward.
            length = 1 + recursion(i+1, j+1, s);

        // If characters don't match, try two cases: 
        else 
            // 1. Move i forward, 2. Move j forward, and take the maximum result
            length = 0 + max(recursion(i+1, j, s), recursion(i, j+1, s));
        
        // Return the computed length of LRS
        return length;
    }

    int LongestRepeatingSubsequence(string str){
        return recursion(0, 0, str);
    }
};

Time Complexity = O(3^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(int i, int j, string& s, vector<vector<int>>& dp) {
        // Base case: if we reach the end of either string, return 0 (no valid subsequence possible)
        if(i >= s.size() || j >= s.size())
            return 0;
        
        // Check if the result is already computed for this subproblem, return it
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // Variable to store the length of the longest repeating subsequence
        int length = 0;
        
        // If characters at current indices of both strings match and the indices are not the same
        if (s[i] == s[j] && i != j)
            // Include this character in the LRS and move both `i` and `j` forward.
            length = 1 + memoization(i+1, j+1, s, dp);
        
        // If characters don't match, try two cases:
        else 
            // 1. Move i forward, 2. Move j forward, and take the maximum result
            length = 0 + max(memoization(i+1, j, s, dp), memoization(i, j+1, s, dp));
        
        // Store the computed result in the dp array for memoization and return it
        return dp[i][j] = length;
    }

    int LongestRepeatingSubsequence(string str){
        int n = str.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return memoization(0, 0, str, dp);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(string& s) {
        int n = s.size();

        // Initialize a DP table of size (n+1)x(n+1) with all elements set to 0.
        // `dp[i][j]` represents the LRS length for the substring starting at `i` and `j`.
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        // Fill the DP table in reverse order, starting from the bottom-right corner.
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                // Variable to store the length of the longest repeating subsequence (dp[i][j])
                int length = 0;

                // If characters at current indices of both strings match and the indices are not the same
                if(s[i] == s[j] && i != j) 
                    // Include this character in the LRS and move both `i` and `j` forward.
                    length = 1 + dp[i+1][j+1];

                // If characters don't match, try two cases:
                else 
                    // 1. Move i forward, 2. Move j forward, and take the maximum result
                    length = 0 + max(dp[i+1][j], dp[i][j+1]);
                
                // Store the computed LRS length for the current position
                dp[i][j] = length;
            }
        }
        // Return the final result at dp[0][0], representing the LRS for the entire strings
        return dp[0][0];
    }

    int LongestRepeatingSubsequence(string str){
        return tabulation(str);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n^2)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(string& s) {
        int n = s.size();
        
        vector<int> next(n+1, 0);       // Stores results for the next row -> Represents dp[i+1][*]
        vector<int> curr(n+1, 0);       // Stores results for the current row -> Represents dp[i][*]

        // Fill the dp array from bottom-up, processing each column in reverse order
        for(int j = n-1; j >= 0; j--) {
            for(int i = n-1; i >= 0; i--) {
                // Variable to store the length of the longest repeating subsequence
                int length = 0;

                // If characters at current indices of both strings match and the indices are not the same
                if(s[i] == s[j] && i != j) 
                    // Include this character in the LRS and move both `i` and `j` forward
                    length = 1 + next[i+1];
                
                // If characters don't match, try two cases:
                else 
                    // 1. Move i forward, 2. Move j forward, and take the maximum result
                    length = 0 + max(next[i], curr[i+1]);
                
                // Update the current row with the calculated result.
                curr[i] = length;
            }
            // Move the current row to next row for the next iteration
            next = curr;
        }
        // Return the final answer stored in `next[0]`, which represents the entire string.
        return next[0];
    }

    int LongestRepeatingSubsequence(string str){
        return spaceOptimization(str);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n)
```