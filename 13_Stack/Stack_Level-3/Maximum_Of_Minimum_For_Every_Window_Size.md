# Question : [Maximum of minimum for every window size - GFG](https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1)

Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
**Note**: Window size varies from 1 to the size of the Array.

### Example 1

```
Input:
N = 7
arr[] = {10,20,30,50,10,70,30}
Output: 70 30 20 10 10 10 10
Explanation:
1.First element in output
indicates maximum of minimums of all
windows of size 1.
2.Minimums of windows of size 1 are {10},
 {20}, {30}, {50},{10}, {70} and {30}.
 Maximum of these minimums is 70.
3. Second element in output indicates
maximum of minimums of all windows of
size 2.
4. Minimums of windows of size 2
are {10}, {20}, {30}, {10}, {10}, and
{30}.
5. Maximum of these minimums is 30
Third element in output indicates
maximum of minimums of all windows of
size 3.
6. Minimums of windows of size 3
are {10}, {20}, {10}, {10} and {10}.
7.Maximum of these minimums is 20.
Similarly other elements of output are
computed.
```

### Example 2

```
Input:
N = 3
arr[] = {10,20,30}
Output: 30 20 10
Explanation: First element in output
indicates maximum of minimums of all
windows of size 1.Minimums of windows
of size 1 are {10} , {20} , {30}.
Maximum of these minimums are 30 and
similarly other outputs can be computed
```

### Your Task

The task is to complete the function `maxOfMin()` which takes the array arr[] and its size N as inputs and finds the maximum of minimum of every window size and returns an array containing the result.

```
Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)
```

### Constraints

-   `1 <= N <= 10^5`
-   `1 <= arr[i] <= 10^6`

## Solution 1

```Cpp
Brute-force Approach :

class Solution {
public:
    vector<int> maxOfMin(int arr[], int n) {
        // Create a result vector 'ans' initialized with zeros, where each index i
        // will store the maximum of minimums of all subarrays of length i + 1
        vector<int> ans(n, 0);

        // Outer loop to iterate over all possible lengths of subarrays (from 1 to n)
        for(int i = 0; i < n; i++) {
            // Inner loop to generate subarrays of length i + 1 (starting at each index j)
            for(int j = 0; j < n - i; j++) {
                // Initialize 'minimum' to a very large value (INT_MAX) to track the minimum element in the current subarray
                int minimum = INT_MAX;

                // Loop through the current subarray starting from index j
                // and having length i + 1 to find the minimum element in that subarray
                for(int k = j; k < j + i + 1; k++) {
                    // Update 'minimum' with the smallest element in the current subarray
                    minimum = min(minimum, arr[k]);
                }

                // Store the maximum of the minimums of all subarrays of length i + 1 in 'ans[i]'
                ans[i] = max(ans[i], minimum);
            }
        }

        // Return the vector containing the maximum of minimums for all subarray lengths
        return ans;
    }
};

Time Complexity = O(n^3)
Space Complexity = O(n)
```

## Solution 2

```Cpp
Optimise Approach :

class Solution {
public:
    vector<int> maxOfMin(int arr[], int n) {
        // Create a result vector 'ans' initialized with zeros, where each index i
        // will store the maximum of minimums of all subarrays of length i + 1
        vector<int> ans(n, 0);

        // Stack to store indices of elements in the array.
        // It will help us find the previous and next smaller elements efficiently.
        stack<int> st;

        // First loop: Find the maximum of minimums for all window sizes using a stack.
        for (int i = 0; i < n; i++) {
            // While the stack is not empty and the current element is smaller than
            // the element at the index stored at the top of the stack.
            while (!st.empty() && arr[st.top()] > arr[i]) {
                // Pop the index from the stack and get the value at that index.
                int index = st.top();
                st.pop();

                // If the stack is empty, it means the element at 'index' was the smallest
                // element in the range from the start to the current index 'i'.
                if (st.empty()) {
                    int range = i;                                      // The range is from index 0 to `i-1`, hence window size is `i`.
                    ans[range - 1] = max(ans[range - 1], arr[index]);   // Update maximum of minimums for this window size.
                }
                // If the stack is not empty, the range of the window is from the element next to `st.top()` to `i-1`.
                else {
                    int range = i - st.top() - 1;                       // Window size is `i - st.top()`.
                    ans[range - 1] = max(ans[range - 1], arr[index]);   // Update the maximum of minimums for this range.
                }
            }
            // Push the current index onto the stack.
            st.push(i);
        }

        // After the first loop, some elements may remain in the stack.
        // Process them as they are the minimum for windows that extend to the end of the array.
        while (!st.empty()) {
            // Pop the index from the stack and get the value at that index.
            int index = st.top();
            st.pop();

            // If the stack is empty, it means the element at 'index' was the smallest
            // element in the range from the start to the end of the array.
            if (st.empty()) {
                int range = n;                                      // Window size is `n`.
                ans[range - 1] = max(ans[range - 1], arr[index]);   // Update maximum of minimums for this window size.
            }
            // If the stack is not empty, the element at 'index' was the smallest
            // element in the range from the element next to the top of the stack
            // to the end of the array.
            else {
                int range = n - st.top() - 1;                       // Window size is `n - st.top()`.
                ans[range - 1] = max(ans[range - 1], arr[index]);   // Update the maximum of minimums for this range.
            }
        }

        // Update the result array to ensure that ans[i] contains the maximum of
        // the minimums of all subarrays of length i+1
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        // Return the result array where ans[i] gives the maximum of minimums for window size `i+1`.
        return ans;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
