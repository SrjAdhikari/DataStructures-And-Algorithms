# Question : [Minimum Cost of ropes - GFG](https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1)

Given an array `arr` containing the lengths of the different ropes, we need to connect these ropes to form one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost. 

### Example 1

```
Input: arr[] = [4, 3, 2, 6]
Output: 29
Explanation: We can connect the ropes in following ways.
1. First connect ropes of lengths 2 and 3. Which makes the array [4, 5, 6]. 
Cost of this operation 2 + 3 = 5. 
2. Now connect ropes of lengths 4 and 5. Which makes the array [9, 6]. Cost of this operation 4 + 5 = 9.
3. Finally connect the two ropes and all ropes have connected. 
Cost of this operation 9 + 6 =15
Total cost for connecting all ropes is 5 + 9 + 15 = 29. 
This is the optimized cost for connecting ropes. 
Other ways of connecting ropes would always have same or more cost. 
For example, if we connect 4 and 6 first (we get three rope of 3, 2 and 10), 
then connect 10 and 3 (we gettwo rope of 13 and 2). 
Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.
```

### Example 2

```
Input: arr[] = [4, 2, 7, 6, 9]
Output: 62 
Explanation: First, connect ropes 4 and 2, which makes the array [6, 7, 6, 9]. 
Cost of this operation 4 + 2 = 6. 
Next, add ropes 6 and 6, which results in [12, 7, 9]. Cost of this operation 6 + 6 = 12.
Then, add 7 and 9, which makes the array [12,16]. Cost of this operation 7 + 9 = 16. And
finally, add these two which gives [28]. Hence, the total cost is 6 + 12 + 16 + 28 = 62.
```

```
Expected Time Complexity: O(n logn)
Expected Auxilliary Space: O(n)
```

### Constraints

- `1 ≤ arr.size() ≤ 20^5`
- `1 ≤ arr[i] ≤ 10^6`

## Solution

```Cpp
class Solution {
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Use a priority queue (min-heap) to store the lengths of the ropes.
        // The priority queue is initialized to behave as a min-heap (smallest element at the top).
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        // Push all the rope lengths from the input array into the priority queue.
        for (long long item : arr) {
            pq.push(item);              // Insertion into the heap takes O(log N) time.
        }

        // Variable to keep track of the total cost of connecting the ropes.
        long long cost = 0;

        // While there is more than one rope left to connect, keep merging.
        while (pq.size() > 1) {
            // Extract the two smallest ropes from the priority queue.
            long long top = pq.top();   // First smallest rope.
            pq.pop();                   // Remove the smallest rope.

            top += pq.top();            // Add the second smallest rope to the first.
            pq.pop();                   // Remove the second smallest rope.

            // The cost of connecting two ropes is added to the total cost.
            cost += top;

            // Push the combined rope back into the priority queue.
            pq.push(top);               // Insertion takes O(log N) time.
        }

        // Return the total minimum cost of connecting all ropes.
        return cost;
    }
};

Time Complexity = O(NlogN)
Space Complexity = O(N)
```