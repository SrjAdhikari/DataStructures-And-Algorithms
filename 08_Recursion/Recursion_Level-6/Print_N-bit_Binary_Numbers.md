# Question : [Print N-bit binary numbers having more 1s than 0s - GFG](https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1)

Given a positive integer **n**. Your task is to generate a string list of all **n-bit binary numbers** where, for any prefix of the number, there are **more or an equal** number of 1's than 0's. The numbers should be sorted in **decreasing order of magnitude**.

### Example 1

```
Input:
n = 2
Output:
{"11", "10"}
Explanation: Valid numbers are those where each prefix has more 1s than 0s:
11: all its prefixes (1 and 11) have more 1s than 0s.
10: all its prefixes (1 and 10) have more 1s than 0s.
So, the output is "11, 10".
```

### Example 2

```
Input:
n = 3
Output:
{"111", "110", "101"}
Explanation: Valid numbers are those where each prefix has more 1s than 0s.
111: all its prefixes (1, 11, and 111) have more 1s than 0s.
110: all its prefixes (1, 11, and 110) have more 1s than 0s.
101: all its prefixes (1, 10, and 101) have more 1s than 0s.
So, the output is "111, 110, 101".
```

### User Task:

Your task is to complete the function **NBitBinary()** which takes a single integer **n** as input and returns the **list of strings in decreasing order**. You need not take any input or print anything.

```
Expected Time Complexity: O(|2^n|)
Expected Auxiliary Space: O(2^n)
```

### Constraints

`1 <= n <= 15`

## Solution

```Cpp
class Solution {
public:
    // Recursive function to generate all valid n-bit binary numbers
    // where the number of 1's is always greater than or equal to the number of 0's in any prefix
    void findNumbers(int n, vector<string>& ans, string& temp, int zeroCount, int oneCount) {
        // Base case: When the length of the current binary string equals n
        if (temp.size() == n) {
            ans.push_back(temp); // Add the valid binary string to the result list
            return;
        }

        // Option to add '1' to the string
        temp.push_back('1'); // Append '1' to the current binary string

        // Recursively call findNumbers with incremented count of '1'
        findNumbers(n, ans, temp, zeroCount, oneCount + 1);

        temp.pop_back(); // Backtrack: remove the last character ('1') to explore other possibilities

        // Option to add '0' to the string, only if the number of '0's is less than the number of '1's
        // This ensures that every prefix of the string has at least as many '1's as '0's
        if (zeroCount < oneCount) {
            temp.push_back('0'); // Append '0' to the current binary string

            // Recursively call findNumbers with incremented count of '0'
            findNumbers(n, ans, temp, zeroCount + 1, oneCount);

            temp.pop_back(); // Backtrack: remove the last character ('0') to explore other possibilities
        }
    }

    // Function to generate all valid n-bit binary numbers in decreasing order of magnitude
    vector<string> NBitBinary(int n) {
        vector<string> ans;                 // Vector to store all valid n-bit binary strings
        string temp;                        // String to build the current binary number
        findNumbers(n, ans, temp, 0, 0);    // Start the process with an empty string and zero counts for '0's and '1's

        return ans;                         // Return the sorted list of valid binary strings
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n + 2^n)
```
