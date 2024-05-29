# Question : [Rotate Image - (LeetCode : 48)](https://leetcode.com/problems/rotate-image/description/)

You are given an `n x n` 2D `matrix` representing an image, rotate the image by **90** degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

### Example 1

![](https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg)

```plaintext
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```

### Example 2

![](https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg)

```plaintext
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

### Constraints

`n == matrix.length == matrix[i].length`

`1 <= n <= 20`

`-1000 <= matrix[i][j] <= 1000`


## Solution

```Cpp

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int row  = matrix.size();       // Get the number of rows in the matrix
        int col = matrix[0].size();     // Get the number of columns in the matrix

        // Step 1: Transpose Array
        for(int i = 0; i < row; i++) {
            for(int j = i + 1; j < col; j++) {
                swap(matrix[i][j], matrix[j][i]);   // Swap elements across the diagonal (transpose)
            }
        }

        // Step 2: Reverse array row-wise
        for(int i = 0; i < row; i++) {
            reverse(matrix[i].begin(), matrix[i].end());    // Reverse each row of the transposed matrix
        }
    }
};

Time Complexity = O(n^2)
Space Complexity = O(1)
```