# Question : [Next Greater Element in Circular Array - GFG](https://www.geeksforgeeks.org/problems/next-greater-element/1)

Given an circular array `arr[ ]` of size `n` having distinct elements, the task is to find the next greater element for each element of the array .

**Note** : The next greater element of an element in the array is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

### Example 1

```
Input: 
n = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3, 3 is 4, 2 is 4 and for 4? 
since it doesn't exist, it is -1.
```

### Example 2

```
Input: 
n = 5, arr[] = [6 8 0 1 3]
Output:
8 -1 1 3 6
Explanation:
In the array, the next larger element to 6 is 8, 
for 8 there is no larger elements hence it is -1, for 0 it is 1,
for 1 it is 3 and then 
for 3 there is 6.
```

### Your Task:

This is a `function` problem. You only need to complete the function `nextLargerElement()` that takes list of integers `arr[ ]` and n as input parameters and returns list of integers of length N denoting the next greater elements for all the corresponding elements in the input array.

```
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
```

### Constraints

-   `1 ≤ n ≤ 10^6`
-   `0 ≤ arri ≤ 10^18`

## Solution

```Cpp
class Solution {
public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n) {
        stack<int> st;                  // Stack to store indices of elements whose next greater element is not yet found
        vector<long long> ans(n, -1);   // Result vector initialized with -1 for all elements
        
        // Traverse the array twice (2 * n - 1 times) to simulate the circular array behavior
        for(int i = 0; i < 2 * n - 1; i++) {

            // While stack is not empty and the current element (arr[i % n]) is greater than the element at the index stored in st.top(),
            // we have found the next greater element for the element at st.top().
            while(!st.empty() && arr[st.top()] < arr[i % n]) {
                // Set the next greater element for arr[st.top()] to arr[i % n].
                ans[st.top()] = arr[i % n];

                // Remove the index from the stack as we have found its next greater element.
                st.pop();
            }

            // Push the current index (i % n) onto the stack to find its next greater element in future iterations.
            st.push(i % n);
        }
        
        // Return the result array which contains the next greater element for each element in the input array.
        return ans;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
