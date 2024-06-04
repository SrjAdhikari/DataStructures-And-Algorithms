//* ************************************************
//* 69. Sqrt(x)
//* ************************************************

// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

// Example 1:
// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.

// Example 2:
// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

// Constraints:
// 0 <= x <= 231 - 1


class Solution {
public:
    int mySqrt(int x) {

        // Initialize the start and end pointers for binary search
        int start = 0;
        int end = x;
        int ans = 0;  // Variable to store the floor value of the square root

        // Perform binary search to find the square root
        while (start <= end) {
            // Calculate the mid value to avoid potential overflow
            long long int mid = start + (end - start) / 2;

            // If mid squared is exactly x, return mid as the square root
            if (mid * mid == x)
                return mid;

            // If mid squared is greater than x, search in the left half
            else if (mid * mid > x)
                end = mid - 1;

            // If mid squared is less than x, search in the right half
            // and update ans to mid (potential floor value of the square root)
            else {
                ans = mid;
                start = mid + 1;
            }
        }

        // Return the floor value of the square root
        return ans;
    }
};

// Time Complexity = O(logn)
// Space Complexity = O(1)