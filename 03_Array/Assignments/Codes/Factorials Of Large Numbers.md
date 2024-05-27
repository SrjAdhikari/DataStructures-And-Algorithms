# Question : [Factorials Of Large Numbers - GFG](https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1)

Given an integer N, find its factorial. return a list of integers denoting the digits that make up the factorial of N.

### Example 1

```plaintext
Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
```

### Example 2

```plaintext
Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
```

### Your Task

You don't need to read input or print anything. Complete the function factorial() that takes integer N as input parameter and returns a list of integers denoting the digits that make up the factorial of N.

```plaintext
Expected Time Complexity : O(N^2)
Expected Auxilliary Space : O(1)
```

### Constraints

`1 ≤ N ≤ 1000`

## Solution 1

```Cpp
class Solution {
public:
    vector<int> factorial(int N) {
        vector<int> ans;  // Vector to store the digits of the factorial
        ans.push_back(1); // Initialize the vector with the first factorial value (1!)
        int carry = 0;    // Variable to store the carry during multiplication

        // Loop through numbers from 2 to N to calculate the factorial
        for (int i = 2; i <= N; i++) {
            // Multiply each digit in the ans vector by the current number i
            for (int j = 0; j < ans.size(); j++) {
                int product = ans[j] * i + carry; // Calculate the product and add carry
                ans[j] = product % 10;            // Store the last digit of the product in ans
                carry = product / 10;             // Update the carry
            }

            // Handle any remaining carry
            while (carry) {
                ans.push_back(carry % 10); // Add the last digit of carry to ans
                carry /= 10;               // Update the carry by removing the last digit
            }
        }

        // Reverse the vector to get the digits in the correct order
        reverse(ans.begin(), ans.end());
        return ans; // Return the result as a vector of digits
    }
};

Time Complexity = O(N^2log(N))
Space Complexity = O(Nlog(N))
```