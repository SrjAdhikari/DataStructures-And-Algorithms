# Question : [GCD of two numbers - GFG](https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1)

Given two positive integers **a** and **b**, find **GCD** of a and b.

**Note**: Don't use the inbuilt gcd function

### Example 1

```
Input:
a = 3
b = 6
Output: 3
Explanation: GCD of 3 and 6 is 3
```

### Example 2

```
Input:
a = 1
b = 1
Output: 1
Explanation: GCD of 1 and 1 is 1
```

### Your task

You don't need to read input or print anything. Complete the function **gcd()** which takes two positive integers as input parameters and returns gcd of a and b as an integer.

```
Expected Time Complexity : O(log(min(a, b)))
Expected Space Compelxity : O(1)
```

### Constraints

`1 ≤ a, b ≤ 10^9`

## Solution

```Cpp

class Solution {
public:
    // Function to calculate the Greatest Common Divisor (GCD) of two numbers using Euclid's algorithm
    int gcd(int a, int b) {
        // Base case: If b is 0, the GCD is a
        if (b == 0) {
            return a;
        }
        // Recursive case: Call gcd with b and the remainder of a divided by b
        return gcd(b, a % b);
    }
};

Time Complexity = O(log(min(a, b)))
Space Complexity = O(log(min(a, b)))
```
