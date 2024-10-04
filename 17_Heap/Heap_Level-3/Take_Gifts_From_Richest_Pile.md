# Question : [Take Gifts From the Richest Pile - (LeetCode : 2558)](https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/)

You are given an integer array `gifts` denoting the number of gifts in various piles. Every second, you do the following:

- Choose the pile with the maximum number of gifts.
- If there is more than one pile with the maximum number of gifts, choose any.
- Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.

At the end of the game, there is **at most one** stone left.

Return *the number of gifts remaining after `k` seconds*.

### Example 1

```
Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation: 
The gifts are taken in the following way:
- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.
```

### Example 2

```
Input: gifts = [1,1,1,1], k = 4
Output: 4
Explanation: 
In this case, regardless which pile you choose, you have to leave behind 1 gift in each pile. 
That is, you can't take any pile with you. 
So, the total gifts remaining are 4.
```

### Constraints

-   `1 <= gifts.length <= 10^3`
-   `1 <= gifts[i] <= 10^9`
-   `1 <= k <= 10^3`

## Solution

```Cpp
class Solution {
public:
    // Function to calculate the total number of gifts left after modifying the piles for k iterations.
    long long pickGifts(vector<int>& gifts, int k) {
        // Variable to store the final total number of gifts after k iterations.
        long long maxGift = 0;
        
        // Create a max-heap (priority queue) to store the number of gifts in each pile.
        priority_queue<long long> pq;
        
        // Push all the initial gift counts into the priority queue (max-heap).
        for (long long gift : gifts) {
            pq.push(gift);
        }

        // Iterate k times, each representing a second where gifts are picked and modified.
        while (k--) {
            // Retrieve the largest pile of gifts (top of the max-heap).
            long long top = pq.top();
            
            // Pop the largest pile from the heap as we will modify it.
            pq.pop();
            
            // Push back the floor of the square root of the top pile back into the heap.
            // This simulates leaving behind the modified pile after picking the gifts.
            pq.push(sqrt(top));
        }

        // Calculate the total gifts remaining in the heaps after k seconds.
        while (!pq.empty()) {
            // Add the current top (largest pile) to the total.
            maxGift += pq.top();
            
            // Remove the current top element.
            pq.pop();
        }

        // Return the total number of remaining gifts.
        return maxGift;
    }
};

Time Complexity = O(NlogN)
Space Complexity = O(N)
```