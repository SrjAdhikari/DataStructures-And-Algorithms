# Question : [Largest subarray with 0 sum - GFG](https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1)

Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

### Example 1

```
Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
Output: 5
Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.
```

### Example 2

```
Input: arr[] = {2,10,4}, n = 3
Output: 0
Explanation: There is no subarray with 0 sum.
```

### Example 3

```
Input: arr[] = {1, 0, -4, 3, 1, 0}, n = 6
Output: 5
Explanation: The subarray is 0 -4 3 1 0.
```

```
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
```

### Constraints

- `1 <= n <= 10^5`
- `-1000 <= arr[i] <= 1000, for each valid i`

## Solution

```Cpp
class Solution {
public:
    int maxLen(vector<int>& arr, int n) {
        int length = 0;             // Variable to store the maximum length of subarray with sum 0
        int prefixSum = 0;          // Variable to store the running prefix sum
        
        // Map to store prefix sum and its first occurrence index
        unordered_map<int, int> mp; 

        // Traverse through the array
        for(int i = 0; i < n; i++) {
            prefixSum += arr[i];    // Add current element to the prefix sum

            // Case 1: If the prefix sum is zero, then the subarray from 0 to i has a sum of 0
            if(prefixSum == 0)
                length = i + 1;     // Update length as the whole subarray from 0 to i has sum 0

            // Case 2: If the prefix sum has been seen before, then a zero-sum subarray exists between the previous occurrence and the current index
            // So, calculate the length of the subarray between the current index and the previous occurrence of this prefix sum
            else if(mp.find(prefixSum) != mp.end()) {
                length = max(length, i - mp[prefixSum]);
            }

            // Case 3: If the prefix sum is not in the map, store it with the current index
            else {
                mp[prefixSum] = i;  // Store the first occurrence of the prefix sum
            }
        }
        
        // Return the maximum length of the subarray with sum 0
        return length;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```