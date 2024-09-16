# Question : [Reverse First K elements of Queue - GFG](https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1)

Given an integer `K` and a queue of integers, we need to reverse the order of the first `K` elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.
- enqueue(x) : Add an item x to rear of queue
- dequeue() : Remove an item from front of queue
- size() : Returns number of elements in queue.
- front() : Finds front item.

**Note**: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

### Example 1

```
Input:
5 3
1 2 3 4 5
Output: 
3 2 1 4 5
Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.
```

### Example 2

```
Input:
4 4
4 3 2 1
Output: 
1 2 3 4
Explanation: 
After reversing the given
input from the 4th position the resultant
output will be 1 2 3 4.
```

### Your Task:

Complete the provided function `modifyQueue()` that takes `queue` and `K` as parameters and returns a modified queue. The printing is done automatically by the driver code.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)
```

### Constraints

`1 <= K <= N <= 10^5`

## Solution

```Cpp
class Solution {
public:

    // Steps:
    // 1. Push the first 'k' elements of the queue into a stack (this reverses them).
    // 2. Store the remaining size of the queue (n - k).
    // 3. Pop elements from the stack and push them back into the queue (reversed order).
    // 4. Move the remaining 'n-k' elements from the front of the queue to the back to maintain their original order.

    // Function to reverse the first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> st;  // Stack to reverse the first k elements
        
        // Step 1: Push the first k elements of the queue into the stack
        while(k) {
            st.push(q.front()); // Push the front element into the stack
            q.pop();            // Remove the front element from the queue
            k--;
        }
        
        // Step 2: Store the size of the remaining elements in the queue
        int size = q.size();  // This is the number of elements left in the queue after removing the first k elements
        
        // Step 3: Pop all elements from the stack and push them back to the queue
        // This will reverse the order of the first k elements
        while(!st.empty()) {
            q.push(st.top()); // Push the top element from the stack to the queue
            st.pop();         // Remove the top element from the stack
        }
        
        // Step 4: Move the remaining elements (after the first k) to the back of the queue
        // These elements were not affected and should remain in their original order
        while(size) {
            q.push(q.front()); // Push the front element to the back of the queue
            q.pop();           // Remove the front element from the queue
            size--;
        }
        
        return q; // Return the modified queue
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```