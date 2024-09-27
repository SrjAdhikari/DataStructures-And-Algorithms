# Question : [Set kth bit - GFG](https://www.geeksforgeeks.org/problems/set-kth-bit3724/1)

Given a number `N` and a value `K`. From the right, set the Kth bit in the binary representation of N. The position of Least Significant Bit(or last bit) is 0, the second last bit is 1 and so on.

### Example 1

```
Input:
N = 10
K = 2
Output:
14
Explanation:
Binary representation of the given number
10 is: 1 0 1 0, number of bits in the
binary reprsentation is 4. Thus 2nd bit
from right is 0. The number after changing
this bit to 1 is: 14(1 1 1 0).
```

### Example 2

```
Input:
N = 15
K = 3
Output:
15
Explanation:
The binary representation of the given
number 15 is: 1 1 1 1, number of bits
in the binary representation is 4. Thus
3rd bit from the right is 1. The number
after changing this bit to 1 is
15(1 1 1 1).
```

### Your Task

You don't need to read input or print anything. Your task is to complete the function `setKthBit()` which takes two integer N and K as input parameter and returns an integer after setting the K'th bit in N.

```
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
```

### Constraints

-   `1 <= n <= 10^9`
-   `0 <= K < X`, where `X` is the number of bits in the binary representation of `N`.

## Solution 1 : Brute Force Approach I

```Cpp
class Solution {
public:
    int setKthBit(int N, int K) {
        // Step 1: Create a mask with only the K-th bit set to 1.
        int mask = 1 << K;

        // Step 2: Perform a bitwise OR operation between the original number N and the mask.
        int ans = N | mask;

        // Step 3: Return the modified number, where the K-th bit is now set to 1.
        return ans;

        // Short hand solution
        // return N | (1 << K);
    }
};

Time Complexity = O(1)
Space Complexity = O(1)
```
