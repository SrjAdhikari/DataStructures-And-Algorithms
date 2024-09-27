# Question : [Reverse Integer - (LeetCode : 7)](https://leetcode.com/problems/reverse-integer/description/)

Given a signed 32-bit integer `x`, return `x` _with its digits reversed_. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0`.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned)**.

### Example 1

```
Input: x = 123
Output: 321
```

### Example 2

```
Input: x = -123
Output: -321
```

### Example 3

```
Input: x = 120
Output: 21
```

### Constraints

-   `-2^31 <= x <= 2^31 - 1`

## Solution

```Cpp
class Solution {
public:
    int reverse(int x) {
        int ans = 0;        // Variable 'ans' to store the reversed number.

        // Loop until 'x' becomes zero. This will extract each digit from the original number.
        while(x){
            // Check for overflow/underflow before multiplying 'ans' by 10.
            // If overflow or underflow is detected, return 0 as per the problem constraints.
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
                return 0;

            // Extract the last digit of 'x' by taking the remainder when divided by 10.
            int lastDigit = x % 10;

            // Add the last digit to 'ans'. Multiply 'ans' by 10 to shift its digits to the left,
            // and add the last digit (this effectively reverses the number).
            ans = ans * 10 + lastDigit;

            // Remove the last digit from 'x' by performing integer division by 10.
            // This reduces 'x' by one digit in each iteration.
            x = x / 10;
        }

        // After reversing all digits and checking for overflow, return the reversed number.
        return ans;
    }
};

Time Complexity = O(log₁₀(x))
Space Complexity = O(1)
```
