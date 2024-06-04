//* ************************************************
//* 852. Peak Index in a Mountain Array
//* ************************************************

// An array arr is a mountain if the following properties hold:
// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.

// Example 1:
// Input: arr = [0,1,0]
// Output: 1

// Example 2:
// Input: arr = [0,2,1,0]
// Output: 1

// Example 3:
// Input: arr = [0,10,5,2]
// Output: 1

// Constraints:
// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        // Initialize the start and end pointers to the beginning and end of the array, respectively
        int start = 0;
        int end = arr.size() - 1;

        // Initialize peakIndex with -1, which will hold the index of the peak
        int peakIndex = -1;

        // Perform a binary search to find the peak element
        while (start <= end) {

            // Calculate the mid index to avoid potential overflow
            int mid = start + (end - start) / 2;

            // Check if the mid element is less than the next element
            if (arr[mid] < arr[mid + 1]) {
                // If true, it means the peak is to the right of mid, so update start
                start = mid + 1;
            } 
            else {
                // If false, it means mid could be the peak, update peakIndex
                peakIndex = mid;
                // Update end to narrow the search to the left part of mid
                end = mid - 1;
            }
        }
        
        // Return the index of the peak element
        return start;
    }
};

// Time Complexity = O(logn)
// Space Complexity = O(1)