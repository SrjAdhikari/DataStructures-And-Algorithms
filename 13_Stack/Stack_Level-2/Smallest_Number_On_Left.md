# Question : [Smallest number on left - GFG](https://www.geeksforgeeks.org/problems/next-greater-element/1)

Given an array `a` of integers of length `n`, find the nearest smaller number for every element such that the smaller element is on left side.If no small element present on the left print -1.

### Example 1

```
Input: n = 3
a = {1, 6, 2}
Output: -1 1 1
Explaination: There is no number at the 
left of 1. Smaller number than 6 and 2 is 1.
```

### Example 2

```
Input: n = 6
a = {1, 5, 0, 3, 4, 5}
Output: -1 1 -1 0 3 4
Explaination: Upto 3 it is easy to see 
the smaller numbers. But for 4 the smaller 
numbers are 1, 0 and 3. But among them 3 
is closest. Similary for 5 it is 4.
```

### Your Task:

You do not need to read input or print anything. Your task is to complete the function `leftSmaller()` which takes n and a as input parameters and returns the list of smaller numbers.

```
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
```

### Constraints

-   `1 ≤ n ≤ 10000`
-   `0 ≤ a[i] ≤ 10^4`

## Solution

```Cpp
class Solution {
public:
    vector<int> leftSmaller(int n, int a[]) {
        // Initialize the result vector with -1. This means, by default, every element
        // has no smaller element on its left.
        vector<int> ans(n, -1);
        
        // Stack to store indices of array elements for which we are looking for the nearest smaller element on the left.
        stack<int> st;

        // Loop through the array from right to left.
        for(int i = n - 1; i >= 0; i--) {
            
            // While the stack is not empty, and the current element (a[i]) is smaller than
            // the element at the index stored at the top of the stack (a[st.top()]),
            // this means a[i] is the nearest smaller element to the left for a[st.top()].
            while(!st.empty() && a[i] < a[st.top()]) {
                // Set a[i] as the nearest smaller element for a[st.top()].
                ans[st.top()] = a[i];

                // Push the current index onto the stack to check if its left smaller element is found in future iterations.
                st.pop();
            }

            // Push the current index onto the stack to potentially find its nearest smaller element later.
            st.push(i);
        }

        // Return the result vector containing the nearest smaller elements on the left for each element.
        return ans;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
