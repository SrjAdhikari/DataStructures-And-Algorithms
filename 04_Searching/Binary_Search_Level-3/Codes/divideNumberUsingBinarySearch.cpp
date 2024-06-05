//* **********************************************************************
    // Given two integers one is a dividend and the other is the divisor, we need to find the quotient when the dividend is divided by the divisor without the use of any ” / “ and ” % “ operators

    // Input: dividend = 10, divisor = 2
    // Output: 5
    // Explanation: 10/2 = 5.

    // Input: dividend = 10, divisor = 3
    // Output: 3
    // Explanation: 10/3 = 3.33333… which is truncated to 3.

    // Input: dividend = 10, divisor = -2
    // Output: -5
    // Explanation: 10/-2 = -5
//* **********************************************************************

#include<iostream>
using namespace std;

int getQuotient(int dividend, int divisor) {

    // Initialize the start and end pointers for binary search
    int start = 0;
    int end = dividend;
    int ans = -1; // Variable to store the quotient

    // Perform binary search to find the quotient
    while (start <= end) {
        
        // Calculate the mid value using bitwise right shift to avoid potential overflow
        int mid = start + ((end - start) >> 1);

        // Check if mid multiplied by divisor equals the dividend
        if (mid * divisor == dividend) {
            return mid; // If true, mid is the quotient
        }
        // If mid multiplied by divisor is less than the dividend, move to the right half
        else if (mid * divisor < dividend) {
            ans = mid; // Update ans with the current mid value
            start = mid + 1; // Move the start pointer to mid + 1
        }
        // If mid multiplied by divisor is greater than the dividend, move to the left half
        else {
            end = mid - 1; // Move the end pointer to mid - 1
        }
    }
    // Return the quotient
    return ans;
}


int main(){
    int dividend = 10;
    int divisor = -2;

    // Calculate the quotient using absolute values of dividend and divisor
    int ans = getQuotient(abs(dividend), abs(divisor));

    // Determine the sign of the result based on the original signs of dividend and divisor
    if ((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0)) {
        ans = -ans;
    }

    // Output the final result
    cout << "Final ans is : " << ans << endl;
    return 0;
}

// Time Complexity = O(logn)
// Space Complexity = O(1)