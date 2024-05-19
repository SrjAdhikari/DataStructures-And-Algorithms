//* ************************************************
//* 7. Reverse Integer -> Leet Code
//* ************************************************

// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Example 1:
// Input: x = 123
// Output: 321

// Example 2:
// Input: x = -123
// Output: -321

// Example 3:
// Input: x = 120
// Output: 21
 
// Constraints:
// -2^31 <= x <= 2^31 - 1


class Solution {
public:
    int reverse(int x) {
        int ans = 0;        // Decleare ans

        while(x){
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) 
                return 0;                   // check 32 bit range if ans is outside the range then return 0

            // ans = ans * 10 + x % 10;     // find remainder and add its to ans

            int lastDigit = x % 10;         // find remainder
            ans = ans * 10 + lastDigit;     // Add remainder to ans
            x = x / 10;                     // Update the value of x
        } 
        
        return ans;                         // if ans in the 32 bit range then return ans
    }
};