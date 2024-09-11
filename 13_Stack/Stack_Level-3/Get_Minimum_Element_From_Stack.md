# Question : [Get minimum element from stack - GFG](https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1)

You are given `N` operations and your task is to Implement a Stack in which you can get a minimum element in O(1) time.

### Example

```
Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()
Output: 2 1
Explanation: In the first test case for
query
push(2)  Insert 2 into the stack.
         The stack will be {2}
push(3)  Insert 3 into the stack.
         The stack will be {2 3}
pop()    Remove top element from stack
         Poped element will be 3 the
         stack will be {2}
getMin() Return the minimum element
         min element will be 2
push(1)  Insert 1 into the stack.
         The stack will be {2 1}
getMin() Return the minimum element
         min element will be 1
```

### Your Task

You are required to complete the three methods `push()` which takes one argument an integer `'x'` to be pushed into the stack, `pop()` which returns an integer popped out from the stack, and `getMin()` which returns the min element from the stack. (-1 will be returned if for `pop() and getMin()` the stack is empty.)

```
Expected Time Complexity: O(1) for all the 3 methods.
Expected Auxiliary Space: O(1) for all the 3 methods.
```

### Constraints

-   `1 <= Number of queries <= 100`
-   `1 <= values of the stack <= 100`

## Solution 1

```Cpp
class Solution {
    stack<pair<int, int>> st;   // Stack to store pairs of (element, minimum at the time of insertion)
    public:
        // Function to return the minimum element from the stack
        int getMin() {
            // If the stack is empty, return -1 indicating there is no element
            if (st.empty())
                return -1;
            else
                // Return the second value of the top pair, which stores the minimum element
                return st.top().second;
        }

        // Function to pop the top element from the stack
        int pop() {
            // If the stack is empty, return -1 indicating there is no element to pop
            if (st.empty())
                return -1;

            // Retrieve the top element (the first value of the pair)
            int popped = st.top().first;

            // Remove the top element from the stack
            st.pop();

            // Return the popped element
            return popped;
        }

        // Function to push an element 'x' into the stack
        void push(int x) {
            // If the stack is empty, push the pair (x, x)
            // Here, x is both the element and the minimum because it's the only element
            if (st.empty())
                st.push({x, x});
            else
                // Otherwise, Push the element x, and update the minimum by comparing x with the current minimum (st.top().second)
                // The second value is the minimum of the current element and the current minimum
                st.push({x, min(x, st.top().second)});
        }
};

Time Complexity = O(1)
Space Complexity = O(n)
```

## Solution 2

```Cpp
class Solution {
    stack<int> s;   // Stack to store the elements and minimums in a single value
    public:
        // Function to return the minimum element from the stack
        int getMin() {
            // If the stack is empty, return -1 (indicating there is no minimum since no elements exist)
            if(s.empty())
                return -1;
            else
                // The minimum value is encoded in each element of the stack.
                // We retrieve the minimum by using the modulo operation.
                // Since the elements are stored in the form `x * 101 + min`,
                // taking `s.top() % 101` gives us the `min` part of the pair.
                return s.top() % 101;
        }

        // Function to pop the top element from the stack
        int pop() {
            // If the stack is empty, return -1 (no elements to pop)
            if(s.empty())
                return -1;

            // The actual element that was pushed onto the stack is encoded with the minimum
            // To retrieve the actual value, we divide the top element by 101.
            // This works because the value was originally stored as `x * 101 + min`,
            // where `x` is the original value, and dividing by 101 recovers `x`.
            int popped = s.top() / 101;

            // Remove the top element from the stack after extracting the value
            s.pop();

            // Return the popped value
            return popped;
        }

        // Function to push an element 'x' into the stack
        void push(int x) {
            // If the stack is empty, it means `x` is the first element being pushed
            // Since this is the only element, it is both the element and the minimum value.
            // The element is encoded in the form `x * 101 + x`, where the second `x` represents the minimum (because it is the only element).
            if(s.empty()) {
                s.push(x * 101 + x);
            }
            else {
                // If the stack is not empty, we need to maintain the minimum element encountered so far.
                // The `min` function compares the current element `x` with the minimum of the previous stack state (stored as `s.top() % 101`).
                // We store both the element `x` and the updated minimum in the stack by encoding them as `x * 101 + min(x, current_min)`.
                // Here, `x` is the element and `min(x, current_min)` ensures that the new minimum is stored alongside the element.
                s.push(x * 101 + min(s.top() % 101, x));
            }
        }
};

Time Complexity = O(1)
Space Complexity = O(1)
```
