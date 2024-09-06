# Question : [Make the array beautiful - GFG](https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1)

Given an array of negative and non-negative integers. You have to make the array beautiful. An array is beautiful if two adjacent integers, arr[i] and arr[i+1] are either negative or non-negative. And you can do the following operation any number of times until the array becomes beautiful.

-   If two adjacent integers are different i.e. one of them is negative and other is non-negative, remove them.

Return the beautiful array after performing the above operation.

**Note**:An empty array is also a beautiful array. There can be many adjacent integers which are different as stated above. So remove different adjacent integers as described above from `left to right`.

### Example 1

```
Input: 4 2 -2 1
Output: 4 1
Explanation: As at indices 1 and 2 , 2 and -2 have
different sign, they are removed. And the  the final
array is: 4 1.
```

### Example 2

```
Input: 2 -2 1 -1
Output: []
Explanation: As at indices 0 and 1, 2 and -2 have
different sign, so they are removed. Now the array
is 1 -1.Now 1 and -1 are also removed as they have
different sign. So the final array is empty.
```

### Your Task:

You don't need to read input or print anything. Your task is to complete the function `makeBeautiful()` which takes an array as an input parameter and returns an array.`

```
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
```

### Constraints

-   `1 <= size of the array <= 10^5`
-   `-10^5 <= arr[i] <= 10^5`

## Solution

```Cpp
class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        // Step 1: Create a stack to help filter elements based on conditions
        stack<int> st;

        // Step 2: Iterate through each element in the input array 'arr'
        for (int i = 0; i < arr.size(); i++) {
            // If the stack is empty, push the current element onto the stack
            if (st.empty())
                st.push(arr[i]);

            // If the current element is non-negative
            else if (arr[i] >= 0) {
                // Check the top element of the stack
                if (st.top() >= 0)  // If the top is also non-negative, push the current element
                    st.push(arr[i]);
                else  // Otherwise, pop the top element (opposite signs cancel each other out)
                    st.pop();
            }
            // If the current element is negative
            else {
                // Check the top element of the stack
                if (st.top() < 0)  // If the top is also negative, push the current element
                    st.push(arr[i]);
                else  // Otherwise, pop the top element (opposite signs cancel each other out)
                    st.pop();
            }
        }

        // Step 3: Transfer the remaining elements in the stack to the output vector 'ans' in reverse order
        vector<int> ans(st.size());     // Initialize a vector of the same size as the stack
        int i = st.size() - 1;          // Start filling the vector from the last index
        while (!st.empty()) {
            ans[i] = st.top();  // Set the i-th element of the vector to the top of the stack
            i--;                // Move to the previous index
            st.pop();           // Remove the top element from the stack
        }

        // Step 4: Return the resulting 'beautiful' array
        return ans;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
