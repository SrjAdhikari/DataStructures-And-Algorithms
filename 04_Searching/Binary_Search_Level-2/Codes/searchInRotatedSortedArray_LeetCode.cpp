//* ************************************************
//* 33. Search in Rotated Sorted Array
//* ************************************************

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Example 3:
// Input: nums = [1], target = 0
// Output: -1

// Constraints:
// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104


class Solution {
public:

    // Helper function to find the pivot index in a rotated sorted array
    int findPivotIndex(vector<int>& arr) {

        int n = arr.size();

        // Initialize the start and end pointers to the beginning and end of the array, respectively
        int start = 0;
        int end = n - 1;

        // Perform a binary search to find the pivot element
        while (start <= end) {

            // Calculate the mid index to avoid potential overflow
            int mid = start + (end - start) / 2;

            // Single Element -> Corner Case        
            if (start == end) 
                return start;

            // Check if mid element is less than the previous element
            if (mid - 1 >= 0 && arr[mid] < arr[mid - 1]) {
                // If true, mid-1 is the pivot
                return mid - 1;
            }
            // Check if mid element is greater than the next element
            else if (mid + 1 < n &&arr[mid] > arr[mid + 1]) {
                // If true, mid is the pivot
                return mid;
            }
            // If the start element is greater than mid element, pivot must be in the left part
            else if (arr[start] > arr[mid]) {
                end = mid - 1;
            }
            // Otherwise, pivot must be in the right part
            else {
                start = mid + 1;
            }
        }
        // If no pivot is found, return -1
        return -1;
    }   

    // Helper function to perform binary search
    int binarySearch(vector<int>& arr, int start, int end, int target){
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {

        // Find the pivot index in the rotated sorted array
        int pivotIndex = findPivotIndex(nums);
        int n = nums.size();
        int targetIndex = -1;

        // Check if the target is in the left sub-array
        if (target >= nums[0] && target <= nums[pivotIndex]) {
            targetIndex = binarySearch(nums, 0, pivotIndex, target);
        } 
        else {
            // Otherwise, search in the right sub-array
            targetIndex = binarySearch(nums, pivotIndex + 1, n - 1, target);
        }
        return targetIndex;
    }
};

// Time Complexity = O(logn)
// Space Complexity = O(1)