# Question : [Magician and Chocolates - Interviewbit](https://www.interviewbit.com/problems/magician-and-chocolates/)

Given `N` bags, each bag contains `Bi` chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag `i`, eats `Bi` chocolates, then the magician fills the `ith` bag with `floor(Bi/2)` chocolates.

Find the maximum number of chocolates that kid can eat in `A` units of time.

**Note**:
    1.floor() function returns the largest integer less than or equal to a given number.
    2. Return your answer modulo 109+7

### Input Format
```
First argument is an integer A.
Second argument is an integer array B of size N.
```

### Example 1

```
Input:
A = 3
B = [6, 5]
Output:
14
Explanation: 
At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates. 
At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates. 
At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate. 
so, total number of chocolates eaten are 6 + 5 + 3 = 14
```

### Example 2

```
Input:
A = 5
B = [2, 4, 6, 8, 10]
Output:
33
```

### Constraints

- `1 <= A <= 10^5`
- `1 <= |B| <= 10^5`
- `1 <= Bi <= INT_MAX`

## Solution

```Cpp
class Solution {
public:
    // Function to return the maximum number of chocolates that can be eaten.
    int nchoc(int A, int* B, int n2) {
        // Create a max heap (priority queue) to store the number of chocolates in each bag.
        priority_queue<int> pq;
        
        // Push all the chocolate counts from array B into the priority queue.
        for(int i = 0; i < n2; i++) {
            pq.push(B[i]);
        }
        
        // Variable to store the total number of chocolates eaten.
        long long total = 0;
        
        // Continue eating chocolates for A iterations or until the queue is empty.
        while(A && (!pq.empty())) {
            // Get the bag with the maximum chocolates.
            int top = pq.top();
            
            // Add the chocolates from the largest bag to the total.
            total += top;
            
            // If there are chocolates left after eating half, push the new pile (top / 2) back into the heap.
            if (top / 2 > 0) { 
                pq.push(top / 2);
            }

            // Remove the top pile from the heap since it has been eaten.
            pq.pop();
            
            // Decrease the count of operations (number of times chocolates can be eaten).
            A--;
        }
        
        // Return the total chocolates eaten modulo 100000007 to avoid overflow.
        return total % 100000007;
    }
};

Time Complexity = O(AlogN)
Space Complexity = O(N)
```