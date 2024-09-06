# Question : [String Manipulation - GFG](https://www.geeksforgeeks.org/problems/string-manipulation3706/1)

Tom is a string freak. He has got sequences of words `arr[]` to manipulate. If in a sequence, two same words come together then Tom destroys each other. Find the number of words left in the sequence after this pairwise destruction.

### Example 1

```
Input: arr[] = ["ab", "aa", "aa", "bcd", "ab"]
Output: 3
Explanation: After the first iteration, we'll have: ab bcd ab. We can't further destroy more strings and hence we stop and the result is 3.
```

### Example 2

```
Input: arr[] = ["tom", "jerry", "jerry", "tom"]
Output: 0
Explanation: After the first iteration, we'll have: tom tom. After the second iteration: 'empty-array' .Hence, the result is 0.
```

```
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
```

### Constraints

-   `1 ≤ arr.size() ≤10^6`
-   `1 ≤ |arri| ≤ 50`

## Solution

```Cpp
class Solution {
public:
    int removeConsecutiveSame(vector<string>& arr) {
        // Step 1: Create a stack to store strings from the array 'arr'
        stack<string> st;

        // Step 2: Iterate through each element of the array 'arr'
        for (int i = 0; i < arr.size(); i++) {
            if (st.empty()) {
                // If the stack is empty, push the current string onto the stack
                st.push(arr[i]);
            }
            else if (arr[i] != st.top()) {
                // If the current string is different from the top of the stack, push it
                st.push(arr[i]);
            }
            else {
                // If the current string is the same as the top of the stack, pop the top element
                // This removes the consecutive duplicate
                st.pop();
            }
        }

        // Step 3: Return the size of the stack, which represents the remaining elements
        // after removing consecutive duplicates
        return st.size();
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
