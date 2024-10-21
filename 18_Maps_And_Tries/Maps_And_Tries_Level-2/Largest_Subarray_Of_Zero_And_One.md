# Question : [Largest subarray of 0's and 1's - GFG](https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1)

Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

### Example 1

```
Input:
N = 4
A[] = {0,1,0,1}
Output: 4
Explanation: The array from index [0...3]
contains equal number of 0's and 1's.
Thus maximum length of subarray having
equal number of 0's and 1's is 4.
```

### Example 2

```
Input:
N = 5
A[] = {0,0,1,0,0}
Output: 2
```

### Your Task:
You don't need to read input or print anything. Your task is to complete the function `maxLen()` which takes the array arr[] and the size of the array as inputs and returns the length of the largest subarray with equal number of 0s and 1s.

```
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
```

### Constraints

- `1 <= N <= 10^5`
- `0 <= A[] <= 1`

## Solution

```Cpp
class Solution {
public:
    int maxLen(int arr[], int N) {
        int length = 0;                 // Tracks the maximum length of the subarray found
        int sum = 0;                    // Variable to maintain the cumulative sum
        unordered_map<int, int> mp;     // Map to store the first occurrence of each sum
        
        for(int i = 0; i < N; i++) {            
            // For each element in the array:
            // If the element is 1, increments the sum.
            // If the element is 0, decrements the sum.
            if(arr[i] == 1)
                sum++;
            else 
                sum--;
            
            // If the sum is 0, the subarray from index 0 to i has equal 1s and 0s
            if(sum == 0)
                length = i + 1;
            
            // If this sum has been seen before, calculate the length of the subarray
            // between the previous occurrence and the current index
            else if(mp.count(sum))
                length = max(length, i - mp[sum]);
            
            // If this sum is seen for the first time, store the index
            else
                mp[sum] = i;
        }

        // Return the maximum length of the subarray found
        return length;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```