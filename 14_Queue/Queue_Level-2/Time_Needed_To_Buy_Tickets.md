# Question : [Time Needed to Buy Tickets - (LeetCode : 2073)](https://leetcode.com/problems/time-needed-to-buy-tickets/description/)

There are `n` people in a line queuing to buy tickets, where the `0th` person is at the front of the line and the `(n - 1)th` person is at the back of the line.

You are given a 0-indexed integer array `tickets` of length `n` where the number of tickets that the `ith` person would like to buy is `tickets[i]`.

Each person takes **exactly 1 second** to buy a ticket. A person can only buy **1 ticket at a time** and has to go back to the end of the line (which happens **instantaneously**) in order to buy more tickets. If a person does not have any tickets left to buy, the person will **leave** the line.

Return *the ***time taken*** for the person at position `k` (***0-indexed***) to finish buying tickets*.

### Example 1

```
Input: tickets = [2,3,2], k = 2
Output: 6
Explanation: 
- In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
- In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.
```

### Example 2
```
Input: tickets = [5,1,1,1], k = 0
Output: 8
Explanation:
- In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0].
- In the next 4 passes, only the person in position 0 is buying tickets.
The person at position 0 has successfully bought 5 tickets and it took 4 + 1 + 1 + 1 + 1 = 8 seconds.
```

### Constraints

-   `n == tickets.length`
-   `1 <= n <= 100`
-   `1 <= tickets[i] <= 100`
-   `0 <= k < n`

## Solution 1

```Cpp
class MinStack {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;               // Queue to maintain the order of people in the queue
        int n = tickets.size();     // Total number of people in the queue

        // Initialize the queue by pushing each person's index into the queue
        for(int i = 0; i < n; i++) {
            q.push(i);      // Push the index of each person into the queue
        }

        int timer = 0;      // Variable to track the total time required

        // Simulate the ticket buying process until the kth person has bought all their tickets
        // Continue until the person at index 'k' has 0 tickets remaining
        while(tickets[k] != 0) { 

            // Decrease the ticket count for the person at the front of the queue (i.e., the one currently buying a ticket)
            tickets[q.front()]--;

            // If the person at the front still has tickets remaining, push them to the back of the queue
            if(tickets[q.front()])
                q.push(q.front());

            // Remove the person at the front from the queue (either they are done or will go to the back of the queue)
            q.pop();

            // Increment the time for each ticket sold
            timer++;
        }

        // Return the total time required for the kth person to buy all their tickets
        return timer;
    }
};

Time Complexity = O(N * M)
Space Complexity = O(N)

=> 'N' is the number of people in the queue.
=> 'M' is the maximum number of tickets that any person needs to buy.
```

## Solution 2

```Cpp
class MinStack {
public:

    // Function to calculate the time required to buy tickets
    // The vector 'tickets' represents the number of tickets each person wants to buy,
    // and 'k' is the index of the person we are calculating the time for.
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(); // Total number of people in line
        int time = 0;           // Variable to store the total time

        // Loop through all people from the start of the line up to the person 'k'
        // We add the minimum between tickets[k] and tickets[i] because:
        // - If person i has tickets[i] <= tickets[k], they will buy all their tickets before person k
        // - Otherwise, they will only buy tickets[k] tickets during this time
        for(int i = 0; i <= k; i++) {
            time += min(tickets[k], tickets[i]);
        }

        // Loop through the people after person 'k'
        // Since person 'k' will buy their last ticket and leave the queue, each person after them
        // will buy at most (tickets[k] - 1) tickets during this time.
        for(int i = k + 1; i < n; i++) {
            time += min(tickets[k] - 1, tickets[i]);
        }

        // Return the total time required for the kth person to buy all their tickets.
        return time;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
