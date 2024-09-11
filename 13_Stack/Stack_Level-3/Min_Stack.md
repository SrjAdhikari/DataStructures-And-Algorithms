# Question : [Min Stack - (LeetCode : 155)](https://leetcode.com/problems/min-stack/description/)

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:

-   `MinStack()` initializes the stack object.
-   `void push(int val)` pushes the element `val` onto the stack.
-   `void pop()` removes the element on the top of the stack.
-   `int top()` gets the top element of the stack.
-   `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with `O(1)` time complexity for each function.

### Example 1

```
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

### Constraints

-   `-2^31 <= val <= 2^31 - 1`
-   Methods `pop`, `top` and `getMin` operations will always be called on **non-empty** stacks.
-   At most `3 * 104` calls will be made to `push`, `pop`, `top`, and `getMin`.

## Solution

```Cpp
class MinStack {
public:
    // Stack to store pairs of values and the minimum value up to that point
    stack<pair<int, int>> st;

    // Pushes a new value onto the stack
    void push(int val) {
        if (st.empty()) {
            // If the stack is empty, push the value with itself as the minimum
            st.push({val, val});
        } else {
            // Otherwise, push the value along with the minimum of the current value and the top element's minimum
            st.push({val, min(val, st.top().second)});
        }
    }

    // Removes the top element from the stack
    void pop() {
        // Simply pop the top element from the stack
        st.pop();
    }

    // Returns the top value of the stack
    int top() {
        // Return the first element of the top pair, which is the value
        return st.top().first;
    }

    // Returns the minimum value in the stack
    int getMin() {
        // Return the second element of the top pair, which is the minimum value
        return st.top().second;
    }
};

Time Complexity = O(1)
Space Complexity = O(n)
```
