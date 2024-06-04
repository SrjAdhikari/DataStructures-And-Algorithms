//* ************************************************
//* 74. Search a 2D Matrix
//* ************************************************

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Get the number of rows and columns in the matrix
        int row = matrix.size();
        int col = matrix[0].size();

        // Calculate the total number of elements in the matrix
        int totalElement = row * col;

        // Initialize the start and end pointers for binary search
        int start = 0;
        int end = totalElement - 1;

        // Perform binary search on the matrix
        while (start <= end) {

            // Calculate the mid index to avoid potential overflow
            int mid = start + (end - start) / 2;
            
            // Convert mid index into row and column indices
            int rowIndex = mid / col;
            int colIndex = mid % col;

            // Get the current number at the mid index
            int currentNum = matrix[rowIndex][colIndex];

            // Check if the current number is equal to the target
            if (currentNum == target) {
                return true;
            }
            // If the current number is greater than the target, search in the left half
            else if (currentNum > target) {
                end = mid - 1;
            }
            // If the current number is less than the target, search in the right half
            else {
                start = mid + 1;
            }
        }
        // If the target is not found, return false
        return false;
    }
};

// Time Complexity = O(log(row * col))
// Space Complexity = O(1)