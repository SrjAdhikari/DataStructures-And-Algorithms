# Question : [Maximal Rectangle - (LeetCode : 85)](https://leetcode.com/problems/maximal-rectangle/description/)

Given a `rows x cols` binary `matrix` filled with `0`'s and `1`'s, find the largest rectangle containing only `1`'s and return *its area*.

### Example 1
![](https://assets.leetcode.com/uploads/2020/09/14/maximal.jpg)
```
Input: matrix = [["1","0","1","0","0"],
                 ["1","0","1","1","1"],
                 ["1","1","1","1","1"],
                 ["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
```

### Example 2
```
Input: matrix = [["0"]]
Output: 0
```

### Example 3
```
Input: matrix = [["1"]]
Output: 1
```

### Constraints

-   `rows == matrix.length`
-   `cols == matrix[i].length`
-   `1 <= row, cols <= 200`
-   `matrix[i][j]` is `'0'` or `'1'`.

## Solution

```Cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(); // Get the number of elements in the heights array
        int index;              // Variable to store the current index being processed
        stack<int> st;          // Stack to store the indices of the heights in increasing order
        int area = INT_MIN;     // Variable to store the maximum area found, initialized to the smallest possible value

        // Step 1: Traverse through the heights array to process each bar
        for (int i = 0; i < n; i++) {
            // Check if the current height is smaller than the height at the top of the stack
            // This means we have found a boundary where the rectangle can end
            while (!st.empty() && heights[i] < heights[st.top()]) {
                index = st.top(); // Get the index of the top element in the stack
                st.pop();         // Pop the top element as we are processing it

                // Calculate the area with heights[index] as the smallest height
                if (!st.empty()) {
                    // If the stack is not empty, calculate the width as (i - st.top() - 1)
                    area = max(area, heights[index] * (i - st.top() - 1));
                } else {
                    // If the stack is empty, this means heights[index] is the smallest so far
                    // So, the width is 'i' itself (i.e., from index 0 to i-1)
                    area = max(area, heights[index] * i);
                }
            }
            // Push the current index onto the stack
            st.push(i);
        }

        // Step 2: Process any remaining bars in the stack (After processing all elements, some bars may still be in the stack. We calculate areas for these.)
        while (!st.empty()) {
            index = st.top(); // Get the index of the top element in the stack
            st.pop();         // Pop the top element as we are processing it

            // Calculate the area with heights[index] as the smallest height
            if (!st.empty()) {
                // If the stack is not empty, calculate the width as (n - st.top() - 1)
                area = max(area, heights[index] * (n - st.top() - 1));
            } else {
                // If the stack is empty, the width is 'n' (i.e., the entire array)
                area = max(area, heights[index] * n);
            }
        }

        // Return the maximum area found
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        // Get the number of rows and columns in the matrix
        int row = matrix.size();
        int col = matrix[0].size();

        // Initialize heights vector for the histogram, initially filled with 0s
        vector<int> heights(col, 0);
    
        // Variable to store the maximum rectangular area
        int area = INT_MIN;

        // Loop through each row in the matrix
        for (int i = 0; i < row; i++) {
            // Update heights for the current row
            for (int j = 0; j < col; j++) {
                // If the current element is '0', reset the height for this column to 0
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else 
                    // Otherwise, increment the height for this column
                    heights[j]++;
            }

            // For each row, find the largest rectangle area in the updated histogram
            area = max(area, largestRectangleArea(heights));
        }

        // Return the maximum area found
        return area;
    }
};

Time Complexity = O(row * col)
Space Complexity = O(col)
```