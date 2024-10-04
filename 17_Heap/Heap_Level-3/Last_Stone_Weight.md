# Question : [Last Stone Weight - (LeetCode : 1046)](https://leetcode.com/problems/last-stone-weight/description/)

You are given an array of integers `stones` where `stones[i]` is the weight of the `ith` stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the **heaviest two stones** have weights `x` and `y` with `x <= y`. The result of this smash is:

- If `x == y`, both stones are destroyed, and
- If `x != y`, the stone of weight `x` is destroyed, and the stone of weight `y` has new weight `y - x`.

At the end of the game, there is **at most one** stone left.

Return *the weight of the last remaining stone*. If there are no stones left, return `0`.

### Example 1

```
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
```

### Example 2

```
Input: stones = [1]
Output: 1
```

### Constraints

-   `1 <= stones.length <= 30`
-   `1 <= stones[i] <= 1000`

## Solution

```Cpp
class Solution {
public:
    // Function to return the last remaining stone's weight after smashing.
    int lastStoneWeight(vector<int>& stones) {
        // Create a max-heap (priority queue) to store the stone weights.
        priority_queue<int> pq;

        // Push all the stone weights into the priority queue (max-heap).
        for (int stone : stones) {
            pq.push(stone);
        }

        // Continue the process until there is one or no stone left.
        while (pq.size() > 1) {
            // Get the two heaviest stones from the heap.
            int first = pq.top();       // The heaviest stone.
            pq.pop();                   // Remove the heaviest stone.

            int second = pq.top();      // The second heaviest stone.
            pq.pop();                   // Remove the second heaviest stone.

            // Calculate the result of the collision between the two stones.
            // Subtract the weight of the second stone from the first.
            first -= second;

            // If there is any weight left after the collision, push it back into the heap.
            if (first > 0) {
                pq.push(first);
            }
        }

        // If there are no stones left, return 0; otherwise, return the last remaining stone.
        // pq.top() gives the weight of the last remaining stone.
        return pq.empty() ? 0 : pq.top();
    }
};

Time Complexity = O(NlogN)
Space Complexity = O(N)
```