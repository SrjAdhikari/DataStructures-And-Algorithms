# Question : [Spiral Matrix - (LeetCode : 54)](https://leetcode.com/problems/spiral-matrix/description/)

Given an `m x n` `matrix`, return all elements of the `matrix` in spiral order.

### Example 1

![](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)

```plaintext
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

### Example 2

![](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)

```plaintext
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

### Constraints

`m == matrix.length`

`1 <= m, n <= 10`

`-100 <= matrix[i][j] <= 100`

## Solution 1

```Cpp

class Solution {
public:
    // Function to return the elements of a matrix in spiral order
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Get the number of rows and columns in the matrix
        int row = matrix.size();
        int col = matrix[0].size();
        
        // Calculate the total number of elements in the matrix
        int totalElements = row * col;
        
        // Initialize the boundaries of the matrix traversal
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;
        
        // Initialize a counter to keep track of the number of elements added to the result
        int count = 0;
        
        // Vector to store the result
        vector<int> result;

        // Loop until we've added all elements to the result
        while(count < totalElements) {

            // Traverse from left to right along the top boundary (Traverse Column Wise)
            for(int i = startingCol; i <= endingCol && count < totalElements; i++) {
                result.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++; // Move the top boundary down -> Here is the catch, Forget to update

            // Traverse from top to bottom along the right boundary (Traverse Row Wise)
            for(int i = startingRow; i <= endingRow && count < totalElements; i++) {
                result.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--; // Move the right boundary left -> Here is the catch, Forget to update

            // Traverse from right to left along the bottom boundary (Traverse Column Wise)
            for(int i = endingCol; i >= startingCol && count < totalElements; i--) {
                result.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--; // Move the bottom boundary up -> Here is the catch, Forget to update

            // Traverse from bottom to top along the left boundary (Traverse Row Wise)
            for(int i = endingRow; i >= startingRow && count < totalElements; i--) {
                result.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++; // Move the left boundary right -> Here is the catch, Forget to update
        }

        // Return the result vector containing the elements in spiral order
        return result;
    }
};

Time Complexity = O(row * col)
Space Complexity = O(row * col)
```