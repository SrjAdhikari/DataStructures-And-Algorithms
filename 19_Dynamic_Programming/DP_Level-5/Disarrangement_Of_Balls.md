# Question : [Disarrangement of balls - GFG](https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1)

You are given `n` balls numbered from 1 to `n` and there are `n` baskets numbered from 1 to `n` in front of you. The `ith` basket is meant for the `ith` ball. Calculate the number of ways in which `no` ball goes into its respective basket.

**Note**: The answer will always fit into a 32-bit integer.

### Example 1

```
Input: n = 2
Output: 1
Explanation: For two balls {1, 2}, there is only one possible derangement {2, 1}.
```

### Example 2

```
Input: n = 3
Output: 2
Explanation: For three balls {1, 2, 3}, there are two possible derangements {3, 1, 2} and {2, 3, 1}.
```

### Constraints

`1 ≤ n ≤ 12`

### Recursive Approach

```Cpp
class Solution {
public:
    int recursion(int n) {
        // Base case 1: There is no derangement for single ball, so return 0.
        if(n == 1)
            return 0;
            
        // Base case 2: There is only one derangement for two balls (swapping two balls), so return 1.
        if(n == 2)
            return 1;
            
        // Recursive step: Derangement formula: D(n) = (n-1) * (D(n-1) + D(n-2))
        // This computes the number of derangements using the recursive relation.
        int ans = (n-1) * (recursion(n-1) + recursion(n-2));
        
        // Return the calculated result.
        return ans;
    }

    int countDer(int n) {
        return recursion(n);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```

### Top-Down (Memoization) Approach

```Cpp
class Solution {
public:
    int memoization(int n, vector<int>& dp) {
        // Base case 1: There is no derangement for single ball, so return 0.
        if(n == 1)
            return 0;
            
        // Base case 2: There is only one derangement for two balls (swapping two balls), so return 1.
        if(n == 2)
            return 1;
            
        // Check if the value for this 'n' has already been computed, if yes return it.
        if(dp[n] != -1)
            return dp[n];
            
        // Recursive step: Apply the derangement formula and store the result in dp[n] to cache it.
        dp[n] = (n-1) * (memoization(n-1, dp) + memoization(n-2, dp));
        
        // Return the stored result from dp[n].
        return dp[n];
    }

    int countDer(int n) {
        vector<int> dp(n+1, -1);
        return memoization(n, dp);

    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Bottom-Up (Tabulation) Approach

```Cpp
class Solution {
public:
    int tabulation(int n) {
        // Initialize a dp array of size n+1 to store the derangements for all lengths from 1 to n.
        vector<int> dp(n+1, -1);

        // Base case 1: Derangement for single ball is 0.
        dp[1] = 0;

        // Base case 2: Derangement for two balls is 1.
        dp[2] = 1;

        // Loop to fill up the dp array for all lengths from 3 to n.
        for(int i = 3; i <= n; i++) {
            // Derangement of i items = (i-1) * (derangements of i-1 items + derangements of i-2 items)
           dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
        }

       // Return the result for the given 'n' which is now stored in dp[n].
       return dp[n];
    }

    int countDer(int n) {
        return tabulation(n);
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

### Space Optimized Approach

```Cpp
class Solution {
public:
    int spaceOptimization(int n) {
        // Base case 1: There is no derangement for single ball, so return 0.
        if(n == 1)
            return 0;
            
        // Base case 2: There is only one derangement for two balls (swapping two balls), so return 1.
        if(n == 2)
            return 1;
        
        // Initialize two variables to store the derangements for the previous two lengths (n-1 and n-2).
        int prev1 = 1;  // Represents derangements of n-1
        int prev2 = 0;  // Represents derangements of n-2
        
        // Loop to calculate the derangements for all lenghts from 3 to n.
        for(int i = 3; i <= n; i++) {
            // Apply the derangement formula to compute the derangement for current 'i'
            int curr = (i-1) * (prev1 + prev2);
            
            // Update the previous two values for the next iteration.
            prev2 = prev1;
            prev1 = curr;
       }
       
       // Return the final result, which is stored in prev1.
       return prev1;
    }

    int countDer(int n) {
        return spaceOptimization(n);
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```