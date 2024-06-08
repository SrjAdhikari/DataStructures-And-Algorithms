# Question : [Koko Eating Bananas - (LeetCode : 875)](https://leetcode.com/problems/koko-eating-bananas/description/)

Koko loves to eat bananas. There are `n` piles of bananas, the `ith` pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return *the minimum integer `k` such that she can eat all the bananas within `h` hours*.

### Example 1

```plaintext
Input: piles = [3,6,7,11], h = 8
Output: 4
```

### Example 2

```plaintext
Input: piles = [30,11,23,4,20], h = 5
Output: 30
```

### Example 3

```plaintext
Input: piles = [30,11,23,4,20], h = 6
Output: 23
```

### Constraints

`1 <= piles.length <= 10^4`

`piles.length <= h <= 10^9`

`1 <= piles[i] <= 10^9`


## Solution

```Cpp

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // Initialize the start and end for binary search
        int start = 1; // Minimum possible eating speed
        int end = 0; // Maximum possible eating speed will be set to the maximum pile size
        int ans = -1; // Variable to store the answer (minimum eating speed)
        int n = piles.size(); // Number of piles

        // Find the maximum number of bananas in a single pile
        for (int i = 0; i < n; i++) {
            end = max(end, piles[i]); // Set end to the largest pile size
        }

        // Perform binary search
        while (start <= end) {

            // Calculate the middle point to test as the eating speed
            long long int mid = start + (end - start) / 2; 
            long long int totalHour = 0;        // Variable to store the total hours needed to eat all piles at speed 'mid'

            // Calculate the total hours required to eat all bananas at the current eating speed 'mid'
            for (int i = 0; i < n; i++){
                totalHour += piles[i] / mid;    // Add the hours needed to eat the current pile
                if(piles[i] % mid)              // If there are leftovers, it takes an additional hour
                    totalHour++;
            }

            // Check if the total hours needed exceeds the allowed hours 'h'
            if (totalHour > h) {
                start = mid + 1;        // Increase the minimum possible speed to reduce total hours
            } else {
                ans = mid;              // Update the answer to the current mid value
                end = mid - 1;          // Decrease the maximum possible speed to find a potentially lower valid speed
            }
        }

        // Return the minimum eating speed that allows finishing all piles within 'h' hours
        return ans;
    }
};

Time Complexity = O(nlogn)
Space Complexity = O(1)
```