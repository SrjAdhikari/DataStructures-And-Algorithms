# Question : [Implement Queue using Stacks - (LeetCode : 232)](https://leetcode.com/problems/implement-queue-using-stacks/description/)

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `peek`, `pop`, and `empty`).

Implement the `MyQueue` class:
- `void push(int x)` Pushes element x to the back of the queue.
- `int pop()` Removes the element from the front of the queue and returns it.
- `int peek()` Returns the element at the front of the queue.
- `boolean empty()` Returns `true` if the queue is empty, `false` otherwise.

### Notes
- You must use only standard operations of a stack, which means only `push to top`, `peek/pop from top`, `size`, and `is empty` operations are valid.

- Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

### Example 1

```
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
```

### Constraints

-   `1 <= x <= 9`
-   At most `100` calls will be made to `push`, `pop`, `peek`, and `empty`.
-   All the calls to `pop` and `peek` are valid.

**Follow-up**: Can you implement the queue such that each operation is amortized `O(1)` time complexity? In other words, performing `n` operations will take overall `O(n)` time even if one of those operations may take longer.

## Solution

```Cpp
class MyQueue {
public:
    stack<int> s1;　　// Stack s1: Used for pushing elements.
    stack<int> s2;　　// Stack s2: Used for popping elements.

    // Constructor to initialize the queue.
    MyQueue() {
        // No need for any specific initialization as we're using default stack implementations.
    }

    // Push element x to the back of the queue.
    void push(int x) {
        // Always Push the new element onto s1.
        s1.push(x);
    }

    // Removes the element from the front of the queue and returns it.
    int pop() {
        // If both stacks are empty, the queue is empty, return 0.
        if (empty())
            return 0;

        // If s2 is not empty, it means the elements are already in reverse order 
        // and the top of s2 is the front of the queue.
        else if (!s2.empty()) {
            int element = s2.top();   // Retrieve the front element.
            s2.pop();                 // Remove the element from s2.
            return element;           // Return the front element.
        }
        // If s2 is empty, but s1 is not, we need to reverse the order of elements in s1
        // to simulate queue behavior (FIFO). We do this by transferring all elements
        // from s1 to s2.
        else {
            while (!s1.empty()) {
                s2.push(s1.top());   // Move the top element of s1 to s2.
                s1.pop();            // Remove the element from s1.
            }
            int element = s2.top();  // Retrieve the front element after transfer.
            s2.pop();                // Remove the element from s2.
            return element;          // Return the front element.
        }
    }

    // Returns the front element of the queue without removing it.
    int peek() {
        // If both stacks are empty, the queue is empty, return 0.
        if (empty()) {
            return 0;
        }
        // If s2 is not empty, the top of s2 is the front element of the queue.
        else if (!s2.empty()) {
            return s2.top();         // Return the front element.
        }
        // If s2 is empty, but s1 is not, we need to reverse the order of elements in s1
        // by transferring them to s2, similar to the pop operation.
        else {
            while (!s1.empty()) {
                s2.push(s1.top());   // Move the top element of s1 to s2.
                s1.pop();            // Remove the element from s1.
            }
            return s2.top();         // Return the front element after transfer.
        }
    }
    
    // Checks whether the queue is empty.
    bool empty() {
        // The queue is empty only if both stacks (s1 and s2) are empty.
        return (s1.empty() && s2.empty());
    }
};

Time Complexity = O(1)
Space Complexity = O(N)
```