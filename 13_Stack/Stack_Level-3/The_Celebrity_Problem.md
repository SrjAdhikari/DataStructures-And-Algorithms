# Question : [The Celebrity Problem - GFG](https://www.geeksforgeeks.org/problems/the-celebrity-problem/1)

A celebrity is a person who is known to all but `does not know` anyone at a party. A party is being organized by some people.  A square matrix `mat` is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return `-1`.

**Note** : Follow 0-based indexing.

### Example 1

```
Input: mat[][] = [[0 1 0],
                 [0 0 0], 
                 [0 1 0]]
Output: 1
Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 
```

### Example 2

```
Input: mat[][] = [[0 1],
                 [1 0]]
Output: -1
Explanation: The two people at the party both know each other. None of them is a celebrity.
```

```
Expected Time Complexity: O(n^2)
Expected Auxiliary Space: O(1)
```

### Constraints

-   `1 <= mat.size()<= 3000`
-   `0 <= mat[i][j]<= 1`

## Solution

```Cpp
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        // Stack to hold indices of possible celebrity candidates
        stack<int> st;
        
        // Get the number of people in the matrix
        int n = mat.size();
        
        // Push all people (0 to n-1) onto the stack as potential celebrities
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Eliminate non-celebrities using the stack
        while (st.size() > 1) {
            // Pop the top two elements from the stack
            int first = st.top();
            st.pop();
            
            int second = st.top();
            st.pop();
            
            // Compare first and second person
            // If `first` knows `second` and `second` does not know `first`, `first` cannot be a celebrity
            // So, `second` is a potential celebrity.
            if (mat[first][second] && !mat[second][first]) {
                st.push(second);
            } 
            // Otherwise, `second` cannot be a celebrity, and `first` is a potential candidate.
            else {
                st.push(first);
            }
        }

        // If stack is empty, there is no candidate for celebrity
        if (st.empty()) {
            return -1;
        }

        // The last remaining person is the only potential candidate for celebrity
        int num = st.top();
        st.pop();

        // Validate the potential celebrity by checking:
        // 1. They should not know anyone else (row should contain all 0s)
        // 2. Everyone else should know them (column should contain n-1 1s, except for self)
        int row = 0, col = 0;
        
        // Check the row and column for the candidate `num`
        for (int i = 0; i < n; i++) {
            row += mat[num][i];  // Count how many people 'num' knows (should be all 0s)
            col += mat[i][num];  // Count how many people know 'num' (should be n-1 1s)
        }

        // A valid celebrity knows no one (row == 0) and is known by everyone else (col == n - 1)
        return (row == 0 && col == n - 1) ? num : -1;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
