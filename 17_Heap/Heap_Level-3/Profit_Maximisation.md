# Question : [Profit Maximisation - Interviewbit](https://www.interviewbit.com/problems/profit-maximisation/)

 Given an array `A` , representing seats in each row of a stadium. You need to sell tickets to `B` people.

Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.

### Input Format
```
First argument is the array A.
Second argument is integer B.
```

### Example 1

```
Input:
A = [2, 3]
B = 3
Output:
7
Explanation: 
First you serve the seat with number = 3. 
Then with 2 and then with 2. Hence answer = 3 + 2 + 2 = 7.
```

### Example 2

```
Input:
A = [1, 4]
B = 2
Output:
7
Explanation:
You give both tickets from the row with 4 seats. 4 + 3 = 7.
```

### Constraints

- `1 <= |A| <= 100000`
- `1 <= B <= 1000000`

## Solution

```Cpp
class Solution {
public:
    // Function to calculate the maximum profit from selling 'B' tickets from various sellers.
    int solve(int* A, int n1, int B) {
        // Variable to store the maximum profit obtained.
        int maxProfit = 0;

        // Create a max-heap (priority queue) to store the number of tickets each seller has.
        priority_queue<int> pq;

        // Push all the ticket counts from the array A into the priority queue.
        for (int i = 0; i < n1; i++) {
            pq.push(A[i]);
        }

        // Continue selling tickets while there are tickets to sell (B > 0) and the heap is not empty.
        while (B && (!pq.empty())) {
            // Get the largest pile of tickets available.
            int top = pq.top();

            // Add the number of tickets sold (from the largest pile) to the maximum profit.
            maxProfit += top;

            // If there are still tickets left after selling from the top pile, decrease the count.
            // Push the updated pile back into the heap if it's not empty.
            if (top - 1) {
                pq.push(top - 1);
            }

            // Remove the largest pile from the heap as it's been processed.
            pq.pop();

            // Decrement the number of tickets that can still be sold.
            B--;
        }

        // Return the total maximum profit after selling 'B' tickets.
        return maxProfit;
    }
};

Time Complexity = O(BlogN)
Space Complexity = O(N)
```