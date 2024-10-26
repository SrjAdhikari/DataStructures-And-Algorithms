# Question : [Subarrays with equal 1s and 0s - GFG](https://www.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1)

Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.

### Example 1

```
Input:
n = 7
A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8 
sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
(4, 5) ,(2, 5), (0, 5), (1, 6)
```

### Example 2

```
Input:
n = 5
A[] = {1,1,1,1,0}
Output: 1
Explanation: The index range for the 
subarray is (3,4).
```

### Your Task:
You don't need to read input or print anything. Your task is to complete the function `countSubarrWithEqualZeroAndOne()` which takes the array arr[] and the size of the array as inputs and returns the number of subarrays with equal number of 0s and 1s.

```
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
```

### Constraints

- `1 <= n <= 10^6`
- `0 <= A[i]<= 1`

## Solution

```Cpp
class Solution {
public:
    // Function to count the number of subarrays with an equal number of 0s and 1s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n) {
        // Variable to keep track of the cumulative sum (difference between 1s and 0s encountered).
        long long int sum = 0;

        // Variable to store the total count of subarrays with an equal number of 0s and 1s.
        int count = 0;

        // An unordered map to store the cumulative sum and its frequency.
        // mp[sum] stores how many times a particular sum has occurred so far.
        unordered_map<int, int> mp;

        // Initialize the map with sum 0 and frequency 1.
        // This is to handle cases where a subarray from the beginning has equal 0s and 1s.
        mp[0] = 1;

        // Traverse the array once.
        for (int i = 0; i < n; i++) {
            // Treat 1s and 0s differently:
            // Increment the cumulative sum for a 1, and decrement for a 0.
            if(arr[i] == 1)
                sum++;      // For a 1, we consider it as +1.
            else 
                sum--;      // For a 0, we consider it as -1.

            // If the current cumulative sum has been seen before, it means that there are subarrays
            // between previous occurrences of this sum and the current index that have an equal number of 0s and 1s.
            // Increment the count by the number of times this sum has occurred before.
            count += mp[sum];

            // Increment the frequency of the current cumulative sum in the map.
            mp[sum]++;
        }

        // Return the total count of subarrays with equal 0s and 1s.
        return count;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```