# Question : [Get min at pop - GFG](https://www.geeksforgeeks.org/problems/get-min-at-pop/1)

_Now, we'll try to solve a famous stack problem_.
You are given an array `A` of size `N`. You need to first push the elements of the array into a stack and then print minimum in the stack at each pop until stack becomes empty.

### Example 1

```
Input:
N = 5
A = {1 2 3 4 5}
Output:
1 1 1 1 1
Explanation:
After pushing elements to the stack,
the stack will be "top -> 5, 4, 3, 2, 1".
Now, start popping elements from the stack
popping 5: min in the stack is 1.popped 5
popping 4: min in the stack is 1. popped 4
popping 3: min in the stack is 1. popped 3
popping 2: min in the stack is 1. popped 2
popping 1: min in the stack is 1. popped 1
```

### Example 2

```
Input:
N = 7
A = {1 6 43 1 2 0 5}
Output:
0 0 1 1 1 1 1
Explanation:
After pushing the elements to the stack,
the stack will be 5->0->2->1->43->6->1.
Now, poping the elements from the stack:
popping 5: min in the stack is 0. popped 5
popping 0: min in the stack is 0. popped 0
popping 2: min in the stack is 1. popped 2
popping 1: min in the stack is 1. popped 1
popping 43: min in the stack is 1. popped 43
popping 6: min in the stack is 1. popped 6
popping 1: min in the stack is 1. popped 1.
```

### Your Task:

Since this is a function problem, you don't need to take any input. Just complete the provided functions `_push()` and `_getMinAtPop()`. The \_push() function takes an array as parameter, you need to push all elements of this array onto a stack and return the stack. The \_getMinAtPop() accepts a stack as a parameter which is returned by \_push() function and prints minimum in the stack at each pop separated by spaces.

```
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
```

### Constraints

-   `0 <= Ai <= 10^7`

## Solution

```Cpp
class Solution {
public:
    // Function to push all elements into the stack while keeping track of the minimum
    stack<int> _push(int arr[], int n) {
        // Stack to store elements and maintain minimum values
        stack<int> st;

        // Iterate through the array 'arr'
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                // If it's the first element, just push it onto the stack
                st.push(arr[i]);
            }
            else {
                // For subsequent elements, push the minimum of the current element and the top of the stack
                st.push(min(arr[i], st.top()));
            }
        }
        // Return the stack which now contains the minimum value at each level
        return st;
    }

    // Function to print minimum value in the stack each time while popping
    void _getMinAtPop(stack<int> s) {
        // Iterate while the stack is not empty
        while (!s.empty()) {
            // Print the top element of the stack
            cout << s.top() << " ";

            // Remove the top element from the stack
            s.pop();
        }
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
