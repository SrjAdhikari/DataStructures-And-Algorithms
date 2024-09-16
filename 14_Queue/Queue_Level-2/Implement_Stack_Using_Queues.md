# Question : [Implement Stack using Queues - (LeetCode : 225)](https://leetcode.com/problems/implement-stack-using-queues/description/)

Implement a first in first out (FIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (`push`, `top`, `pop`, and `empty`).

Implement the `MyStack` class:
- `void push(int x)` Pushes element x to the top of the stack.
- `int pop()` Removes the element on the top of the stack and returns it.
- `int top()` Returns the element on the top of the stack.
- `boolean empty()` Returns `true` if the stack is empty, `false` otherwise.

### Notes
- You must use **only** standard operations of a queue, which means only `push to back`, `peek/pop from front`, `size`, and `is empty` operations are valid.

- Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

### Example 1

```
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
```

### Constraints

-   `1 <= x <= 9`
-   At most `100` calls will be made to `push`, `pop`, `top`, and `empty`.
-   All the calls to `pop` and `top` are valid.

**Follow-up**: Can you implement the stack using only one queue?

## Solution 1 : Using 2 Queues

```Cpp

class MyStack {
public:
    // Two queues are used to implement stack operations
    queue<int> q1;
    queue<int> q2;
    
    // Constructor: Initializes two empty queues
    MyStack() {
        // No specific initialization needed
    }

    // Checks whether the stack is empty
    bool empty() {
        // Stack is empty if both queues are empty
        return (q1.empty() && q2.empty());
    }

    // Pushes element x onto the stack
    void push(int x) {
        // If both queues are empty, this is the first element
        // We can use either queue, here we use q1
        if (empty()) {
            q1.push(x);
        }
        // If q1 is empty, push the element into q2
        else if (q1.empty()) {
            q2.push(x);
        }
        // Otherwise, push the element into q1
        else {
            q1.push(x);
        }
    }

    // Removes and returns the element on the top of the stack
    int pop() {
        // If the stack is empty, return 0 (or any other error code)
        if (empty()) {
            return 0;
        }

        // If q1 is empty, the elements are in q2
        if (q1.empty()) {
            // Move all elements from q2 to q1 except the last one
            while (q2.size() > 1) {
                q1.push(q2.front());  // Move front element of q2 to q1
                q2.pop();             // Remove the front element from q2
            }
            // The last element in q2 is the top of the stack
            int element = q2.front(); // Get the top element
            q2.pop();                 // Remove the element from q2
            return element;
        }
        // If q2 is empty, the elements are in q1
        else {
            // Move all elements from q1 to q2 except the last one
            while (q1.size() > 1) {
                q2.push(q1.front());  // Move front element of q1 to q2
                q1.pop();             // Remove the front element from q1
            }
            // The last element in q1 is the top of the stack
            int element = q1.front(); // Get the top element
            q1.pop();                 // Remove the element from q1
            return element;
        }
    }

    // Returns the element on the top of the stack without removing it
    int top() {
        // If the stack is empty, return 0 (or any other error code)
        if (empty()) {
            return 0;
        }

        // If q1 is empty, the elements are in q2
        if (q1.empty()) {
            // Return the last element in q2
            return q2.back();
        }
        // If q2 is empty, the elements are in q1
        else {
            // Return the last element in q1
            return q1.back();
        }
    }
};

Time Complexity = O(1)
Space Complexity = O(N)
```

## Solution 2 : Using Single Queue

```Cpp

class MyStack {
public:
    // A single queue used to implement stack operations
    queue<int> q;

    // Constructor: Initializes an empty queue
    MyStack() {
        // No special initialization needed beyond default construction
    }

    // Pushes an element x onto the stack
    void push(int x) {
        q.push(x);             // Enqueue the new element
        int size = q.size();   // Get the current size of the queue
        
        // Rotate the queue to make the newly added element the front of the queue
        while (size > 1) {
            q.push(q.front()); // Move the front element to the back of the queue
            q.pop();           // Remove the front element
            size--;            // Decrease the size
        }
        // After the loop, the newly added element is now at the front of the queue
    }

    // Removes and returns the element on the top of the stack
    int pop() {
        // Check if the stack is empty
        if (empty()) {
            return -1;
        }

        int element = q.front();  // Get the element at the front (top of the stack)
        q.pop();                  // Remove the element from the queue
        return element;           // Return the removed element
    }

    // Returns the element on the top of the stack without removing it
    int top() {
        // Check if the stack is empty
        if (empty()) {
            return -1;
        }

        // Return the element at the front of the queue (top of the stack)
        return q.front();
    }

    // Checks whether the stack is empty
    bool empty() {
        // Return true if the queue is empty, meaning the stack is also empty
        return q.empty();
    }
};

Time Complexity = O(1)
Space Complexity = O(N)
```