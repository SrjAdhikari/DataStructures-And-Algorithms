//* ************************************************
//* 34. Find First and Last Position of Element in Sorted Array
//* ************************************************

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109


class Solution {
public:

    // Function to find the first occurrence of a target element in a sorted array
    int findFirstOccurrence(vector<int>& arr, int target) {
        int start = 0;                 // Initialize start index
        int end = arr.size() - 1;      // Initialize end index
        int firstOccurrence = -1;      // Initialize the result variable

        // Loop until the search space is exhausted
        while (start <= end) {
            
            // Calculate the mid element index
            int mid = start + (end - start) / 2;  

            // Check if the target is present at mid
            if (arr[mid] == target) {
                firstOccurrence = mid;      // Update the first occurrence index
                end = mid - 1;              // Continue to search in the left half
            }
            // If target is greater, ignore the left half
            else if (arr[mid] < target) {
                start = mid + 1;
            }
            // If target is smaller, ignore the right half
            else {
                end = mid - 1;
            }
        }
        // Return the first occurrence index, or -1 if not found
        return firstOccurrence;
    }


    // Function to find the last occurrence of a target element in a sorted array
    int findLastOccurrence(vector<int>& arr, int target) {
        int start = 0;                 // Initialize start index
        int end = arr.size() - 1;      // Initialize end index
        int lastOccurrence = -1;       // Initialize the result variable

        // Loop until the search space is exhausted
        while (start <= end) {

            // Calculate the mid element index
            int mid = start + (end - start) / 2;  

            // Check if the target is present at mid
            if (arr[mid] == target) {
                lastOccurrence = mid;   // Update the last occurrence index
                start = mid + 1;        // Continue to search in the right half
            }
            // If target is greater, ignore the left half
            else if (arr[mid] < target) {
                start = mid + 1;
            }
            // If target is smaller, ignore the right half
            else {
                end = mid - 1;
            }
        }
        // Return the last occurrence index, or -1 if not found
        return lastOccurrence;
    }


    // Function to search for the range of occurrences of a target element in a sorted array
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> result(2); // Initialize a vector to store the result, with size 2

        // Find the first occurrence of the target in the array
        int firstOccur = findFirstOccurrence(nums, target);

        // Find the last occurrence of the target in the array
        int lastOccur = findLastOccurrence(nums, target);

        // Store the indices of the first and last occurrences in the result vector
        result[0] = firstOccur;
        result[1] = lastOccur;

        // Return the result vector containing the range of occurrences
        return result;
    }
};

// Time Complexity = O(logn)
// Space Complexity = O(1)