# Question : [Insert an Element at the Bottom of a Stack - GFG](https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1)

You are given a stack `st` of `n` integers and an element `x`. You have to insert `x` at the bottom of the given stack.

**Note**: Everywhere in this problem, the bottommost element of the stack is shown first while priniting the stack.

### Example 1

```
Input:
n = 5
x = 2
st = {4,3,2,1,8}
Output:
{2,4,3,2,1,8}
Explanation:
After insertion of 2, the final stack will be {2,4,3,2,1,8}.
```

### Example 2

```
Input:
n = 3
x = 4
st = {5,3,1}
Output:
{4,5,3,1}
Explanation:
After insertion of 4, the final stack will be {4,5,3,1}.
```

### Your Task:

You don't need to read input or print anything. Your task is to complete the function `insertAtBottom()` which takes a stack `st` and an integer `x` as inputs and returns the modified stack after insertion.

```
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
```

### Constraints

-   `1 <= n <= 10^5`
-   `0 <= x, elements of stack <= 10^9`

## Solution

```Cpp
class Solution {
public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        // Step 1: Create a temporary stack to hold the elements
        stack<int> temp;

        // Step 2: Transfer all elements from the original stack 'st' to the temporary stack 'temp'
        // This is done to reach the bottom of 'st'
        while (!st.empty()) {
            temp.push(st.top());  // Push the top element of 'st' onto 'temp'
            st.pop();             // Pop the top element from 'st'
        }

        // At this point, 'st' is empty and all its elements are in 'temp' in reverse order

        // Step 3: Insert the new element 'x' at the bottom of the original stack 'st'
        st.push(x);  // Since 'st' is empty, pushing 'x' places it at the bottom

        // Step 4: Transfer all elements from 'temp' back to the original stack 'st'
        // This restores the original order of elements on top of the newly inserted element 'x'
        while (!temp.empty()) {
            st.push(temp.top());  // Push the top element of 'temp' back to 'st'
            temp.pop();           // Pop the top element from 'temp'
        }

        // Step 5: Return the modified stack
        return st;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
