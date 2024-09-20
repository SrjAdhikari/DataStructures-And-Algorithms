# Question : [Interleave the First Half of the Queue with Second Half - GFG](https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1)

You are given a queue `Q` of `N` integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

### Example 1

```
Input:
N = 4
Q = {2,4,3,1}
Output:
{2,3,4,1}
Explanation:
After the mentioned rearrangement of the first half
and second half, our final queue will be {2,3,4,1}.
```

### Example 2

```
Input:
N = 2
Q = {3,5}
Output:
{3,5}
Explanation:
After the mentioned rearrangement of the first half
and second half, our final queue will be {3,5}.
```

### Your Task:

You don't need to read input or print anything. Your task is to complete the function `rearrangeQueue()` which takes a queue `Q` as input and returns the modified queue after the rearrangement.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
```

### Constraints

- `2 <= N <= 10^5`
- `1 <= Elements of Queue <= 10^3`
- Sum of N over all test cases doesn't exceeds 106

## Solution

```Cpp
class Solution {
public:
    vector<int> rearrangeQueue(queue<int> &q) {
        vector<int> ans;  // This will store the rearranged elements of the queue in interleaved fashion.
        queue<int> q2;    // A secondary queue used to store the first half of the original queue elements.

        // Determine the halfway point of the queue to divide it into two halves.
        int half = q.size() / 2;

        // Move the first half of the elements from the original queue (q) to the secondary queue (q2).
        while (half) {
            q2.push(q.front());     // Push the front element of q to q2.
            q.pop();                // Remove the front element from q.
            half--;                 // Decrease the half counter after transferring each element.
        }

        // Now, q contains the second half of the elements and q2 contains the first half.
        // The next loop interleaves the elements from both queues into the answer vector.
        while (!q.empty()) {
            ans.push_back(q2.front());  // Add the front element of q2 (from the first half) to the result.
            q2.pop();                   // Remove the element from q2.
            
            ans.push_back(q.front());   // Add the front element of q (from the second half) to the result.
            q.pop();                    // Remove the element from q.
        }

        // Return the interleaved result stored in the vector.
        return ans;  
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```