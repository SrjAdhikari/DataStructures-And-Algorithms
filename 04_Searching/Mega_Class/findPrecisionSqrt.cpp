#include<iostream>
using namespace std;

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


// Function to compute the square root of a number with higher precision
double myPrecisionSqrt(int num){
    // Call to another function 'mySqrt' that provides an initial approximation of the square root
    double sqrt = mySqrt(num);
    int precision = 5;      // Define the desired precision level (number of decimal places)
    double step = 0.1;      // Initial step size for refining the square root

    // Loop to refine the square root approximation to the desired precision level
    while(precision--){

        double j = sqrt;    // Start refining from the current approximation of the square root
        // Increment 'j' until 'j * j' exceeds 'num'

        while(j * j <= num){
            sqrt = j;       // Update the square root approximation
            j += step;      // Increase 'j' by the current step size
        }
        step /= 10;         // Decrease the step size by a factor of 10 for finer adjustments
    }
    return sqrt;            // Return the refined square root value
}


int main() {
    int num = 63;
    double precisionSqrt = myPrecisionSqrt(num);

    cout << "Precision square root is : " << precisionSqrt << endl;

    return 0;
}

// Time Complexity = O(logn) + O(precision)
// Space Complexity = O(1)